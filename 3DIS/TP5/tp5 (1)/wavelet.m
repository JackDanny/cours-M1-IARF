function [I2]=wavelet(I,ord)
  
  g=[1/2 1/2];
  h=[1/2 -1/2];
  
  [s1,s2]=size(I);
  
  if (ord == 1)
  
   I2=onde_mat(I,h,g);
   
  
   
   
   
   
   elseif (ord > 1)
   
   I2=onde_mat(I,h,g);
   I3=wavelet(I2(1:(end/2),1:(end/2)),(ord-1));
   
   
   %for i=1:s1/2
   %   for j=1:s2/2
   
   %     I2(i,j)=I3(i,j);
   
   %   end
   %end
   I2( 1:(end/2),1:(end/2)  )=I3(1:end,1:end);
   
   else
   
   
   
   end
  
  
  