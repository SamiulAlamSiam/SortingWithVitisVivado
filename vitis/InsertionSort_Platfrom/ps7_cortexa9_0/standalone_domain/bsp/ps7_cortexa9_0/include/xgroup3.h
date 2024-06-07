// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XGROUP3_H
#define XGROUP3_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xgroup3_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XGroup3_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XGroup3;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XGroup3_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XGroup3_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XGroup3_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XGroup3_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XGroup3_Initialize(XGroup3 *InstancePtr, u16 DeviceId);
XGroup3_Config* XGroup3_LookupConfig(u16 DeviceId);
int XGroup3_CfgInitialize(XGroup3 *InstancePtr, XGroup3_Config *ConfigPtr);
#else
int XGroup3_Initialize(XGroup3 *InstancePtr, const char* InstanceName);
int XGroup3_Release(XGroup3 *InstancePtr);
#endif

void XGroup3_Start(XGroup3 *InstancePtr);
u32 XGroup3_IsDone(XGroup3 *InstancePtr);
u32 XGroup3_IsIdle(XGroup3 *InstancePtr);
u32 XGroup3_IsReady(XGroup3 *InstancePtr);
void XGroup3_EnableAutoRestart(XGroup3 *InstancePtr);
void XGroup3_DisableAutoRestart(XGroup3 *InstancePtr);

void XGroup3_Set_array_r(XGroup3 *InstancePtr, u32 Data);
u32 XGroup3_Get_array_r(XGroup3 *InstancePtr);
void XGroup3_Set_array_size(XGroup3 *InstancePtr, u32 Data);
u32 XGroup3_Get_array_size(XGroup3 *InstancePtr);
u32 XGroup3_Get_output_r(XGroup3 *InstancePtr);
u32 XGroup3_Get_output_r_vld(XGroup3 *InstancePtr);

void XGroup3_InterruptGlobalEnable(XGroup3 *InstancePtr);
void XGroup3_InterruptGlobalDisable(XGroup3 *InstancePtr);
void XGroup3_InterruptEnable(XGroup3 *InstancePtr, u32 Mask);
void XGroup3_InterruptDisable(XGroup3 *InstancePtr, u32 Mask);
void XGroup3_InterruptClear(XGroup3 *InstancePtr, u32 Mask);
u32 XGroup3_InterruptGetEnabled(XGroup3 *InstancePtr);
u32 XGroup3_InterruptGetStatus(XGroup3 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
