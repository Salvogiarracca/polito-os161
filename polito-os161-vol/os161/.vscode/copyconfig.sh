#!/bin/bash

# $1 => oldConfigName
# $2 => HOME
# $3 => newConfigName

newPath="\${env:HOME}/os161/src/kern/compile/$3"

cp "$2/os161/src/kern/conf/$1" "$2/os161/src/kern/conf/$3"

jq ".configurations[0].includePath += [\"$newPath\"]" "$2/os161/.vscode/c_cpp_properties.json" > tmp.json 

mv tmp.json "$2/os161/.vscode/c_cpp_properties.json"

exit 0
