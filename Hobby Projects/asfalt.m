kortPerRunda=26;
%antalSpelare=2;
antalRundor=1;
x=1:antalRundor;
%teoretiskt max:
maxDraw=(4*13)+(4*12)+(4*11)+(4*10)+(4*9)+(4*8)+(2*7);
minDraw=(2*7)+(4*6)+(4*5)+(4*4)+(4*3)+(4*2)+(4*1);
bestCase=maxDraw-minDraw;
%==4*(13-1)+4*(12-2)+4*(11-3)+4*(10-4)+4*(9-5)+4*(8-6)+2*(7-7)
resultat=asfaltfunc(kortPerRunda,antalRundor);
%plot(x,resultat(2,:))
i=0;
varv=0;
while max(resultat,[],1)<120
   resultat=asfaltfunc(kortPerRunda,antalRundor);
   if i+1 == intmax
      varv=varv+1; 
      i=0;
   end
   i=i+1;
   
end
disp(i)
disp(varv)



