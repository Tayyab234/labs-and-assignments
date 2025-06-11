import socket

def main():
    # Define server address and port
    server_ip = '127.0.0.1'
    server_port = 2000
    
    # Create UDP socket
    try:
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        print("Socket Created")
    except socket.error as err:
        print("Could not create socket. Error: %s" % err)
        return
    
    try:
        # Get input from user
        client_message = input("Enter Message: ")
        
        # Send the message to the server
        try:
            udp_socket.sendto(client_message.encode(), (server_ip, server_port))
        except socket.error as err:
            print("Send Failed. Error: %s" % err)
            return


    finally:
        # Ensure the socket is closed
        udp_socket.close()
        print("Socket Closed")

if __name__ == "__main__":
    main()
