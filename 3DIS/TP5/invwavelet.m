function [I3]=invwavelet(I,ord)


g=2*[1/2 1/2];
h=2*[-1/2 1/2];

[s1,s2]=size(I);
%I3=zeros(s1,s2);
I3=I;

if (ord == 1)
  I3=inv_onde_mat(I,h,g);

  elseif (ord > 1)
   current_size1=floor(s1/(2));
   current_size2=floor(s2/(2));

   I2=invwavelet(I(1:current_size1,1:current_size2),(ord-1));
   
   I3(1:current_size1,1:current_size2)=I2;
   
   I3=inv_onde_mat( I3 ,h,g);


  

   
   
   
   %for i=1:s1/2
   %   for j=1:s2/2
   
   %     I2(i,j)=I3(i,j);
   
   %   end
   %end
   %I2( 1:floor(end/2),1:floor(end/2)  )=I3(1:end,1:end);
   
   else
   
   
   
   end
  
