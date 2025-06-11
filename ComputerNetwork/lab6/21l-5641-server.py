# -*- coding: utf-8 -*-

import socket

def main():
    # Define server address and port
    server_ip = '127.0.0.1'
    server_port = 2000

    # Create UDP socket
    try:
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        udp_socket.bind((server_ip, server_port))
        print("Socket Created and Bound")
    except socket.error as err:
        print("Could not create or bind socket. Error: {}".format(err))
        return

    print("Listening for Messages...\n")
    server = True
    database = []

    while server:
        # Receive the message from the client
        try:
            client_message, client_address = udp_socket.recvfrom(2000)
            client_ip, client_port = client_address
            print("Received Message from IP: {0} and Port No: {1}".format(client_ip, client_port))
            message = client_message.decode()
            m1 = message.split("-")
            if len(m1) == 3 and len(m1[0]) == 2 and len(m1[1]) == 4 and len(m1[2]) == 2:
                check = m1[0] + "-" + m1[1]
                if check not in database:
                    print("Welcome Student ", check)
                    database.append(check)
                    print(check)
                    print("Now Total students in database \n : {0}".format(database))
                else:
                    print("You are already here")
                    print("Total students in database \n : {0}".format(database))
            elif len(m1) == 3 and len(m1[0]) == 2 and len(m1[1]) == 7 and len(m1[2]) == 2:
                m1[1] = m1[1].strip()
                check = m1[0] + "-" + m1[1]
                if check not in database:
                    print("You didn't check in today. Contact System Administrator.")
                else:
                    database.remove(check)
                    print("GoodBye Student {0} ! Have a nice day.".format(check))
                    print("Total students in database \n : {0}".format(database))
            else:
                print("The format you entered for check in and check out is incorrect")
                print("Total students in database \n : {0}".format(database))
        except socket.error as err:
            print("Receive Failed. Error: {0}".format(err))
            return

    # Close the socket
    udp_socket.close()

if __name__ == "__main__":
    main()
