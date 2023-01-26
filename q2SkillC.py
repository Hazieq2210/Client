import socket

# Create a socket object
ClientSocket = socket.socket()

# Define the host and port
# IP address of the server
host = '192.168.159.128'
port = 8080

# Connect to the server
print('Waiting for a connection')
try:
        ClientSocket.connect((host, port))
except socket.error as e:
        print(str(e))

# Receive the server's welcome message
Response = ClientSocket.recv(1024)
print(Response.decode('utf-8'))

while True:
        # Get the temperature in Fahrenheit from the user
        fahrenheit = int(input("Enter the temperature in Fahrenheit: "))
        # Send the temperature to the server
        ClientSocket.sendall(str.encode(str(fahrenheit)))

        # Receive the converted temperature from the server
        Response = ClientSocket.recv(1024)
        print(Response.decode('utf-8'))

# Close the connection
ClientSocket.close()
