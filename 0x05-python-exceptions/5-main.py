#!/usr/bin/python3

from 5-raise_exception import raise_exception

try:
    raise_exception()
except TypeError as te:
    print("Exception raised")

