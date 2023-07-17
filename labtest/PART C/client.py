import socket

def main():
    server_ip = '197.1.0.1'
    server_port = 8040

    # Create socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Prompt user for a number
    number = int(input("Enter a number: "))

    # Send number to server
    sock.sendto(str(number).encode(), (server_ip, server_port))

    # Receive result from server
    data, server_address = sock.recvfrom(1024)
    result = data.decode()

    print("Result from server: {}".format(result))

if name == 'main':
    main()
