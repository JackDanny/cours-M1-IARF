function [I2]=calc_median(I)

%on transforme l'image en double
I=double(I);

%on prends la hauteur et la largeur de l'image
[li,hi]=size(I);

%on prend une matrice de taille largeur-1 et hauteur-1 car le filtre 3*3 a suprimer les bords
I2=zeros(li-2,hi-2);

for i=2:li-1
  for j=2:hi-1
    %on selectionne le 9 voisinage
    F=I(i-1:i+1,j-1:j+1);
    %on le transforme en matrice 1*9
    F=reshape(F,1,9);
    %on trie
    F=sort(F);
    %et on prend la valeur mediane
    I2(i-1,j-1)=F(5);
    
  end
end




figure;

colormap(gray(256));

imagesc (I2); figure(gcf)


