function [X,Y]=hermite(P0,P1,T0,T1)

%un vecteur de 101 valeurs espacées régulièrement entre 0 et 1, donc avec un pas de 0.01
u=linspace(0,1,101);


h0=((u-1).^2).*(2*u + 1);
h1=(u.^2).*(3 - 2*u);
h2=u.*((u-1).^2);
h3=(u.^2).*(u-1);


X=h0.*P0(1) + h1.*P1(1) + h2 .* T0(1) + h3 .* T1(1);
Y=h0.*P0(2) + h1.*P1(2) + h2 .* T0(2) + h3 .* T1(2);


