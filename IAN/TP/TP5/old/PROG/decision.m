 function [mindist,Mot] = decision(Ldist,Ldico) 
%

%une étape d'extraction des vecteurs de paramètres acoustiques;
%une DTW qui permet de calculer la distance entre le mot prononcé et un mot du dictionnaire;
%une étape de décision ;
%l'affichage du mot reconnu sur le terminal de l'utilisateur;
%la possibilité de visualiser les résultats de la DTW sur l'ensemble du dictionnaire afin
%d'évaluer la robustesse de la reconnaissance.

[mindist,indx] = min(Ldist);

Mot=Ldico(indx);
