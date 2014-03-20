function s_ssquantifie = quantification(q,signal)

s_ssquantifie=( floor(signal*2^(q-1)) )/( 2^(q-1) );

