from flask import Flask, request, jsonify
import threading

app = Flask(__name__)

# Dictionary to hold the users and their messages
users = {}
messages = []

# A lock to synchronize access to the shared resource 'messages'
message_lock = threading.Lock()

@app.route('/connect', methods=['POST'])
def connect():
    username = request.json.get('username')
    if not username:
        return jsonify({"error": "Username is required"}), 400

    users[username] = []
    return jsonify({"message": f"Welcome {username}!"})

@app.route('/send_message', methods=['POST'])
def send_message():
    username = request.json.get('username')
    message = request.json.get('message')

    if not username or not message:
        return jsonify({"error": "Username and message are required"}), 400

    with message_lock:
        messages.append(f"{username}: {message}")
        # Store the message in the user's message list
        if username in users:
            users[username].append(message)

    return jsonify({"message": "Message sent!"})

@app.route('/get_messages', methods=['GET'])
def get_messages():
    with message_lock:
        return jsonify({"messages": messages})

@app.route('/get_user_messages', methods=['GET'])
def get_user_messages():
    username = request.args.get('username')
    if not username or username not in users:
        return jsonify({"error": "Invalid username"}), 400

    return jsonify({"messages": users[username]})

def run_flask():
    # Use 'threaded=True' to allow multiple requests at once
    app.run(debug=True, host='0.0.0.0', port=5000, use_reloader=False)

if __name__ == "__main__":
    # Run the Flask server in a separate thread
    server_thread = threading.Thread(target=run_flask)
    server_thread.daemon = True
    server_thread.start()

    print("Server is running at http://localhost:5000")
    server_thread.join()  # Keep the server running
