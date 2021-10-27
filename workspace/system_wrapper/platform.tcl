# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/erickof/Documentos/Git/Intro-to-Design-Systems-with-FPGA-Workshop/workspace/system_wrapper/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/erickof/Documentos/Git/Intro-to-Design-Systems-with-FPGA-Workshop/workspace/system_wrapper/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {system_wrapper}\
-hw {/home/erickof/Documentos/Git/Intro-to-Design-Systems-with-FPGA-Workshop/my-system/system_wrapper.xsa}\
-fsbl-target {psu_cortexa53_0} -out {/home/erickof/Documentos/Git/Intro-to-Design-Systems-with-FPGA-Workshop/workspace}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {hello_world}
platform generate -domains 
platform active {system_wrapper}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
platform generate
