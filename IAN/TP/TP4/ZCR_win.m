function res= ZCR_win(S)
 
N=length(S);


res=(1/(2*(N-1)))*sum( abs(sign( S(2:end) )-sign( S(1:N-1) )));



 
 
