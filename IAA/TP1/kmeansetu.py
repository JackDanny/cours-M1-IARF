#!/usr/bin/env python
# -*- coding: utf-8 -*-
# prerequis : librairie pylab installée (regroupe scypy, matplotlib, numpy et ipython)
# codade de la méthode des Kmeans pour réaliser une partition de données

from pylab import *
import random

def attente_touche():
	print("veuillez appuyer sur une touche...")
	raw_input()

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
		plot(centres[groupe][0], centres[groupe][1], formes_ctr[groupe])
		
		for index_point in range(len(data[groupe])):
			point=data[groupe][index_point]
			plot(point[0],point[1],forme)
	hold(False)

def calcul_distance(point1, point2):
	return sqrt((point1[0]-point2[0])**2+(point1[1]-point2[1])**2)

def calcul_centroide(liste):
	# calcul du centroide d'une liste de points passée en argument
	somme_x = 0.0
	somme_y = 0.0
	moyenne_x = 0.0
	moyenne_y = 0.0
	nb = len(liste)
	for point in range(nb):
		somme_x += liste[point][0]
		somme_y += liste[point][1]
	if nb != 0:
	  moyenne_x = somme_x / nb
	  moyenne_y = somme_y / nb
	return [moyenne_x, moyenne_y]

#calcul de l'inertie totale d'une classe sans les coeffs
def calcul_inertie_totale_nuage(liste):
    #on calcul le centre des points
    centre=calcul_centroide(liste)
    inertie=0.
    d=0.
    nbPoints=0.
    for i in range(len(liste)):
        #et on rajoute la distance au carré de chacun des points au centre
        d = calcul_distance(liste[i],centre)
        inertie += d**2

    return inertie




#calcul de l'inertie inter classe
def calcul_inertie_inter(liste,centre):
    inertie_inter=0.;
    listePoints=[]
    nbPoints=0.
    #pour chaque région...
    for i in range(len(liste)):
        #pour chaque point de la région...
        for j in range(len(liste[i])):
            #on rajoute a la liste des points liste[i][j]
            listePoints.append(liste[i][j])
        #le nombre totale de points s'en trouve augmenter
        nbPoints+=len(liste[i])
    #on calcule le centre d'inertie de tous les points de l'univers
    centre_total=calcul_centroide(listePoints)
    #on calcule la somme des carrés des distances de chaque centroide au centre de tous les points,
    #coefficientés nb_de_points_du_nuage/nb_points
    for i in range(len(centre)):

        distance_centres=calcul_distance(centre[i], centre_total)
        inertie_inter+=((distance_centres**2) * (len(liste[i]))/(nbPoints))


    return inertie_inter


#calcule l'inertie totale d'une classe
def calcul_inertie_classe(liste, centre):
        inertie_totale = 0.
        d=0.
        #on fait la somme des carrées des distances des points au centre d'inertie
        for i in range(len(liste)):
            d=calcul_distance(liste[i], centre)
            inertie_totale += (d**2)


        return inertie_totale


# calcul de l'inertie intra-classes d'une liste points passée en argument
def calcul_inertie(liste, centres):
	# Question 4
        # calcul de l'inertie intra-classes d'une liste de nuages de points passée en argument
        # Sortie : inertie
	# À vous de jouer...
        inertie_intra=0.
        nbPoints=0.
        #on fait la somme des inerties de chaque classes
        #et nbPoints a pour valeur finale le nombre totale de points
        for i in range(len(liste)):
            inertie_intra+=calcul_inertie_classe(liste[i],centres[i])
            nbPoints+=len(liste[i])
        #on rajoute un coeff = 1/nbPoints pour vérifier la décomposition de Huygens
        return inertie_intra/nbPoints

