    #!/usr/bin/env python
# -*- coding: utf-8 -*-
# prerequis : librairie pylab installée (regroupe scypy, matplotlib, numpy et ipython)
# codage de la méthode de classification par loi normale

from pylab import *
import random

#attend l'appuie d'une touche
def attente_touche():
	raw_input()


def affichage_lois_normales(liste_donnees_classes,liste_parametres_classes):
	assert type(liste_donnees_classes) is list
	assert type(liste_parametres_classes) is list
	assert len(liste_donnees_classes)==len(liste_parametres_classes)

# affichage_lois_normales affiche les données si elles sont de dimension 2 et trace les ellipses représentant les lois normales
#
# Entrée :
# - liste_donnees_classe : liste de classes (classe = listes de points (1 point = 1 vecteur de dimension 2)):
# - liste_parametres : liste des paramètres
#     element1 : centroïde (au format "array")
#     element2 : matrice de variance-covariance (au format "array")
	
	nb_classes = len(liste_donnees_classes)
	couleurs= [ 'b', 'g', 'r', 'c', 'm', 'y', 'k', 'w' ]
	formespoints = [ 'x', 'o', 'v', '^', '<', '>', '1', '2', '3', '4', 's', 'p', '*', 'h', 'H', '+', '.', 'D', 'd', ',' ]
	formescentres = ['D','D','D']
	
	hold(True)
	for classe in range(nb_classes):
		# Affichage des points de la classe 
		forme=formespoints[classe]
		couleur=couleurs[classe]
		stylepoint=forme+couleur
		for point in liste_donnees_classes[classe]:
			plot(point[0],point[1],stylepoint)
			
		# Affichage des centroïdes
		forme=formescentres[classe]
		stylecentre=forme+couleur
		vecteur_moyenne = liste_parametres_classes[classe][0]
		plot(vecteur_moyenne[0],vecteur_moyenne[1],stylecentre)

                # Affichage des ellipses de dispertion


                mu=liste_parametres_classes[classe][0]
                sigma=liste_parametres_classes[classe][1]

        '''
        #ce code en commentaire sert à tracer les ellipses mais il n'est pas encore fonctionel
        vectAxes = axis()
      

        coul_ellipse=-1;
        for classe in range(nb_classes):
                #on prends les parametres de la classe en cours de traitement
                mu=liste_parametres_classes[classe][0]
                sigma=liste_parametres_classes[classe][1]

                #pour chacune des autres classes suivantes, on va tracer l'ellipse
                X=linspace(vectAxes[0],vectAxes[1],150)
                X1=[]
                Y1=[]
                for x in X :
                        #Pour chaque X,on se fait un vecteur Y. Les vecteurs X et Y peuvent être vu comme une matrice de points de taille len(X)*len(Y) dans laquelle on
                        #ne garde que les points (x,y) verifiant une propriété
                    Y = linspace(vectAxes[2],vectAxes[3],100)
                    for y in Y :
                            #on calcul la classe et le score pour les deux lois pour le point (x,y). Mais ici seul le score nous interesse.
                        [c,score]=calcul_vraisemblance_loi_normale([x,y],[[mu,sigma]])
   

                            #lorsqu'on a le même score pour le même point pour les deux classes, on est à la frontiere de décision
                            #comme on a des valeurs échantilloné, on ne fait pas en sorte que les deux scores soient égaux mais on se laisse une
                            #marge epsillon assez grande pour que le résultat soit visible.
                        if (abs(score[0])>=(10-0.1) and (abs(score[0])<=10+0.1)):
                                X1.append(x)
                                Y1.append(y)
                    #axis(vectAxes)

                coul_ellipse=(coul_ellipse+1)%len(couleurs);
                plot(X1,Y1,couleurs[coul_ellipse]+'.')
                    #axis(vectAxes)






                #axis(vectAxes)
                '''
        show()

	
