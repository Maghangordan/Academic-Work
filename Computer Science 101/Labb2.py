import math

#Kod skriven av Magnus Danielsson, Högskoleingenjör Datateknik grupp 3 i kursen Datavetenskapens grunder
#2019-09-11

#Uppgift 2.1

print("2.1")
print()

A=set([1,2,3,4])
B=set([3,4,5])
C=set([5])
U=set([0,1,2,3,4,5,6,7,8,9])

print("Tillhör siffran 1 mängden A? ",1 in A)
print("Tillhör siffran 5 mängden A? ",5 in A)
print("Tillhör siffran 1 nollmängden?" ,1 in set())
print("Tillhör siffran 1 mängden U? ",1 in U)
print("Är A en delmängd till B? ", A.issubset(B))
print("Är C en delmängd till B? ", C.issubset(B))
print("Är A en delmängd till Nollmängden? ", A.issubset(set()))
print("Är A en delmängd till U? ", A.issubset(U))
print("Är snittet av A & C en delmängd av B? ",A.intersection(C).issubset(B))
print("Är unionen av A & C en delmängd av B? ",A.union(C).issubset(B))
print("Är differensen A\B samma som mängden C? ",A.difference(B)==C)
print("Är differensen B\C en delmängd av A? ",B.difference(C).issubset(A))
print("Är differensen B\C samma som mängden A? ",B.difference(C)==A)
print("Är kardinaliteten |U| lika med 5? ", 5 == len(U))
print("Är summan av kardinaliteterna |A|+|B|=5? ",(len(A)+len(B)==5))

#Uppgift 2.2

print()
print("2.2")
print()

#Vi gör setet {{2,1},{2,1,3,4}} på raden under
set1=set([frozenset([2,1]),frozenset([2,1,3,4])])
print(set1)

print("Tillhör mängden A mängden {{2,1},{2,1,3,4}}? ",A in set1)
print("Är A en delmängd till mängden {{2,1},{2,1,3,4}}? ",A.issubset(set1))
print("Är C en delmängd till mängden {{2,1},{2,1,3,4}}? ",C.issubset(set1))

#Uppgift 2.3

print()
print("2.3")
print()

def comp(n):
    
#Vi använder den tidigare använda mängden U som universum, därför används samma namn/symbol
    
    return (U.difference(n))
#Om man skriver comp(A) och eller comp(U) i shellen så får man komplementet till A och eller U
print("Är A en delmängd av C komplement? ",A.issubset(comp(C)))
print("Är kompletementet av A komplement lika med A? ",comp(comp(A))==A)

#Uppgift 2.4

print()
print("2.4")
print()
print("Finns i kod!")

def setprod(m1,m2):
    p=set()
    for e1 in m1:
        for e2 in m2:
            p.add((e1,e2))

    return p

#Uppgift 2.5

print()
print(2.5)
print()

print("A x B = ",setprod(A,B))
print()
print("A x (B x C) = ",setprod(A,setprod(B,C)))
print()
print("Är A x B = B x A? ",setprod(A,B)==setprod(B,A))
print()
print("Är A x Ø = Ø? ",setprod(A,set())==set())















