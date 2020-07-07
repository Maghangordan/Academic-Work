import math

#Kod skriven av Magnus Danielsson, Högskoleingenjör Datateknik grupp 3 i kursen Datavetenskapens grunder
#2019-09-11

#Uppgift 3.1
def klocka_plus(tid1,tid2):


    newmin=tid1[1]+tid2[1]
    newtim=tid1[0]+tid2[0]
    minut3=newmin%60
    extratim=newmin//60
    tim3=(newtim+extratim)%24
    return(tim3,minut3)

print('Uppgift 1, 10:45+11:15= ',klocka_plus((10,45),(14,30))) #T.ex
print('Uppgift 1, 10:45+(-14):(-30) ',klocka_plus((10,45),(-14,-30))) #T.ex
print()

#######################################


#Uppgift 3.2
def delare(m,n):

    return(n%m==0)

def primtal(p):
    divisor=0;
    print('Är ',p,' ett primtal?')
    if p==1:
        return False
    for x in range(1,p): #Från 1 till p, inget större än p kan vara en heltalsdelare
        if delare(x,p)==True: #Delare undersöker om x är en delare för p
            divisor=divisor+1; #Om x är en delare adderar vi en delare
    if(divisor>=2):
        return False #Har p fler än 2 (1 och sig självt) så är det ej ett primtal
    else:
        return True #Har p ej fler än 2 delare så är det ett primtal
    print()

#######################################

#Uppgift 3.3
    
antalAnrop=0 #Vi använder denna variabel för att se hur många gånger fib(3) beräknas
antalSnabb=0 #Vi använder denna variabel för att se hur många anrop loopfib() får 

def fib(n): #Långsamma fib
    
    global antalAnrop #Vi "importerar" antalAnrop
    
    if n<3:
        return 1
    else:
        print('Beräknar fib(',n,')')
        
        if n==3:
            antalAnrop=antalAnrop+1
            print('fib(3) har anropats ',antalAnrop,' gånger')
        return fib(n-1)+fib(n-2)


def loopfib(n): #Snabbfibben
    
    global antalSnabb #Vi importerar antalSnabbrop
    curr=1
    prev=1
    for x in range(n-2):
        antalSnabb=antalSnabb+1
        print('loopfib() har körts ',antalSnabb,' gånger')
        curr,prev=curr+prev,curr
    return curr

#Kommentarer
#Föga oväntat slutsats är att den rekursiva fib(n) funktionen behöver anropa
#sig själv oerhört många gånger.
#Exempelvis så kräver fib(10) att fib(3) anropas 21 gånger, medans själva
#fib() anropas ännu fler gånger.
#loopfib(10) anropar endast funktionen 8 gånger

#######################################

#Uppgift 3.5

#Finns i Labb3Träd



        