def affichage_histogramme_loinormale(data):

    # Affiche un historgramme d'une liste de valeur et superpose l'affichage de la loi normale associée
    figure()
    #subplot(2,3,1)
    
    n, bins, patches = plt.hist(data,30, normed=1, facecolor='green', alpha=0.75)
    y = normpdf( bins, mean(data), std(data))

    l = plt.plot(bins, y, 'r--', linewidth=1)



    

def affichage_point(point,numero_forme):
	# affiche un point en utilisant un numero de forme definit
	couleurs= ['c', 'm', 'y', 'k', 'w', 'b', 'g', 'r' ]
	couleur = couleurs[numero_forme-1]
	formes = [ 'H', 'H', 'H' ]
	forme=formes[numero_forme-1]
	style=couleur+forme
	hold(True)
	plot(point[0],point[1],style)
	hold(False)


def apprentissage_loi_normale(liste_donnees_classe):
    assert type(liste_donnees_classe) is list
	# apprentissage_loi_normale renvoie la liste des paramètres de la loi
	# normale correspondant aux données récupérées
	#
	# Entrée :
	# - liste_donnees_classe : liste de points (1 point = 1 vecteur de dimension 2) d'une classe
	# Sortie :
	# - liste_parametres : liste des paramètres
	#     element1 : centroïde (au format "array")
	#     element2 : matrice de covariance (au format "array")
	

    tab_donnees=array(liste_donnees_classe)

	# calcul du vecteur moyenne
	#   utilisez la fonction mean() directement sur tab_donnees
	# ... a faire
    #on applique la moyenne sur l'axe 0 pour obtenir le vecteur moyenne de chaque coordonnée

    
    vect_moyenne=mean(liste_donnees_classe,0)

    #print("moyenne= " +str(vect_moyenne))
	# calcul de la patrice de covariance
	#   utilisez la fonction cov() directement sur tab_donnees, en utilisant transpose() si nécessaire
	#   cov calcule la matrice de covariance si l'on présente les données 
	# ... a faire


    mat_covariance = cov(tab_donnees.transpose())
    
    return [vect_moyenne, mat_covariance]

def calcul_vraisemblance_loi_normale(donnee,liste_parametres):
    assert type(donnee) is list
    assert type(liste_parametres) is list

    # calcul de la log vraisemblance
    #  (attention, restez sur le type array, si vous utilisez matrix vous ne pourrez pas transposer un vecteur)
    #   fonctions à utiliser :
    #       - dot(A,B) (produit matriciel de A par B)
    #       - inv(A)   (matrice inverse de A)
    #       - argmax : renvoi le numero de l'élément le plus grand
    #       - transpose(A) : transposee de A (qu'il soit un vecteur ou une matrice)
    # ... a faire
    score=[]
    for i in range(len(liste_parametres)) :
        #on recupère la moyenne de la classe i
        vect_moyenne = array(liste_parametres[i][0])

        #on recupère la matrice de covariance de la classe i
        mat_covariance = array(liste_parametres[i][1])

        #on recupère x sous forme d'array        
        x = array(donnee)   

        #on stocke le vecteur x-mu dans v_diff_mean
        v_diff_mean = x -  vect_moyenne 
        
        #on stocke l'inverse de la matrice de covariance dans inv_cov 
        inv_cov = inv(mat_covariance)   
        
        #on effectue le produit entre inv_cov et v_diff_mean
        
        prod=dot(inv_cov,v_diff_mean)

        #puis le produit de v_diff mean par le resultat trouvé
        
        prod2=dot(v_diff_mean,prod)
        
        #on ajoute log(det(cov)) au resultat pour obtenir le score
        res =  log(det(mat_covariance)) + prod2 

        #on ajoute le resultat à la liste des scores
        score.append(res)
    #on prend le argmin de la liste pour obtenir la bonne classe associé
    c=argmin(score)
    return [c,score] 

