
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2$
create_project: 2default:default2
00:00:022default:default2
00:00:072default:default2
305.0472default:default2
9.3442default:defaultZ17-268h px? 
?
Command: %s
53*	vivadotcl2Q
=synth_design -top pipeline_cpu_display -part xc7a200tfbv676-22default:defaultZ4-113h px? 
:
Starting synth_design
149*	vivadotclZ4-321h px? 
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2
xc7a200t2default:defaultZ17-347h px? 
?
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2
xc7a200t2default:defaultZ17-349h px? 
W
Loading part %s157*device2$
xc7a200tfbv676-22default:defaultZ21-403h px? 
?
,overwriting previous definition of module %s2490*oasys2
inst_rom2default:default2Y
CD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/inst_rom.v2default:default2
392default:default8@Z8-2490h px? 
?
.identifier '%s' is used before its declaration4750*oasys2

multiplier2default:default2Y
CD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/multiply.v2default:default2
192default:default8@Z8-6901h px? 
?
%s*synth2?
xStarting RTL Elaboration : Time (s): cpu = 00:00:05 ; elapsed = 00:00:14 . Memory (MB): peak = 904.785 ; gain = 240.918
2default:defaulth px? 
?
synthesizing module '%s'%s4497*oasys2(
pipeline_cpu_display2default:default2
 2default:default2e
OD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu_display.v2default:default2
82default:default8@Z8-6157h px? 
?
synthesizing module '%s'%s4497*oasys2
BUFGCE2default:default2
 2default:default2Q
;D:/Vivado2019.2/Vivado/2019.2/scripts/rt/data/unisim_comp.v2default:default2
10852default:default8@Z8-6157h px? 
^
%s
*synth2F
2	Parameter CE_TYPE bound to: SYNC - type: string 
2default:defaulth p
x
? 
V
%s
*synth2>
*	Parameter IS_CE_INVERTED bound to: 1'b0 
2default:defaulth p
x
? 
U
%s
*synth2=
)	Parameter IS_I_INVERTED bound to: 1'b0 
2default:defaulth p
x
? 
g
%s
*synth2O
;	Parameter SIM_DEVICE bound to: ULTRASCALE - type: string 
2default:defaulth p
x
? 
d
%s
*synth2L
8	Parameter STARTUP_SYNC bound to: FALSE - type: string 
2default:defaulth p
x
? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
BUFGCE2default:default2
 2default:default2
12default:default2
12default:default2Q
;D:/Vivado2019.2/Vivado/2019.2/scripts/rt/data/unisim_comp.v2default:default2
10852default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2 
pipeline_cpu2default:default2
 2default:default2]
GD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.v2default:default2
92default:default8@Z8-6157h px? 
?
synthesizing module '%s'%s4497*oasys2
fetch2default:default2
 2default:default2V
@D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/fetch.v2default:default2
92default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
fetch2default:default2
 2default:default2
22default:default2
12default:default2V
@D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/fetch.v2default:default2
92default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
decode2default:default2
 2default:default2W
AD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/decode.v2default:default2
82default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
decode2default:default2
 2default:default2
32default:default2
12default:default2W
AD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/decode.v2default:default2
82default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
exe2default:default2
 2default:default2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/exe.v2default:default2
82default:default8@Z8-6157h px? 
?
synthesizing module '%s'%s4497*oasys2
alu2default:default2
 2default:default2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/alu.v2default:default2
82default:default8@Z8-6157h px? 
?
synthesizing module '%s'%s4497*oasys2
adder2default:default2
 2default:default2V
@D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/adder.v2default:default2
82default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
adder2default:default2
 2default:default2
42default:default2
12default:default2V
@D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/adder.v2default:default2
82default:default8@Z8-6155h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
alu2default:default2
 2default:default2
52default:default2
12default:default2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/alu.v2default:default2
82default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
multiply2default:default2
 2default:default2Y
CD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/multiply.v2default:default2
82default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
multiply2default:default2
 2default:default2
62default:default2
12default:default2Y
CD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/multiply.v2default:default2
82default:default8@Z8-6155h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
exe2default:default2
 2default:default2
72default:default2
12default:default2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/exe.v2default:default2
82default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
mem2default:default2
 2default:default2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/mem.v2default:default2
