from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer

# Create a dummy authorizer for managing 'virtual' users
authorizer = DummyAuthorizer()

# Define a user with a password and a specific directory
authorizer.add_user("user", "password", "./", perm="elradfmw")

# Instantiate an FTP handler object
handler = FTPHandler
handler.authorizer = authorizer

# Specify the host and port to listen on
server = FTPServer(("0.0.0.0", 20), handler)

# Start the FTP server
server.serve_forever()
