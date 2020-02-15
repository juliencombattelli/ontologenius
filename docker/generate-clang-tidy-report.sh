#!/bin/bash
catkin_make clean
script -q -e -c catkin_make clang-tidy.txt
cat clang-tidy.txt | grep -oE '\[[a-zA-Z]+(\.|-)[a-zA-Z.-]*\]' | sort | uniq -c | sort | awk '{print; types++; total+=$1} END{print "Types ",types; print "Total ",total}'