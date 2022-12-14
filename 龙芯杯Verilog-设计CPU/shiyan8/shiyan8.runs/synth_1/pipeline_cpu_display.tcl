# 
# Synthesis run script generated by Vivado
# 

set TIME_start [clock seconds] 
proc create_report { reportName command } {
  set status "."
  append status $reportName ".fail"
  if { [file exists $status] } {
    eval file delete [glob $status]
  }
  send_msg_id runtcl-4 info "Executing : $command"
  set retval [eval catch { $command } msg]
  if { $retval != 0 } {
    set fp [open $status w]
    close $fp
    send_msg_id runtcl-5 warning "$msg"
  }
}
set_param chipscope.maxJobs 3
create_project -in_memory -part xc7a200tfbv676-2

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir D:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.cache/wt [current_project]
set_property parent.project_path D:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.xpr [current_project]
set_property XPM_LIBRARIES XPM_MEMORY [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_output_repo d:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
add_files D:/Vivado2019.2/zuchengyuanli/source_code/pipeline_inst/inst_pipeline.coe
add_files -quiet D:/Vivado2019.2/zuchengyuanli/source_code/lcd_module.dcp
set_property used_in_implementation false [get_files D:/Vivado2019.2/zuchengyuanli/source_code/lcd_module.dcp]
read_verilog -library xil_defaultlib {
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/adder.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/alu.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/decode.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/exe.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/fetch.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/inst_rom.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/mem.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/multiply.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/regfile.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/wb.v
  D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu_display.v
}
read_ip -quiet D:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/inst_rom/inst_rom.xci
set_property used_in_implementation false [get_files -all d:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/inst_rom/inst_rom_ooc.xdc]

read_ip -quiet D:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/data_ram/data_ram.xci
set_property used_in_implementation false [get_files -all d:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/data_ram/data_ram_ooc.xdc]

# Mark all dcp files as not used in implementation to prevent them from being
# stitched into the results of this synthesis run. Any black boxes in the
# design are intentionally left as such for best results. Dcp files will be
# stitched into the design at a later time, either when this synthesis run is
# opened, or when it is stitched into a dependent implementation run.
foreach dcp [get_files -quiet -all -filter file_type=="Design\ Checkpoint"] {
  set_property used_in_implementation false $dcp
}
read_xdc D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.xdc
set_property used_in_implementation false [get_files D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.xdc]

read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]
set_param ips.enableIPCacheLiteLoad 1
close [open __synthesis_is_running__ w]

synth_design -top pipeline_cpu_display -part xc7a200tfbv676-2


# disable binary constraint mode for synth run checkpoints
set_param constraints.enableBinaryConstraints false
write_checkpoint -force -noxdef pipeline_cpu_display.dcp
create_report "synth_1_synth_report_utilization_0" "report_utilization -file pipeline_cpu_display_utilization_synth.rpt -pb pipeline_cpu_display_utilization_synth.pb"
file delete __synthesis_is_running__
close [open __synthesis_is_complete__ w]
