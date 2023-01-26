import socket

# Create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server using its IP address and port
client.connect(("192.168.159.128", 8888))

# Receive data from the server
response = client.recv(4096).decode()

# Print the received data
print(response)

# Close the connection
client.close()
