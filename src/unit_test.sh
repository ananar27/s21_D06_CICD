#!/bin/bash

if [[ ${2} == "1" ]] && [[ $CI_JOB_STATUS == "success" ]]
then
exit
fi