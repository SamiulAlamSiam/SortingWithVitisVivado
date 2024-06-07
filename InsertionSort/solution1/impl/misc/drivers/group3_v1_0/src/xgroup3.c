// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xgroup3.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XGroup3_CfgInitialize(XGroup3 *InstancePtr, XGroup3_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XGroup3_Start(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL) & 0x80;
    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XGroup3_IsDone(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XGroup3_IsIdle(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XGroup3_IsReady(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XGroup3_EnableAutoRestart(XGroup3 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XGroup3_DisableAutoRestart(XGroup3 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_AP_CTRL, 0);
}

void XGroup3_Set_array_r(XGroup3 *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_ARRAY_R_DATA, Data);
}

u32 XGroup3_Get_array_r(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_ARRAY_R_DATA);
    return Data;
}

void XGroup3_Set_array_size(XGroup3 *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_ARRAY_SIZE_DATA, Data);
}

u32 XGroup3_Get_array_size(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_ARRAY_SIZE_DATA);
    return Data;
}

u32 XGroup3_Get_output_r(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_OUTPUT_R_DATA);
    return Data;
}

u32 XGroup3_Get_output_r_vld(XGroup3 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_OUTPUT_R_CTRL);
    return Data & 0x1;
}

void XGroup3_InterruptGlobalEnable(XGroup3 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_GIE, 1);
}

void XGroup3_InterruptGlobalDisable(XGroup3 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_GIE, 0);
}

void XGroup3_InterruptEnable(XGroup3 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_IER);
    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_IER, Register | Mask);
}

void XGroup3_InterruptDisable(XGroup3 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_IER);
    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_IER, Register & (~Mask));
}

void XGroup3_InterruptClear(XGroup3 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XGroup3_WriteReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_ISR, Mask);
}

u32 XGroup3_InterruptGetEnabled(XGroup3 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_IER);
}

u32 XGroup3_InterruptGetStatus(XGroup3 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XGroup3_ReadReg(InstancePtr->Control_BaseAddress, XGROUP3_CONTROL_ADDR_ISR);
}

