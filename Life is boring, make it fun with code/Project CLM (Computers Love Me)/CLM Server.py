from flask import Flask, request, render_template_string
import socket
import threading
from datetime import datetime

app = Flask(__name__)

# Server configuration
HOST = '0.0.0.0'
PORT = 12345
client_socket = None

# HTML UI Template
HTML_TEMPLATE = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Timestamp Scheduler</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background-color: #f4f4f9;
        }
        .container {
            text-align: center;
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        input[type="datetime-local"] {
            padding: 10px;
            font-size: 16px;
            margin-bottom: 20px;
        }
        button {
            padding: 10px 20px;
            font-size: 16px;
            color: white;
            background-color: #007BFF;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        button:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Set Timestamp</h1>
        <form method="POST" action="/set_timestamp">
            <input type="datetime-local" id="timestamp" name="timestamp" required>
            <br>
            <button type="submit">Send</button>
        </form>
    </div>
</body>
</html>
"""

@app.route('/')
def index():
    return render_template_string(HTML_TEMPLATE)

@app.route('/set_timestamp', methods=['POST'])
def set_timestamp():
    global client_socket
    try:
        timestamp = request.form.get('timestamp')  # Get the timestamp from the form
        if not timestamp:
            return "Error: Timestamp is required", 400

        # Validate timestamp
        datetime_obj = datetime.fromisoformat(timestamp)
        print(f"Received timestamp: {timestamp}")

        # Send the timestamp to the client
        if client_socket:
            client_socket.sendall(timestamp.encode('utf-8'))
            return "Timestamp sent to client"
        else:
            return "Error: No client connected", 500
    except Exception as e:
        return f"Error: {str(e)}", 500

def start_socket_server():
    global client_socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen(1)
    print(f"Socket server listening on {HOST}:{PORT}")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Client connected from {addr}")

# Start the socket server in a background thread
threading.Thread(target=start_socket_server, daemon=True).start()

# Start the Flask app
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