def calcul_vraisemblance_loi_normale_apriori(donnee,liste_parametres,probaclasses):
    assert type(donnee) is list
    assert type(liste_parametres) is list

    # fonction similaire à calcul_vraisemblance_loi_normale mais avec comme parametre supplémentaires
    #la liste des probabilités de chacune des classes

    score=[]
    for i in range(len(liste_parametres)) :
        #on recupère la moyenne de la classe i
        vect_moyenne = array(liste_parametres[i][0])

        #on recupère la matrice de covariance de la classe i
        mat_covariance = array(liste_parametres[i][1])

        #on recupère x sous forme d'array        
        x = array(donnee)   

        #on stocke le vecteur x-mu dans v_diff_mean
        v_diff_mean = x -  vect_moyenne 
        
        #on stocke l'inverse de la matrice de covariance dans inv_cov 
        inv_cov = inv(mat_covariance)   
        
        #on effectue le produit entre inv_cov et v_diff_mean
        
        prod=dot(inv_cov,v_diff_mean)

        #puis le produit de v_diff mean par le resultat trouvé
        
        prod2=dot(v_diff_mean,prod)
        
        #on ajoute log(det(cov)) au resultat
        res =  log(det(mat_covariance)) + prod2 

        #on enlève 2*log de la proba pour obtenir le score final
        res = res - (2*log(probaclasses[i]))
        
        
        score.append(res)
    c=argmin(score)
    return [c,score] 

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




    for i in range(len(d1)):
        X1.append([d11[i],d12[i],d13[i]])
        X2.append([d21[i],d22[i],d23[i]])
        X3.append([d31[i],d32[i],d33[i]])
        X4.append([d41[i],d42[i],d43[i]])



    return (X1,X2,X3,X4)

def apprentissage_loi_normale_optimise(liste_donnees_classe):
    assert type(liste_donnees_classe) is list
        # fonction similaire à apprentissage_loi_normale mais en supposant que la matrice de
        #variance-covariance est diagonale

    tab_donnees=array(liste_donnees_classe)

        # calcul du vecteur moyenne
        #   utilisez la fonction mean() directement sur tab_donnees
        # ... a faire
    #on applique la moyenne sur l'axe 0 pour obtenir le vecteur moyenne de chaque coordonnée


    vect_moyenne=mean(liste_donnees_classe,0)


        # calcul du vecteur des variances à l'aide de la fonction var sur l'axe 0


    vect_variances = var(tab_donnees,0)

    return [vect_moyenne, vect_variances]

def calcul_vraisemblance_loi_normale_optimise(donnee,liste_parametres):
    assert type(donnee) is list
    assert type(liste_parametres) is list

    # fonction similaire à calcul_vraisemblance_loi_normale mais en supposant que la matrice de
    #variance-covariance est diagonale
    score=[]
    for i in range(len(liste_parametres)) :
        #on recupère la moyenne de la classe i
        vect_moyenne = array(liste_parametres[i][0])

        #on recupère le vecteur des covariances de la classe i
        vect_variances = array(liste_parametres[i][1])


        #on recupère x sous forme d'array
        x = array(donnee)

        #on stocke le vecteur x-mu dans v_diff_mean
        v_diff_mean = x -  vect_moyenne

        #on calcule log(det(vect_variances)), ie on multiplie tous ses membres et on prend le log

        prod=1.
        for j in range(len(vect_variances)):
            prod=prod*vect_variances[j]


        prod=log(prod)

        #on calcule la somme des (x-mu)²/var et on la stocke dans somme

        somme=0.

        for j in range(len(v_diff_mean)):
            somme=somme+pow(v_diff_mean[j],2)/vect_variances[j]


        #on ajoute log(det(cov)) au resultat pour obtenir le score
        res =  prod + somme



        score.append(res)
    c=argmin(score)
    return [c,score]



# Programme principal : apprentissage de parametres pour 3 classes et
#                       test sur 3 points

