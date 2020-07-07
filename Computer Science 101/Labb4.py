from logic import *
#Labb4
#By Magnus Danielsson, Högskoleingenjör Datateknik group 2.

#~A "Not A"
#A&B "A AND B"
#A|B "A OR B"
#A>B "If A thus B"
#A==B "A if and only if B"

#Assignment 1

#a)
fa=(rainy | windy) #True if rainy OR windy is True
#b)
fb=(rainy > windy) # True if rainy AND windy is True
                # True if rainy AND windy is false
#c)
fc=(rainy > wet) & (~rainy > ~wet)
                # True if rainy AND windy is True
                # True if rainy AND windy is False
#d)
fd=(rainy | windy) & (rainy > wet) & (windy > cold)
                # True if windy,cold is True 
                # True if windy,wet,cold is True
                # True if rainy,wet is True 
                # True if rainy,wet,cold is True
                # True if rainy,windy,wet,cold is True
#e)
fe=((rainy & windy) == snow) & winter & (~snow | ~winter)
                # True if rainy,winter is True 
                # True if windy,winter is True 
                # True if winter is True 
#f)
ff=(rainy == windy) & (winter | summer) & (spring | summer) & (~winter > ~windy)
                # True if rainy,windy,winter,summer,spring is True /
                # True if summer is True
                
#g)
fg=(wet > sunny) & (summer | spring) & (snow == winter)
                # True if wet,sunny,summer,spring,snow,winter is True /
                # True if spring is True

#Output
print('Statement logic part 1')
print()

#1a)
print('1a)',val(fa,[rainy])) #True because rainy True

#1b)
print('1b)',val(fb,[rainy,windy])) #True because rainy,windy False

#1c)
print('1c)',val(fc,[rainy,wet])) #True because rainy,wet True 

#1d)
print('1d)',val(fd,[rainy,wet])) #True because rainy,wet True

#1e)
print('1e)',val(fe,[winter])) #True because winter True

#1f)
print('1f)',val(ff,[summer])) #True because summer True

#1g)
print('1g)',val(fg,[spring])) #True because spring is true
print()

##########################################################

print('Statement logic part 2')
print()
#Assignment 2.1)
fone=((summer&(~winter&~spring&~autumn))|(winter&(~summer&~spring&~autumn))|(spring&(~summer&~winter&~autumn))|(autumn&(~summer&~winter&~spring)))
print('2.1',val(fone,[summer])) # True for spring OR summer OR autumn OR winter

#Assignment 2.2)
ftwo=((snow>winter)&(snow>~rainy))
                              # True if winter,snow is True
                              # True if winter is True
                              # True if rainy is True
                              # False if snow,rainy
                              # False if snow
                              # False if winter,snow,rainy
print('2.2',val(ftwo,[winter,snow]))

#Assignment 2.3)
fthree=((snow>cold)&(rainy>~cold))
                              # True if snow, cold is True
                              # True if rainy is True
                              # True if cold is True
                              # True if cold, snow, rainy is False
                              # False if snow is True AND cold is False
                              # False if rainy AND cold is True
                              
print('2.3',val(fthree,[cold,snow]))
print()
##########################################################

#Assignment 3
print('Assignment 3')
print()

fa = forall(x, hungry(x) > ~happy(x))
print('3a', val(fa,[])) # True because nothing is hungry and nothing is not happy

fb = exists(x, hungry(x) & ~happy(x))
print('3b', val(fb,[hungry(fido)],[fido])) #True because something exists, is hungry and not specified as happy

fc=(~hungry(fido) & forall(x,~hungry(x) > happy(x)))
print('3c',val(fc,[happy(fido)],[fido])) # True because fido is NOT hungry and fido IS happy. all not hungry x are happy

fd=(hungry(fido)&happy(cleo) & forall(x,~hungry(x)>happy(x)))
print('3d',val(fd,[hungry(fido),happy(cleo)],[fido,cleo])) # Might be the equivilence to a tautology?

fe=(exists(x,hungry(x) & ~happy(x) & ~(x==fido)))
print('3e',val(fe,[hungry(cleo)],[cleo])) # True if some x exists and is hungry and not happy. x cannot be fido

ff=(exists(x,loves(x,john) & loves(john,x)))
print('3f',val(ff,[loves(mary,john),loves(john,mary)],[mary, john])) #True if x loves y and y loves x

fg=(exists(x, loves(x,john)) & forall(x,forall(y, (loves(x,y) & loves(y,x)) > (happy(x) & happy(y)))))
print('3g',val(fg,[loves(mary,john),happy(john),happy(mary)],[john,mary])) #True if x loves y and y loves x AND x and y are happy

fh=(loves(john, mary) & hates(mary,john) & forall(x, exists(y, (loves(x,y) & hates(y,x))) > ~happy(x)))
print('3h',val(fh,[loves(john,mary),hates(mary,john)],[john,mary])) #False if blank or john is happy

fi=(human(john) & human(bob) & forall(x,human(x) > exists(y, (dog(y) | cat(y)) & owns(x,y))))
print('3i',val(fi,[human(john),human(bob),dog(fido),cat(cleo),owns(bob,cleo),owns(john,fido)],[bob,john,cleo,fido]))
                                                                    # There must be human bob and john who each owns a cat or dog cleo or fido
fj=(exists(x,dog(x)) & exists(y,cat(y)) & exists(z,female(z)) & exists(u,male(u)) & forall(x,male(x) | female(x)))
print('3j',val(fj,[dog(fido),cat(cleo),male(fido),female(cleo)],[fido,cleo]))
                                                                    # There must exist a cat and a dog. There must also exist
                                                                    # a male and a female. the dog can be a male or a female
                                                                    # the cat can also be a male or female
##########################################################
print()
#Assignment 4
print('Assignment 4')
print()

fone=(exists(x,dog(x)&hungry(x)))
print('4.1',val(fone,[hungry(fido)],[fido])) # True iff there is a dog and the dog is hungry
ftwo=(exists(x,dog(x)>hungry(x)))
print('4.2',val(ftwo,[hungry(fido)],[fido]))                # True if anything anything is hungry

fthree=(forall(x,dog(x)>hungry(x)))
print('4.3',val(fthree,[cat(fido),hungry(fido)],[fido])) # True even if x isn't a dog as long as it's hungry

ffour=(forall(x,dog(x)&hungry(x)))
print('4.4',val(ffour,[cat(fido),hungry(fido)],[fido])) # x has to be a dog and hungry


