#!/bin/bash

RUNTIMES=`find . -name C`

for i in $RUNTIMES
do
    (cd $i; make)
done



GRAMMARS=`find . -name \*.rng`
JAVA=java
TRANG=Java/jars/trang.jar

for i in $GRAMMARS
do
    echo $i
    o=`echo $i | sed s/rng/rnc/g`
    $JAVA -jar $TRANG -i encoding=utf-8 -o encoding=utf-8 $i $o
done

