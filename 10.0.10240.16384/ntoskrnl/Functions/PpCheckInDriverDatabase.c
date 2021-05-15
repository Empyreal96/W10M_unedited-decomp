// PpCheckInDriverDatabase 
 
int __fastcall PpCheckInDriverDatabase(unsigned __int16 *a1, int a2, int a3, unsigned int a4, int a5, int a6)
{
  int v8; // r4
  int v9; // r2
  int v10; // r3
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v17; // [sp+8h] [bp-20h] BYREF
  unsigned int v18; // [sp+Ch] [bp-1Ch]

  v17 = a3;
  v18 = a4;
  if ( InitIsWinPEMode )
    return 0;
  v8 = IopBuildFullDriverPath(a1, a2, (unsigned __int16 *)&v17);
  if ( v8 < 0 )
  {
    if ( (PiLoggedErrorEventsMask & 8) == 0 )
    {
      PiLoggedErrorEventsMask |= 8u;
      RtlInitUnicodeString((unsigned int)&v17, L"BUILD DRIVER PATH FAILED");
      ((void (__fastcall *)(int *, _DWORD, int, _DWORD, _DWORD, int))PnpLogEvent)(&v17, 0, -1073740947, 0, 0, a2);
    }
  }
  else
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(__int16 *)(v9 + 0x134) - 1;
    *(_WORD *)(v9 + 308) = v10;
    ExAcquireResourceExclusiveLite((int)&PiDDBLock, 1, v9, v10);
    v8 = PiLookupInDDBCache(&v17, a3);
    if ( v8 == -1073741823 )
      v8 = ((int (__fastcall *)(int *, int, unsigned int, int, unsigned __int16 *, int))PiLookupInDDB)(
             &v17,
             a3,
             a4,
             a6,
             a1,
             a2);
    if ( v8 == -1073740948 )
      return sub_7CBFB4();
    v12 = ExReleaseResourceLite((int)&PiDDBLock);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
    ExFreePoolWithTag(v18);
  }
  if ( v8 != -1073740948 && v8 != -1073740949 )
    return 0;
  if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x20000) != 0 )
    Template_j(Microsoft_Windows_Kernel_PnPHandle, MEMORY[0x649E54]);
  return v8;
}
