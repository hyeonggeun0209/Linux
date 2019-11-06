#!/bin/bash

echo "select option 1-3: "
echo "1: start server"
echo "2: stop server"
echo "3: resume server"

read opt
case "$opt" in
1) STATUS="started" ;;
2) STATUS="stopped" ;;
3) STATUS="resumed" ;;
*) STATUS="with invalid option" ;;
esac

echo "the server $STATUS"
