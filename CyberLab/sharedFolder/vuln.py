import os

file_path = b"""
<?php
	echo "yeah";                                                                                                                                                                              
?>                                                                                                                                                                                                               

"""

with open("f.php.png", "wb") as f:
    f.write(b'\x89PNG\r\n\x1a\n' + file_path)
