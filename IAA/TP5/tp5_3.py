#!/usr/bin/env python
# -*- coding: utf-8 -*-
# prerequis : librairie pylab installée (regroupe scypy, matplotlib, numpy et ipython)


from pylab import *
import colorsys


from scipy import misc
import time

def attente_touche():
	raw_input()

#execfile('data2.py')

#execfile('data3.py')


def affichageCourbeTauxErreur(aa,ee,eh,eu,ii,oe,oh,oo,uu,yy):
    close('all')    
    pointsRecokppv=[]
    
    pointsRecoloi=[] 
    
    X=[]
    for l in range(10,90):
        X.append(l)
        print("l="+str(l))
        (learn_classes,test_classes,liste_parametres_classes)=partitiondata(l,aa,ee,eh,eu,ii,oe,oh,oo,uu,yy)
        
        matconfkppv=zeros((len(learn_classes),len(learn_classes)))
        matconfloi=zeros((len(learn_classes),len(learn_classes)))

        K=5    

        for i in range(len(test_classes)):
            for j in range(len(test_classes[i])):
                decisionkpv = decision_kppv(learn_classes,test_classes[i][j],K)
                matconfkppv[i][decisionkpv]+=1
    
                [decisionloi,liste_vraisemblances] = calcul_vraisemblance_loi_normale(test_classes[i][j],liste_parametres_classes)
                matconfloi[i][decisionloi]+=1

        #print("\nLa matrice de confusion pour les kppv est:\n" + str(matconfkppv))
        #print("\nLa matrice de confusion pour les loi normales est:\n" + str(matconfloi))

        recokppv=0.

        for i in range(len(matconfkppv)):
            recokppv += matconfkppv[i][i]

        recokppv/=len(test_classes)*len(test_classes[0])
    
        recoloi=0.
        for i in range(len(matconfloi)):
            recoloi += matconfloi[i][i]

        recoloi/=len(test_classes)*len(test_classes[0])

        pointsRecokppv.append(recokppv)
        pointsRecoloi.append(recoloi)

        #print("taux de reconnaissance avec kppv:\n" + str(recokppv))
        #print("taux de reconnaissance avec apprentissage loi normales:\n" + str(recoloi))
        
    
    
    plot(X,pointsRecokppv,'r-')
    plot(X,pointsRecoloi,'b-')

    show()



def partitiondata(appr,aa,ee,eh,eu,ii,oe,oh,oo,uu,yy):
    

    #données d'apprentissages

    learn_class_aa = []
    learn_class_ee = []
    learn_class_eh = []
    learn_class_eu = []
    learn_class_ii = []
    learn_class_oe = []
    learn_class_oh = []
    learn_class_oo = []
    learn_class_uu = []
    learn_class_yy = []



    for i in range(int(len(aa)*appr/100.)):
        learn_class_aa.append(aa[i])
        learn_class_ee.append(ee[i])
        learn_class_eh.append(eh[i])
        learn_class_eu.append(eu[i])
        learn_class_ii.append(ii[i])
        learn_class_oe.append(oe[i])
        learn_class_oh.append(oh[i])
        learn_class_oo.append(oo[i])
        learn_class_uu.append(uu[i])
        learn_class_yy.append(yy[i])

    learn_classes=[learn_class_aa,learn_class_ee,learn_class_eh,learn_class_eu,learn_class_ii,learn_class_oe,learn_class_oh,learn_class_oo,learn_class_uu,learn_class_yy]

    #données de tests

    test_class_aa = []
    test_class_ee = []
    test_class_eh = []
    test_class_eu = []
    test_class_ii = []
    test_class_oe = []
    test_class_oh = []
    test_class_oo = []
    test_class_uu = []
    test_class_yy = []

    for i in range((int(len(aa)*appr/100.)),(int(len(aa)) ) ):

        test_class_aa.append(aa[i])
        test_class_ee.append(ee[i])
        test_class_eh.append(eh[i])
        test_class_eu.append(eu[i])
        test_class_ii.append(ii[i])
        test_class_oe.append(oe[i])
        test_class_oh.append(oh[i])
        test_class_oo.append(oo[i])
        test_class_uu.append(uu[i])
        test_class_yy.append(yy[i])
    
    #print("test_class_aa " + str(len(test_class_aa)))

    test_classes=[test_class_aa,test_class_ee,test_class_eh,test_class_eu,test_class_ii,test_class_oe,test_class_oh,test_class_oo,test_class_uu,test_class_yy]

    

    liste_parametres_class_aa = apprentissage_loi_normale(learn_class_aa)
    liste_parametres_class_ee = apprentissage_loi_normale(learn_class_ee)
    liste_parametres_class_eh = apprentissage_loi_normale(learn_class_eh)
    liste_parametres_class_eu = apprentissage_loi_normale(learn_class_eu)
    liste_parametres_class_ii = apprentissage_loi_normale(learn_class_ii)
    liste_parametres_class_oe = apprentissage_loi_normale(learn_class_oe)
    liste_parametres_class_oh = apprentissage_loi_normale(learn_class_oh)
    liste_parametres_class_oo = apprentissage_loi_normale(learn_class_oo)
    liste_parametres_class_uu = apprentissage_loi_normale(learn_class_uu)
    liste_parametres_class_yy = apprentissage_loi_normale(learn_class_yy)

    liste_parametres_classes = [liste_parametres_class_aa,liste_parametres_class_ee,liste_parametres_class_eh,liste_parametres_class_eu,liste_parametres_class_ii,liste_parametres_class_oe,liste_parametres_class_oh,liste_parametres_class_oo,liste_parametres_class_uu,liste_parametres_class_yy]

    return(learn_classes,test_classes,liste_parametres_classes)







