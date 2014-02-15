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


def affichage_kppv(liste_donnees_classes,point_a_classer,K):
	assert type(liste_donnees_classes) is list
	
	nb_classes = len(liste_donnees_classes)
	couleurs= [ 'b', 'g', 'r', 'c', 'm', 'y', 'k', 'w' ]
	formespoints = [ 'x', 'o', 'v', '^', '<', '>', '1', '2', '3', '4', 's', 'p', '*', 'h', 'H', '+', '.', 'D', 'd', ',' ]
	formescentres = ['D','D','D']
	
	hold(True)
	for classe in range(nb_classes):
		# Affichage des points de référence
		forme=formespoints[classe]
		couleur=couleurs[classe]
		stylepoint=forme+couleur
		for point in liste_donnees_classes[classe]:
			plot(point[0],point[1],stylepoint)
		
	# Affichage du point a classer
	# ...
		
	# Affichage des segments sur les K points les plus proches
	# ...
		
	show()
	hold(False)
	

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
	for i  in range(len(liste_points_classes)):
		
		for j in range(len(liste_points_classes[i])):
			distances_class.append( (norm(array(point_a_classer)-array(liste_points_classes[i][j])),i ))
		
	#print("distances_class avant sort" + str(distances_class))
	distances_class.sort(comp)
	#print("distances_class apres sort" + str(distances_class))

	
	
	# recherche des points les plus proches
	# ...
	
	nbOccClass=[0]
	for i in range(K):
		nbOccClass.append(0)
	
	for i in range(K):
		c=distances_class[i][1]
		nbOccClass[c]=nbOccClass[c]+1
	
	# décision sur les classes
	# ...
	classe_la_plus_proche=argmax(nbOccClass)
	
	# classe_la_plus_proche = ...
	
	for i in range(len(nbOccClass)):
		if ( (i!= classe_la_plus_proche) and (nbOccClass[i] == nbOccClass[classe_la_plus_proche]) ):
		    print("erreur, indécision!!!")
		    
		
    
	return classe_la_plus_proche

# Programme principal : préparation points représentatifs et
#                       test sur 3 points

donnees_classe1 = [[3.6484028273127254, 0.073429844289042881], [2.330634259457685, 0.21748520551489497], [2.644948143301538, 0.20411304520644272], [2.7753121336336251, 0.18681685779827709], [2.1983916903402347, 0.19693911318338075], [2.836900928011457, 0.16884540288894506], [2.6235769902396133, 0.14047193438597244], [2.7157154911382348, 0.18092519035140286], [2.6662657025141492, 0.17384029751490698], [2.7900235283901487, 0.17124467162767718], [2.3025641883523864, 0.19080233853944761], [2.50402381354598, 0.26502653237173324], [2.4698500051963022, 0.23443828139261397], [2.5051902610502612, 0.23067614484914289], [2.4684409160318621, 0.21863502590393655], [3.0295456522668971, 0.086190046340667389], [2.4470385350120138, 0.21074952985853601], [2.5841314160351514, 0.1399509161051439], [2.9340821512886901, 0.13392607949486274]]
donnees_classe2 = [[4.0958394694071085, 0.62090992691837554], [3.0515154047252695, 0.53512517722257091], [2.9491682603712408, 0.44028070952077253], [3.2829314223632156, 0.49129132399409814], [3.2997815280896532, 0.46202148420611983], [3.1994813507553297, 0.51730303394481048], [3.2739397765597413, 0.42456810719843918], [3.0094501931685627, 0.53307647477381548], [3.1121716887339406, 0.61264659221630813], [3.1567904507066951, 0.56034384641028545], [3.1666032722891706, 0.47572772737933283], [2.8978523007369641, 0.39472962675440465], [3.3719622811831127, 0.57256856612568585], [3.0025688112273086, 0.5581421242147987], [3.2243758188595679, 0.52064997498366095], [3.0110164875805565, 0.43111214123321362], [3.1485374067025722, 0.64330361652352819], [3.2302342511064359, 0.62838600861174609], [3.4725953755453878, 0.43200027260585433]]
donnees_classe3 = [[3.836285556162859, 0.17488885815676444], [3.9046036496933407, 0.21995742377870348], [4.1545108753116367, 0.19645400534459045], [4.1987833316122352, 0.19703304602057539], [3.8715397281540196, 0.18336748445715684], [4.1631952751744903, 0.21583751780035143], [3.8067755719682346, 0.13029984504649231], [4.2331995779590086, 0.16583095278355137], [4.0664834258300173, 0.26180733777608278], [3.8539747179857335, 0.17215241559346361], [4.1093448646782491, 0.17765106796797839], [3.7176133236929481, 0.24048737653006386], [4.3310642505061496, 0.18847876748651521], [3.5832847883882, 0.22498735527596694], [3.999611132714854, 0.12367136651967732], [4.2664222137560586, 0.28957677201563969], [3.9681326235446828, 0.21086457727627866], [3.7197425382728775, 0.24458119801735781], [3.6350175478315383, 0.23427148092916744]]

liste_donnees_classes = [donnees_classe1,donnees_classe2,donnees_classe3]

donnee_test_classe1 = [3.0299364237682695, 0.069933489299203899]
donnee_test_classe2 = [3.3156657804150163, 0.67327144428452557]
donnee_test_classe3 = [4.0484484569058861, 0.24216712711692681]

K=4

print "Decision par K-PPV, avec K = ",int(K)

decision1 = decision_kppv(liste_donnees_classes,donnee_test_classe1,K)
print "La donnee de classe 1 a ete reconnue comme une donnee de classe ",int(decision1)
figure()
affichage_kppv(liste_donnees_classes,donnee_test_classe1,K)

decision2 = decision_kppv(liste_donnees_classes,donnee_test_classe2,K)
print "La donnee de classe 2 a ete reconnue comme une donnee de classe ",int(decision2)
figure()
affichage_kppv(liste_donnees_classes,donnee_test_classe2,K)

decision3 = decision_kppv(liste_donnees_classes,donnee_test_classe3,K)
print "La donnee de classe 3 a ete reconnue comme une donnee de classe ",int(decision3)
figure()
affichage_kppv(liste_donnees_classes,donnee_test_classe3,K)

print "Cas d'indécision (K=5)"
donnee_test_indecidable = [1.65, 1.02]
decision = decision_kppv(liste_donnees_classes,donnee_test_indecidable,5)
print "La donnee a ete reconnue comme une donnee de classe ",int(decision)," Normalement : indecidable."
affichage_kppv(liste_donnees_classes,donnee_test_indecidable,K)


