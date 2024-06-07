############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project InsertionSort
set_top group3
add_files insertion.h
add_files insertion.c
add_files -tb insertionTb.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7z010-clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -output E:/USN_Education/VitisCode/InsertionSort/VIVADO_IP_Zip_File -rtl verilog
source "./InsertionSort/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -rtl verilog -format ip_catalog -output E:/USN_Education/VitisCode/InsertionSort/VIVADO_IP_Zip_File