donnees_classe1 = [[0.94922183000000004, 0.30706191999999999], [0.13517493999999999, 0.51524634000000002], [0.26140632000000003, -0.94148577], [-0.16233766999999999, -0.14605462999999999], [-0.53201138000000003, 1.6821036], [-0.87572934999999996, -0.48381505000000002], [-0.71200454999999996, -1.1742123], [-0.19223952, -0.27407023000000003], [1.5300724999999999, -0.24902473999999999], [-1.0642134000000001, 1.6034573000000001], [1.2346790999999999, -0.22962645000000001], [-1.5061597, -0.44462782000000001], [-0.15594104, 0.27606825000000002], [-0.26116365000000002, 0.44342190999999997], [0.39189421000000002, -1.2506789], [-0.94796091999999998, -0.74110609000000005], [-0.50781754999999995, -0.32057551000000001], [0.012469041, -3.0291773000000002], [-0.45701464000000003, 1.2424484], [-1.0667013999999999, 0.93372816000000003], [0.35032099999999999, -0.029005764], [0.18245217, -1.565056], [-0.08453948, 1.6039464000000001], [0.098347774999999998, 0.041373612999999997], [-0.73416910999999996, -0.030813730000000001], [0.23234700999999999, 0.42638756], [-0.37280874000000003, -0.23645458], [2.0236909000000001, -2.2583540000000002], [2.2294456999999999, 0.33756370000000002], [1.0000608, -1.6641645], [-0.59003455999999999, -0.27806416], [0.42271568999999998, -1.6702007000000001], [0.47163432999999999, -1.2128471999999999], [0.066190048000000001, 0.65235589000000005], [0.32705996999999998, 1.0826335], [1.0060770999999999, -0.65090773999999996], [0.25705615999999998, -0.94437780999999998], [-1.3217885, 0.92482593000000002], [4.9849075000000002e-05, -0.054918914999999999], [0.91112727000000004, 0.59458370000000005], [0.35020117000000001, 1.2502511999999999], [0.92978945999999996, 0.23976326000000001], [-0.69036109999999995, -0.65155364000000004], [1.1921018999999999, -1.6118304000000001], [-0.024461937, -1.9488471999999999], [1.0204979999999999, 0.86171629999999999], [0.0011620834999999999, -0.070837212999999996], [-2.4862839000000001, 0.58117231999999996], [-2.1924348999999999, -2.3192803], [0.079933710000000005, -0.94848098000000003], [0.41149061999999997, 0.67697781000000001], [0.85773255000000004, -0.69115912999999995], [0.44937761999999998, 0.10063335], [0.82606999999999997, 0.53615707999999995], [0.89788842999999996, -0.13193787000000001], [-0.14720146000000001, 1.0077734], [-2.1236554999999999, -0.50458641000000004], [-1.2705944, -0.3825848], [0.64867925999999998, 0.82572714999999997], [-1.0149436000000001, -0.47106990999999998], [0.13702486999999999, -0.29186338000000001], [0.30181856000000001, 0.39993094000000001], [-0.92996155999999996, -0.17683027000000001], [-2.1320945999999998, 1.1453617], [-0.62909075999999997, -1.2038500000000001], [-0.25394467999999998, -1.4286468999999999], [-0.020857618000000001, -0.56066499999999997], [2.1777787000000002, 1.1384654000000001], [-2.4968865, 0.44132693000000001], [-1.3981379, -0.25505517999999999], [0.16440407000000001, 0.74773403000000005], [-0.27304695000000001, 1.5763001000000001], [-0.48093714999999998, 0.32751212000000002], [0.66473411999999998, 0.085188593000000007], [0.88095279000000004, 0.32321314000000001], [-0.78414618000000003, -1.8053733999999999], [1.8585929000000001, -0.60453009000000002], [0.10335972, 0.56316695999999999], [0.113597, -0.90472620999999998], [-0.46771457999999999, -0.12488995], [1.4789585000000001, -0.86081569000000002], [0.78466846999999995, 0.30862314000000002], [-0.23386003999999999, -1.0569727], [-0.28414095, -0.086690281999999994], [-1.4693951000000001, 0.19218224], [-0.82229328000000002, -0.094240588], [0.33621334000000003, -0.90465406000000004], [-0.28825635999999999, 0.35006275999999997], [-1.8358591, 1.0359758999999999], [2.4244610999999998, 0.95940051000000004], [-0.315772, 0.42862267999999998], [-1.0359848, 1.8778655], [0.9407044, 0.78734578], [-0.87587426000000002, 0.31994913000000003], [-0.55829428000000003, -0.31142942000000001], [-0.57000991999999995, -1.0257335999999999], [-0.90874558999999999, -0.20989732999999999], [-1.6988641, 0.60760057999999995], [-0.11779829, 0.69916033]]
donnees_classe2 = [[0.74115313999999999, 3.8621732999999998], [3.3187652000000001, 1.6923117000000001], [2.566408, 3.3426244999999999], [6.5783969000000004, 5.7694369999999999], [1.6501131, 6.0349234999999997], [3.7254041999999998, 2.9369451], [3.7147429000000001, 2.7950339], [2.8758556999999998, 4.4896976000000004], [4.4090344999999997, 4.4171924000000002], [3.6714970999999998, 1.7925131000000001], [3.7172386999999998, 4.6302352999999998], [3.4888938, 4.0346929999999999], [3.7268851000000001, 2.6965591], [3.2938714999999998, 2.2127172000000002], [3.8883956, 1.8529298999999999], [1.9311294999999999, 2.1905013000000002], [0.055715837999999997, 4.4383803000000004], [3.3251905000000002, 2.2450717], [4.3702984999999996, 1.2884836], [2.8977575999999998, 2.758553], [3.3192067000000001, 3.3128586000000002], [2.1351201, 2.9699487000000002], [2.835121, 3.6277073], [4.0932656999999999, 4.1092732999999999], [2.1363471999999999, 3.0773590999999998], [1.7858830000000001, 1.8864993000000001], [2.9931507000000002, 4.5326303000000001], [2.2303340999999999, 3.3713788], [2.7744156000000002, 4.1173561000000003], [1.9109357, 3.0325574999999998], [3.552527, 4.1006102000000002], [4.5442118999999996, 3.0859310999999998], [1.5084097000000001, 2.2576982000000001], [1.9384182999999999, 5.3504572000000001], [2.3843980999999999, 3.7480768000000002], [2.8075815, 3.8886104000000001], [2.2351508, 1.597731], [1.5776241, 3.4881939000000002], [2.8226247999999998, 2.8039464999999999], [4.4193102, 3.2915844000000001], [3.1978111, 4.5876991], [2.1955339999999999, 3.6966244000000001], [3.8350881999999999, 2.7562848999999998], [3.2156701000000001, 1.8341561], [1.8520471999999999, 3.1048746999999999], [3.722254, 5.5854913000000002], [2.3331092999999998, 3.1873309999999999], [2.9175056000000001, 1.0669770999999999], [2.5610338000000001, 1.2053212], [3.8403754999999999, 2.1119678999999998], [3.1000928000000001, 2.4554711], [3.3035207999999998, 2.3996734000000002], [3.4899653000000002, 3.7393630999999998], [4.7118878000000004, 2.8058765000000001], [0.86164472999999997, 2.1604112999999998], [4.3545942999999996, 1.9278447000000001], [3.9609538999999998, 3.1240497999999999], [4.4366966000000003, 1.0390999999999999], [2.8023018, 1.7921545000000001], [5.9080079999999997, 3.8252188999999999], [4.3789720000000001, 1.9418196999999999], [2.5313843999999999, 2.7275306000000001], [4.0984246000000004, 2.7221280999999999], [3.7015414999999998, 0.94818369999999996], [2.64615, 2.1764134999999998], [1.4229430000000001, 3.5079747000000001], [3.2819840999999998, 3.0334799000000001], [1.6663220999999999, 4.1274923000000001], [3.3501794, 2.7009340000000002], [3.0228898000000002, 2.7380046], [1.2497876000000001, 2.7143489999999999], [2.1686334999999999, 2.0207937], [1.8435983, 2.4664429000000001], [0.99736426, 3.9642293999999998], [3.5200600999999998, 2.9799720999999999], [2.9652289000000001, 2.2018363999999999], [4.0186852999999996, 2.8667824999999998], [2.2854698, 4.3513858000000001], [2.7752289000000001, 2.410971], [2.7062463999999999, 2.1520738000000001], [1.8798717, 5.5259996999999998], [4.6554976000000003, 3.3075351999999998], [1.7428816, 2.1345320000000001], [2.8234659, 3.7914161000000002], [1.6679956, 0.67013283999999995], [1.5509027, 3.3335108], [3.3913536, 3.4516794000000002], [2.8697153000000002, 3.1836891], [2.523847, 3.8620215999999998], [1.6383055, 3.4550296], [2.1512905999999998, 2.6651131000000001], [3.5527833000000002, 4.0390907], [1.8823612999999999, 4.2606586999999996], [3.6601431, 2.9321343999999998], [2.8047787999999998, 2.7823935999999998], [2.6968923999999999, 3.0230456000000001], [3.0512904000000001, 3.8260627999999999], [4.5269766999999996, 3.4669143999999998], [2.7902866999999998, 3.6251904000000001]]
donnees_classe3 = [[1.5168790000000001, -1.0202644000000001], [2.5530050000000002, 0.10965859], [4.1287364999999996, -0.28996304000000001], [4.2615506999999999, 0.47542480999999998], [4.1741168000000002, 0.12694707], [2.3431841000000002, -1.4813991], [3.1554890000000002, 0.81855137], [2.7074118999999999, -0.54078641999999999], [2.6913581999999998, -1.0965933000000001], [2.5069902000000002, -0.18073935999999999], [3.0458411000000001, -0.063783119999999999], [3.6113352000000001, 0.10931769], [4.8140155, 0.31202383], [4.8044938000000004, -0.72312147999999998], [3.5265469999999999, -0.26025085999999997], [3.6001425, 0.59393079999999998], [0.81397839000000005, -1.3270431], [1.5589864, 0.40184449999999999], [4.4702013000000003, -0.32681422999999998], [3.8123230000000001, 0.54554009999999997], [1.9483676999999999, 0.39746700000000001], [2.2481053000000002, 1.5162669], [2.9674334999999998, 1.6359996999999999], [2.5749415, 0.58943336999999996], [2.9372088000000001, -2.0219589], [2.0178685000000001, 0.61251129999999998], [2.9451139, -1.1187320000000001], [2.3736215000000001, 0.24951773999999999], [2.0069810000000001, 0.97495021999999998], [2.3592905000000002, 1.8088626000000001], [1.9201337000000001, 0.19918944], [1.4789734000000001, -0.72363113000000001], [2.4067497000000002, 0.40133634000000001], [3.9421333000000001, 0.30048596999999999], [2.6269293, 0.81548851], [3.7988870000000001, 0.12020528], [3.5712476, 0.41279600999999999], [2.0130381000000002, 0.75956833000000001], [2.3427986999999999, -0.60391848000000004], [3.1769468000000001, -0.30750347], [2.8681795999999999, 0.59535766999999995], [4.0468327999999998, -0.19795863], [3.3276781999999998, -0.2383015], [3.2295969000000002, 0.4399979], [2.3831340999999999, 0.27483679], [3.601102, 0.092307950999999999], [4.7298413999999998, -0.60855744000000001], [2.2629402000000001, -1.7498792999999999], [3.9104825999999999, 0.86708255000000001], [2.9201071999999999, 0.89847599], [3.1837034000000002, 0.29079012999999998], [3.1129446999999999, 0.43995219000000002], [3.1016623999999999, 2.7873351999999998], [1.8333349999999999, -1.8542991], [1.8593189000000001, -1.0933435], [2.5663906999999999, -0.16846987999999999], [2.7814663999999998, 0.54133443999999997], [3.3892661999999998, 0.75122898000000005], [4.7782558999999996, 1.2230626], [1.7167439, -2.3289545], [3.9019314999999999, -1.8356387000000001], [3.0667569000000001, 0.035479485999999998], [5.2271681000000001, -0.069214254000000003], [2.4926769000000002, 0.23580967], [3.2458049, 0.070045208999999997], [2.3914195, -1.2225934000000001], [3.3165003999999998, -1.3428692], [1.9678157000000001, 1.3312158999999999], [2.5810968000000001, -0.14032172000000001], [3.8998222999999999, -0.30011101000000001], [4.0293656999999996, -0.34506597], [4.0128019000000004, 0.62933457999999998], [2.7869849000000002, -0.86569731000000005], [1.9568916999999999, -0.27006880999999999], [2.5618585999999999, -0.40867430999999999], [3.9835452, -0.29769714000000003], [4.1436789000000003, -0.53162012000000003], [3.9725657000000001, -0.52225047999999996], [3.1765778, 0.97073781999999997], [2.5860276999999998, -0.43827052], [5.0033906000000004, 0.95099350000000005], [2.5679962000000001, 0.64894074000000002], [2.6399237000000002, 0.70588501999999997], [4.4158491, -1.6045157000000001], [4.0288531000000001, 1.4579678], [3.0474713000000002, 1.7462567], [3.1553874999999998, -1.2371197], [0.80650571999999998, -0.33340707000000003], [3.7135433, 0.31740773], [3.4136104, -0.57708557999999999], [3.1440017999999998, -1.6386657], [2.2399100000000001, -0.81879310000000005], [3.5197289, -0.014160058999999999], [1.8444706, -0.0095249160999999992], [2.3101894999999999, -0.66669915000000002], [3.8641494000000001, 0.11341944], [3.3983628000000001, 0.88396989000000004], [3.1802576999999999, 0.55085452000000001], [3.6829643000000001, 1.1706087000000001]]


