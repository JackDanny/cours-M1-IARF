function []=spectro_bi(p)

%p=1-p;

I=imread('lena.jpg');

I=double(I);

spectrenorm=fft2(I);

spectre=log(abs(fft2(I)));



imagesc(spectre)
colormap(gray)

[l,h]=size(spectre)

filtre=zeros(l,h);


l1=floor(l*p);
h1=floor(h*p);


filtre(h1:(end-h1),l1:(end-l1))=1.;

spectre=filtre.*spectre;
%spectre(h1:(end-h1),l1:(end-l1))=0.;


figure()

imagesc(spectre)
colormap(gray)


[l2,h2]=size(spectrenorm)

l3=floor(l2*p)
h3=floor(h2*p)

filtre(h3:(end-h3),l3:(end-l3))=1.;

spectrenorm=filtre.*spectrenorm;




I2=(ifft2(spectrenorm));

figure()


imagesc(abs(I2))
colormap(gray)




