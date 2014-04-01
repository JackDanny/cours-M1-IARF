function tourn(az,el)

TOUR = 0
while TOUR == 0
   
   for i = 1:18
       az = az +1;
       el = el - 2;
       view(az,el);
       pause(2);
   end
   disp('Entrer 0 puis RETOUR CHARIOT pour poursuivre la rotation. ')
   TOUR = input('Sinon, appuyez sur n''importe quelle touche puis sur RETOUR CHARIOT. ');
end

disp('Rotation terminée.')