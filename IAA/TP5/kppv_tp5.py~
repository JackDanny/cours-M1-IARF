#!/usr/bin/env python
# -*- coding: utf-8 -*-
# prerequis : librairie pylab installée (regroupe scypy, matplotlib, numpy et ipython)
# codage de la méthode de classification par k plus proches voisins

from pylab import *
import random

def attente_touche():
	raw_input()

#on trie une liste selon la 1er coordonnée
def comp(v1, v2):
    if v1[0]<v2[0]:
        return -1
    elif v1[0]>v2[0]:
        return 1
    else:
        return 0


	

def decision_kppv(liste_points_classes,point_a_classer,K):
	assert type(liste_points_classes) is list
	# decision_kppv 
	#
	# Entrée :
	# - liste_points_classes : liste pour chaque classe de liste de
	#   points représentatifs de la classe 
	# - point_a_classer : 
	# - K : entier, nombre de voisins a prendre en compte
	# Sortie :
	# - numero de la classe la plus proche (0 si pas de décision)
	
	nb_classes = len(liste_points_classes)
	nb_points_representatifs = len(liste_points_classes[0])
	


	# calcul des distances à chacun des points représentatifs
	# ...
	
	distances_class = []
        for i  in range(nb_classes):
                #pour chaque distance on va aussi stocker la classe à laquelle il appartient
		for j in range(len(liste_points_classes[i])):
                        distances_class.append( (norm(array(point_a_classer)-array(liste_points_classes[i][j])),i ))
		

        distances_class.sort(comp)
        
	
	
	# recherche des points les plus proches
	# ...
	
        #on compte le nombre d'occurence des classes auxquelles appartiennent les points
	nbOccClass=[0]
        for i in range(len(liste_points_classes)-1):
		nbOccClass.append(0)
	

	for i in range(K):
                #le ieme point le plus proche appatient à la classe c
                c=distances_class[i][1]
                #on incrémente donc nbOccClass de 1
		nbOccClass[c]=nbOccClass[c]+1
	
        #print("nbOccClasse = "+str(nbOccClass))
        # décision sur les classes
	# ...

        #on prend l'indice de l'élément de plus grande valeur de nbOccClass
        classe_la_plus_proche=argmax(nbOccClass)

        #liste des classes ayant max(nbOccClass) occurences
        #ceci sert à savoir si on a un cas d'indécision
        classArgmax=[]

        for i in range(len(nbOccClass)):
            if(nbOccClass[i] == max(nbOccClass)):
                classArgmax.append(i)

        #print("classArgmax" + str(classArgmax))

        #si la liste n'a pas 1 éléments, elle en a plusieurs donc on est dans un cas d'indécision
        if(nbOccClass.count(nbOccClass[classe_la_plus_proche]) != 1):
            #prendPasDecision(nbOccClass,classArgmax)
            #classe_la_plus_proche = prendDecisionRandom(classArgmax)
            #classe_la_plus_proche = DecisionIncrementeK(liste_points_classes,point_a_classer,K)
            #classe_la_plus_proche = DecisionDecrementeK(liste_points_classes,point_a_classer,K)
            #print("distances classes: " + str(distances_class))
            classe_la_plus_proche = DecisionPoidsDistance(distances_class,nb_classes,K)
	
	# classe_la_plus_proche = ...

	return classe_la_plus_proche


def prendPasDecision(nbOccClass,classArgmax):
    print("nbOccClass = " + str(nbOccClass))

    print("les classes qui portent soucis sont:" +str(array(classArgmax)+1))

    raise Exception("indecision")
    pass

def prendDecisionRandom(listeClasse):
    r=randint(0,len(listeClasse))
    return listeClasse[r]

def DecisionIncrementeK(liste_points_classes,point_a_classer,K):
    print("indecision, on decremente K. K= " + str(K+1))
    c=decision_kppv(liste_points_classes,point_a_classer,K+1)
    return c

def DecisionDecrementeK(liste_points_classes,point_a_classer,K):
    print("indecision, on decremente K. K= " + str(K-1))
    c=decision_kppv(liste_points_classes,point_a_classer,K-1)
    return c

def DecisionPoidsDistance(distances_class,nb_classes,K):

    valeurClasses=zeros(nb_classes)

    for i in range(K):
        #la classe dans laquelle ajouter la valeur
        classAugm=distances_class[i][1]
        #la valeur à ajouter
        val=1./(1.+distances_class[i][0])
        #print("on rajoute:" + str(val) + " à " + str(classAugm))
        #on rajoute la valeur
        valeurClasses[classAugm]=valeurClasses[classAugm]+val

    #print("valeurs Classes " + str(valeurClasses))
    #on retourne la classe qui a la plus grande valeur


    c=argmax(valeurClasses)
    return c

