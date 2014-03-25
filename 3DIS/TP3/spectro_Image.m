function [spectre]= spectro_Image(I)


spectre=log(abs(fft2(I)));
figure()

imagesc(spectre)
colormap(gray)



