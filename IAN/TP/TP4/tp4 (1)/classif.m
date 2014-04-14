%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Classification de notes de musiques %
%           M1 IAN TP4                %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ens_notes={'C','Cd','D','Dd','E','F'};

ens_instruments={'piano','clavecin','harpe'};

% Apprentissage des vecteurs moyenne
ens_parametres={} ;
for instrument=1:length(ens_instruments),
  ens_moyennes={};
  vect_moyenne = [];
  for note=1:length(ens_notes),
    parametres = [];
    
    
    for numero=1:6, 
      nomfichier = ['sons/app/', ens_instruments{instrument},'/',ens_notes{note},'1_',num2str(numero,'%.3d'),'.wav']
      [signal,fe,q]=wavread(nomfichier);
      
      % parametrisation (resultat = vecteur ligne)
      % param = ...
      param1=energie(signal,length(signal),1);
      parametres=[parametres,param1];
      
      %param2=ZCR_win(signal);
      %param3=fs;
      %param4=fft(signal);
      %param5=ifft(log(abs(fft(signal))));
      %param6=canaux(signal,fs,24);
      
      
      % on stocke le parametre dans une ligne de la matrice parametres
      % parametres = [ parametres ; param ] ;
    end
    
    % On calcule le vecteur moyenne
    vect_moyenne = mean( parametres);
    
    
    
    
    
    
    % On le stocke
    ens_moyennes{note}=vect_moyenne;
  end
  ens_parametres{instrument}=ens_moyennes;
end

% On a recupere un vecteur moyenne par note et par instrument dans ens_parametres
% Maintenant il faut parcourir les fichiers de test et prendre une decision
% ...

for instrument=1:length(ens_instruments),
  ens_moyennes={};
  vect_moyenne = [];
  for note=1:length(ens_notes),
    parametres = [];
    
    
   
      nomfichier = ['sons/tst/', ens_instruments{instrument},'/',ens_notes{note},'1_',num2str(numero,'%.3d'),'.wav']
      [signal,fe,q]=wavread(nomfichier);
      
      % parametrisation (resultat = vecteur ligne)
      % param = ...
      param1=energie(signal,length(signal),1);
      parametres=[parametres,param1];
      
    
   
    
    % On calcule le vecteur moyenne
    vect_moyenne = mean( parametres);
    
    
    
    
    
    
    % On le stocke
    ens_moyennes{note}=vect_moyenne;
  end
  ens_parametres{instrument}=ens_moyennes;
end
