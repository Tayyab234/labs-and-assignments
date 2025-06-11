import socket

def main():
    # Define server address and port
    server_ip = '127.0.0.1'
    server_port = 2000

    # Create TCP socket
    try:
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        tcp_socket.bind((server_ip, server_port))
        tcp_socket.listen(1)  # Listen for incoming connections
        print("Server is listening for connections...\n")
    except socket.error as err:
        print(f"Could not create or bind socket. Error: {err}")
        return

    database = list()

    # Accept a client connection
    while True:
        try:
            client_socket, client_address = tcp_socket.accept()
            print(f"Connection established with {client_address[0]} on port {client_address[1]}")

            # Receive message from the client
            client_message = client_socket.recv(1024).decode()
            print(f"Received Message from Client: {client_message}")

            with open('Voters_List.txt', 'r') as f:
                k = f.readline()
                check = False

                if client_message not in database:
                    database.append(client_message)
                else:
                    r1 = "Client already cast the vote."
                    client_socket.send(r1.encode())
                    continue  # Skip further processing for this client
                l1 = client_message.split('/')
                while k:
                    l2 = k.split('/')
                    if l1[0].lower() == l2[0].lower() and l1[1] == l2[1]:
                        check = True
                        with open('Candidates_List.txt', 'r') as f1:
                            r1 = f1.read()
                            r1 += "\nPlease enter the symbol name of candidate which you want to cast vote: "
                            client_socket.send(r1.encode())
                            c2 = client_socket.recv(1024).decode()
                            client_message += " vote cast to: " + c2
                            with open('output.txt', 'a') as f2:  # Append mode
                                f2.write(client_message + '\n')
                        break  # Exit loop after processing valid input
                    k = f.readline()

                if not check:
                    r1 = "Details do not match. Error."
                    client_socket.send(r1.encode())

            # Send a response back to the client
            response_message = "Details have been saved in file. Thank you for casting your vote."
            client_socket.send(response_message.encode())
            client_socket.close()

        except socket.error as err:
            print(f"Socket error: {err}")
            if 'client_socket' in locals():
                client_socket.close()

    tcp_socket.close()

if __name__ == "__main__":
    main()