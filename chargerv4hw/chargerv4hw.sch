EESchema Schematic File Version 4
LIBS:chargerv4hw-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L chargerv4hw-rescue:D-device D2
U 1 1 5B043F18
P 7200 2250
F 0 "D2" H 7300 2000 50  0000 C CNN
F 1 "SS2H10-E3/52T" H 7300 2100 50  0000 C CNN
F 2 "Diodes_SMD:D_SMB_Handsoldering" H 7200 2250 50  0001 C CNN
F 3 "" H 7200 2250 50  0001 C CNN
	1    7200 2250
	-1   0    0    1   
$EndComp
$Comp
L chargerv4hw-rescue:D-device D1
U 1 1 5B043F6D
P 7100 3950
F 0 "D1" H 7100 4050 50  0000 C CNN
F 1 "LL4148" H 7100 4150 50  0000 C CNN
F 2 "footprints:SOD-80" H 7100 3950 50  0001 C CNN
F 3 "" H 7100 3950 50  0001 C CNN
	1    7100 3950
	-1   0    0    1   
$EndComp
$Comp
L chargerv4hw-rescue:R-device R13
U 1 1 5B043F92
P 7550 4500
F 0 "R13" V 7630 4500 50  0000 C CNN
F 1 "1k" V 7550 4500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7480 4500 50  0001 C CNN
F 3 "" H 7550 4500 50  0001 C CNN
	1    7550 4500
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R7
U 1 1 5B043FF7
P 6700 3800
F 0 "R7" V 6780 3800 50  0000 C CNN
F 1 "3.3k" V 6700 3800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6630 3800 50  0001 C CNN
F 3 "" H 6700 3800 50  0001 C CNN
	1    6700 3800
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R4
U 1 1 5B04403C
P 6700 2400
F 0 "R4" H 6850 2400 50  0000 C CNN
F 1 "180k" H 7000 2300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6630 2400 50  0001 C CNN
F 3 "" H 6700 2400 50  0001 C CNN
	1    6700 2400
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R6
U 1 1 5B04407F
P 6700 3000
F 0 "R6" V 6800 3000 50  0000 C CNN
F 1 "22k" V 6700 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6630 3000 50  0001 C CNN
F 3 "" H 6700 3000 50  0001 C CNN
	1    6700 3000
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J4
U 1 1 5B0440AE
P 7850 2250
F 0 "J4" H 7850 2350 50  0000 C CNN
F 1 "B+" H 7850 2150 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 7850 2250 50  0001 C CNN
F 3 "" H 7850 2250 50  0001 C CNN
	1    7850 2250
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J6
U 1 1 5B0440F9
P 7850 4350
F 0 "J6" H 7850 4450 50  0000 C CNN
F 1 "B-" H 7850 4250 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 7850 4350 50  0001 C CNN
F 3 "" H 7850 4350 50  0001 C CNN
	1    7850 4350
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J5
U 1 1 5B044126
P 7850 3950
F 0 "J5" H 7850 4050 50  0000 C CNN
F 1 "BT" H 7850 3850 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 7850 3950 50  0001 C CNN
F 3 "" H 7850 3950 50  0001 C CNN
	1    7850 3950
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:CP-device C2
U 1 1 5B0443D4
P 5050 2900
F 0 "C2" H 5075 3000 50  0000 L CNN
F 1 "10.0" H 5075 2800 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 5088 2750 50  0001 C CNN
F 3 "" H 5050 2900 50  0001 C CNN
	1    5050 2900
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:C-device C3
U 1 1 5B044479
P 5350 2900
F 0 "C3" H 5375 3000 50  0000 L CNN
F 1 "1.0" H 5375 2800 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 5388 2750 50  0001 C CNN
F 3 "" H 5350 2900 50  0001 C CNN
	1    5350 2900
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J2
U 1 1 5B0446CD
P 2600 3150
F 0 "J2" H 2600 3250 50  0000 C CNN
F 1 "PS-" H 2600 3050 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 2600 3150 50  0001 C CNN
F 3 "" H 2600 3150 50  0001 C CNN
	1    2600 3150
	-1   0    0    1   
