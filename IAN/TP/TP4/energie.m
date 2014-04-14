function res=energie(S)
%S le signal

res=[];
%pour i de 1 à (taille signal - fenêtre) avec recouvrement P

  a1=S.*S;
  %on fait la somme de ces valeurs et on normalize par la taille de la fenêtre
  res=sum(a1)./length(a1);
 
  

  
end 
