function [dist,mot]= decision(ListCoutTotal,ListeMot)

%on prend le plus petit cout et son indice associé
[dist,indexMot]=min(ListCoutTotal);

%on retourne le mot correspondant
mot=ListeMot(indexMot);


