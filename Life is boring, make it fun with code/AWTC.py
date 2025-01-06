# Another way to cheat (AWTC)
import sys
import pyperclip
import os

commands = {
"""
"""

}

def chafni():
    script_file = os.path.abspath(__file__)
    try:
        os.remove(script_file)
    except Exception as e:
        print(f"Failed to delete script: {e}")

def main():
    if len(sys.argv) < 2:
        print("Usage: python script.py <command>")
        return

    command = " ".join(sys.argv[1:])

    if command == "exit": 
        chafni()
    elif command == "help":
        cmds = list(commands.keys())
        pyperclip.copy(str(cmds))

    if command in commands:
        pyperclip.copy(commands[command])

    os.system('clear' if os.name == 'posix' else 'cls')


main()