import socket
import time
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
    client_message = input("Enter the name of the file : ")

    # Send the message to the server
    try:
        tcp_socket.send(client_message.encode())
    except socket.error as err:
        print(f"Send Failed. Error: {err}")
        return

    # Receive the response from the server
    try:
        with open('output1','wb') as file1:
           while True:
                # Receive data in chunks
               chunk = tcp_socket.recv(1024)
               if not chunk:
                    break  # End of file reached
               file1.write(chunk)
               time.sleep(6)
               print(chunk.decode())
            
      
    except socket.error as err:
        print(f"Receive Failed. Error: {err}")
   # finally:
        # Check if an error message was received
    #    if chunk and b'Error:' in chunk:
     #       error_message = chunk.decode()
      #      print(f"Server Response: {error_message}")

    # Close the socket
    tcp_socket.close()

if __name__ == "__main__":
    main()
