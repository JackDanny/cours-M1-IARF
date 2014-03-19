function  specto( s )
%UNTITLED1 Summary of this function goes here
%  Detailed explanation goes here
s=s';

m=[];
for i=1:100:(length(s)-1024)
    v=abs(fft(s(i:(i+1023)).*hamming(1024)'));
    m=[m v(512:1024)'];
end

imagesc(m)    
end
