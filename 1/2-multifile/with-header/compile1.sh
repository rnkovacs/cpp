#!/usr/bin/env bash

g++ -c main.cpp
g++ -c zup.cpp
g++ main.o zup.o -o zup
