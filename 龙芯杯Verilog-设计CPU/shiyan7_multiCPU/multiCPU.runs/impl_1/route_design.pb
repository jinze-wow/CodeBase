
Q
Command: %s
53*	vivadotcl2 
route_design2default:defaultZ4-113h px? 
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
xc7a200t2default:defaultZ17-347h px? 
?
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xc7a200t2default:defaultZ17-349h px? 
p
,Running DRC as a precondition to command %s
22*	vivadotcl2 
route_design2default:defaultZ4-22h px? 
P
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px? 
V
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
V

Starting %s Task
103*constraints2
Routing2default:defaultZ18-103h px? 
}
BMultithreading enabled for route_design using a maximum of %s CPUs17*	routeflow2
22default:defaultZ35-254h px? 
p

Phase %s%s
101*constraints2
1 2default:default2#
Build RT Design2default:defaultZ18-101h px? 
C
.Phase 1 Build RT Design | Checksum: 19bebfda3
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:51 ; elapsed = 00:01:32 . Memory (MB): peak = 1891.062 ; gain = 137.9412default:defaulth px? 
v

Phase %s%s
101*constraints2
2 2default:default2)
Router Initialization2default:defaultZ18-101h px? 
{
\No timing constraints were detected. The router will operate in resource-optimization mode.
64*routeZ35-64h px? 
{

Phase %s%s
101*constraints2
2.1 2default:default2,
Fix Topology Constraints2default:defaultZ18-101h px? 
N
9Phase 2.1 Fix Topology Constraints | Checksum: 19bebfda3
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:51 ; elapsed = 00:01:32 . Memory (MB): peak = 1897.906 ; gain = 144.7852default:defaulth px? 
t

Phase %s%s
101*constraints2
2.2 2default:default2%
Pre Route Cleanup2default:defaultZ18-101h px? 
G
2Phase 2.2 Pre Route Cleanup | Checksum: 19bebfda3
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:51 ; elapsed = 00:01:32 . Memory (MB): peak = 1897.906 ; gain = 144.7852default:defaulth px? 
H
3Phase 2 Router Initialization | Checksum: bcbc5a5f
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:52 ; elapsed = 00:01:33 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
p

Phase %s%s
101*constraints2
3 2default:default2#
Initial Routing2default:defaultZ18-101h px? 
C
.Phase 3 Initial Routing | Checksum: 142425bce
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:35 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
s

Phase %s%s
101*constraints2
4 2default:default2&
Rip-up And Reroute2default:defaultZ18-101h px? 
u

Phase %s%s
101*constraints2
4.1 2default:default2&
Global Iteration 02default:defaultZ18-101h px? 
H
3Phase 4.1 Global Iteration 0 | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
F
1Phase 4 Rip-up And Reroute | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
|

Phase %s%s
101*constraints2
5 2default:default2/
Delay and Skew Optimization2default:defaultZ18-101h px? 
O
:Phase 5 Delay and Skew Optimization | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
n

Phase %s%s
101*constraints2
6 2default:default2!
Post Hold Fix2default:defaultZ18-101h px? 
p

Phase %s%s
101*constraints2
6.1 2default:default2!
Hold Fix Iter2default:defaultZ18-101h px? 
C
.Phase 6.1 Hold Fix Iter | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
A
,Phase 6 Post Hold Fix | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
o

Phase %s%s
101*constraints2
7 2default:default2"
Route finalize2default:defaultZ18-101h px? 
B
-Phase 7 Route finalize | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
v

Phase %s%s
101*constraints2
8 2default:default2)
Verifying routed nets2default:defaultZ18-101h px? 
I
4Phase 8 Verifying routed nets | Checksum: 1a276db50
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:53 ; elapsed = 00:01:37 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
r

Phase %s%s
101*constraints2
9 2default:default2%
Depositing Routes2default:defaultZ18-101h px? 
D
/Phase 9 Depositing Routes | Checksum: f3473832
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:54 ; elapsed = 00:01:38 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
@
Router Completed Successfully
2*	routeflowZ35-16h px? 
?

%s
*constraints2q
]Time (s): cpu = 00:00:54 ; elapsed = 00:01:38 . Memory (MB): peak = 1942.441 ; gain = 189.3202default:defaulth px? 
Z
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
712default:default2
1612default:default2
02default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
route_design2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
route_design: 2default:default2
00:00:562default:default2
00:01:392default:default2
1942.4412default:default2
189.3202default:defaultZ17-268h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0012default:default2
1942.4412default:default2
0.0002default:defaultZ17-268h px? 
H
&Writing timing data to binary archive.266*timingZ38-480h px? 
D
Writing placer database...
1603*designutilsZ20-1893h px? 
=
Writing XDEF routing.
211*designutilsZ20-211h px? 
J
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px? 
J
#Writing XDEF routing special nets.
210*designutilsZ20-210h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2)
Write XDEF Complete: 2default:default2
00:00:002default:default2
00:00:012default:default2
1942.4412default:default2
0.0002default:defaultZ17-268h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2r
^D:/Vivado2019.2/zuchengyuanli/multiCPU/multiCPU.runs/impl_1/multi_cycle_cpu_display_routed.dcp2default:defaultZ17-1381h px? 
?
%s4*runtcl2?
?Executing : report_drc -file multi_cycle_cpu_display_drc_routed.rpt -pb multi_cycle_cpu_display_drc_routed.pb -rpx multi_cycle_cpu_display_drc_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_drc -file multi_cycle_cpu_display_drc_routed.rpt -pb multi_cycle_cpu_display_drc_routed.pb -rpx multi_cycle_cpu_display_drc_routed.rpx2default:defaultZ4-113h px? 
>
IP Catalog is up to date.1232*coregenZ19-1839h px? 
P
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px? 
?
#The results of DRC are in file %s.
168*coretcl2?
bD:/Vivado2019.2/zuchengyuanli/multiCPU/multiCPU.runs/impl_1/multi_cycle_cpu_display_drc_routed.rptbD:/Vivado2019.2/zuchengyuanli/multiCPU/multiCPU.runs/impl_1/multi_cycle_cpu_display_drc_routed.rpt2default:default8Z2-168h px? 
\
%s completed successfully
29*	vivadotcl2

