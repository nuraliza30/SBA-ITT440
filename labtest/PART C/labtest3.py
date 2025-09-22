import socket
import sys

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def main():
    server_ip = '197.1.0.1'
    server_port = 8040

    # Create socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Bind socket to address
    server_address = (server_ip, server_port)
    sock.bind(server_address)

    print("Server is listening on {}:{}".format(server_ip, server_port))

    while True:
        # Receive number from client
        data, client_address = sock.recvfrom(1024)
        number = int(data.decode())

        print("Received number from client: {}".format(number))

        # Check if number is prime
        result = is_prime(number)

        # Send result back to client
        message = "Prime" if result else "Not Prime"
        sock.sendto(message.encode(), client_address)

        print("Sent result to client: {}".format(message))

if name == 'main':
    main()