liste_donnees_classes = [donnees_classe1,donnees_classe2,donnees_classe3]

# Question 1 :
# affichage de l'histogramme
# ... a faire


d1=array(donnees_classe1)
d2=array(donnees_classe2)
d3=array(donnees_classe3)

#on ferme toutes les fenetres ouvertes
close('all')


#on affiche les 6 histogrammes en leur donnant un titre pour les identifier
affichage_histogramme_loinormale(d1[:,0])
title("donnees_classe1 x")
show()

affichage_histogramme_loinormale(d1[:,1])
title("donnees_classe1 y")
show()

affichage_histogramme_loinormale(d2[:,0])
title("donnees_classe2 x")
show()
affichage_histogramme_loinormale(d2[:,1])
title("donnees_classe2 y")
show()


affichage_histogramme_loinormale(d3[:,0])
title("donnees_classe3 x")
show()
affichage_histogramme_loinormale(d3[:,1])
title("donnees_classe3 y")
show()





print("\nExercice 3:Classification : decision par maximum de vraisemblance\n")


liste_parametres_classe1 = apprentissage_loi_normale(donnees_classe1)
liste_parametres_classe2 = apprentissage_loi_normale(donnees_classe2)
liste_parametres_classe3 = apprentissage_loi_normale(donnees_classe3)


