% Triangle vocalique en trois dimensions

% Adressez vos questions à : alexis.michaud@vjf.cnrs.fr



% effacer les variables antérieures.
% Il est conseillé de mettre cette commande en tête
% de chacun de vos scripts, faute de quoi il peut y avoir des erreurs
% si une variable que vous utilisez existait déjà en mémoire, 
% avec un autre contenu.
clear

% définition d'une chaîne de caractères ("character array") 
% contenant les noms des voyelles: 
voy = 'iyeauovwxbcdf';

% liste des codes des caractères phonétiques, 
% permettant d'aller les chercher dans la police choisie (SILDoulosIPA)
codes = [105 121 101 97 117 111 79 119 120 79 79 79 79];
%         i   y   e   a  u   o   v  w  x  b  c  d  f
% liste des couleurs choisies pour représenter chacun des symboles.
% Les couleurs sont en mode RGB; elles sont donc définies par 3 valeurs.
couleurs = [1 0 1; 0 1 1; 1 0 0; 0 1 0; 0 0 0; 0 0 1; 0 0 0.5; 0 0.5 0; 0.5 0 0.5; ...
   0 0.5 0.5; 0.5 0 0; 0.5 0.5 0.5; 1 0.8 0];
% effacer les figures antérieures
clf

%%% choix de gros caractères pour les chiffres des axes:
% récupérer les paramètres actuels, dans un vecteur qu'on nomme h
h = axes;
% modifier la valeur du paramètre 'FontSize': choisir une taille de 15 points
set(h,'Fontsize',15)

% choix de la taille de caractères pour l'affichage des symboles phonétiques
ftsize = 15;

% afficher une trame sur la figure
grid on

% sélection des axes: x (F2), y (F1), z (F3)
axis([500 2400 250 800 2200 3200])

% maintien des axes: pas de changement automatique à chaque nouveau dessin
axis manual
hold on

% autoriser l'utilisateur à faire pivoter la figure en 3 dimensions
rotate3d on

% Réglage du point de vue: démarrage de l'animation
% en vision 2D
az = -180;
el = 90;

% affichage selon le point de vue sélectionné
view(az,el);

% autres points de vue possibles: % az = 0;     el = 90;
%                                 % az = 89.99; el = -90;


%%% affichage sur la figure des signes API correspondants, aux coordonnées 
%%% correspondant à leurs formants


% Début de la boucle
for n = 1:length(voy)
   
%% Première étape: chargement du fichier texte contenant les résultats.

% On vérifie d'abord que le fichier existe bien.
exi = exist(['./',voy(n),'.txt']);
% Cette commande renvoie la valeur 0 si le fichier n'existe pas à l'endroit spécifié, 
% et 2 si le fichier existe bien.
if exi == 0
   disp(['Attention: le fichier de résultats ',voy(n),'.txt ne se trouve pas dans le répertoire C:\.'])
   disp('Les données de formants pour cette voyelle n''ont pas pu être chargées.')
else
   if exi == 2
      % chargement du fichier, dans un vecteur qu'on appellera F (comme Formant)
      F = load (['./',voy(n),'.txt']);
      disp(['Fichier ',voy(n),'.txt chargé.'])
      % vérifier que le fichier contient bien 3 valeurs, ni plus ni moins
      if length(F) == 3
         % afficher le symbole aux coordonnées F1, F2 et F3.
         % Note: l'axe des x correspond à F2 et l'axe des y à F3, 
         % pour suivre les conventions du triangle vocalique des tableaux de
         % l'Alphabet Phonétique International.
         text(F(2),F(1),F(3),char(codes(n)),'color',couleurs(n,:),'FontSize',ftsize,'FontName','Times New Roman')
         
         % S'il s'agit d'une nasale, il faut ajouter le diacritique correspondant.
         if (voy(n) == 'v' | voy(n) == 'w' | voy(n) == 'x')
            text(F(2),F(1),F(3),[char(codes(n))],'color',couleurs(n,:),'FontSize',ftsize,'FontName','Times New Roman')
         end
         
      else
         disp(['Le fichier ',voy(n),'.txt doit contenir 3 valeurs, ni plus ni moins.'])
         disp('Vérifiez le fichier.')
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

% Réglage du point de vue en vision 3D
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
