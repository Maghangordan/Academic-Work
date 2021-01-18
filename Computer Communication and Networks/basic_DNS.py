#-----------------------------------------------------------
#-----------------------------------------------------------
# Lab 5: DNS client
# General structure
#-----------------------------------------------------------
#-----------------------------------------------------------
import sys, time, re
from socket import *


#-----------------------------------------
# URL formatting function (YOUR CODE)
#-----------------------------------------
                       #5.1.1)
def formatURL(url_in): #input is a string. We want to split it based on the character '.'
                       #and count the numbers of characters before each '.'
                       #This integer can be converted into hexadecimal, which we then join into a byte-class variable
    urlList=url_in.split('.') #list-type variable
    numChar=[int]*len(urlList); #Pre-allocating with room for the same numbers of integers as there are strings in the list
    url_bin=b'';
    for i in range(0,len(urlList)):
            numChar[i]=len(urlList[i]);
            
                                   #We now know how many characters each of the strings have in the list
                                   #However, hex gives us the format "0x3" instead of "\x03"
                                   #When we use numChar[i].to_bytes(2,'little/big'), we get b'\x0b\x00'
                                   #We can use b''.join() for this! (Or b''+b'x0b')
            url_bin=url_bin+(numChar[i].to_bytes(1,'little'));
            
            url_bin=b''.join([url_bin,urlList[i].encode()]); #This was way simpler than I imagined it would be
            
    url_bin=url_bin+b'\x00'; #This gives us url_bin=b'\x0b\x03\x02\x00'. We want to add the bytes-form strings from urlList prior to every '\' except the first one
                            #Of course, this is done in the for-loop (1) 
                            #5.1.2) See addititional_info=b'\x00\x01\x00\x01';
                            
    #print(url_bin)
    
    
    # your code goes here
    return url_bin

     
#DNS_server='10.1.112.11'
DNS_server='8.8.8.8'
DNS_port=53
timeout=5
#-----------------------------------------
# Socket initialization
#-----------------------------------------
 
clientsocket = socket(AF_INET, SOCK_DGRAM)
clientsocket.settimeout(timeout)
  
DNS_port = int(DNS_port) 


url_to_query='www.oru.se'
formatted_url=formatURL(url_to_query);
additional_info=b'\x00\x01\x00\x01';
#-----------------------------------------
# Question assembly (YOUR CODE)
#-----------------------------------------
query_to_DNS=formatted_url+additional_info
def makeMessage(query_to_DNS):
    query_to_DNS=b'\x00\x02\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00'+query_to_DNS
    return query_to_DNS
query_to_DNS=makeMessage(query_to_DNS)
#print(query_to_DNS)
try:
    
    clientsocket.sendto(query_to_DNS,(DNS_server, DNS_port))
    message, address = clientsocket.recvfrom(1024)
    #print(message)
    
           
        
    #-----------------------------------------
    # Response parsing (YOUR CODE)
    # 5.4.1)
    iteration=0; 
    for i in range(0,len(message)):
        if(message[i]==0 and message[i+1]==1 and message[i+2]==0 and message[i+3]==1): #\x00\x01\x00\x01'
            iteration=iteration+1;
            if(iteration==3): #Based on wireshark observations
                ipAdress=[i+10,i+14]
    print("Ip-adress of ",url_to_query,'is: ')            
    for i in range(ipAdress[0],ipAdress[1]):
        print(message[i],end='.')

    #-----------------------------------------
        
except:
#-----------------------------------------
# Exception handling
#-----------------------------------------
    print('A timeout has occured, no reply from the DNS server');

  
     
 
