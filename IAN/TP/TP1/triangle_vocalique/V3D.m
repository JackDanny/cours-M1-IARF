% Triangle vocalique en trois dimensions

% Adressez vos questions � : alexis.michaud@vjf.cnrs.fr



% effacer les variables ant�rieures.
% Il est conseill� de mettre cette commande en t�te
% de chacun de vos scripts, faute de quoi il peut y avoir des erreurs
% si une variable que vous utilisez existait d�j� en m�moire, 
% avec un autre contenu.
clear

% d�finition d'une cha�ne de caract�res ("character array") 
% contenant les noms des voyelles: 
voy = 'iyeauovwxbcdf';

% liste des codes des caract�res phon�tiques, 
% permettant d'aller les chercher dans la police choisie (SILDoulosIPA)
codes = [105 121 101 97 117 111 79 119 120 79 79 79 79];
%         i   y   e   a  u   o   v  w  x  b  c  d  f
% liste des couleurs choisies pour repr�senter chacun des symboles.
% Les couleurs sont en mode RGB; elles sont donc d�finies par 3 valeurs.
couleurs = [1 0 1; 0 1 1; 1 0 0; 0 1 0; 0 0 0; 0 0 1; 0 0 0.5; 0 0.5 0; 0.5 0 0.5; ...
   0 0.5 0.5; 0.5 0 0; 0.5 0.5 0.5; 1 0.8 0];
% effacer les figures ant�rieures
clf

%%% choix de gros caract�res pour les chiffres des axes:
% r�cup�rer les param�tres actuels, dans un vecteur qu'on nomme h
h = axes;
% modifier la valeur du param�tre 'FontSize': choisir une taille de 15 points
set(h,'Fontsize',15)

% choix de la taille de caract�res pour l'affichage des symboles phon�tiques
ftsize = 15;

% afficher une trame sur la figure
grid on

% s�lection des axes: x (F2), y (F1), z (F3)
axis([500 2400 250 800 2200 3200])

% maintien des axes: pas de changement automatique � chaque nouveau dessin
axis manual
hold on

% autoriser l'utilisateur � faire pivoter la figure en 3 dimensions
rotate3d on

% R�glage du point de vue: d�marrage de l'animation
% en vision 2D
az = -180;
el = 90;

% affichage selon le point de vue s�lectionn�
view(az,el);

% autres points de vue possibles: % az = 0;     el = 90;
%                                 % az = 89.99; el = -90;


%%% affichage sur la figure des signes API correspondants, aux coordonn�es 
%%% correspondant � leurs formants


% D�but de la boucle
for n = 1:length(voy)
   
%% Premi�re �tape: chargement du fichier texte contenant les r�sultats.

% On v�rifie d'abord que le fichier existe bien.
exi = exist(['./',voy(n),'.txt']);
% Cette commande renvoie la valeur 0 si le fichier n'existe pas � l'endroit sp�cifi�, 
% et 2 si le fichier existe bien.
if exi == 0
   disp(['Attention: le fichier de r�sultats ',voy(n),'.txt ne se trouve pas dans le r�pertoire C:\.'])
   disp('Les donn�es de formants pour cette voyelle n''ont pas pu �tre charg�es.')
else
   if exi == 2
      % chargement du fichier, dans un vecteur qu'on appellera F (comme Formant)
      F = load (['./',voy(n),'.txt']);
      disp(['Fichier ',voy(n),'.txt charg�.'])
      % v�rifier que le fichier contient bien 3 valeurs, ni plus ni moins
      if length(F) == 3
         % afficher le symbole aux coordonn�es F1, F2 et F3.
         % Note: l'axe des x correspond � F2 et l'axe des y � F3, 
         % pour suivre les conventions du triangle vocalique des tableaux de
         % l'Alphabet Phon�tique International.
         text(F(2),F(1),F(3),char(codes(n)),'color',couleurs(n,:),'FontSize',ftsize,'FontName','Times New Roman')
         
         % S'il s'agit d'une nasale, il faut ajouter le diacritique correspondant.
         if (voy(n) == 'v' | voy(n) == 'w' | voy(n) == 'x')
            text(F(2),F(1),F(3),[char(codes(n))],'color',couleurs(n,:),'FontSize',ftsize,'FontName','Times New Roman')
         end
         
      else
         disp(['Le fichier ',voy(n),'.txt doit contenir 3 valeurs, ni plus ni moins.'])
         disp('V�rifiez le fichier.')
      end
   end
end

end

% choix des labels des axes
xlabel('Formant 2 (Hz)')
ylabel('Formant 1 (Hz)')
zlabel('Formant 3 (Hz)')

% orientation du papier pour impression
orient landscape
% choix de la taille de papier pour impression
set(1,'PaperType','A5')
set(1,'PaperPosition',[0.5 0.5 10 7])
% impression sous forme de fichier jpeg (image)
print -djpeg100 './V_2D'

% R�glage du point de vue en vision 3D
view(3);

% orientation du papier pour impression
orient landscape
% choix de la taille de papier pour impression
set(1,'PaperType','A5')
set(1,'PaperPosition',[0.5 0.5 7 7])

% impression sous forme de fichier jpeg (image)
print -djpeg100 './V_3D'

% demande de rotation par utilisateur
   ROTATIF = input('Voulez-vous voir une rotation en 3 dimensions? Si oui, entrez 1 puis RETOUR CHARIOT.');
if ROTATIF == 1
   tourn(az,el)
end
