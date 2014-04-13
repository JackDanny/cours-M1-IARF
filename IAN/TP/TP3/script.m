
%on ferme toutes les fenetres
close 'all'

%on lit le signal
[s,fs]=wavread('parole.wav');


figure()

subplot(2,1,1)
plot(s);


subplot(2,1,2)

res=ZCR_result(s,1024,512);

plot(res)

figure()
s2=wavread('parole.wav');

s2=s2(6300:6811); %taille=512

%affichage du signal
subplot(5,1,1)

plot(s2)

%affichage du signal fenetre par Hamming
subplot(5,1,2)

fen_ham=hamming(length(s2));

s2_ham=s2.*fen_ham;

plot(s2_ham)


%affichage du spectre
subplot(5,1,3)

fft_sig=abs(fft(s2_ham));

plot(fft_sig)

%affichage du log du spectre
subplot(5,1,4)

log_fft_sig=log(fft_sig);

plot(log_fft_sig)

%affichage du cepstre

subplot(5,1,5)

cepstre=ifft(log(abs(fft(s2_ham))));

plot(cepstre);


figure()

extrait=cepstre(2:51);

s_extrait=abs(fft(extrait));

plot(s_extrait);

%III

%figure()

en=canaux(fft_sig,fs,24);

figure();








