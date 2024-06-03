#!/bin/bash

scp cat/s21_cat raffordg@192.168.100.11:/usr/local/bin/
scp grep/s21_grep raffordg@192.168.100.11:/usr/local/bin/

ssh raffordg@192.168.100.11 ls -lah /usr/local/bin/
