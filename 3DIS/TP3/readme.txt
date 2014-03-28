
%a mettre au debut si img b&w ou color

colormap('default')
colormap(gray(256))

I=imread('lena.jpg')

spectro_Image(I);

passe_haut(50,I);

passe_bas(50,I);

colormap(gray(256));




I2=imnoise(I,'salt & pepper',0.05);

%I3=passe_bas(80,I2);

I4=I2-I3

fftshift

passe_bas_fftshift(95,I2)

vaut mieux faire un passe haut sans fftshift
et passe bas avec
