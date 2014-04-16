 function [X,Y]=bezier(L,p)
 
%on recupere nb ligne et nb colone de L
 [s1,s2] = size(L);
 
%le nb de points est égale au nb de colone
 nb_pts=s2;
 
 %le pas p divise l'intervalle [0,1] en nb_val+1 intervalles (ce nombre peut être flottant mais son utilisation dans linspace creera un nombre entier de colone
 nb_val= 1/p;
 
 u=linspace(0,1,nb_val+1);
 
 X=zeros(1,length(u));
 Y=zeros(1,length(u));
 
 
 for i=1:1:s2
	
	
	X = X + (poly_Bernstein(s2-1,i-1,u) * L(1,i));
	Y = Y + (poly_Bernstein(s2-1,i-1,u) * L(2,i));
	
 end