$EndComp
$Comp
L chargerv4hw-rescue:R-device R3
U 1 1 5B0447DF
P 4950 3950
F 0 "R3" V 4850 3950 50  0000 C CNN
F 1 "330" V 4950 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4880 3950 50  0001 C CNN
F 3 "" H 4950 3950 50  0001 C CNN
	1    4950 3950
	0    1    1    0   
$EndComp
$Comp
L chargerv4hw-rescue:+3.3V-power1 #PWR09
U 1 1 5B046B44
P 6700 3650
F 0 "#PWR09" H 6700 3500 50  0001 C CNN
F 1 "+3.3V" H 6700 3790 50  0000 C CNN
F 2 "" H 6700 3650 50  0001 C CNN
F 3 "" H 6700 3650 50  0001 C CNN
	1    6700 3650
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:GND-power1 #PWR01
U 1 1 5B048006
P 2800 3150
F 0 "#PWR01" H 2800 2900 50  0001 C CNN
F 1 "GND" H 2800 3000 50  0000 C CNN
F 2 "" H 2800 3150 50  0001 C CNN
F 3 "" H 2800 3150 50  0001 C CNN
	1    2800 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3050 5050 3050
$Comp
L chargerv4hw-rescue:GND-power1 #PWR06
U 1 1 5B04ADE9
P 5350 3050
F 0 "#PWR06" H 5350 2800 50  0001 C CNN
F 1 "GND" H 5350 2900 50  0000 C CNN
F 2 "" H 5350 3050 50  0001 C CNN
F 3 "" H 5350 3050 50  0001 C CNN
	1    5350 3050
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:+3.3V-power1 #PWR05
U 1 1 5B04B86D
P 5350 2750
F 0 "#PWR05" H 5350 2600 50  0001 C CNN
F 1 "+3.3V" H 5350 2890 50  0000 C CNN
F 2 "" H 5350 2750 50  0001 C CNN
F 3 "" H 5350 2750 50  0001 C CNN
	1    5350 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3950 7650 3950
Wire Wire Line
	6300 3150 6700 3150
Connection ~ 5350 3050
Connection ~ 5350 2750
Connection ~ 5050 2750
Connection ~ 6700 3150
$Comp
L chargerv4hw-rescue:GND-power1 #PWR07
U 1 1 5B0562BB
P 6300 4750
F 0 "#PWR07" H 6300 4500 50  0001 C CNN
F 1 "GND" H 6300 4600 50  0000 C CNN
F 2 "" H 6300 4750 50  0001 C CNN
F 3 "" H 6300 4750 50  0001 C CNN
	1    6300 4750
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R11
U 1 1 5B063491
P 7300 4500
F 0 "R11" V 7380 4500 50  0000 C CNN
F 1 "1k" V 7300 4500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7230 4500 50  0001 C CNN
F 3 "" H 7300 4500 50  0001 C CNN
	1    7300 4500
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R12
U 1 1 5B06352A
P 7300 4800
F 0 "R12" V 7380 4800 50  0000 C CNN
F 1 "1k" V 7300 4800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7230 4800 50  0001 C CNN
F 3 "" H 7300 4800 50  0001 C CNN
	1    7300 4800
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R14
U 1 1 5B063591
P 7550 4800
F 0 "R14" V 7630 4800 50  0000 C CNN
F 1 "1k" V 7550 4800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7480 4800 50  0001 C CNN
F 3 "" H 7550 4800 50  0001 C CNN
	1    7550 4800
	1    0    0    -1  