liste_parametres_classes = [liste_parametres_classe1, liste_parametres_classe2, liste_parametres_classe3]

#print(liste_parametres_classe1)


donnee_test_classe1 = [0.18322726, -1.0297674999999999]
donnee_test_classe2 = [3.5376671000000002, 4.8338850000000004]
donnee_test_classe3 = [3.2696486, 0.49428706]

figure()
affichage_lois_normales(liste_donnees_classes,liste_parametres_classes)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe1,liste_parametres_classes)
print "La donnee de classe 1 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe2,liste_parametres_classes)
print "La donnee de classe 2 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe3,liste_parametres_classes)
print "La donnee de classe 3 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)


attente_touche()

print("\nExercice 4:Probabilite a priori\n")

probaclasses=[9998./10000.,1./10000.,1./10000.]

print("probabilites: " + str(probaclasses))

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale_apriori(donnee_test_classe1,liste_parametres_classes,probaclasses)

print "La donnee de classe 1 a ete reconnue a priori comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale_apriori(donnee_test_classe2,liste_parametres_classes,probaclasses)
print "La donnee de classe 2 a ete reconnue a priori comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale_apriori(donnee_test_classe3,liste_parametres_classes,probaclasses)
print "La donnee de classe 3 a ete reconnue a priori comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)



