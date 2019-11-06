#!/bin/bash

func() {
echo $0; echo $1; echo $2;
echo $#; echo $@; echo $*;
}

func 0 1 2