$EndComp
Connection ~ 7550 4350
Connection ~ 7550 4950
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J8
U 1 1 5B0648CB
P 7850 5750
F 0 "J8" H 7850 5850 50  0000 C CNN
F 1 "LEDR" H 7850 5650 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 7850 5750 50  0001 C CNN
F 3 "" H 7850 5750 50  0001 C CNN
	1    7850 5750
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:Q_NMOS_GSD-device Q1
U 1 1 5B0865AE
P 6200 4550
F 0 "Q1" H 6400 4600 50  0000 L CNN
F 1 "NTR4170NT1G" H 6350 4850 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6400 4650 50  0001 C CNN
F 3 "" H 6200 4550 50  0001 C CNN
	1    6200 4550
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:GND-power1 #PWR08
U 1 1 5B086FDE
P 6700 3150
F 0 "#PWR08" H 6700 2900 50  0001 C CNN
F 1 "GND" H 6700 3000 50  0000 C CNN
F 2 "" H 6700 3150 50  0001 C CNN
F 3 "" H 6700 3150 50  0001 C CNN
	1    6700 3150
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:C-device C5
U 1 1 5B087829
P 6300 5200
F 0 "C5" H 6325 5300 50  0000 L CNN
F 1 "0.1" H 6325 5100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6338 5050 50  0001 C CNN
F 3 "" H 6300 5200 50  0001 C CNN
	1    6300 5200
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R10
U 1 1 5B0878AC
P 6700 5200
F 0 "R10" V 6780 5200 50  0000 C CNN
F 1 "22k" V 6700 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6630 5200 50  0001 C CNN
F 3 "" H 6700 5200 50  0001 C CNN
	1    6700 5200
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:R-device R9
U 1 1 5B087AC2
P 6700 4900
F 0 "R9" H 6850 4950 50  0000 C CNN
F 1 "18K" H 7000 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6630 4900 50  0001 C CNN
F 3 "" H 6700 4900 50  0001 C CNN
	1    6700 4900
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:GND-power1 #PWR010
U 1 1 5B087BF8
P 6700 5350
F 0 "#PWR010" H 6700 5100 50  0001 C CNN
F 1 "GND" H 6700 5200 50  0000 C CNN
F 2 "" H 6700 5350 50  0001 C CNN
F 3 "" H 6700 5350 50  0001 C CNN
	1    6700 5350
	1    0    0    -1  
$EndComp
Connection ~ 7300 4350
Wire Wire Line
	7300 4950 7550 4950
$Comp
L chargerv4hw-rescue:GND-power1 #PWR011
U 1 1 5B089611
P 7550 4950
F 0 "#PWR011" H 7550 4700 50  0001 C CNN
F 1 "GND" H 7550 4800 50  0000 C CNN
F 2 "" H 7550 4950 50  0001 C CNN
F 3 "" H 7550 4950 50  0001 C CNN
	1    7550 4950
	1    0    0    -1  
$EndComp
Connection ~ 6300 2850
Connection ~ 6300 5050
Wire Wire Line
	6800 5100 6700 5050
Wire Wire Line
	5750 4550 6000 4550
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J7
U 1 1 5B08B3A8
P 7850 5350
F 0 "J7" H 7850 5450 50  0000 C CNN
F 1 "LEDG" H 7850 5250 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 7850 5350 50  0001 C CNN
F 3 "" H 7850 5350 50  0001 C CNN
	1    7850 5350
	1    0    0    -1  
$EndComp
Text Label 7450 3950 2    60   ~ 0
BT
Wire Wire Line
	6700 3950 6950 3950
Wire Wire Line
	7350 2250 7650 2250
Text Label 7400 2250 0    60   ~ 0
B+
Wire Wire Line
	5350 3950 5100 3950
Wire Wire Line
	5050 2750 5350 2750
Wire Wire Line
	7550 4350 7650 4350
Wire Wire Line
	7300 4350 7550 4350
Wire Wire Line
	6300 2850 6700 2850
Wire Wire Line
	6300 5050 6700 5050
$Comp
L MCU_SiliconLabs1:C8051F860-C-GS U1
U 1 1 5D2A448D
P 3300 3950
F 0 "U1" H 3900 4215 50  0000 C CNN
F 1 "C8051F860-C-GS" H 3900 4124 50  0000 C CNN
F 2 "SMD_Packages:SO-16-N" H 3300 3950 50  0001 C CNN
F 3 "" H 3300 3950 50  0001 C CNN
	1    3300 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 4250 3000 4250
Wire Wire Line
	3000 4350 3300 4350
Wire Wire Line
	3000 3950 3300 3950
Wire Wire Line
	3000 4050 3300 4050
Wire Wire Line
	3000 4150 3300 4150