82default:default8@Z8-6157h px? 
?
default block is never used226*oasys2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/mem.v2default:default2
892default:default8@Z8-226h px? 
?
default block is never used226*oasys2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/mem.v2default:default2
1072default:default8@Z8-226h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
mem2default:default2
 2default:default2
82default:default2
12default:default2T
>D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/mem.v2default:default2
82default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
wb2default:default2
 2default:default2S
=D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/wb.v2default:default2
102default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
wb2default:default2
 2default:default2
92default:default2
12default:default2S
=D:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/wb.v2default:default2
102default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
inst_rom2default:default2
 2default:default2Y
CD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/inst_rom.v2default:default2
392default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
inst_rom2default:default2
 2default:default2
102default:default2
12default:default2Y
CD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/inst_rom.v2default:default2
392default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
regfile2default:default2
 2default:default2X
BD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/regfile.v2default:default2
82default:default8@Z8-6157h px? 
?
+Unused sequential element %s was removed. 
4326*oasys2
	rf_reg[0]2default:default2X
BD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/regfile.v2default:default2
312default:default8@Z8-6014h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
regfile2default:default2
 2default:default2
112default:default2
12default:default2X
BD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/regfile.v2default:default2
82default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2
data_ram2default:default2
 2default:default2?
uD:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/.Xil/Vivado-24496-DESKTOP-RIQG005/realtime/data_ram_stub.v2default:default2
62default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2
data_ram2default:default2
 2default:default2
122default:default2
12default:default2?
uD:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/.Xil/Vivado-24496-DESKTOP-RIQG005/realtime/data_ram_stub.v2default:default2
62default:default8@Z8-6155h px? 
?
Kinstance '%s' of module '%s' has %s connections declared, but only %s given4757*oasys2#
data_ram_module2default:default2
data_ram2default:default2
112default:default2
102default:default2]
GD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.v2default:default2
3302default:default8@Z8-7023h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2 
pipeline_cpu2default:default2
 2default:default2
132default:default2
12default:default2]
GD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.v2default:default2
92default:default8@Z8-6155h px? 
?
synthesizing module '%s'%s4497*oasys2

lcd_module2default:default2
 2default:default2?
wD:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/.Xil/Vivado-24496-DESKTOP-RIQG005/realtime/lcd_module_stub.v2default:default2
62default:default8@Z8-6157h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2

lcd_module2default:default2
 2default:default2
142default:default2
12default:default2?
wD:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/.Xil/Vivado-24496-DESKTOP-RIQG005/realtime/lcd_module_stub.v2default:default2
62default:default8@Z8-6155h px? 
?
'done synthesizing module '%s'%s (%s#%s)4495*oasys2(
pipeline_cpu_display2default:default2
 2default:default2
152default:default2
12default:default2e
OD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu_display.v2default:default2
82default:default8@Z8-6155h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[31]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[30]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[29]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[28]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[27]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[26]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[25]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[24]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[23]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[22]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[21]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[20]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[19]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[18]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[17]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[16]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[15]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[14]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[13]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[12]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[11]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[10]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2
mem_addr[1]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2
mem_addr[0]2default:defaultZ8-3331h px? 
?
%s*synth2?
xFinished RTL Elaboration : Time (s): cpu = 00:00:06 ; elapsed = 00:00:16 . Memory (MB): peak = 961.367 ; gain = 297.500
2default:defaulth px? 
D
%s
*synth2,

Report Check Netlist: 
2default:defaulth p
x
? 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
? 
u
%s
*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth p
x
? 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
? 
u
%s
*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth p
x
? 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
M
%s
*synth25
!Start Handling Custom Attributes
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Handling Custom Attributes : Time (s): cpu = 00:00:07 ; elapsed = 00:00:18 . Memory (MB): peak = 961.367 ; gain = 297.500
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished RTL Optimization Phase 1 : Time (s): cpu = 00:00:07 ; elapsed = 00:00:18 . Memory (MB): peak = 961.367 ; gain = 297.500
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.2192default:default2
961.3672default:default2
0.0002default:defaultZ17-268h px? 
?
?The value of SIM_DEVICE on instance '%s' of type '%s' is '%s'; it is being changed to match the current FPGA architecture, '%s'. For functional simulation to match hardware behavior, the value of SIM_DEVICE should be changed in the source netlist. %s369*netlist2

