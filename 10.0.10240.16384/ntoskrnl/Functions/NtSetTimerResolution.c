// NtSetTimerResolution 
 
int __fastcall NtSetTimerResolution(unsigned int a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // r9
  unsigned int v6; // r8
  _DWORD *v7; // r4
  _DWORD *v8; // r4
  int v9; // r5
  int v10; // r6
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r0
  int v14; // r10
  unsigned int *v15; // r0
  int v16; // r6
  int v17; // r6
  unsigned int v18; // r0
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int varg_r1; // [sp+34h] [bp+Ch]
  unsigned int varg_r2; // [sp+38h] [bp+10h]

  varg_r1 = a2;
  v4 = (_DWORD *)a3;
  varg_r2 = a3;
  LOBYTE(varg_r1) = a2;
  v6 = a1;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v7 = (_DWORD *)a3;
    if ( a3 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
  }
  v8 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v9 = 0;
  ExAcquireTimeRefreshLock(1);
  v10 = KeTimeIncrement;
  if ( a2 )
  {
    v14 = 1;
    __dmb(0xBu);
    v15 = v8 + 48;
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80001000, v15) );
    __dmb(0xBu);
    if ( v16 >= 0 )
      v15 = (unsigned int *)ExpInsertTimerResolutionEntry((int)v8);
    if ( (v16 & 0x1000) != 0 )
      v14 = v6 <= v8[171];
    else
      ++ExpTimerResolutionCount;
    if ( !v8[170] || v6 < v8[172] )
    {
      v17 = PoDiagCaptureUsermodeStack(v15);
      if ( v17 )
      {
        v18 = v8[170];
        if ( v18 )
          ExFreePoolWithTag(v18);
        v8[170] = v17;
        v8[172] = v6;
      }
    }
    v8[171] = v6;
    PoTraceSystemTimerResolution(0, v8);
    v13 = ExpUpdateTimerResolution(v14, v6, 0);
    goto LABEL_25;
  }
  __dmb(0xBu);
  v11 = v8 + 48;
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0xFFFFEFFF, v11) );
  __dmb(0xBu);
  if ( (v12 & 0x1000) != 0 )
  {
    --ExpTimerResolutionCount;
    v8[171] = 0;
    PoTraceSystemTimerResolution(0, v8);
    v13 = ExpUpdateTimerResolution(0, 0, 0);
LABEL_25:
    v10 = v13;
    goto LABEL_26;
  }
  v9 = -1073741243;
LABEL_26:
  v19 = ExReleaseResourceLite((int)&ExpTimeRefreshLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  __mrc(15, 0, 13, 0, 3);
  *v4 = v10;
  return v9;
}
