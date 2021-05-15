// PnpSetDeviceInterfacePropertyData 
 
int __fastcall PnpSetDeviceInterfacePropertyData(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7)
{
  _BYTE *v10; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned __int16 *v18; // [sp+18h] [bp-D8h] BYREF
  __int16 v19; // [sp+28h] [bp-C8h]
  char v20[168]; // [sp+2Ah] [bp-C6h] BYREF

  v19 = 0;
  v10 = memset(v20, 0, sizeof(v20));
  v18 = 0;
  if ( !a1 || !*(_DWORD *)(a1 + 4) || !*(_WORD *)a1 )
    return -1073741811;
  if ( a3 )
    return sub_815AC8(v10);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(__int16 *)(v12 + 0x134) - 1;
  *(_WORD *)(v12 + 308) = v13;
  ExAcquireResourceExclusiveLite((int)&PnpDevicePropertyLock, 1, v12, v13);
  v14 = PnpUnicodeStringToWstr((int *)&v18, 0, (unsigned __int16 *)a1);
  if ( v14 >= 0 )
    v14 = PiPnpRtlSetObjectProperty(PiPnpRtlCtx, v18, 3, 0, 0, a2, a5, a7, a6);
  PnpUnicodeStringToWstrFree((unsigned int)v18, a1);
  v15 = ExReleaseResourceLite((int)&PnpDevicePropertyLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  if ( v14 == -1073741275 )
    v14 = -1073741772;
  return v14;
}
