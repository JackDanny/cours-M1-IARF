function B=poly_Bernstein(n,k,u)
 

 B = nchoosek(n,k) * (u.^ k) .* ((1-u).^(n-k));