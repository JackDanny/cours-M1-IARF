#!/bin/sh
cd "`dirname "$0"`"		# the copious quoting is for handling paths with spaces
# -server                       use server VM for highest performance
# -Djava.library.path=./lib     ensure JOGL can find native libraries 
# -Djava.ext.dirs=              ignore any existing JOGL installation
# -XX:MaxPermSize=128m          avoid OutOfMemory errors for large models
# -Xmx1024m                     use up to 1GB RAM (edit to increase)
# -jar NetLogo.jar              specify main jar
# "$@"                          pass along any command line arguments
java -server -Djava.library.path=./lib -Djava.ext.dirs= -XX:MaxPermSize=128m -Xmx1024m -Duser.language=en -Duser.country=US -jar NetLogo.jar "$@"