cpu_clk_cg2default:default2
BUFGCE2default:default2

ULTRASCALE2default:default2
7SERIES2default:default2

2default:defaultZ29-345h px? 
e
-Analyzing %s Unisim elements for replacement
17*netlist2
12default:defaultZ29-17h px? 
?
?The value of SIM_DEVICE on instance '%s' of type '%s' is '%s'; it is being changed to match the current FPGA architecture, '%s'. For functional simulation to match hardware behavior, the value of SIM_DEVICE should be changed in the source netlist. %s369*netlist2

cpu_clk_cg2default:default2
BUFGCTRL2default:default2

ULTRASCALE2default:default2
7SERIES2default:default2

2default:defaultZ29-345h px? 
j
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px? 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px? 
>

Processing XDC Constraints
244*projectZ1-262h px? 
=
Initializing timing engine
348*projectZ1-569h px? 
?
$Parsing XDC File [%s] for cell '%s'
848*designutils2?
nd:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/inst_rom/inst_rom/blk_mem_gen_1_in_context.xdc2default:default2)
cpu/inst_rom_module	2default:default8Z20-848h px? 
?
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2?
nd:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/inst_rom/inst_rom/blk_mem_gen_1_in_context.xdc2default:default2)
cpu/inst_rom_module	2default:default8Z20-847h px? 
?
$Parsing XDC File [%s] for cell '%s'
848*designutils2
id:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/data_ram/data_ram/data_ram_in_context.xdc2default:default2)
cpu/data_ram_module	2default:default8Z20-848h px? 
?
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2
id:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.srcs/sources_1/ip/data_ram/data_ram/data_ram_in_context.xdc2default:default2)
cpu/data_ram_module	2default:default8Z20-847h px? 
?
Parsing XDC File [%s]
179*designutils2_
ID:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.xdc2default:default8Z20-179h px? 
?
Finished Parsing XDC File [%s]
178*designutils2_
ID:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.xdc2default:default8Z20-178h px? 
?
?Implementation specific constraints were found while reading constraint file [%s]. These constraints will be ignored for synthesis but will be used in implementation. Impacted constraints are listed in the file [%s].
233*project2]
ID:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu.xdc2default:default2:
&.Xil/pipeline_cpu_display_propImpl.xdc2default:defaultZ1-236h px? 
?
Parsing XDC File [%s]
179*designutils2_
ID:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/dont_touch.xdc2default:default8Z20-179h px? 
?
Finished Parsing XDC File [%s]
178*designutils2_
ID:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/dont_touch.xdc2default:default8Z20-178h px? 
H
&Completed Processing XDC Constraints

245*projectZ1-263h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0012default:default2
1081.7812default:default2
0.0002default:defaultZ17-268h px? 
?
!Unisim Transformation Summary:
%s111*project2a
M  A total of 1 instances were transformed.
  BUFGCE => BUFGCTRL: 1 instance 
2default:defaultZ1-111h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common24
 Constraint Validation Runtime : 2default:default2
