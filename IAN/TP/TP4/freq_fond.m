function res=freq_fond(S,fs)
%S le signal
%fs frequence d'échantillonage



  [C,lags]=xcorr(S);
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

  res=F0;

  
end