execfile('loinormale_tp5.py')
execfile('kppv_tp5.py')
execfile('data12.py')

appr=80.

#affichageCourbeTauxErreur(aa,ee,eh,eu,ii,oe,oh,oo,uu,yy)

(learn_classes,test_classes,liste_parametres_classes)=partitiondata(appr,aa,ee,eh,eu,ii,oe,oh,oo,uu,yy)


close('all')

affichage_lois_normales(learn_classes,liste_parametres_classes)

#pour chacune des classes test


print("Pour les Kppv je prends K=5\n")

K=5

matconfkppv=zeros((len(learn_classes),len(learn_classes)))
matconfloi=zeros((len(learn_classes),len(learn_classes)))

tps1 = time.clock()
for i in range(len(test_classes)):
    for j in range(len(test_classes[i])):
        decisionkpv = decision_kppv(learn_classes,test_classes[i][j],K)
        matconfkppv[i][decisionkpv]+=1

tps2 = time.clock()
for i in range(len(test_classes)):
    for j in range(len(test_classes[i])):
        [decisionloi,liste_vraisemblances] = calcul_vraisemblance_loi_normale(test_classes[i][j],liste_parametres_classes)
        matconfloi[i][decisionloi]+=1
tps3 = time.clock()

print("\ntemps d'exécution des kppv:" + str(tps2-tps1)) 
print("\ntemps d'exécution des lois normales:" + str(tps3-tps2)) 

print("\nLa matrice de confusion pour les kppv est:\n" + str(matconfkppv))
print("\nLa matrice de confusion pour les loi normales est:\n" + str(matconfloi))

recokppv=0.

for i in range(len(matconfkppv)):
    recokppv += matconfkppv[i][i]

recokppv/=len(test_classes)*len(test_classes[0])

recoloi=0.
for i in range(len(matconfloi)):
    recoloi += matconfloi[i][i]

recoloi/=len(test_classes)*len(test_classes[0])

print("taux de reconnaissance avec kppv:\n" + str(recokppv))
print("taux de reconnaissance avec apprentissage loi normales:\n" + str(recoloi))

z=1.96

confintkppv = z*sqrt((recokppv*(1-recokppv))/(len(test_classes)*len(test_classes[0])))
confintloi = z*sqrt((recoloi*(1-recoloi))/(len(test_classes)*len(test_classes[0])))

print("intervalle de confiance kppv:\n" + str(confintkppv))
print("intervalle de confiance apprentissage loi normales:\n" + str(confintloi))


#print "La donnee de classe 4 a ete reconnue comme une donnee de classe ",int(decision4+1)


























