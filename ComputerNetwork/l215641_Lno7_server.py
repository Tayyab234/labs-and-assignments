import socket
import os
def main():
    # Define server address and port
    server_ip = '127.0.0.1'
    server_port = 2000  # Define the server port

    # Create TCP socket
    try:
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        tcp_socket.bind((server_ip, server_port))
        tcp_socket.listen(1)  # Listen for incoming connections
        print("Server is listening for connections...\n")
    except socket.error as err:
        print(f"Could not create or bind socket. Error: {err}")
        return
    k=True
    while k:
       # Accept a client connection
       client_socket, client_address = tcp_socket.accept()
       print(f"Connection established with {client_address[0]} on port {client_address[1]}")
      
       # Receive message from the client
       try:
           file_name = client_socket.recv(1024).decode()
           print(f"Received Message from Client: {file_name}")
            #Check if the file exists
           if os.path.isfile(file_name):
                # Send the file in chunks
                with open(file_name, 'rb') as file:
                    while True:
                        chunk = file.read(1024)  # Read in 1024 byte chunks
                        if not chunk:
                            break  # End of file reached
                        client_socket.send(chunk)  # Send the chunk to the client
                
                print(f"File '{file_name}' sent successfully.")
           else:
                error_message = f"Error: File '{file_name}' does not exist."
                client_socket.send(error_message.encode())
                #print(error_message)
           
       except socket.error as err:
           print(f"Receive Failed. Error: {err}")

       # Send a response back to the client
       try:
           response_message = "Message received!"
           client_socket.send(response_message.encode())
       except socket.error as err:
           print(f"Send Failed. Error: {err}")
       client_socket.close()


    tcp_socket.close()

if __name__ == "__main__":
    main()
