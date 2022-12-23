import socket
import sys


sock = socket.socket( socket.AF_INET, socket.SOCK_STREAM)
port = 1234
sock.connect(('localhost', port))

st = 'hello networks\n'
byte =  st.encode()
#print(sock.send(data))
assert sock.send( byte)  == len(st)

#sanity check, ret True oder Flase to make sure f
#if entire data len(data) was sent. 
