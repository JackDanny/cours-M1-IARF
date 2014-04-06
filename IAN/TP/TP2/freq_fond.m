function res=freq_fond(S, W, P,fs)
%S le signal
%W la fenetre
%P le pas (recouvrement)

res=[];
%pour i de 1 à (taille signal - fenêtre) avec recouvrement P
for i=1:P:(length(S)-W)
  %on prend une fenetre de taille W
  extrait=S(i:(i+(W-1)));
  %on calcule l'autocorelation

  [C,lags]=xcorr(extrait);
  lags=lags./fs;

  %on garde que la partie positive et la partie comprise entre 50 et 500Hz
  lags=lags( floor((end/2)+ (fs/500)) : floor((end/2) + (fs/50)) );
  C=C( floor(end/2 + fs/500) : floor(end/2 + fs/50) );

  
  %on prend l'indice position du max C
  [maximum position] = max(C);
  %et on renvoie le lag associé pour avoir T0
  T0=lags(position);
  %On en déduit F0
  F0=1/T0;

  res=[res , F0];

  
end
