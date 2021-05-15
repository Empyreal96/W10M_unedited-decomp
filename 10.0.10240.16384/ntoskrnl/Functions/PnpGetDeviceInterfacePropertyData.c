// PnpGetDeviceInterfacePropertyData 
 
int __fastcall PnpGetDeviceInterfacePropertyData(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _BYTE *v11; // r0
  unsigned int v13; // r2
  int v14; // r4
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  unsigned int v18[4]; // [sp+20h] [bp-E0h] BYREF
  __int16 v19; // [sp+30h] [bp-D0h]
  char v20[168]; // [sp+32h] [bp-CEh] BYREF

  v19 = 0;
  v11 = memset(v20, 0, sizeof(v20));
  v18[0] = 0;
  if ( !a1 || !*(_DWORD *)(a1 + 4) || !*(_WORD *)a1 )
    return -1073741811;
  if ( a3 )
    return sub_8192AC(v11);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  ExAcquireResourceSharedLite((int)&PnpDevicePropertyLock, 1);
  v14 = PnpUnicodeStringToWstr((int *)v18, 0, (unsigned __int16 *)a1);
  if ( v14 >= 0 )
    v14 = PnpGetObjectProperty(PiPnpRtlCtx, v18[0], 3, 0, 0, a2, a8, a6, a5, a7, 0);
  PnpUnicodeStringToWstrFree(v18[0], a1);
  v15 = ExReleaseResourceLite((int)&PnpDevicePropertyLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  if ( v14 == -1073741275 )
    v14 = -1073741772;
  return v14;
}