report_drc2default:defaultZ4-42h px? 
?
%s4*runtcl2?
?Executing : report_methodology -file multi_cycle_cpu_display_methodology_drc_routed.rpt -pb multi_cycle_cpu_display_methodology_drc_routed.pb -rpx multi_cycle_cpu_display_methodology_drc_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_methodology -file multi_cycle_cpu_display_methodology_drc_routed.rpt -pb multi_cycle_cpu_display_methodology_drc_routed.pb -rpx multi_cycle_cpu_display_methodology_drc_routed.rpx2default:defaultZ4-113h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
Y
$Running Methodology with %s threads
74*drc2
22default:defaultZ23-133h px? 
?
2The results of Report Methodology are in file %s.
450*coretcl2?
nD:/Vivado2019.2/zuchengyuanli/multiCPU/multiCPU.runs/impl_1/multi_cycle_cpu_display_methodology_drc_routed.rptnD:/Vivado2019.2/zuchengyuanli/multiCPU/multiCPU.runs/impl_1/multi_cycle_cpu_display_methodology_drc_routed.rpt2default:default8Z2-1520h px? 
d
%s completed successfully
29*	vivadotcl2&
report_methodology2default:defaultZ4-42h px? 
?
%s4*runtcl2?
?Executing : report_power -file multi_cycle_cpu_display_power_routed.rpt -pb multi_cycle_cpu_display_power_summary_routed.pb -rpx multi_cycle_cpu_display_power_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_power -file multi_cycle_cpu_display_power_routed.rpt -pb multi_cycle_cpu_display_power_summary_routed.pb -rpx multi_cycle_cpu_display_power_routed.rpx2default:defaultZ4-113h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
P
/No user defined clocks was found in the design!216*powerZ33-232h px? 
K
,Running Vector-less Activity Propagation...
51*powerZ33-51h px? 
?
3Invalid input clock frequency for %s. Out of range!214*power2,

cpu_clk_cg	
cpu_clk_cg2default:default8Z33-230h px? 
?
3Invalid input clock frequency for %s. Out of range!214*power2,

cpu_clk_cg	
cpu_clk_cg2default:default8Z33-230h px? 
?
3Invalid input clock frequency for %s. Out of range!214*power2,

cpu_clk_cg	
cpu_clk_cg2default:default8Z33-230h px? 
?
3Invalid input clock frequency for %s. Out of range!214*power2,

cpu_clk_cg	
cpu_clk_cg2default:default8Z33-230h px? 
?
3Invalid input clock frequency for %s. Out of range!214*power2,

cpu_clk_cg	
cpu_clk_cg2default:default8Z33-230h px? 
P
3
Finished Running Vector-less Activity Propagation
1*powerZ33-1h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
832default:default2
1672default:default2
02default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
report_power2default:defaultZ4-42h px? 
?
%s4*runtcl2?
{Executing : report_route_status -file multi_cycle_cpu_display_route_status.rpt -pb multi_cycle_cpu_display_route_status.pb
2default:defaulth px? 
?
%s4*runtcl2?
?Executing : report_timing_summary -max_paths 10 -file multi_cycle_cpu_display_timing_summary_routed.rpt -pb multi_cycle_cpu_display_timing_summary_routed.pb -rpx multi_cycle_cpu_display_timing_summary_routed.rpx -warn_on_violation 
2default:defaulth px? 
r
UpdateTimingParams:%s.
91*timing29
% Speed grade: -2, Delay Type: min_max2default:defaultZ38-91h px? 
|
CMultithreading enabled for timing update using a maximum of %s CPUs155*timing2
22default:defaultZ38-191h px? 
?
iThere are no user specified timing constraints. Timing constraints are needed for proper timing analysis.200*timingZ38-313h px? 
?
%s4*runtcl2t
`Executing : report_incremental_reuse -file multi_cycle_cpu_display_incremental_reuse_routed.rpt
2default:defaulth px? 
g
BIncremental flow is disabled. No incremental reuse Info to report.423*	vivadotclZ4-1062h px? 
?
%s4*runtcl2t
`Executing : report_clock_utilization -file multi_cycle_cpu_display_clock_utilization_routed.rpt
2default:defaulth px? 
?
%s4*runtcl2?
?Executing : report_bus_skew -warn_on_violation -file multi_cycle_cpu_display_bus_skew_routed.rpt -pb multi_cycle_cpu_display_bus_skew_routed.pb -rpx multi_cycle_cpu_display_bus_skew_routed.rpx
2default:defaulth px? 
r
UpdateTimingParams:%s.
91*timing29
% Speed grade: -2, Delay Type: min_max2default:defaultZ38-91h px? 
|
CMultithreading enabled for timing update using a maximum of %s CPUs155*timing2
22default:defaultZ38-191h px? 


End Record