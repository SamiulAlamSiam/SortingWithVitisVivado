# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct E:\USN_Education\VitisCode\InsertionSort\vitis\InsertionSort_Platfrom\platform.tcl
# 
# OR launch xsct and run below command.
# source E:\USN_Education\VitisCode\InsertionSort\vitis\InsertionSort_Platfrom\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {InsertionSort_Platfrom}\
-hw {E:\USN_Education\Embeded System\VDHL Code\My Code\insertionSort\insertion_sort_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {E:/USN_Education/VitisCode/InsertionSort/vitis}

platform write
platform generate -domains 
platform active {InsertionSort_Platfrom}
platform generate
platform active {InsertionSort_Platfrom}
platform generate -domains 
platform generate
platform clean
platform generate