Wire Wire Line
	3000 4450 3300 4450
Wire Wire Line
	3000 4550 3300 4550
Wire Wire Line
	3000 4650 3300 4650
Wire Wire Line
	4800 3950 4500 3950
Wire Wire Line
	5350 4050 4500 4050
Wire Wire Line
	5350 4150 4500 4150
Wire Wire Line
	5350 4250 4500 4250
Wire Wire Line
	5350 4350 4500 4350
Wire Wire Line
	4800 4450 4500 4450
Wire Wire Line
	4800 4550 4500 4550
Wire Wire Line
	4800 4650 4500 4650
Text Label 3000 4450 0    50   ~ 0
C2CK
Text Label 3000 4550 0    50   ~ 0
C2D
Text Label 3000 4150 0    50   ~ 0
TEMP
Text Label 3000 4050 0    50   ~ 0
BV+
Text Label 3000 3950 0    50   ~ 0
BV-
Text Label 5350 3950 2    50   ~ 0
LEDR
Text Label 5350 4050 2    50   ~ 0
TX
Text Label 5350 4150 2    50   ~ 0
RX
Text Label 5350 4250 2    50   ~ 0
BULK
Text Label 5350 4350 2    50   ~ 0
LEDG
Wire Wire Line
	5750 5050 6300 5050
Text Label 5750 5050 0    50   ~ 0
BV-
Text Label 5750 2850 0    50   ~ 0
BV+
Wire Wire Line
	5750 2250 6700 2250
Text Label 5750 2250 0    50   ~ 0
VDD
$Comp
L chargerv4hw-rescue:Conn_01x01-conn J1
U 1 1 5B044634
P 2600 2750
F 0 "J1" H 2600 2850 50  0000 C CNN
F 1 "PS+" H 2600 2650 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_1mmDrill" H 2600 2750 50  0001 C CNN
F 3 "" H 2600 2750 50  0001 C CNN
	1    2600 2750
	-1   0    0    1   
$EndComp
Wire Wire Line
	2800 2750 3300 2750
$Comp
L chargerv4hw-rescue:GND-power1 #PWR04
U 1 1 5B04AE4B
P 4750 3350
F 0 "#PWR04" H 4750 3100 50  0001 C CNN
F 1 "GND" H 4750 3200 50  0000 C CNN
F 2 "" H 4750 3350 50  0001 C CNN
F 3 "" H 4750 3350 50  0001 C CNN
	1    4750 3350
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:LM317_3PinPackage-regul U2
U 1 1 5B04421D
P 4350 2750
F 0 "U2" H 4200 2875 50  0000 C CNN
F 1 "LM317LCPK" H 4350 2875 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-89-3_Handsoldering" H 4350 3000 50  0001 C CIN
F 3 "" H 4350 2750 50  0001 C CNN
	1    4350 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3050 4750 3050
Wire Wire Line
	4750 2750 5050 2750
Wire Wire Line
	4650 2750 4750 2750
Connection ~ 4750 2750
$Comp
L chargerv4hw-rescue:R-device R1
U 1 1 5B0442E4
P 4750 2900
F 0 "R1" V 4830 2900 50  0000 C CNN
F 1 "470" V 4750 2900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4680 2900 50  0001 C CNN
F 3 "" H 4750 2900 50  0001 C CNN
	1    4750 2900
	1    0    0    -1  
$EndComp
Connection ~ 4750 3050
$Comp
L chargerv4hw-rescue:R-device R2
U 1 1 5B044367
P 4750 3200
F 0 "R2" V 4830 3200 50  0000 C CNN
F 1 "680" V 4750 3200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4680 3200 50  0001 C CNN
F 3 "" H 4750 3200 50  0001 C CNN
	1    4750 3200
	1    0    0    -1  
$EndComp
$Comp
L chargerv4hw-rescue:CP-device C1
U 1 1 5D2E8B3D
P 3300 2900
F 0 "C1" H 3325 3000 50  0000 L CNN
F 1 "220.0" H 3325 2800 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D10.0mm_P3.50mm" H 3338 2750 50  0001 C CNN
F 3 "" H 3300 2900 50  0001 C CNN
	1    3300 2900
	1    0    0    -1  
