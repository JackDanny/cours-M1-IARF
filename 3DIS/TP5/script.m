close 'all'

I=imread('TP5I01.jpg');

%I=double(I);
%I=imread('gar.jpg');
%I=imread('Cool.jpg')
%inv

%I=rgb2gray(I);
I=double(I);
%g=[0.5 0.5];
%h=[-0.5 0.5];

%I2=onde_mat(double(I),h,g)

I3=wavelet(double(I),7);

I4=invwavelet(I3,7);

imagesc (I3); figure(gcf)
%imshow(I3,colormap(gray(256)));
colormap(gray(256));

figure()

imagesc (I4); figure(gcf)
colormap(gray(256));

I5=I-I4;
