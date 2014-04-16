function [X,Y]=bezier2(L,p)

[s1,s2]=size(L);


for i=1:2:s1
   L2=L(i:i+1,:);
   
   %on prend les indices des premières colones ou on trouve pas un 0 en commencant par la droite
   min_col1=find(L2(1,:),1,'last');
   min_col2=find(L2(2,:),1,'last');
   
   %et on prend le max. Ainsi toutes les colones suivantes sont egales a [ 0; 0]
   max_col=max(min_col1,min_col2);
   
   %on ne prends que ces points en compte
   L2=L2(:,1:max_col);
   %et on calcule bezier
   [X,Y]=bezier(L2,p);
  plot(X,Y);
  
  hold on
end

