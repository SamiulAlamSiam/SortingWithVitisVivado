#include "platform.h"
#include <xparameters_ps.h>
#include "xgroup3.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xuartps_hw.h"

int main() {
	print("\n\rInsertion Sort\n\r>");

	XGroup3 XGroup3 = { .Control_BaseAddress = XPAR_PS7_ETHERNET_0_BASEADDR,
			.IsReady = 0 };

	init_platform();

	XGroup3_Config* const config = XGroup3_LookupConfig(
	XPAR_PS7_ETHERNET_0_DEVICE_ID);
	const int ret = XGroup3_CfgInitialize(&XGroup3, config);
	Xil_AssertNonvoid(ret == XST_SUCCESS);

	XGroup3_DisableAutoRestart(&XGroup3);

	int c[4];
	while (1) {
		for (int i = 0; i < 4; ++i) {
			c[i] = (int) inbyte();
		}
		//const u32 c = (u32) inbyte();
		if (XGroup3_IsIdle(&XGroup3)) {
			for (int i = 0; i < 4; ++i) {
				XGroup3_Set_array_r(&XGroup3, c[i]);
			}
			//XGroup3_Set_array_r(&XGroup3, c);
			XGroup3_Start(&XGroup3);

			while (!XGroup3_IsDone(&XGroup3));

			const u32 val = XGroup3_Get_output_r(&XGroup3);
			//outbyte(val);
			XUartPs_SendByte(STDOUT_BASEADDRESS, val);
		}

	}

	cleanup_platform();
	return 0;
}
