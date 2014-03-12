function [m,m2]=spectro_signal(S,W,P)
%\spectro_signal pour afficher le spectrogramme d'un signal sur des fenêtres glissantes 
%spectro_signal(S,W,P) avec
%S  - le signal
%W  - la fenêtre
%P  - le pas
m=[];
m2=[];

for i=1:P:(length(S)-W)
  extrait=S(i:(i+(W-1)));
  a1=abs(fft(extrait));
 
  a2=abs(fft(extrait.*(hamming(length(extrait)))'));
  %on prend la partie droite de la fft
  a1=a1((length(a1)/2):end);
  a2=a2((length(a2)/2):end);
  

  m=[m ; a1];
  m2=[m2 ; a2];
  
  
end

%on transpose m
  m=m';
  m2=m2';

%on affiche

figure()

image(m);figure(gcf);

figure()

image(m2);figure(gcf);
