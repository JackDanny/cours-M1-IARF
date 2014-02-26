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

        plot(point_a_classer[0],point_a_classer[1],'Dk')

	# Affichage des segments sur les K points les plus proches
	# ...

        #liste des distances du point à classer à chaque points de liste_donnees_classes
        distances_class = []

        for i  in range(nb_classes):
                #on stock aussi le num de la classe i et sa position dans cette classe j
                for j in range(len(liste_donnees_classes[i])):
                        distances_class.append( (norm(  (array(point_a_classer)) - (array(liste_donnees_classes[i][j]))  ),i,j ))

        #on trie la liste par distances croissantes
        distances_class.sort(comp)
        #print("distances_class apres sort" + str(distances_class))

        #on va relier les K plus proches voisins
        for i in range(K):
            #on recupere l'indice de la classe à laquelle appartient le ieme point le plus prêt
            i1=distances_class[i][1]
            #... ainsi que sa position dans la sous-liste
            i2=distances_class[i][2]


            #on recupère donc l'abcisse du point de la i1 ieme classe à la position i2
            x=liste_donnees_classes[i1][i2][0]
            #print("dc 1" +str(liste_donnees_classes[i1][i2][1]))

            #et l'ordonnée du point de la i1 ieme classe à la position i2
            y=liste_donnees_classes[i1][i2][1]

            #on relie le point à classer au point de coordonées x y
            plot([point_a_classer[0],x],[point_a_classer[1],y],'r-')

        #on normalise les axes pour mieux "voir" les distances
        axis('equal')

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
        for i  in range(nb_classes):
                #pour chaque distance on va aussi stocker la classe à laquelle il appartient
		for j in range(len(liste_points_classes[i])):
                        distances_class.append( (norm(array(point_a_classer)-array(liste_points_classes[i][j])),i ))
		
	#print("distances_class avant sort" + str(distances_class))
        distances_class.sort(comp)
        #print("distances_class apres sort" + str(distances_class))
        #print("distances: "+str(distances_class))
	
	
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

# Programme principal : préparation points représentatifs et
#                       test sur 3 points


def genere_donnee():
    #fonction servant à generer les donnees pour verifier la generalisation
    #on se met en dimension 3 avec 4 classes
    X1=[]
    X2=[]
    X3=[]
    X4=[]

    #la fonction normal du module numpy.random sert à générerune liste de valeurs
    #suivant une loi normal
    d11=normal(0.,2.,100.)
    d12=normal(0.,2.,100.)
    d13=normal(0.,2.,100.)

    d21=normal(3.,2.,100.)
    d22=normal(3.,2.,100.)
    d23=normal(3.,2.,100.)

    d31=normal(0.,2.,100.)
    d32=normal(0.,2.,100.)
    d33=normal(3.,2.,100.)

    d41=normal(0.,2.,100.)
    d42=normal(3.,2.,100.)
    d43=normal(0.,2.,100.)




    for i in range(len(d11)):
        X1.append([d11[i],d12[i],d13[i]])
        X2.append([d21[i],d22[i],d23[i]])
        X3.append([d31[i],d32[i],d33[i]])
        X4.append([d41[i],d42[i],d43[i]])



    return (X1,X2,X3,X4)

