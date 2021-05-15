// PnpGetDeviceInstancePropertyData 
 
int __fastcall PnpGetDeviceInstancePropertyData(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  unsigned int v9; // r2
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // [sp+20h] [bp-C8h] BYREF
  __int16 v16; // [sp+28h] [bp-C0h]
  char v17[168]; // [sp+2Ah] [bp-BEh] BYREF

  v16 = 0;
  memset(v17, 0, sizeof(v17));
  v15 = 0;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ExAcquireResourceSharedLite((int)&PnpDevicePropertyLock, 1);
  v10 = PnpGetObjectProperty(
          PiPnpRtlCtx,
          a1,
          1,
          0,
          0,
          (int)DEVPKEY_Device_InLocalMachineContainer,
          (int)&v15,
          a6,
          1,
          a7,
          0);
  v11 = ExReleaseResourceLite((int)&PnpDevicePropertyLock);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  if ( v10 >= 0 )
    *a8 = v15;
  if ( v10 == -1073741275 )
    v10 = -1073741772;
  return v10;
}
