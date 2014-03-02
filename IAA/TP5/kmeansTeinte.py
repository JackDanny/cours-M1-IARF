#!/usr/bin/env python
# -*- coding: utf-8 -*-
# prerequis : librairie pylab installée (regroupe scypy, matplotlib, numpy et ipython)
# codade de la méthode des Kmeans pour réaliser une partition de données

from pylab import *
import random

def attente_touche():
	print("veuillez appuyer sur une touche...")
	raw_input()

def appartient_liste(data,liste):
    
    for i in range(len(liste)):
        if liste[i]==data :
            return True
    return False


def affichage_donnees(data,centres):
	assert type(data) is list
	assert type(centres) is list
	cla()
	couleurs = [ 'b', 'g', 'r', 'c', 'm', 'y', 'k', 'w' ]
	styles = [ 'x', ',', 'o', 'v', '^', '<', '>', '1', '2', '3', '4', 's', 'p', '*', 'h', 'H', '+', '.', 'D', 'd' ]
	formes = []
	formes_ctr = []
	
	nb = len(centres)
	no_couleur = 0
	style = styles.pop(0)

        for groupe in range(nb):

            if (no_couleur >= (len(couleurs))):
                style = styles.pop(0)
                no_couleur = 0
            formes.append(style + couleurs[no_couleur])
            formes_ctr.append("o" + couleurs[no_couleur])
            no_couleur += 1
	hold(True)
	for groupe in range(nb):
		forme = formes[groupe]
		plot(centres[groupe], formes_ctr[groupe])
		
		for index_point in range(len(data[groupe])):
			point=data[groupe][index_point]
			plot(point[2],forme)
	hold(False)


#on calcule la distance entre deux points seulement avec la valeur de la composante T de TSL
def calcul_distance(teinte1, teinte2):
	return abs(teinte2-teinte1)


def calcul_centroide(liste):
	# calcul du centroide de la composante T d'une liste de points passée en argument
    somme_t = 0.0
    moyenne_t = 0.0
    nb=len(liste)
    for point in range(len(liste)):
		somme_t += liste[point][2]

    if nb != 0:
        moyenne_t = somme_t / nb
	  
	return moyenne_t


def kmeans(data,nbGroupes):
    # assert lève une exception si le type de data n'est pas une liste
    assert type(data) is list
    # assert lève une exception si nbGroupes n'est pas un entier
    assert type(nbGroupes) is int
    # on verifie que le nombre de classes désiré est inférieur au nombre de point
    assert(nbGroupes <= len(data))
    #on verifie que le nombre de classes désiré est supérieur à 0
    assert(nbGroupes > 0)


	# kmeans applique l'akgorithme des K-means sur la liste des points
	# fournie en paramètres et applique une partition en nbGroupes sur ces points.
	#
	# Entrée :
	# - data : liste de point (1 point = 1 vecteur de dimension 2)
	# - nbGroupes : nombre de partitions à effectuer sur les données
	# Sortie :
	# - data : liste des groupes de points partitionnés par la méthode des kmeans
	
	# active le mode interactif: permet de ne pas utiliser la méthode draw() ou show() à chaque appel à plot()
    ion()

	

    data = [ data ]

    for groupevide in range(nbGroupes-1):
		data.append([])


	
	# choix centres initiaux : tirage aleatoire dans les points présents.
    
    centres = []


    for groupe in range(nbGroupes):
        
        retry = True
        while retry:
            point_random=random.choice(data[0])
            retry=appartient_liste(point_random[2],centres)


        centres.append(point_random[2])
    
	
	# boucle tant qu'il y a des changements sur la méthode
    non_stabilise = True
    iteration = 1
    while non_stabilise:
        # Affichage des points et des centroïdes
        print("Itération = " + str(iteration)) ;
        #print("Données groupées : ") ; print(data) ;
        print("Centres : ") ; print(centres) ;
        '''
        inertie = calcul_inertie(data, centres)
        print("inertie: " + str(inertie))
        
        print("inertie inter: " + str(calcul_inertie_inter(data,centres)))
        '''
        #affichage_donnees(data,centres)    
        #attente_touche()
        # 1. reallocation
        # ... A vous de jouer !
        # indication : utiliser la fonction argmin renvoie l'indice du min d'une liste 


        newdata = []
        #newdata est nitialisé par nbGroupes éléments vide
        for i in range(nbGroupes):
	    	newdata.append([])

		
	    #pour chaque groupe i data
        for i in range(0,len(data)):
			
	    	#pour chaque élémet j de data[i]
            for j in range(0,len(data[i])):
	    		#liste des distances de j par rapports aux centres
                listDist = []
			
	    		#pour chacun des centre k
                for k in range(0,len(centres)): 
                    #on calcule et rajoute la distance du point data[i][j] au centre k
                    '''
                    print("data[i][j][2] =" + str(data[i][j][2]))
                    print("centres[k] =" + str(centres[k]))
                    '''         

                    listDist.append(calcul_distance(data[i][j][2],centres[k]))
	    		#on prend l'indice de l'élément le plus petit de listDist, autrement dit
	    		#l'indice du centre le plus proche de data[i][j][2]
                minDistList=argmin(listDist)
	    		#on rajoute data[i][j] dans le groupe minDistList des nouvelles data
                #print("newdata" + str(newdata))
                newdata[minDistList].append(data[i][j])

       
        data=list(newdata)

        #print("reallocation: " + str(data))

	    # 2. recentrage
	    # calcul des nouveaux centres de gravité
        anciens_centres = list(centres)
	    #centres = []
	    # ... A vous de jouer pour attribuer centres...
		



        for i in range(len(anciens_centres)):
		    centres[i]=calcul_centroide(data[i])
		
            #print("centres: " +str(centres))




		
		
	    # 3. Mise à jour du critère de boucle
	    # critère basique : 
        
        if anciens_centres == centres:
            non_stabilise = False
            
    
        #critère inertie : seuil relatif de 10% par exemple
        
    
        iteration=iteration+1
        #print("data:" + str(data))
    return (data,centres)




