import socket

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

    while True:
        # Accept a client connection
        client_socket, client_address = tcp_socket.accept()
        print(f"Connection established with {client_address[0]} on port {client_address[1]}")

        # Receive message from the client
        try:
            client_message = client_socket.recv(1024).decode()
            vowels = set('AEIOUaeiou')
            if client_message == "100":
                break
            words = client_message.split()
            new_message = []
            for word in words:
                if any(char1 in vowels for char1 in word):
                    new_message.append(word[:-1] + " ")
                else:
                    new_message.append(word + " ")
            new_message = ''.join(new_message)  # Convert list to string
            print(f"Received Message from Client: {client_message}")
            print("After applying conditions: ", new_message)
        except socket.error as err:
            print(f"Receive Failed. Error: {err}")

        # Send a response back to the client
        try:
            response_message = new_message
            client_socket.send(response_message.encode())
        except socket.error as err:
            print(f"Send Failed. Error: {err}")
        finally:
            client_socket.close()

    # Close the server socket
    tcp_socket.close()

if __name__ == "__main__":
    main()