#pour une matrice, donne l'indice de ligne et de colone de la plus petite valeur
def argsMinMatrix(liste):

	#tableau contenant les indice du minimum de chaque ligne
	#ie minIndexArray[i] contient l'indice de colone du minimum de la ligne i de la matrice liste
	minIndexArray=[]	
		
	#la liste des valeurs correspondants à ces indices
	listeValue=[]

	for i in range(len(liste)):
		minIndexArray.append(argmin(liste[i],axis=0))
		#on va rajouter les valeurs correspondantes à ces indices dans listeValue
		listeValue.append(liste[i][minIndexArray[i]])
        

    #on prend l'indice de la plus faible valeur, on trouve ainsi la ligne ayant la plus petite
	#valeur de minimum
        indMin=argmin(listeValue,axis=0)
    #on en deduit les indices, indMin pour la ligne, minIndexArray pour sa colone



	#return [indMin,minIndexArray[indMin]]
	ret=[]
	ret.append(indMin)
	ret.append(minIndexArray[indMin])
	

	return ret

def init_centres(liste, nbG):
	# Question 3
	# Sortie : liste des centres
	# À vous de jouer... 
	#au debut on a len(liste) groupes
	#chaque point est considéré comme un groupe
	newList = []
	for i in range(0,len(liste)):
		newList.append([liste[i]])
	    
	
	
	
	#tant que l'on a pas nbG groupes
	while len(newList) > nbG:
		#MatDist va contenir les distances entre les régions
		MatDist = []
		#on initialise sa taille
		for i in range(0,len(newList)-1):
			MatDist.append([])



	    #pour chaque groupe
		for i in range(0,len(newList)):
	    #pour chacun des autre groupes
			for j in range(i+1,len(newList)):
				listeDist=[]
	        #pour chacune des regions k de liste[i]
				for k in range(0,len(newList[i])):
	           #pour chacun des points de liste[j]
					for l in range(0,len(newList[j])):
	                #on calcule les distance entre les points de la region i et
	                #ceux de la region j et on les ajoute à listeDist
						listeDist.append(calcul_distance(newList[i][k],newList[j][l]))
	        #on ne garde que la distance minimal, c'est la distance entre deux regions
	        #et on le concatene à MatDist[i]
	        #resultat MatDist[a][b] contient la distance entre la region a et a+1+b
				MatDist[i].append(min(listeDist))
                #print("MatDist")
                #print(MatDist)

	
		argsMin=argsMinMatrix(MatDist)
                #print("la region")
                #print(argsMin[0])
                #print("fusionne avec")
                #print(argsMin[1])
		x=argsMin[0]
		y=argsMin[1]
                #print(" newList")
                #print(newList)
		newList[x]=newList[x]+newList[x+1+y]
		del newList[x+1+y]
                #print(" newList after")
                #print(newList)


	listCentroide= [calcul_centroide(elem) for elem in newList]

	return(listCentroide)

   





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

	# choix centres initiaux : initialisation plus robuste que le choix aléatoire (question 3)

        centres = init_centres(data, nbGroupes)
        #centres = [[3.0, -5.0], [1.0, 1.0]]
        #centres = [[1.0, 2.0], [-2.0, -1.0]]
	# mise de la liste de point fournie en paramètres sous la forme
	# d'une liste de groupes : le premier groupe contenant tous les points du départ,
	# les autres étant vides

        print("calc inertie totale: " + str(calcul_inertie_totale_nuage(data)/len(data)) )

	data = [ data ]



	for groupevide in range(nbGroupes-1):
		data.append([])


	
	# choix centres initiaux : tirage aleatoire dans les points présents.
        '''
	centres = [ ]
	for groupe in range(nbGroupes):
		centres.append(random.choice(data[0]))
        '''
	
	# boucle tant qu'il y a des changements sur la méthode
	non_stabilise = True
	iteration = 1
	while non_stabilise:
		# Affichage des points et des centroïdes
		print("Itération = " + str(iteration)) ;
		print("Données groupées : ") ; print(data) ;
		print("Centres : ") ; print(centres) ;
                inertie = calcul_inertie(data, centres)
                print("inertie: " + str(inertie))
                print("inertie inter: " + str(calcul_inertie_inter(data,centres)))
        
		affichage_donnees(data,centres)
		attente_touche()
		
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
					listDist.append(calcul_distance(data[i][j],centres[k]))
				#on prend l'indice de l'élément le plus petit de listDist, autrement dit
				#l'indice du centre le plus proche de data[i][j]
				minDistList=argmin(listDist)
				#on rajoute data[i][j] dans le groupe minDistList des nouvelles data
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
                '''
                if anciens_centres == centres:
                       non_stabilise = False
                       print("Itération = " + str(iteration)) ;
                       print("Données groupées : ") ; print(data) ;
                       print("Centres : ") ; print(centres) ;

                '''
                #critère inertie : seuil relatif de 10% par exemple

                new_inertie = calcul_inertie(data, centres)
                diff_relative = (inertie - new_inertie)/inertie * 100
                print("old inertie: " + str(inertie) + " new inertie: " + str(new_inertie) + " diff_relat: " + str(diff_relative))
                if diff_relative < 10:
                        non_stabilise = False

		iteration=iteration+1
    
	return data
