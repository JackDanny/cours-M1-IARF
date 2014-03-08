# the name of the extension
EXTENSION=gis

# a list of external jars the extension needs to build and ship with
EXTERNAL_JARS=jai_codec-1.1.3.jar jai_core-1.1.3.jar jscience-4.2.jar jts-1.9.jar commons-codec-1.3.jar commons-logging-1.1.jar commons-httpclient-3.0.1.jar

# a space separated list of directories to include in the tarball
DISTDIRS=
# a space separated list of files to include in the tarball
DISTFILES=LICENSE.txt

JAVACARGS=-g -deprecation -Xlint:all -Xlint:-serial -Xlint:-fallthrough -encoding us-ascii -source 1.5 -target 1.5