$EndComp
Connection ~ 3300 2750
Wire Wire Line
	3300 2750 4050 2750
$Comp
L chargerv4hw-rescue:GND-power1 #PWR03
U 1 1 5D2EA5A8
P 3300 3050
F 0 "#PWR03" H 3300 2800 50  0001 C CNN
F 1 "GND" H 3300 2900 50  0000 C CNN
F 2 "" H 3300 3050 50  0001 C CNN
F 3 "" H 3300 3050 50  0001 C CNN
	1    3300 3050
	1    0    0    -1  
$EndComp
Text Label 5750 4550 0    50   ~ 0
BULK
$Comp
L chargerv4hw-rescue:VDD-power1 #PWR02
U 1 1 5D2F0599
P 3300 2750
F 0 "#PWR02" H 3300 2600 50  0001 C CNN
F 1 "VDD" H 3300 2900 50  0000 C CNN
F 2 "" H 3300 2750 50  0001 C CNN
F 3 "" H 3300 2750 50  0001 C CNN
	1    3300 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 5350 7650 5350
Wire Wire Line
	7350 5750 7650 5750
Text Label 7350 5350 0    50   ~ 0
LEDG
Text Label 7350 5750 0    50   ~ 0
LEDR
Wire Wire Line
	6700 3950 5750 3950
Connection ~ 6700 3950
Text Label 5750 3950 0    50   ~ 0
TEMP
Connection ~ 6700 5050
Wire Wire Line
	6300 5350 6700 5350
Connection ~ 6700 5350
$Comp
L Connector_Generic:Conn_01x05 J3
U 1 1 5D31DA21
P 5000 5550
F 0 "J3" H 5080 5592 50  0000 L CNN
F 1 "PRG/SER" H 5080 5501 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch1.27mm" H 5000 5550 50  0001 C CNN
F 3 "~" H 5000 5550 50  0001 C CNN
	1    5000 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 5350 4800 5350
Wire Wire Line
	4350 5450 4800 5450
Wire Wire Line
	4350 5550 4800 5550
Wire Wire Line
	4350 5650 4800 5650
Wire Wire Line
	4350 5750 4800 5750
Text Label 4350 5350 0    50   ~ 0
GND
Text Label 4350 5550 0    50   ~ 0
C2CK
Text Label 4350 5450 0    50   ~ 0
C2D
Text Label 4350 5750 0    50   ~ 0
TX
Text Label 4350 5650 0    50   ~ 0
RX
Text Label 3000 4250 0    50   ~ 0
GND
Text Label 3000 4350 0    50   ~ 0
+3V3
Wire Wire Line
	7050 2250 6700 2250
Connection ~ 6700 2250
Wire Wire Line
	5750 2850 6300 2850
$Comp
L chargerv4hw-rescue:C-device C4
U 1 1 5B044153
P 6300 3000
F 0 "C4" H 6325 3100 50  0000 L CNN
F 1 "0.1" H 6325 2900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6338 2850 50  0001 C CNN
F 3 "" H 6300 3000 50  0001 C CNN
	1    6300 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5D488858
P 6700 2700
F 0 "R5" H 6770 2746 50  0000 L CNN
F 1 "18K" H 6770 2655 50  0000 L CNN
F 2 "" V 6630 2700 50  0001 C CNN
F 3 "~" H 6700 2700 50  0001 C CNN
	1    6700 2700
	1    0    0    -1  
$EndComp
Connection ~ 6700 2850
Wire Wire Line
	6300 4350 6700 4350
$Comp
L Device:R R8
U 1 1 5D48CE93
P 6700 4600
F 0 "R8" H 6770 4646 50  0000 L CNN
F 1 "180K" H 6770 4555 50  0000 L CNN
F 2 "" V 6630 4600 50  0001 C CNN
F 3 "~" H 6700 4600 50  0001 C CNN
	1    6700 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 4450 6700 4350
Connection ~ 6700 4350
Wire Wire Line
	6700 4350 7300 4350
$EndSCHEMATC
