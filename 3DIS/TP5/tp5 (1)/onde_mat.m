function [I2]=onde_mat(I,h,g)
[s1,s2] = size(I)

I2=zeros(s1,s2);

for i=1:2:s1
  for j=1:2:s2
  
    I_calc=onde2x2(I(i:i+1,j:j+1) ,h,g);
    
    I2((i+1)/2,((j+1)/2)) = I_calc(1,1);
    I2((end/2)+((i+1)/2),((j+1)/2)) = I_calc(1,2);
    I2(((i+1)/2),(end/2)+((j+1)/2)) = I_calc(2,1);
    I2((end/2)+((i+1)/2),(end/2)+((j+1)/2)) = I_calc(2,2);
  end
end
    
    
    
    