(X1,X2,X3,X4)=genere_donnee()

liste_donnees_classes = [X1,X2,X3,X4]


d1=array(X1)
d2=array(X2)
d3=array(X3)
d4=array(X4)


attente_touche()
#on ferme toutes les fenetres ouvertes
close('all')
print("\nExercice 5:Generalisation\n")

#on affiche les 6 histogrammes en leur donnant un titre pour les identifier
affichage_histogramme_loinormale(d1[:,0])
title("donnees_classe1 x")
show()

affichage_histogramme_loinormale(d1[:,1])
title("donnees_classe1 y")
show()

affichage_histogramme_loinormale(d1[:,2])
title("donnees_classe1 z")
show()


affichage_histogramme_loinormale(d2[:,0])
title("donnees_classe2 x")
show()
affichage_histogramme_loinormale(d2[:,1])
title("donnees_classe2 y")
show()

affichage_histogramme_loinormale(d2[:,2])
title("donnees_classe2 z")
show()


affichage_histogramme_loinormale(d3[:,0])
title("donnees_classe3 x")
show()
affichage_histogramme_loinormale(d3[:,1])
title("donnees_classe3 y")
show()

affichage_histogramme_loinormale(d3[:,2])
title("donnees_classe3 z")
show()

affichage_histogramme_loinormale(d4[:,0])
title("donnees_classe4 x")
show()
affichage_histogramme_loinormale(d4[:,1])
title("donnees_classe4 y")
show()
affichage_histogramme_loinormale(d4[:,2])
title("donnees_classe4 z")
show()


