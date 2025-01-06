from flask import Flask, request, render_template_string
import socket
import threading

app = Flask(__name__)

# Server configuration
HOST = '0.0.0.0'
PORT = 12345
clients = []  # List to store connected clients

# HTML Template with Date-Time Picker
HTML_TEMPLATE = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Server Control</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f9f9f9;
        }
        .container {
            max-width: 600px;
            margin: 0 auto;
            padding: 20px;
            background: white;
            border-radius: 8px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        h1 {
            text-align: center;
        }
        input, button {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ccc;
            border-radius: 4px;
            font-size: 16px;
        }
        button {
            background-color: #007BFF;
            color: white;
            border: none;
            cursor: pointer;
        }
        button:hover {
            background-color: #0056b3;
        }
        .danger {
            background-color: #FF4136;
        }
        .danger:hover {
            background-color: #B22222;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Server Control Panel</h1>
        <form method="POST" action="/send_command">
            <label for="datetime">Select Date and Time:</label>
            <input type="datetime-local" id="datetime" name="command" required>
            <button type="submit">Send Timestamp</button>
        </form>
        <form method="POST" action="/send_command">
            <input type="hidden" name="command" value="self-destruct">
            <button type="submit" class="danger">Self-Destruct</button>
        </form>
    </div>
</body>
</html>
"""

@app.route('/')
def index():
    """Serves the HTML control panel."""
    return render_template_string(HTML_TEMPLATE)

@app.route('/send_command', methods=['POST'])
def send_command():
    """Handles the sending of commands to all connected clients."""
    global clients
    command = request.form.get('command')
    if not command:
        return "Error: Command is required", 400

    # Send the command to all connected clients
    disconnected_clients = []
    for client in clients:
        try:
            client.sendall(command.encode('utf-8'))
        except Exception as e:
            print(f"Error sending to client: {e}")
            disconnected_clients.append(client)

    # Remove disconnected clients from the list
    clients = [client for client in clients if client not in disconnected_clients]

    return f"Command '{command}' sent successfully to {len(clients)} clients."

def handle_client(client_socket, addr):
    """Handles communication with a single client."""
    print(f"New client connected from {addr}")
    while True:
        try:
            data = client_socket.recv(1024)
            if not data:
                break
            print(f"Received from {addr}: {data.decode('utf-8')}")
        except Exception as e:
            print(f"Error with client {addr}: {e}")
            break
    print(f"Client {addr} disconnected.")
    clients.remove(client_socket)
    client_socket.close()

def start_socket_server():
    """Socket server to handle multiple client connections."""
    global clients
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen(5)
    print(f"Socket server listening on {HOST}:{PORT}")

    while True:
        client_socket, addr = server_socket.accept()
        clients.append(client_socket)
        threading.Thread(target=handle_client, args=(client_socket, addr), daemon=True).start()

# Start the socket server in a background thread
threading.Thread(target=start_socket_server, daemon=True).start()

# Start the Flask app
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
