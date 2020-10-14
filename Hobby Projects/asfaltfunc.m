function [x] = asfaltfunc(antalKort,antalRundor)
x=zeros(2,antalRundor);
for runda=1:antalRundor
deck=randperm(52,antalKort);
personA=zeros(1,antalKort); aCardNr=1; pointsA=zeros(1,antalKort);
personB=zeros(1,antalKort); bCardNr=1; pointsB=zeros(1,antalKort);
for i=1:antalKort
    if mod(i,2)==0
        if deck(i)>=1 && deck(i)<=13
            personA(aCardNr)=deck(i);
            aCardNr=aCardNr+1;
        end
        if deck(i)>13 && deck(i)<=26
            personA(aCardNr)=(deck(i)-13);
            aCardNr=aCardNr+1;
        end
        if deck(i)>26 && deck(i)<=39
           personA(aCardNr)=(deck(i)-26);
           aCardNr=aCardNr+1;
        end
        if deck(i)>39 && deck(i)<=52
           personA(aCardNr)=(deck(i)-39);
           aCardNr=aCardNr+1;
        end
        
    else
        if deck(i)>=1 && deck(i)<=13
            personB(bCardNr)=deck(i);
            bCardNr=bCardNr+1;
        end
        if deck(i)>13 && deck(i)<=26
            personB(bCardNr)=(deck(i)-13);
            bCardNr=bCardNr+1;
        end
        if deck(i)>26 && deck(i)<=39
           personB(bCardNr)=(deck(i)-26);
           bCardNr=bCardNr+1;
        end
        if deck(i)>39 && deck(i)<=52
           personB(bCardNr)=(deck(i)-39);
           bCardNr=bCardNr+1;
        end
    
    end
        
end
for i=1:antalKort
    if personA(i)>personB(i)
       pointsA(i)=(personA(i)-personB(i));
    end
    if personB(i)>personA(i)
       pointsB(i)=(personB(i)-personA(i)); 
    end
end
x(1,runda)=sum(pointsA);
x(2,runda)=sum(pointsB);
end