#obs=[[1,0],[7,0],[15,0],[5,0],[2,0]]
obs = [ [1.0,1.0],[3.0,3.0],[1.0,5.0],[-3.0,5.0],[-5.0,3.0],[-3.0,1.0],[3.0,-1.0],[5.0,-3.0],[3.0,-5.0],[-1.0,-5.0],[-3.0,-3.0],[-1.0,-1.0] ]
#obs=[ [1.0,1.0],[3.0,3.0]]

kmeans(obs,2)

# Exemples de sortie du programme

# comparaison des critères d'arrêt avec les mêmes centres au départ [[3.0, -5.0], [1.0, 1.0]]

# critère basique 
# Itération = 1
# Données groupées : 
# [[[1.0, 1.0], [3.0, 3.0], [1.0, 5.0], [-3.0, 5.0], [-5.0, 3.0], [-3.0, 1.0], [3.0, -1.0], [5.0, -3.0], [3.0, -5.0], [-1.0, -5.0], [-3.0, -3.0], [-1.0, -1.0]], []]
# Centres : 
# [[3.0, -5.0], [1.0, 1.0]]
# inertie: 656.0
# veuillez appuyer sur une touche...
# 
# Itération = 2
# Données groupées : 
# [[[5.0, -3.0], [3.0, -5.0], [-1.0, -5.0]], [[1.0, 1.0], [3.0, 3.0], [1.0, 5.0], [-3.0, 5.0], [-5.0, 3.0], [-3.0, 1.0], [3.0, -1.0], [-3.0, -3.0], [-1.0, -1.0]]]
# Centres : 
# [[2.3333333333333335, -4.333333333333333], [-0.7777777777777778, 1.4444444444444444]]
# inertie: 151.111111111
# veuillez appuyer sur une touche...
# 
# Itération = 3
# Données groupées : 
# [[[5.0, -3.0], [3.0, -5.0], [-1.0, -5.0], [3.0, -1.0]], [[1.0, 1.0], [3.0, 3.0], [1.0, 5.0], [-3.0, 5.0], [-5.0, 3.0], [-3.0, 1.0], [-3.0, -3.0], [-1.0, -1.0]]]
# Centres : 
# [[2.5, -3.5], [-1.25, 1.75]]
# inertie: 137.0
# veuillez appuyer sur une touche...

# critère inertie 10%
# Itération = 1
# Données groupées : 
# [[[1.0, 1.0], [3.0, 3.0], [1.0, 5.0], [-3.0, 5.0], [-5.0, 3.0], [-3.0, 1.0], [3.0, -1.0], [5.0, -3.0], [3.0, -5.0], [-1.0, -5.0], [-3.0, -3.0], [-1.0, -1.0]], []]
# Centres : 
# [[3.0, -5.0], [1.0, 1.0]]
# inertie: 656.0
# veuillez appuyer sur une touche...
# 
# old inertie: 656.0 new inertie: 151.111111111 diff_relat: 76.9647696477
# Itération = 2
# Données groupées : 
# [[[5.0, -3.0], [3.0, -5.0], [-1.0, -5.0]], [[1.0, 1.0], [3.0, 3.0], [1.0, 5.0], [-3.0, 5.0], [-5.0, 3.0], [-3.0, 1.0], [3.0, -1.0], [-3.0, -3.0], [-1.0, -1.0]]]
# Centres : 
# [[2.3333333333333335, -4.333333333333333], [-0.7777777777777778, 1.4444444444444444]]
# inertie: 151.111111111
# veuillez appuyer sur une touche...
# 
# old inertie: 151.111111111 new inertie: 137.0 diff_relat: 9.33823529412



