function [s2]=  filtrage_passe_bas(s,fs,f)

%-S signal
%-fs frequence d'echantillonage
%-f frequence

%on prend la transformée de fourrier
tfs=fft(s);

l=length(tfs);
%on fait un filtre de la taille du signal
F=ones(size(tfs));



F( 1 : floor(l/fs) *f)=0;
F( end :-1: (end - ( floor(l/fs) *f)) )=0;
%F( 1 : end)=1;

tfs2=F.*tfs;


s2=ifft(tfs2);

%sound(y,fs);
wavwrite(s2,fs,'son_haute_freq.wav');