00:00:002default:default2 
00:00:00.0202default:default2
1081.7812default:default2
0.0002default:defaultZ17-268h px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
Finished Constraint Validation : Time (s): cpu = 00:00:13 ; elapsed = 00:00:38 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
V
%s
*synth2>
*Start Loading Part and Timing Information
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Loading part: xc7a200tfbv676-2
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Loading Part and Timing Information : Time (s): cpu = 00:00:13 ; elapsed = 00:00:38 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
Z
%s
*synth2B
.Start Applying 'set_property' XDC Constraints
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished applying 'set_property' XDC Constraints : Time (s): cpu = 00:00:13 ; elapsed = 00:00:38 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
}
8ROM "%s" won't be mapped to RAM because it is too sparse3998*oasys2!
display_valid2default:defaultZ8-5546h px? 
|
8ROM "%s" won't be mapped to RAM because it is too sparse3998*oasys2 
display_name2default:defaultZ8-5546h px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished RTL Optimization Phase 2 : Time (s): cpu = 00:00:14 ; elapsed = 00:00:40 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
L
%s
*synth24
 Start RTL Component Statistics 
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     64 Bit       Adders := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   3 Input     33 Bit       Adders := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit       Adders := 3     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     30 Bit       Adders := 2     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      5 Bit       Adders := 1     
2default:defaulth p
x
? 
8
%s
*synth2 
+---XORs : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit         XORs := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit         XORs := 2     
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	              167 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	              154 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	              118 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               64 Bit    Registers := 2     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               40 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 38    
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                5 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 13    
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     64 Bit        Muxes := 3     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     40 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     39 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input     32 Bit        Muxes := 2     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 31    
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     24 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input      8 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      5 Bit        Muxes := 3     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   6 Input      4 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit        Muxes := 35    
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	  12 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
O
%s
*synth27
#Finished RTL Component Statistics 
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
Y
%s
*synth2A
-Start RTL Hierarchical Component Statistics 
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
O
%s
*synth27
#Hierarchical RTL Component report 
2default:defaulth p
x
? 
I
%s
*synth21
Module pipeline_cpu_display 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      5 Bit       Adders := 1     
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               40 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 2     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 3     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     40 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     39 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 2     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	  12 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
:
%s
*synth2"
Module fetch 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     30 Bit       Adders := 1     
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 1     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input     32 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 2     
2default:defaulth p
x
? 
;
%s
*synth2#
Module decode 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit       Adders := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     30 Bit       Adders := 1     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 7     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      5 Bit        Muxes := 3     
2default:defaulth p
x
? 
:
%s
*synth2"
Module adder 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   3 Input     33 Bit       Adders := 1     
2default:defaulth p
x
? 
8
%s
*synth2 
Module alu 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
8
%s
*synth2 
+---XORs : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit         XORs := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit         XORs := 1     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 6     
2default:defaulth p
x
? 
=
%s
*synth2%
Module multiply 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
:
%s
*synth2"
+---Adders : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     64 Bit       Adders := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit       Adders := 2     
2default:defaulth p
x
? 
8
%s
*synth2 
+---XORs : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit         XORs := 1     
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               64 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 2     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     64 Bit        Muxes := 3     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 3     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
8
%s
*synth2 
Module exe 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 4     
2default:defaulth p
x
? 
8
%s
*synth2 
Module mem 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 1     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input     32 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     24 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input      8 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   6 Input      4 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   4 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
7
%s
*synth2
Module wb 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 3     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                5 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 1     
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input     32 Bit        Muxes := 6     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit        Muxes := 1     
2default:defaulth p
x
? 
<
%s
*synth2$
Module regfile 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               32 Bit    Registers := 31    
2default:defaulth p
x
? 
9
%s
*synth2!
+---Muxes : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	   2 Input      1 Bit        Muxes := 31    
2default:defaulth p
x
? 
A
%s
*synth2)
Module pipeline_cpu 
2default:defaulth p
x
? 
K
%s
*synth23
Detailed RTL Component Info : 
2default:defaulth p
x
? 
=
%s
*synth2%
+---Registers : 
2default:defaulth p
x
? 
Z
%s
*synth2B
.	              167 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	              154 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	              118 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	               64 Bit    Registers := 1     
2default:defaulth p
x
? 
Z
%s
*synth2B
.	                1 Bit    Registers := 5     
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
[
%s
*synth2C
/Finished RTL Hierarchical Component Statistics
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
H
%s
*synth20
Start Part Resource Summary
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s
*synth2m
YPart Resources:
DSPs: 740 (col length:100)
BRAMs: 730 (col length: RAMB18 100 RAMB36 50)
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Finished Part Resource Summary
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
W
%s
*synth2?
+Start Cross Boundary and Area Optimization
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
]
%s
*synth2E
1Warning: Parallel synthesis criteria is not met 
2default:defaulth p
x
? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[31]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[30]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[29]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[28]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[27]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[26]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[25]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[24]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[23]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[22]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[21]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[20]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[19]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[18]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[17]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[16]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[15]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[14]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[13]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[12]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[11]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2 
mem_addr[10]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2
mem_addr[1]2default:defaultZ8-3331h px? 
?
!design %s has unconnected port %s3331*oasys2 
pipeline_cpu2default:default2
mem_addr[0]2default:defaultZ8-3331h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys29
%cpu/WB_module/cause_exc_code_r_reg[0]2default:default2
FDRE2default:default29
%cpu/WB_module/cause_exc_code_r_reg[4]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys29
%cpu/WB_module/cause_exc_code_r_reg[1]2default:default2
FDRE2default:default29
%cpu/WB_module/cause_exc_code_r_reg[4]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys29
%cpu/WB_module/cause_exc_code_r_reg[2]2default:default2
FDRE2default:default29
%cpu/WB_module/cause_exc_code_r_reg[4]2default:defaultZ8-3886h px? 
?
6propagating constant %s across sequential element (%s)3333*oasys2
12default:default2;
'cpu/WB_module/\cause_exc_code_r_reg[3] 2default:defaultZ8-3333h px? 
?
6propagating constant %s across sequential element (%s)3333*oasys2
02default:default2;
'cpu/WB_module/\cause_exc_code_r_reg[4] 2default:defaultZ8-3333h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2'
display_name_reg[5]2default:default2
FDS2default:default2(
display_name_reg[13]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2'
display_name_reg[6]2default:default2
FDR2default:default2(
display_name_reg[14]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2'
display_name_reg[7]2default:default2
FDR2default:default2'
display_name_reg[9]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2'
display_name_reg[9]2default:default2
FDR2default:default2(
display_name_reg[15]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[15]2default:default2
FDR2default:default2(
display_name_reg[23]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[21]2default:default2
FDR2default:default2(
display_name_reg[29]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[22]2default:default2
FDS2default:default2(
display_name_reg[30]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[23]2default:default2
FDR2default:default2(
display_name_reg[31]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[27]2default:default2
FDR2default:default2(
display_name_reg[28]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[29]2default:default2
FDR2default:default2(
display_name_reg[37]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[30]2default:default2
FDS2default:default2(
display_name_reg[38]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[31]2default:default2
FDR2default:default2(
display_name_reg[39]2default:defaultZ8-3886h px? 
?
"merging instance '%s' (%s) to '%s'3436*oasys2(
display_name_reg[33]2default:default2
FDS2default:default2(
display_name_reg[36]2default:defaultZ8-3886h px? 
?
6propagating constant %s across sequential element (%s)3333*oasys2
02default:default2*
\display_name_reg[39] 2default:defaultZ8-3333h px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Cross Boundary and Area Optimization : Time (s): cpu = 00:00:20 ; elapsed = 00:00:58 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
R
%s
*synth2:
&Start Applying XDC Timing Constraints
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Applying XDC Timing Constraints : Time (s): cpu = 00:00:24 ; elapsed = 00:01:09 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
F
%s
*synth2.
Start Timing Optimization
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
}Finished Timing Optimization : Time (s): cpu = 00:00:24 ; elapsed = 00:01:11 . Memory (MB): peak = 1081.781 ; gain = 417.914
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-
Start Technology Mapping
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
|Finished Technology Mapping : Time (s): cpu = 00:00:25 ; elapsed = 00:01:14 . Memory (MB): peak = 1128.949 ; gain = 465.082
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s
*synth2'
Start IO Insertion
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
Q
%s
*synth29
%Start Flattening Before IO Insertion
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
T
%s
*synth2<
(Finished Flattening Before IO Insertion
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
H
%s
*synth20
Start Final Netlist Cleanup
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Finished Final Netlist Cleanup
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
*BlackBox module %s has unconnected pin %s
3599*oasys2)
\cpu/data_ram_module 2default:default2
enb2default:defaultZ8-4442h px? 
?
!Found another clock driver %s:%s
3964*oasys2

cpu_clk_cg2default:default2
O2default:default2e
OD:/Vivado2019.2/zuchengyuanli/source_code/8_pipeline_cpu/pipeline_cpu_display.v2default:default2
502default:default8@Z8-5410h px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
vFinished IO Insertion : Time (s): cpu = 00:00:28 ; elapsed = 00:01:22 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
O
%s
*synth27
#Start Renaming Generated Instances
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Renaming Generated Instances : Time (s): cpu = 00:00:28 ; elapsed = 00:01:22 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
E
%s
*synth2-

Report RTL Partitions: 
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
+| |RTL Partition |Replication |Instances |
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
W
%s
*synth2?
++-+--------------+------------+----------+
2default:defaulth p
x
? 
D
%s
*synth2,

Report Check Netlist: 
2default:defaulth p
x
? 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
? 
u
%s
*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth p
x
? 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
? 
u
%s
*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth p
x
? 
u
%s
*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
L
%s
*synth24
 Start Rebuilding User Hierarchy
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Rebuilding User Hierarchy : Time (s): cpu = 00:00:28 ; elapsed = 00:01:22 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Start Renaming Generated Ports
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Renaming Generated Ports : Time (s): cpu = 00:00:28 ; elapsed = 00:01:22 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
M
%s
*synth25
!Start Handling Custom Attributes
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Handling Custom Attributes : Time (s): cpu = 00:00:28 ; elapsed = 00:01:23 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
J
%s
*synth22
Start Renaming Generated Nets
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Renaming Generated Nets : Time (s): cpu = 00:00:28 ; elapsed = 00:01:23 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
K
%s
*synth23
Start Writing Synthesis Report
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
A
%s
*synth2)

Report BlackBoxes: 
2default:defaulth p
x
? 
O
%s
*synth27
#+------+--------------+----------+
2default:defaulth p
x
? 
O
%s
*synth27
#|      |BlackBox name |Instances |
2default:defaulth p
x
? 
O
%s
*synth27
#+------+--------------+----------+
2default:defaulth p
x
? 
O
%s
*synth27
#|1     |lcd_module    |         1|
2default:defaulth p
x
? 
O
%s
*synth27
#|2     |inst_rom      |         1|
2default:defaulth p
x
? 
O
%s
*synth27
#|3     |data_ram      |         1|
2default:defaulth p
x
? 
O
%s
*synth27
#+------+--------------+----------+
2default:defaulth p
x
? 
A
%s*synth2)

Report Cell Usage: 
2default:defaulth px? 
H
%s*synth20
+------+-----------+------+
2default:defaulth px? 
H
%s*synth20
|      |Cell       |Count |
2default:defaulth px? 
H
%s*synth20
+------+-----------+------+
2default:defaulth px? 
H
%s*synth20
|1     |data_ram   |     1|
2default:defaulth px? 
H
%s*synth20
|2     |inst_rom   |     1|
2default:defaulth px? 
H
%s*synth20
|3     |lcd_module |     1|
2default:defaulth px? 
H
%s*synth20
|4     |BUFG       |     1|
2default:defaulth px? 
H
%s*synth20
|5     |BUFGCE     |     1|
2default:defaulth px? 
H
%s*synth20
|6     |CARRY4     |    84|
2default:defaulth px? 
H
%s*synth20
|7     |LUT1       |   131|
2default:defaulth px? 
H
%s*synth20
|8     |LUT2       |    52|
2default:defaulth px? 
H
%s*synth20
|9     |LUT3       |   189|
2default:defaulth px? 
H
%s*synth20
|10    |LUT4       |    93|
2default:defaulth px? 
H
%s*synth20
|11    |LUT5       |   484|
2default:defaulth px? 
H
%s*synth20
|12    |LUT6       |  1428|
2default:defaulth px? 
H
%s*synth20
|13    |MUXF7      |   300|
2default:defaulth px? 
H
%s*synth20
|14    |MUXF8      |    32|
2default:defaulth px? 
H
%s*synth20
|15    |FDRE       |  1872|
2default:defaulth px? 
H
%s*synth20
|16    |FDSE       |    14|
2default:defaulth px? 
H
%s*synth20
|17    |IBUF       |     3|
2default:defaulth px? 
H
%s*synth20
|18    |OBUF       |     8|
2default:defaulth px? 
H
%s*synth20
+------+-----------+------+
2default:defaulth px? 
E
%s
*synth2-

Report Instance Areas: 
2default:defaulth p
x
? 
a
%s
*synth2I
5+------+----------------------+-------------+------+
2default:defaulth p
x
? 
a
%s
*synth2I
5|      |Instance              |Module       |Cells |
2default:defaulth p
x
? 
a
%s
*synth2I
5+------+----------------------+-------------+------+
2default:defaulth p
x
? 
a
%s
*synth2I
5|1     |top                   |             |  4835|
2default:defaulth p
x
? 
a
%s
*synth2I
5|2     |  cpu                 |pipeline_cpu |  4647|
2default:defaulth p
x
? 
a
%s
*synth2I
5|3     |    MEM_module        |mem          |     3|
2default:defaulth p
x
? 
a
%s
*synth2I
5|4     |    EXE_module        |exe          |   506|
2default:defaulth p
x
? 
a
%s
*synth2I
5|5     |      multiply_module |multiply     |   506|
2default:defaulth p
x
? 
a
%s
*synth2I
5|6     |    IF_module         |fetch        |   235|
2default:defaulth p
x
? 
a
%s
*synth2I
5|7     |    WB_module         |wb           |   250|
2default:defaulth p
x
? 
a
%s
*synth2I
5|8     |    rf_module         |regfile      |  2416|
2default:defaulth p
x
? 
a
%s
*synth2I
5+------+----------------------+-------------+------+
2default:defaulth p
x
? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
?
%s*synth2?
?Finished Writing Synthesis Report : Time (s): cpu = 00:00:28 ; elapsed = 00:01:23 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth px? 
~
%s
*synth2f
R---------------------------------------------------------------------------------
2default:defaulth p
x
? 
s
%s
*synth2[
GSynthesis finished with 0 errors, 1 critical warnings and 25 warnings.
2default:defaulth p
x
? 
?
%s
*synth2?
Synthesis Optimization Runtime : Time (s): cpu = 00:00:18 ; elapsed = 00:01:11 . Memory (MB): peak = 1133.777 ; gain = 349.496
2default:defaulth p
x
? 
?
%s
*synth2?
?Synthesis Optimization Complete : Time (s): cpu = 00:00:28 ; elapsed = 00:01:23 . Memory (MB): peak = 1133.777 ; gain = 469.910
2default:defaulth p
x
? 
B
 Translating synthesized netlist
350*projectZ1-571h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0752default:default2
1133.7772default:default2
0.0002default:defaultZ17-268h px? 
?
?The value of SIM_DEVICE on instance '%s' of type '%s' is '%s'; it is being changed to match the current FPGA architecture, '%s'. For functional simulation to match hardware behavior, the value of SIM_DEVICE should be changed in the source netlist. %s369*netlist2

cpu_clk_cg2default:default2
BUFGCE2default:default2

ULTRASCALE2default:default2
7SERIES2default:default2

2default:defaultZ29-345h px? 
g
-Analyzing %s Unisim elements for replacement
17*netlist2
4172default:defaultZ29-17h px? 
?
?The value of SIM_DEVICE on instance '%s' of type '%s' is '%s'; it is being changed to match the current FPGA architecture, '%s'. For functional simulation to match hardware behavior, the value of SIM_DEVICE should be changed in the source netlist. %s369*netlist2

cpu_clk_cg2default:default2
BUFGCTRL2default:default2

ULTRASCALE2default:default2
7SERIES2default:default2

2default:defaultZ29-345h px? 
j
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px? 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px? 
u
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0022default:default2
1144.8122default:default2
0.0002default:defaultZ17-268h px? 
?
!Unisim Transformation Summary:
%s111*project2a
M  A total of 1 instances were transformed.
  BUFGCE => BUFGCTRL: 1 instance 
2default:defaultZ1-111h px? 
U
Releasing license: %s
83*common2
	Synthesis2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
672default:default2
572default:default2
12default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
synth_design2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
synth_design: 2default:default2
00:00:422default:default2
00:01:572default:default2
1144.8122default:default2
806.4772default:defaultZ17-268h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0032default:default2
1144.8122default:default2
0.0002default:defaultZ17-268h px? 
K
"No constraints selected for write.1103*constraintsZ18-5210h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2g
SD:/Vivado2019.2/zuchengyuanli/shiyan8/shiyan8.runs/synth_1/pipeline_cpu_display.dcp2default:defaultZ17-1381h px? 
?
%s4*runtcl2?
~Executing : report_utilization -file pipeline_cpu_display_utilization_synth.rpt -pb pipeline_cpu_display_utilization_synth.pb
2default:defaulth px? 
?
Exiting %s at %s...
206*common2
Vivado2default:default2,
Sat Oct  8 09:00:42 20222default:defaultZ17-206h px? 


End Record