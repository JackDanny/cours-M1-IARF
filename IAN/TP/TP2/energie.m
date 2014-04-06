function res=energie(S, W, P)
%S le signal
%W la fenetre
%P le pas (recouvrement)

res=[];
%pour i de 1 à (taille signal - fenêtre) avec recouvrement P
for i=1:P:(length(S)-W)
  %on prend une fenetre de taille W
  extrait=S(i:(i+(W-1)));
  %on met les valeurs au carré
  a1=extrait.*extrait;
  %on fait la somme de ces valeurs et on normalize par la taille de la fenêtre
  a2=sum(a1)./length(a1);
  %on concatène pour avoir énergie en fonction du temps
  res=[res , a2];

  
end
