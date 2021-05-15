// IoRequestDeviceRemovalForReset 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoRequestDeviceRemovalForReset(int a1)
{
  _BYTE *v2; // r0
  unsigned int v3; // r4 OVERLAPPED
  int v4; // r6
  int (*v5)(); // r3

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 112, 1164996176);
  v3 = (unsigned int)v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 112);
  KeInitializeDpc(v3 + 48, (int)PfSnTracingStateDpcRoutine, v3);
  KeInitializeTimerEx((_DWORD *)v3, 0);
  v5 = IopRetryDeviceRemovalForReset;
  *(_QWORD *)(v3 + 88) = *(_QWORD *)(&v3 - 1);
  *(_DWORD *)(v3 + 80) = 0;
  *(_DWORD *)(v3 + 96) = 0;
  v4 = PnpSetTargetDeviceRemove(
         a1,
         0,
         1,
         0,
         1,
         54,
         0,
         (int)IopDeviceRemovalForResetComplete,
         v3,
         (_DWORD *)(v3 + 100),
         0,
         0,
         (_DWORD *)(v3 + 104));
  if ( v4 >= 0 )
  {
    if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x2000000) != 0 )
      Template_hzr0(Microsoft_Windows_Kernel_PnPHandle, MEMORY[0x649E54]);
  }
  else
  {
    ExFreePoolWithTag(v3);
  }
  return v4;
}
