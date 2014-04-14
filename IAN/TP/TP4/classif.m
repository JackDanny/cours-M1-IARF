%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Classification de notes de musiques %
%           M1 IAN TP4                %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%remettre canaux
ens_notes={'C','Cd','D','Dd','E','F'};

ens_instruments={'piano','clavecin','harpe'};

% Apprentissage des vecteurs moyenne
ens_parametres={} ;

%pour chaque instrument
for instrument=1:length(ens_instruments),
  ens_moyennes={};
  vect_moyenne = [];
  vect_moyenne2 = [];

  vect_moyenne4 = [];
  vect_moyenne5 = [];
  vect_moyenne6 = [];



  %pour chaque note
  for note=1:length(ens_notes),
    parametres = [];
    parametres2 = [];
    parametres3 = [];
    parametres4 = [];
    parametres5 = [];
    parametres6 = [];
    %pour chacun des 6 extraits
    for numero=1:6, 
      nomfichier = ['sons/app/', ens_instruments{instrument},'/',ens_notes{note},'1_',num2str(numero,'%.3d'),'.wav'];
      [signal,fe,q]=wavread(nomfichier);
      
      % parametrisation (resultat = vecteur ligne)
      % param = ...
      param1=energie(signal);
      param2=ZCR_win(signal);
      param3=freq_fond(signal,fe);
      param4=fft(signal);
      length(param4);
      param5=ifft(log(abs(fft(signal))));
      param6=canaux(signal,fe,24);
      size(param6);

      
      % on stocke le parametre dans une ligne de la matrice parametres
      parametres=[parametres ; param1];
      parametres2=[parametres2 ; param2];
      parametres3=[parametres3 ; param3];
      parametres4=[parametres4 ; param4'];
      parametres5=[parametres5 ; param5'];
      parametres6=[parametres6 ; param6];

    end
    
    % On calcule les vecteurs moyenne
    vect_moyenne = mean( parametres);
    vect_moyenne2 = mean( parametres2);
    vect_moyenne3 = mean( parametres3);

    size(parametres4);
    vect_moyenne4 = mean( parametres4);
    size(vect_moyenne4);
    vect_moyenne5 = mean( parametres5);

    size(parametres6);
    vect_moyenne6 = mean( parametres6);
    size(vect_moyenne6);
    
    % On le stocke
    ens_moyennes{note}=vect_moyenne;
    ens_moyennes2{note}=vect_moyenne2;
    ens_moyennes3{note}=vect_moyenne3;
    ens_moyennes4{note}=vect_moyenne4;
    ens_moyennes5{note}=vect_moyenne5;
    ens_moyennes6{note}=vect_moyenne6;
  end
  ens_parametres{instrument}=ens_moyennes;
  ens_parametres2{instrument}=ens_moyennes2;
  ens_parametres3{instrument}=ens_moyennes3;
  ens_parametres4{instrument}=ens_moyennes4;
  ens_parametres5{instrument}=ens_moyennes5;
  ens_parametres6{instrument}=ens_moyennes6;

end

% On a recupere un vecteur moyenne par note et par instrument dans ens_parametres
% Maintenant il faut parcourir les fichiers de test et prendre une decision
% ...


ens_notes_reco={};
for instrument=1:length(ens_instruments),
  %ens_moyennes={};
  %vect_moyenne = [];
  for note=1:length(ens_notes),
      distance_notes = [];
    
    
   
      nomfichier = ['sons/tst/', ens_instruments{instrument},'/',ens_notes{note},'1_',num2str(7,'%.3d'),'.wav'];
      [signal,fe,q]=wavread(nomfichier);
      
      param1=energie(signal);
      param2=ZCR_win(signal);
      param3=freq_fond(signal,fe);
      param4=fft(signal);
      param5=ifft(log(abs(fft(signal))));
      param6=canaux(signal,fe,24);

      %ensemble des vecteurs moyennes pour les notes de l'instrument
      listVect1=cell2mat(ens_parametres{instrument});
      listVect2=cell2mat(ens_parametres2{instrument});
      listVect3=cell2mat(ens_parametres3{instrument});
      listVect4=cell2mat(ens_parametres4{instrument});
      %on veut 6 colones pour utiliser mean et sum
      listVect4=reshape(listVect4,length(listVect4)/6,6);
      
      listVect5=cell2mat(ens_parametres5{instrument});
      listVect5=reshape(listVect5,length(listVect5)/6,6);

      listVect6=cell2mat(ens_parametres6{instrument});
      listVect6=reshape(listVect6,length(listVect6)/6,6);

      %distance de chaque note par rapport à un parametre pour chaque vecteur moyen
      distance_notes1= abs(listVect1 - param1);
      [min1,ind1]=min(distance_notes1);

      distance_notes2= abs(listVect2 - param2);
      [min2,ind2]=min(distance_notes2);

      distance_notes3= abs(listVect3 - param3);
      [min3,ind3]=min(distance_notes3);

      %size(listVect4);
      %size(repmat(param4,1,6));
      distance_notes4= sum(abs(listVect4 - repmat(param4,1,6)));
      [min4,ind4]=min(distance_notes4);


      distance_notes5= sum(abs(listVect5 - repmat(param5,1,6)));
      [min5,ind5]=min(distance_notes5);

      %size(listVect6);
      %size(param6);
      distance_notes6= sum(abs(listVect6 - repmat(param6',1,6)));
      [min6,ind6]=min(distance_notes6);
    
      
     
      ens_notes_reco{instrument}{note}{1}=ind1;
      %phrase = ['instrument ', ens_instruments{instrument},' note ',ens_notes{note},' note reconnu ',ens_notes{ind1},' avec parametre 1']
      ens_notes_reco{instrument}{note}{2}=ind2;
      %phrase = ['instrument ', ens_instruments{instrument},' note ',ens_notes{note},' note reconnu ',ens_notes{ind2},' avec parametre 2']
      ens_notes_reco{instrument}{note}{3}=ind3;
      %phrase = ['instrument ', ens_instruments{instrument},' note ',ens_notes{note},' note reconnu ',ens_notes{ind3},' avec parametre 3']
      ens_notes_reco{instrument}{note}{4}=ind4;
      %phrase = ['instrument ', ens_instruments{instrument},' note ',ens_notes{note},' note reconnu ',ens_notes{ind4},' avec parametre 4']
      ens_notes_reco{instrument}{note}{5}=ind5;
      %phrase = ['instrument ', ens_instruments{instrument},' note ',ens_notes{note},' note reconnu ',ens_notes{ind5},' avec parametre 5']
      ens_notes_reco{instrument}{note}{6}=ind6;
      phrase = ['instrument ', ens_instruments{instrument},' note ',ens_notes{note},' note reconnu ',ens_notes{ind6},' avec parametre 6']
    
    
    % On le stocke
    %ens_moyennes{note}=vect_moyenne;
  end
  %ens_parametres{instrument}=ens_moyennes;
end


