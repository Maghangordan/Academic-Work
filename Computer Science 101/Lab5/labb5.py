from automata import *
import re
#Code by Magnus Danielsson, högskoleingenjör datateknik group 2
#Assignment 1
print('Assignment 1')
auto1_run('0') #s0->s0 False
print()
auto1_run('1') #s0->s1 True
print()
auto1_run('01')#s0->s0->s1 True
print()
auto1_run('10') #s0->s1->s0 False
print()
auto1_run('0001') #s0->s0->s0->s0->s1 True
print()
auto1_run('00010') #s0->s0->s0->s0->s1->s0 False
print()
auto1_run('01010101') #s0->s0->s1->s0->s1->s0->s1->s0->s1 True

##############################
#Assignment 2
print()
print('Assignment 2')
mealy_run('0')
print()
mealy_run('1')
print()
mealy_run('1101')
print()
mealy_run('001010100')
print()
mealy_run('11111')
############################
#Assignment 3
#Assignment 3 is the tortoise.py file
print()
print()
print('Assignment 3')
print('Made in tortoise.py')
print()
############################
#Assignment 4
print()
print('Assignment 4')
print(re.match('((auto|flyg)(mat|pilot))$','auto')) #Does not match
print(re.match('((auto|flyg)(mat|pilot))$','autopilot')) #Match
print(re.match('((auto|flyg)(mat|pilot))$','autopiloten')) #Does not match
print(re.match('((auto|flyg)(mat|pilot))$','läskautomat')) #Does not match
############################
#Assignment 5
print()
print('Assignment 5')
#5a)
print('5a)')
print(re.match('(.*)(tex)$','myfile.tex')) #match
print(re.match('[a-z]*[1-9]*.tex$','yourfile'))
print(re.match('[a-z]*[1-9]*.tex$','cooldoc123.tex')) #match
print(re.match('[a-z]*[1-9]*.tex$','textdocument.doc'))
print(re.match('[a-z]*[1-9]*.tex$','filebile.ini'))
#5b)
print('5b)')
print(re.match('[a-z]*[1-9]*[^.]$','myfile.tex'))
print(re.match('[a-z]*[1-9]*[^.]$','yourfile')) #match because it doesn't end with a .
print(re.match('[a-z]*[1-9]*[^.]$','cooldoc123.tex'))
print(re.match('[a-z]*[1-9]*[^.]$','textdocument.doc'))
print(re.match('[a-z]*[1-9]*[^.]$','filebile.ini'))
#5c)
print('5c')
print(re.match('[a-z]*[1-9]{3}\.[a-z]*$','myfile.tex'))
print(re.match('[a-z]*[1-9]{3}\.[a-z]*$','yourfile'))
print(re.match('[a-z]*[1-9]{3}\.[a-z]*$','cooldoc123.tex')) #match because the name a combination of a-z, 3 numbers between 1-9, a dot follows and after the dot follow some combination of a-z
print(re.match('[a-z]*[1-9]{3}\.[a-z]*$','textdocument.doc'))
print(re.match('[a-z]*[1-9]{3}\.[a-z]*$','filebile.ini'))
#5d)
print('5d)')
print(re.match('[a-z]*[1-9]*(.txt|.doc|.tex|.ini)$','myfile.tex')) #match
print(re.match('[a-z]*[1-9]*(.txt|.doc|.tex|.ini)$','yourfile')) 
print(re.match('[a-z]*[1-9]*(.txt|.doc|.tex|.ini)$','cooldoc123.tex')) #match
print(re.match('[a-z]*[1-9]*(.txt|.doc|.tex|.ini)$','textdocument.doc')) #match
print(re.match('[a-z]*[1-9]*(.txt|.doc|.tex|.ini)$','filebile.ini')) #match
############################
#Assignment 6
print()
print('Assignment 6')
print(re.match('(0|[1-9][0-9]*)$','0')) #match (assuming 0 is a natural number)
print(re.match('(0|[1-9][0-9]*)$','0a'))
print(re.match('(0|[1-9][0-9]*)$','04'))
print(re.match('(0|[1-9][0-9]*)$','15')) #match
print(re.match('(0|[1-9][0-9]*)$','1066')) #match
print(re.match('(0|[1-9][0-9]*)$','femton'))

############################
#Assignment 7
print()
print('Assignment 7')
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','0')) #No match
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','10')) #No match
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','10+20')) #Match because natural number x-amount of operation natural number
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','7+8+33/5-999')) #No match because several repetitions AND the instructions says only match for the form natural number x-amount of operation(s) natural number
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','mycket')) #No match
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','22**13+-4')) #No match because 3 natural numbers
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','+32')) #No match
print(re.match('(([0-9][0-9]*)+[\+|\-|\*|\/]+(0|[1-9][0-9]*))$','15+')) #No match
#Credit to Mohamadreza Faridghasemnia for providing insight and making the regex work

#'((0|[1-9][0-9]*)[+\-*/]*(0|[1-9][0-9])*)*$' alternative solution
#yields different result and may be valid based on how the instructions are interpreted

