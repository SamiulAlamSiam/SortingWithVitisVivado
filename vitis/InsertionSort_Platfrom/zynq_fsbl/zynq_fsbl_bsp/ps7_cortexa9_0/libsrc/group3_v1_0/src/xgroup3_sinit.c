// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xgroup3.h"

extern XGroup3_Config XGroup3_ConfigTable[];

XGroup3_Config *XGroup3_LookupConfig(u16 DeviceId) {
	XGroup3_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XGROUP3_NUM_INSTANCES; Index++) {
		if (XGroup3_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XGroup3_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XGroup3_Initialize(XGroup3 *InstancePtr, u16 DeviceId) {
	XGroup3_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XGroup3_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XGroup3_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

