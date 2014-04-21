function coeffCepstraux = extractionCoeffCepstraux(audioIn)

[y, freqEch, nbits, opts] = wavread(audioIn);
dureeFenetre = 30e-3;
nbEchParFenetre = freqEch * dureeFenetre;
pasFenetre = floor(nbEchParFenetre * 0.5);
y=y+eps;

fenetreAnalyse = buffer(y, nbEchParFenetre, pasFenetre);

for i = 1 : size(fenetreAnalyse, 2)
   
    fenetreAnalyse(:,i);

	size(fenetreAnalyse,2);
    coeffCepstraux(:, i) = rceps(fenetreAnalyse(:,i));
end