
%on ferme toutes les fenetres
close 'all'

%on lit le signal
[s,fs]=wavread('parole.wav');


figure()

%affichage du signal
subplot(2,1,1);

t=(0:length(s)-1)/fs;

plot(t,s);

xlabel('Temps(en sec)');

ylabel('Amplitude');

legend('signal');


%affichage du ZCR
subplot(2,1,2)

res=ZCR_result(s,1024,512);

t2=(0:length(res)-1) * ( ((length(s)-1)/fs) / (length(res)-1) );

plot(t2,res)

legend('ZCR');

xlabel('Temps(en sec)');

ylabel('ZCR(normalisé)');



figure()


s2=wavread('parole.wav');

%on garde juste un extrait
s2=s2(6300:6811); %taille=512

%affichage du signal
subplot(5,1,1)

t=(0:length(s2)-1)/fs;

plot(t,s2)

legend('signal');

xlabel('Temps(en sec)');

ylabel('Amplitude');

%affichage du signal fenetre par Hamming

subplot(5,1,2)

%affichage du fenetrage de Hamming
fen_ham=hamming(length(s2));

s2_ham=s2.*fen_ham;

plot(t,s2_ham)

legend('Signal fenêtré par Hamming');

xlabel('Temps(en sec)');

ylabel('Amplitude');

%affichage du spectre
subplot(5,1,3)

f=((0:length(s2)-1)*fs)/(length(s2)-1);

fft_sig=abs(fft(s2_ham));

plot(f,fft_sig)

legend('Spectre');

xlabel('frequences(Hz)');

ylabel('Amplitude');


%affichage du log du spectre
subplot(5,1,4)

log_fft_sig=log(fft_sig);

plot(f,log_fft_sig)

legend('log du Spectre');

xlabel('frequences(Hz)');

ylabel('Amplitude');


%affichage du cepstre

subplot(5,1,5)

cepstre=ifft(log(abs(fft(s2_ham))));

ech=(0:length(s2)-1);

plot(ech,cepstre);


legend('Cepstre');

xlabel('Echantillons');

ylabel('Amplitude');


%affichage du spectre de cepstre
figure()

extrait=cepstre(2:51);

s_extrait=abs(fft(extrait));

plot(s_extrait);


legend('Spectre lissé');

%III

%figure()

en=canaux(fft_sig,fs,24);









