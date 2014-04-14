function [Iresult]=wavelet(img,ordre)
    g=[0.5 0.5]; % pour les lignes
    h=[-0.5 0.5]; % pour les lignes
    %hh=[0.5 -0.5]; % pour les colonnes
    img = double(img);
    [n,m]=size(img);
    Iresult = zeros(n,m);
    for i=1:1:ordre %pour  ordre
        taille_n = round( n / 2^i);
        taille_m = round( m / 2^i);
        l = taille_n;
        nbc = taille_m ;
        for x=1:2:(taille_n)*2-1
            for y=1:2:(taille_m)*2-1
                a = img(x,y);
                b = img(x+1,y);
                c = img(x,y+1);
                d = img(x+1,y+1);
                
                resA = 0.25*(a+b+c+d);
                resB = 0.25*(a-b+c-d);
                resC = 0.25*(a+b-c-d);
                resD = 0.25*(a-b-c+d);

                x2=(x-1)/2+1;
                y2=(y-1)/2+1;
                Iresult(x2,y2)=resA;
                Iresult(x2+l,y2)=resB;
                Iresult(x2,y2+nbc)=resC;
                Iresult(x2+l,y2+nbc)=resD;
            end
        end
    end
    %imagesc(Iresult); colormap(gray);
end
     
