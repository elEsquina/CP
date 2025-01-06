import sys
import shutil
import os

# Directory containing the files
SOURCE_DIR = ".."

# Ensure the source directory exists
if not os.path.exists(SOURCE_DIR):
    os.makedirs(SOURCE_DIR)

# Generate commands from the files in the directory
commands = {file: os.path.join(SOURCE_DIR, file) for file in os.listdir(SOURCE_DIR) if os.path.isfile(os.path.join(SOURCE_DIR, file))}

def chafni():
    """Deletes the current script file."""
    script_file = os.path.abspath(__file__)
    try:
        os.remove(script_file)
    except Exception as e:
        print(f"Failed to delete script: {e}")

def main():
    """Main function to process commands."""
    if len(sys.argv) < 2:
        print("Usage: python script.py <command>")
        return

    command = " ".join(sys.argv[1:])

    if command == "exit":
        chafni()
    elif command == "help":
        cmds = list(commands.keys())
        print("Available commands:")
        print(cmds)
        return
    elif command in commands:
        source_path = commands[command]
        destination_path = os.path.join(os.getcwd(), command)

        try:
            shutil.copy(source_path, destination_path)
            print(f"Copied {command} to {os.getcwd()}")
        except Exception as e:
            print(f"Failed to copy {command}: {e}")
    else:
        print(f"Command '{command}' not found.")

    os.system('clear' if os.name == 'posix' else 'cls')

if __name__ == "__main__":
    main()
