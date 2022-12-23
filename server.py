import socket
import sys


#sock object - to use associated methods(). 
#socket() function returns a socket object
#socket object creation
sock = socket.socket( socket.AF_INET, socket.SOCK_STREAM);

port = 1234
sock.bind(('localhost', port))

sock.listen(5)
try:
    while True:
        #addr bound at the other end of the socket, conn object to send and recv
        conn, addr = sock.accept()
        data = conn.recv(1024)
        while data:
            print (data)
            #conn.recv( bufsize[] ) ret value in bytes. 
            #max amount of data to be rcvd at once is bufsize 
            data = conn.recv(1024)
except KeyboardInterrupt:
       sock.close
