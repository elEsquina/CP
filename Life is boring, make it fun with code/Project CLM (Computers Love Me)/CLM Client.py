import socket
import threading
import os
import sys
from datetime import datetime
import pygame

# Client configuration
HOST = '127.0.0.1'  # Server's IP address
PORT = 12345  # Server's port
MP3_FILE = 'sound.mp3'  # Replace with the path to your MP3 file
SELF_DESTRUCT_FILE = __file__  # The current script file to self-destruct

def handle_server_commands(sock):
    """Handles incoming commands from the server."""
    while True:
        try:
            data = sock.recv(1024).decode('utf-8')
            if not data:
                break

            print(f"Received command: {data}")
            if data.strip() == "self-destruct":
                initiate_self_destruct()
            else:
                try:
                    timestamp = datetime.fromisoformat(data)
                    schedule_playback(timestamp)
                except ValueError:
                    print("Invalid timestamp format. Ignoring command.")
        except Exception as e:
            print(f"Error: {e}")
            break

def schedule_playback(timestamp):
    """Schedules playback of the MP3 file at the specified timestamp."""
    now = datetime.now()
    delay = (timestamp - now).total_seconds()
    if delay > 0:
        print(f"Scheduled to play MP3 at {timestamp}")
        threading.Timer(delay, play_mp3).start()
    else:
        print("Timestamp is in the past. Ignoring command.")

def play_mp3():
    """Plays the MP3 file using pygame."""
    print("Playing MP3 file...")
    pygame.mixer.init()
    pygame.mixer.music.load(MP3_FILE)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        pass  # Wait for the music to finish playing

def initiate_self_destruct():
    """Deletes the script file (self-destruct)."""
    try:
        print(f"Self-destruct initiated. Deleting file: {SELF_DESTRUCT_FILE}")
        os.remove(SELF_DESTRUCT_FILE)
        print("File successfully deleted. Exiting program.")
        sys.exit(0)  # Exit the program
    except Exception as e:
        print(f"Error during self-destruct: {e}")

def main():
    """Main function to connect to the server and handle commands."""
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((HOST, PORT))
        print("Connected to server.")
        handle_server_commands(sock)

if __name__ == '__main__':
    main()
