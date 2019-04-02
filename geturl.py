# get value to use for local oauth server and app local config in lando env
import json, os, socket
ip = socket.gethostbyname(socket.getfqdn())
os.chdir('./docroot')
landoInfo = json.loads(os.popen('lando info').read())
port = landoInfo['appserver']['urls'][1].split(':')[2]
print 'http://' + ip + ':' + port