liste_parametres_classe1 = apprentissage_loi_normale(X1)
liste_parametres_classe2 = apprentissage_loi_normale(X2)
liste_parametres_classe3 = apprentissage_loi_normale(X3)
liste_parametres_classe4 = apprentissage_loi_normale(X4)


liste_parametres_classes = [liste_parametres_classe1, liste_parametres_classe2, liste_parametres_classe3,liste_parametres_classe4]

donnee_test_classe1 = [0.,0.,0.]
donnee_test_classe2 = [3.,3.,3.]
donnee_test_classe3 = [0.,0.,3.]
donnee_test_classe4 = [0.,3.,0.]

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe1,liste_parametres_classes)
print "La donnee de classe 1 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe2,liste_parametres_classes)
print "La donnee de classe 2 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe3,liste_parametres_classes)
print "La donnee de classe 3 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)


[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale(donnee_test_classe4,liste_parametres_classes)
print "La donnee de classe 4 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)


attente_touche()
#on ferme toutes les fenetres ouvertes
close('all')

print("\nExercice 6:Optimisation\n")


liste_parametres_classe1 = apprentissage_loi_normale_optimise(donnees_classe1)
liste_parametres_classe2 = apprentissage_loi_normale_optimise(donnees_classe2)
liste_parametres_classe3 = apprentissage_loi_normale_optimise(donnees_classe3)

liste_parametres_classes = [liste_parametres_classe1, liste_parametres_classe2, liste_parametres_classe3]

donnee_test_classe1 = [0.18322726, -1.0297674999999999]
donnee_test_classe2 = [3.5376671000000002, 4.8338850000000004]
donnee_test_classe3 = [3.2696486, 0.49428706]

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale_optimise(donnee_test_classe1,liste_parametres_classes)
print "La donnee de classe 1 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale_optimise(donnee_test_classe2,liste_parametres_classes)
print "La donnee de classe 2 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)

[classe_trouvee,liste_vraisemblances] = calcul_vraisemblance_loi_normale_optimise(donnee_test_classe3,liste_parametres_classes)
print "La donnee de classe 3 a ete reconnue comme une donnee de classe ",int(classe_trouvee)+1
print "Vraisemblances : ",list(liste_vraisemblances)


