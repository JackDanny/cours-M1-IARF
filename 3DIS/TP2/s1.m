silence=zeros(1,100);

X=linspace(0,1,8000);

DO3=sin(2*X*pi*264)*0.8;

MI3=sin(2*X*pi*330)*0.8;

SOL3=sin(2*X*pi*396)*0.8;

DO4=sin(2*X*pi*528)*0.8;

S1=[silence DO3 silence MI3 silence SOL3 silence DO4];



SOL3=sin(2*X*pi*392)*0.8;

SOL2=sin(2*X*pi*196)*0.8;

mario=[MI3 silence MI3 silence MI3 DO3 MI3 SOL3 SOL2];


b=(rand(1,length(S1))*0.4)-0.2;

S2=S1+b;

%wavwrite(S1,8000,16,'melodie1')

wavwrite(S2,8000,16,'melodie2');

%sound(S2)
%m=[]

%S1(1:1024)
%(100:1124)


%for i=1 i<size(S1-1) i+100:
%  m=[m S1(i:i+1024)]
%end
m=[];
m2=[];
for i=1:100:(length(S1)-1024)
  extrait=S1(i:(i+1023));
  a1=abs(fft(extrait));
 
  a2=abs(fft(extrait.*(hamming(length(extrait)))'));
  %on prend la partie droite de la fft
  a1=a1((length(a1)/2):end);
  a2=a2((length(a2)/2):end);
  

  m=[m ; a1];
  m2=[m2 ; a2];
  
  
end
%on transpose m
  m=m';
  m2=m2';

fftaux=fft(S1)
%fftaux=fftaux((length(fftaux)/2):end);



