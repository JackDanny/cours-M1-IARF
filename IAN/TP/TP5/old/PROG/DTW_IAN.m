function [Mch,Mcout,cout] = DTW_IAN(MRec,MRef) 

%x, ref_alpha)


%MRec matrice du signal à reconnaitre
%MRef matrice du signal de reference
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     Mch=[];

%matrice des couts

[s1,s2]=size(MRec);
[s3,s4]=size(MRef);



%pdist

%matrice de cout
Mcout = zeros(s4+1,s2+1);

%matrice des chemins
Mch = ones(s4+1,s2+1);


Mchemin = zeros(s4+1,s2+1,3);

Mcout(1,:)=inf;
Mcout(:,1)=inf;
Mcout(1,1)=0;



for i=2:s4+1
	for j=2:s2+1
             distance= sqrt(  sum( (MRef(:,i-1) - MRec(:,j-1)).^2) );
          
	     c1=Mcout(i,j-1)+distance;
             c2=Mcout(i-1,j-1)+2*distance;
             c3=Mcout(i-1,j)+distance;
		
             if min([c1,c2,c3]) == c1
		 Mchemin(i,j,1)=1;
             end
             
             if min([c1,c2,c3]) == c2
		 Mchemin(i,j,2)=1;
             
             end
             
             if min([c1,c2,c3]) == c3
                 Mchemin(i,j,3)=1;
             end

	     Mcout(i,j)=min([c1,c2,c3]);


	end
end



%cout du chemin
cout=Mcout(s4+1,s2+1)/(s4+s2);


a=s4+1;
b=s2+1;






while ((a ~= 1) || (b ~= 1)) ;
  
  if(Mchemin(a,b,2) == 1);
    a=a-1;
    b=b-1;
    Mch(a,b)=2;
  
  
  elseif(Mchemin(a,b,1) == 1);
    b=b-1;
    Mch(a,b)=2;
  
  
  else(Mchemin(a,b,3) == 1);
   a=a-1;
     Mch(a,b)=2;
  end
  
  
  
end

figure();

imagesc(Mch), xlabel('Test'), ylabel('Ref')



















