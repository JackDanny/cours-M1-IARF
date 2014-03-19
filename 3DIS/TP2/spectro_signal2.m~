function [m,m2]=spectro_signal2(S,W,P,f)
%\spectro_signal pour afficher le spectrogramme d'un signal sur des fenêtres glissantes 
%spectro_signal(S,W,P) avec
%S  - le signal
%W  - la fenêtre
%P  - le pas
m=[];
m2=[];

%a la base on a 8000 echantillons par secondes
if nargin < 4
  f=8000;
  
end

disp(['La variable W vaut : ' num2str(W)]);
disp(['La variable P vaut : ' num2str(P)]);
disp(['La variable f vaut : ' num2str(f)]);



for i=1:P:(length(S)-W)
  extrait=S(i:(i+(W-1)));
  a1=abs(fft(extrait));
   
  
  a2=abs(fft(extrait.*(hamming(length(extrait)))));



%  a1=a1*(8000/W);
%  a2=a2*(8000/W);
  %on prend la partie droite de la fft
  a1=a1(1:(length(a1)/2));
  a2=a2(1:length(a2)/2);
  

  m=[m , a1];
  m2=[m2 , a2];
  
  
end


%on affiche



figure()




image(m);
%on inverse l'axe y pour avoir l'origine en (0,0) 
%voir http://enacit1.epfl.ch/cours_matlab/graphiques.shtml
% origine en bas à gauche, valeurs Y croissant de bas en haut
axis('xy')
%figure(gcf);

W2=W/16;

%on modifie l'axe y
%on a 8000 echantillons par secondes, il faut donc multiplier par 8000/W pour avoir la fréquence en Hz
%les valeurs vont de 0 à 512 en temps normal (car on a pris la moitié de la fft d'une fenêtre 1024)
%ici on les fait aller à 4000Hz ici (8000/2)
set(gca,'Ytick', [0 W2 2*W2 3*W2 4*W2 5*W2 6*W2 7*W2 8*W2] )
set(gca,'YtickLabel', ([0 W2 2*W2 3*W2 4*W2 5*W2 6*W2 7*W2 8*W2]*(f/2)/(W/2)) )

%on modifie l'axe x
%normalement le son dure 4.5 s
duree=length(S)/f;

%on veut graduer toutes les 500ms
px=(length(m(1,:)))/(2*duree);
set(gca,'Xtick', [0 px 2*px 3*px 4*px 5*px 6*px 7*px 8*px 9*px] )
set(gca,'XtickLabel', [0 0.5 1 1.5 2 2.5 3 3.5 4 4.5] )


figure()

image(m2);
%on inverse l'axe y pour avoir l'origine en (0,0) 
axis('xy')
%figure(gcf);
set(gca,'Ytick', [0 W2 2*W2 3*W2 4*W2 5*W2 6*W2 7*W2 8*W2] )
set(gca,'YtickLabel', ([0 W2 2*W2 3*W2 4*W2 5*W2 6*W2 7*W2 8*W2]*(f/2)/(W/2)) )
%;rajoute une ligne , rajoute une colone ' ' rajoute une colone

%on modifie l'axe x
%normalement le son dure 4.5 s
px=(length(m(1,:)))/(2*duree);
set(gca,'Xtick', [0 px 2*px 3*px 4*px 5*px 6*px 7*px 8*px 9*px] )
set(gca,'XtickLabel', [0 0.5 1 1.5 2 2.5 3 3.5 4 4.5] )





