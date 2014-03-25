function []=dernier

I=imread('lena.jpg');

J=imnoise(I,'salt & pepper',0.05);

imagesc(J)


colormap(gray);