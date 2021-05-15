// NtSetSystemTime 
 
int __fastcall NtSetSystemTime(_DWORD *a1, unsigned int a2)
{
  int v4; // r6
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r3
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  int v11; // r4
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  __int64 v18; // [sp+10h] [bp-50h] BYREF
  char v19; // [sp+18h] [bp-48h]
  __int64 v20[2]; // [sp+20h] [bp-40h] BYREF
  __int64 v21; // [sp+30h] [bp-30h] BYREF
  __int16 v22[20]; // [sp+38h] [bp-28h] BYREF

  LODWORD(v21) = a2;
  if ( a1 )
  {
    v4 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v19 = v4;
    v5 = SeSinglePrivilegeCheck(SeSystemtimePrivilege, dword_9229E4, v4, (int)&SeSystemtimePrivilege);
    if ( !v5 )
      return -1073741727;
    if ( v4 )
    {
      if ( ((unsigned __int8)a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v5);
      if ( a2 )
      {
        if ( (a2 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v5);
        if ( a2 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *(_BYTE *)a2 = *(_BYTE *)a2;
        *(_BYTE *)(a2 + 4) = *(_BYTE *)(a2 + 4);
      }
      LODWORD(v18) = *a1;
      v7 = a1[1];
      HIDWORD(v18) = v7;
    }
    else
    {
      LODWORD(v18) = *a1;
      v7 = a1[1];
      HIDWORD(v18) = v7;
    }
    if ( v7 > 0x20000000 )
      return -1073741811;
    ExAcquireTimeRefreshLock(1);
    ExpSetSystemTime(1, 0, 1, SHIDWORD(v18), v18, (int)v20);
    SeAuditSystemTimeChange(v20[0], SHIDWORD(v20[0]), v18, SHIDWORD(v18));
    v8 = ExReleaseResourceLite((int)&ExpTimeRefreshLock);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v8);
    if ( a2 )
      *(_QWORD *)a2 = v20[0];
    return 0;
  }
  v6 = -1073741811;
  ExAcquireTimeRefreshLock(1);
  v11 = (unsigned __int8)ExpSystemIsInCmosMode;
  if ( HalQueryRealTimeClock(v22) )
  {
    RtlTimeFieldsToTime(v22, &v21);
    if ( ExpRefreshTimeZoneInformation() )
    {
      KeQuerySystemTime(v20);
      if ( !ExpRealTimeIsUniversal )
      {
        if ( v11 )
        {
          ExLocalTimeToSystemTime(&v21, &v18);
          KeSetSystemTime((int)&v18, (int)v20, 0);
LABEL_31:
          PoNotifySystemTimeSet();
          v6 = 0;
          goto LABEL_32;
        }
        ExSystemTimeToLocalTime(v20, (int *)&v21);
        RtlTimeToTimeFields((int)&v21, v22, v12, v13);
        HalSetRealTimeClock(v22);
      }
      v18 = v20[0];
      goto LABEL_31;
    }
  }
LABEL_32:
  v14 = ExReleaseResourceLite((int)&ExpTimeRefreshLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v6;
}
