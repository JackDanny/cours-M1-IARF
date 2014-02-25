#!/usr/bin/env python
# -*- coding: utf-8 -*-
# prerequis : librairie pylab installée (regroupe scypy, matplotlib, numpy et ipython)
# codage de la méthode de classification par k plus proches voisins

from pylab import *

def attente_touche():
	raw_input()
	
execfile('data2.py')

#print('aa= ' + str(aa))
#print('ee= ' + str(ee))
eh
eu
ii
oe
oh
oo
uu
yy

print("len aa = " + str(len(aa)))

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



for i in range(int(len(aa)*80./100.)):
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

for i in range((int(len(aa)*80./100.)),(int(len(aa)) ) ):

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

execfile('loinormale2.py')


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

close('all')

affichage_lois_normales(learn_classes,liste_parametres_classes)