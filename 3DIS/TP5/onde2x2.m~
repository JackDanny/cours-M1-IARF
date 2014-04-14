 function [I2]=onde2x2(I,h,g)
 
 a=I(1,1);
 b=I(1,2);
 c=I(2,1);
 d=I(2,2);
 
 gx(1)=g(2)*a+g(1)*b;
 gx(2)=g(2)*c+g(1)*d;
 
 hx(1)=h(2)*a+h(1)*b;
 hx(2)=h(2)*c+h(1)*d;
 
 
 gxgy=g(2)*gx(1)+g(1)*gx(2);
 gxhy=h(2)*gx(1)+h(1)*gx(2);
 
 hxgy=g(2)*hx(1)+g(1)*hx(2);
 hxhy=h(2)*hx(1)+h(1)*hx(2);
 
 
 I2(1,1)=gxgy;
 I2(1,2)=gxhy;
 I2(2,1)=hxgy;
 I2(2,2)=hxhy;
 
 
 
 