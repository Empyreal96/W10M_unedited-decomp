// ExpSetTimeZoneInformation 
 
int __fastcall ExpSetTimeZoneInformation(unsigned int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3
  int v8; // r4
  _BYTE v10[172]; // [sp+4h] [bp-370h] BYREF
  _BYTE v11[260]; // [sp+B0h] [bp-2C4h] BYREF
  _BYTE v12[448]; // [sp+1B4h] [bp-1C0h] BYREF

  if ( a2 == 172 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 + 172 > MmUserProbeAddress || a1 + 172 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
    memmove((int)v10, a1, 0xACu);
    memset(v11, 0, 256);
    v11[256] = 1;
  }
  else
  {
    if ( a2 != 432 )
      return -1073741820;
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v4 = a1 + 432;
    if ( a1 + 432 > MmUserProbeAddress || v4 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
    memmove((int)v10, a1, 0x1B0u);
  }
  ExAcquireTimeRefreshLock(1);
  memmove((int)v12, (int)&ExpTimeZoneInformation, 0x1B0u);
  v5 = ExReleaseResourceLite((int)&ExpTimeRefreshLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  v8 = RtlpSetTimeZoneInformationWorker((int)v10, 0x1B0u);
  if ( v8 >= 0 )
  {
    v8 = NtSetSystemTime(0, 0);
    if ( v8 < 0 )
      RtlpSetTimeZoneInformationWorker((int)v12, 0x1B0u);
  }
  return v8;
}
