#!/bin/env bash

CC=gcc
FLAGS="-Wall -Wextra"
MAIN="cwaifu"

$CC $FLAGS $MAIN.c -o $MAIN
