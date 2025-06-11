import socket

def main():
    # Define server address and port
    server_ip = '127.0.0.1'
    server_port = 2000

    # Create TCP socket
    try:
        tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("Socket Created")
    except socket.error as err:
        print(f"Could not create socket. Error: {err}")
        return

    # Connect to the server
    try:
        tcp_socket.connect((server_ip, server_port))
        print("Connected to server")
    except socket.error as err:
        print(f"Connection Failed. Error: {err}")
        return

    # Get input from user
    h1 = input("Please enter your name: ")
    h2 = input("Please enter your CNIC: ")
    client_message = h1 + "/" + h2

    # Send the message to the server
    try:
        tcp_socket.send(client_message.encode())

        while True:
            r1 = tcp_socket.recv(1024).decode()
            if not r1:  # If no data is received, exit loop
                break
            print(r1)

        h3 = input()  # Get candidate symbol input from user
        tcp_socket.send(h3.encode())

    except socket.error as err:
        print(f"Send Failed. Error: {err}")
        return

    # Receive the response from the server
    try:
        response_message = tcp_socket.recv(1024).decode()
        print(f"Server Response: {response_message}")
    except socket.error as err:
        print(f"Receive Failed. Error: {err}")

    # Close the socket
    tcp_socket.close()

if __name__ == "__main__":
    main()