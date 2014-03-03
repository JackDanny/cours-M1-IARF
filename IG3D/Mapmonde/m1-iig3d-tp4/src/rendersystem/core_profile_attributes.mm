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
#include <QGLContext>
namespace gui {

/**
  * Creation of an OpenGL 3.2 core profile on MacOsX Lion for Qt 4.7
  */
void* select_3_2_mac_visual(GDHandle handle)
{
    static const int Max = 40;
    NSOpenGLPixelFormatAttribute attribs[Max];
    int cnt = 0;

    attribs[cnt++] = NSOpenGLPFAOpenGLProfile;
    attribs[cnt++] = NSOpenGLProfileVersion3_2Core;

    attribs[cnt++] = NSOpenGLPFADoubleBuffer;
    attribs[cnt++] = NSOpenGLPFAAccelerated;

    attribs[cnt++] = NSOpenGLPFADepthSize;
    attribs[cnt++] = (NSOpenGLPixelFormatAttribute)16;

    attribs[cnt++] = NSOpenGLPFAStencilSize;
    attribs[cnt++] = (NSOpenGLPixelFormatAttribute)8;

    attribs[cnt++] = NSOpenGLPFAColorSize;
    attribs[cnt++] = (NSOpenGLPixelFormatAttribute)32;
    attribs[cnt++] = NSOpenGLPFAAlphaSize;
    attribs[cnt++] = (NSOpenGLPixelFormatAttribute)8;

    attribs[cnt] = 0;
    Q_ASSERT(cnt < Max);

    return [[NSOpenGLPixelFormat alloc] initWithAttributes:attribs];
}

}
