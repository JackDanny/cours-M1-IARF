close 'all'

I=imread('TP5I01.jpg')

%inv

%g=[0.5 0.5];
%h=[-0.5 0.5];

%I2=onde_mat(double(I),h,g)

I3=wavelet(double(I),4);

imagesc (I3); figure(gcf)

colormap(gray(256))