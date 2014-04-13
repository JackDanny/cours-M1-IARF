function en=canaux(spectre,Fs,nfilt)
% - spectre est le module de la FFT
% - Fs est la frequence d'echantillonnage
% - nfilt est le nombre de canaux visualises
%
% Exemple : en=canaux(spectre,16000,24)

% Init de la taille du spectre
lgsig1 = length(spectre);

% Init des frequences de coupure (par rapport echelle Mel)
fcoup = [0,100,200,300,400,500,600,700,800,900,1000,1150,1300,1500,1700,2000,2350,2700,3100,3550,4000,4500,5050,5600,6200,6850,7500];

% Init des filtres triangulaires : x1 (montant), x2 (descendant)
x2 = zeros(1,lgsig1);
x1 = zeros(1,lgsig1);

% Frequences possibles en fonction de la taille de la fenetre et de Fs
f = [1:lgsig1]/lgsig1*Fs/2;

% Calcul des poids (entre 0 et 1) des branches du triangle : x1 et x2
% avec symetrie par rapport à 0,5
% +
% Stockage des indices de frequences de coupure par rapport au frequences f
for i=1:lgsig1
	nm(i) = 0;
	x1(i) = 0;
	for n=1:nfilt+1
		if((f(i)>=fcoup(n)) && (f(i)<fcoup(n+1)))
            nm(i) = n;
            x1(i) = (f(i)-fcoup(n))/(fcoup(n+1)-fcoup(n));
            x2(i) = 1-x1(i);
		end
	end
end

% figure;
% plot(x1);
% hold on;
% plot(x2,'r');
% hold off;

% Ponderation des valeurs spectrales par rapport aux filtres triangulaires
x2sig=x2.*spectre(1:lgsig1)';
x1sig=x1.*spectre(1:lgsig1)';

% Somme des valeurs spectrales ponderees pour chaque triangle
en=zeros(1,nfilt);
for i=1:nfilt
    en(i) = sum(x1sig(nm==i)) + sum(x2sig(nm==i));
end

% Affichage
figure;
subplot(211);
plot(f,spectre);
subplot(212)
stairs(fcoup(1:nfilt),en);
