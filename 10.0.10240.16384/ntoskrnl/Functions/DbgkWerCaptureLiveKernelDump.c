// DbgkWerCaptureLiveKernelDump 
 
int __fastcall DbgkWerCaptureLiveKernelDump(unsigned __int16 *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v13; // r3
  int v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r2
  unsigned int v17; // r1
  __int16 v18; // r3
  _BYTE *v19; // r0
  unsigned int v20; // r5
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r2
  unsigned int v24; // r1
  __int16 v25; // r3
  int v27; // [sp+0h] [bp-28h] BYREF
  int v28; // [sp+4h] [bp-24h]
  int v29; // [sp+8h] [bp-20h]
  unsigned __int16 *varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v27 = a2;
  v28 = a3;
  v29 = a4;
  LOBYTE(v27) = 1;
  if ( KeGetCurrentIrql(a1) )
  {
    DbgPrintEx(5, 1, (int)"DBGK: DbgkWerCaptureLiveKernelDump: called at IRQL > PASSIVE_LEVEL\n", v13);
    return -1073741496;
  }
  if ( !DbgkpWerInitialized )
  {
    DbgPrintEx(
      5,
      1,
      (int)"DBGK: DbgkWerCaptureLiveKernelDump: called before initialization.\n",
      (unsigned __int8)DbgkpWerInitialized);
    return -1073741661;
  }
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v15 + 308);
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&DbgkpBusy);
  while ( __strex(1u, (unsigned int *)&DbgkpBusy) );
  __dmb(0xBu);
  if ( v16 == 1 )
  {
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x134) + 1;
    *(_WORD *)(v17 + 308) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741267;
  }
  v19 = (_BYTE *)ExAllocatePoolWithTag(1, 120, 1466393156);
  v20 = (unsigned int)v19;
  if ( v19 )
  {
    memset(v19, 0, 120);
    v14 = RtlStringCchLengthW(a1, 0x10u, 0);
    if ( v14 >= 0 )
    {
      v14 = RtlStringCchCopyW((_WORD *)v20, v21, (int)a1);
      if ( v14 >= 0 )
      {
        *(_DWORD *)(v20 + 32) = a2;
        *(_DWORD *)(v20 + 36) = a3;
        *(_DWORD *)(v20 + 40) = a4;
        *(_DWORD *)(v20 + 44) = a5;
        *(_DWORD *)(v20 + 48) = a6;
        *(_DWORD *)(v20 + 52) = a7;
        *(_DWORD *)(v20 + 56) = a8;
        *(_DWORD *)(v20 + 60) = a9;
        v29 = DbgkpWerDefaultPolicy;
        v28 = 0;
        v22 = WerLiveKernelCreateReport_0();
        v14 = v22;
        if ( v22 >= 0 )
        {
          v19 = (_BYTE *)DbgkpWerProcessPolicyResult(v20, v29, v28, &v27);
          v14 = (int)v19;
          if ( !(_BYTE)v27 )
            goto LABEL_24;
        }
        else
        {
          DbgPrintEx(
            5,
            0,
            (int)"DBGK: DbgkWerCaptureLiveKernelDump: WerLiveKernelCreateReport failed, status 0x%x.\n\n",
            v22);
        }
      }
    }
    DbgkpWerCleanupContext(v20);
    v19 = (_BYTE *)ExFreePoolWithTag(v20);
  }
  else
  {
    v14 = -1073741670;
  }
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)&DbgkpBusy);
  while ( __strex(0, (unsigned int *)&DbgkpBusy) );
  __dmb(0xBu);
LABEL_24:
  v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v25 = *(_WORD *)(v24 + 0x134) + 1;
  *(_WORD *)(v24 + 308) = v25;
  if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
    KiCheckForKernelApcDelivery((int)v19);
  return v14;
}
