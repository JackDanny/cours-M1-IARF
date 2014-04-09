close 'all'
F=1/16 * [1 2 1 ; 2 4 2 ; 1 2 1];


I=imread('lena.jpg');

figure()

colormap(gray(256));
image(I)

%convolution par un filtre gaussien
convolution(I,F);

F2=[-1 -1 -1 ; -1 9 -1 ; -1 -1 -1];

%convolution avec filtre passe haut

convolution(I,F2);

%bruitage de l'image

figure()

colormap(gray(256));
I2=imnoise(I,'salt & pepper',0.5);

image(I2)

%application du filtre median

calc_median(I2);

 [y,fs,nb]=wavread('vinyle.wav');

close 'all'

%sound(y,fs,nb);

fft_y=spectro_signal2(y,1024,512,fs);

%on prend la transformée de fourrier
tfs=fft(y);

l=length(tfs);
%on fait un filtre de la taille du signal
F=zeros(size(tfs));



F( 1 : floor(l/fs) *4000)=1;
F( end :-1: (end - ( floor(l/fs) *4000)) )=1;
%F( 1 : end)=1;

tfs2=F.*tfs;


s2=ifft(tfs2);

%sound(y,fs);
wavwrite(s2,fs,'son2.wav');

[y2,fs,nb]=wavread('son2.wav');

sound(y,fs,nb);
sound(y2,fs,nb);

