import requests

SERVER_URL = "http://192.168.0.105:5000"

def connect_user(username):
    """Connect to the server with a given username."""
    response = requests.post(f"{SERVER_URL}/connect", json={"username": username})
    if response.status_code == 200:
        print(response.json()["message"])
    else:
        print(response.json()["error"])

def send_message(username, message):
    """Send a message to the server."""
    response = requests.post(f"{SERVER_URL}/send_message", json={"username": username, "message": message})
    if response.status_code == 200:
        print(response.json()["message"])
    else:
        print(response.json()["error"])

def get_messages():
    """Retrieve all messages from the server."""
    response = requests.get(f"{SERVER_URL}/get_messages")
    if response.status_code == 200:
        messages = response.json()["messages"]
        print("All Messages:")
        for msg in messages:
            print("\n===========================")
            print(msg)
            print("\n===========================")

    else:
        print(response.json()["error"])

def get_user_messages(username):
    """Retrieve messages for a specific user."""
    response = requests.get(f"{SERVER_URL}/get_user_messages", params={"username": username})
    if response.status_code == 200:
        messages = response.json()["messages"]
        print(f"Messages for {username}:")
        for msg in messages:
            print(msg)
    else:
        print(response.json()["error"])

def chat_interface():
    """Interactive chat interface for the client."""
    username = input("Enter your username: ")
    connect_user(username)

    while True:
        print("\nOptions:")
        print("1. Send Message")
        print("2. View All Messages")
        print("3. View My Messages")
        print("4. Exit")
        choice = input("Select an option: ")

        if choice == '1':
            print("Enter your message (type 'END' on a new line to finish):")
            lines = []
            while True:
                line = input()
                if line == "END":
                    break
                lines.append(line)
            message = "\n".join(lines)
            send_message(username, message)

        elif choice == '2':
            get_messages()

        elif choice == '3':
            get_user_messages(username)

        elif choice == '4':
            print("Exiting...")
            break

        else:
            print("Invalid option. Please try again.")

if __name__ == "__main__":
    chat_interface()