'''
close('all')

donnees_classe1 = [[3.6484028273127254, 0.073429844289042881], [2.330634259457685, 0.21748520551489497], [2.644948143301538, 0.20411304520644272], [2.7753121336336251, 0.18681685779827709], [2.1983916903402347, 0.19693911318338075], [2.836900928011457, 0.16884540288894506], [2.6235769902396133, 0.14047193438597244], [2.7157154911382348, 0.18092519035140286], [2.6662657025141492, 0.17384029751490698], [2.7900235283901487, 0.17124467162767718], [2.3025641883523864, 0.19080233853944761], [2.50402381354598, 0.26502653237173324], [2.4698500051963022, 0.23443828139261397], [2.5051902610502612, 0.23067614484914289], [2.4684409160318621, 0.21863502590393655], [3.0295456522668971, 0.086190046340667389], [2.4470385350120138, 0.21074952985853601], [2.5841314160351514, 0.1399509161051439], [2.9340821512886901, 0.13392607949486274]]
donnees_classe2 = [[4.0958394694071085, 0.62090992691837554], [3.0515154047252695, 0.53512517722257091], [2.9491682603712408, 0.44028070952077253], [3.2829314223632156, 0.49129132399409814], [3.2997815280896532, 0.46202148420611983], [3.1994813507553297, 0.51730303394481048], [3.2739397765597413, 0.42456810719843918], [3.0094501931685627, 0.53307647477381548], [3.1121716887339406, 0.61264659221630813], [3.1567904507066951, 0.56034384641028545], [3.1666032722891706, 0.47572772737933283], [2.8978523007369641, 0.39472962675440465], [3.3719622811831127, 0.57256856612568585], [3.0025688112273086, 0.5581421242147987], [3.2243758188595679, 0.52064997498366095], [3.0110164875805565, 0.43111214123321362], [3.1485374067025722, 0.64330361652352819], [3.2302342511064359, 0.62838600861174609], [3.4725953755453878, 0.43200027260585433]]
donnees_classe3 = [[3.836285556162859, 0.17488885815676444], [3.9046036496933407, 0.21995742377870348], [4.1545108753116367, 0.19645400534459045], [4.1987833316122352, 0.19703304602057539], [3.8715397281540196, 0.18336748445715684], [4.1631952751744903, 0.21583751780035143], [3.8067755719682346, 0.13029984504649231], [4.2331995779590086, 0.16583095278355137], [4.0664834258300173, 0.26180733777608278], [3.8539747179857335, 0.17215241559346361], [4.1093448646782491, 0.17765106796797839], [3.7176133236929481, 0.24048737653006386], [4.3310642505061496, 0.18847876748651521], [3.5832847883882, 0.22498735527596694], [3.999611132714854, 0.12367136651967732], [4.2664222137560586, 0.28957677201563969], [3.9681326235446828, 0.21086457727627866], [3.7197425382728775, 0.24458119801735781], [3.6350175478315383, 0.23427148092916744]]

liste_donnees_classes = [donnees_classe1,donnees_classe2,donnees_classe3]

donnee_test_classe1 = [3.0299364237682695, 0.069933489299203899]
donnee_test_classe2 = [3.3156657804150163, 0.67327144428452557]
donnee_test_classe3 = [4.0484484569058861, 0.24216712711692681]

K=5

print "Decision par K-PPV, avec K = ",int(K)

print("point a classer " +str(donnee_test_classe1))
decision1 = decision_kppv(liste_donnees_classes,donnee_test_classe1,K)
print "La donnee de classe 1 a ete reconnue comme une donnee de classe ",int(decision1+1)
figure()
affichage_kppv(liste_donnees_classes,donnee_test_classe1,K)

print ""
print("point a classer " +str(donnee_test_classe2))
decision2 = decision_kppv(liste_donnees_classes,donnee_test_classe2,K)
print "La donnee de classe 2 a ete reconnue comme une donnee de classe ",int(decision2+1)
figure()
affichage_kppv(liste_donnees_classes,donnee_test_classe2,K)


print ""
print("point a classer " +str(donnee_test_classe3))
decision3 = decision_kppv(liste_donnees_classes,donnee_test_classe3,K)
print "La donnee de classe 3 a ete reconnue comme une donnee de classe ",int(decision3+1)
figure()
affichage_kppv(liste_donnees_classes,donnee_test_classe3,K)




print("\n5.Generalisation\n")


(donnees_classe1,donnees_classe2,donnees_classe3,donnees_classe4)=genere_donnee()

liste_donnees_classes = [donnees_classe1,donnees_classe2,donnees_classe3,donnees_classe4]


donnee_test_classe1 = [0.,0.,0.]
donnee_test_classe2 = [3.,3.,3.]
donnee_test_classe3 = [0.,0.,3.]
donnee_test_classe4 = [0.,3.,0.]


print "point a classer : ",donnee_test_classe1
decision1 = decision_kppv(liste_donnees_classes,donnee_test_classe1,K)
print "La donnee de classe 1 a ete reconnue comme une donnee de classe ",int(decision1+1)

print "\n"

print "point a classer : ",donnee_test_classe2
decision2 = decision_kppv(liste_donnees_classes,donnee_test_classe2,K)
print "La donnee de classe 2 a ete reconnue comme une donnee de classe ",int(decision2+1)

print "\n"

print "point a classer : ",donnee_test_classe3
decision3 = decision_kppv(liste_donnees_classes,donnee_test_classe3,K)
print "La donnee de classe 3 a ete reconnue comme une donnee de classe ",int(decision3+1)

print "\n"

print "point a classer : ",donnee_test_classe4
decision4 = decision_kppv(liste_donnees_classes,donnee_test_classe4,K)
print "La donnee de classe 4 a ete reconnue comme une donnee de classe ",int(decision4+1)



#traitement du cas d'égalité



'''


