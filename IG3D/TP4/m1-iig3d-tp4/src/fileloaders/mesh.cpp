/***************************************************************************
 *   Copyright (C) 2012 by Mathias Paulin                                  *
 *   Mathias.Paulin@irit.fr                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "mesh.h"
#include "utils.h"
#include <iostream>

namespace loaders {
using namespace utils;
Mesh::Mesh (): nbVertices_(0), nbTriangles_(0), hasTextureCoords_ (true), hasNormal_ (true) {

}

Mesh::Mesh (const std::vector<float> &vertexBuffer, const std::vector<int> &triangleBuffer, const std::vector<int> &quadBuffer, bool hasNormal, bool hasTextureCoords) : hasTextureCoords_ (hasTextureCoords), hasNormal_ (hasNormal) {
	// Construction de la liste des sommets et BBox
	nbVertices_ = 0;
	std::vector<float>::const_iterator it = vertexBuffer.begin();
	while (it != vertexBuffer.end()) {
		float x = *it; ++it;
		float y = *it; ++it;
		float z = *it; ++it;
                Vertex v (glm::vec3(x, y, z));
		if (hasNormal) {
			float nx = *it; ++it;
			float ny = *it; ++it;
			float nz = *it; ++it;
                        v.normal_ = glm::vec3 (nx, ny, nz);
                        glm::normalize(v.normal_);
		}
		if (hasTextureCoords) {
			v.texcoord_[0] = *it; ++it;
                        v.texcoord_[1] = *it; ++it;
		}
		vertices_.push_back (v);
		++nbVertices_;
	}

	// construction liste des faces triangulaires
	std::vector<int>::const_iterator fit = triangleBuffer.begin();
	nbTriangles_ = 0;
	while (fit != triangleBuffer.end()) {
		int index1 = *fit; ++fit;
		assert (index1 < nbVertices_);
		int index2 = *fit; ++fit;
		assert (index2 < nbVertices_);
		int index3 = *fit; ++fit;
		assert (index3 < nbVertices_);
		++nbTriangles_;
		TriangleIndex f (index1, index2, index3);
		triangles_.push_back (f);
	}

        //   construction liste des faces quads
	std::vector<int>::const_iterator fiq = quadBuffer.begin();
	while (fiq != quadBuffer.end()) {
		int index1 = *fiq; ++fiq;
		assert (index1 < nbVertices_);
		int index2 = *fiq; ++fiq;
		assert (index2 < nbVertices_);
		int index3 = *fiq; ++fiq;
		assert (index3 < nbVertices_);
		int index4 = *fiq; ++fiq;
		assert (index4 < nbVertices_);

                ++nbTriangles_;
                TriangleIndex f1 (index1, index2, index3);
                triangles_.push_back (f1);

                ++nbTriangles_;
                TriangleIndex f2 (index1, index3, index4);
                triangles_.push_back (f2);

	}

	if (!hasNormal){
                computeNormals();
                hasNormal = true;
        }

}

Mesh::~Mesh() {

}

void Mesh::printfInfo() const {
        std::cerr << "\tMesh -> " << "vert : " << nbVertices_  << " tri : " << nbTriangles_ << " " << hasNormal_ << " " << hasTextureCoords_ << std::endl;
}

void Mesh::computeNormals (void) {
	for (TriangleIndexArray::iterator f_iter = triangles_.begin() ; f_iter != triangles_.end() ; ++f_iter) {
                Vertex& v0 = vertices_[f_iter->indexes_[0]];
                Vertex& v1 = vertices_[f_iter->indexes_[1]];
                Vertex& v2 = vertices_[f_iter->indexes_[2]];
                glm::vec3 p0, p1, p2;
		p0 = v0.position_;
		p1 = v1.position_;
		p2 = v2.position_;

                // compute normals
                glm::vec3 f_normal;
                f_normal = glm::cross((p1 - p0), (p2 - p0));
                glm::normalize(f_normal);
		v0.normal_ += f_normal;
		v1.normal_ += f_normal;
		v2.normal_ += f_normal;
	}
	for (VertexArray::iterator v_iter = vertices_.begin() ; v_iter != vertices_.end() ; ++v_iter) {
                glm::normalize(v_iter->normal_);
	}
}
 
void Mesh::getData ( std::vector<float> &vertexBuffer, std::vector<int> &triangleBuffer, bool &parametrized ){
    parametrized = true;

    for (VertexArray::iterator v_iter = vertices_.begin() ; v_iter != vertices_.end() ; ++v_iter) {
        vertexBuffer.push_back(v_iter->position_[0]);
        vertexBuffer.push_back(v_iter->position_[1]);
        vertexBuffer.push_back(v_iter->position_[2]);
        vertexBuffer.push_back(v_iter->normal_[0]);
        vertexBuffer.push_back(v_iter->normal_[1]);
        vertexBuffer.push_back(v_iter->normal_[2]);
        if (hasTextureCoords_){
            vertexBuffer.push_back(v_iter->texcoord_[0]);
            vertexBuffer.push_back(v_iter->texcoord_[1]);
        } else {
            vertexBuffer.push_back(v_iter->position_[0]);
            vertexBuffer.push_back(v_iter->position_[1]);
        }
    }
    for (TriangleIndexArray::iterator f_iter = triangles_.begin() ; f_iter != triangles_.end() ; ++f_iter) {
        triangleBuffer.push_back(f_iter->indexes_[0]);
        triangleBuffer.push_back(f_iter->indexes_[1]);
        triangleBuffer.push_back(f_iter->indexes_[2]);
    }
}

Mesh & Mesh::operator+=(const Mesh &m){
    for (VertexArray::const_iterator v_iter = m.vertices_.begin() ; v_iter != m.vertices_.end() ; ++v_iter) {
        vertices_.push_back(*v_iter);
    }
    for (TriangleIndexArray::const_iterator f_iter = m.triangles_.begin() ; f_iter != m.triangles_.end() ; ++f_iter) {
        TriangleIndex f (f_iter->indexes_[0]+nbVertices_,
                         f_iter->indexes_[1]+nbVertices_,
                         f_iter->indexes_[2]+nbVertices_);
        triangles_.push_back(f);
    }
    nbVertices_+=m.nbVertices_;
    nbTriangles_+=m.nbTriangles_;
    return *this;
}

} // namespace loaders
