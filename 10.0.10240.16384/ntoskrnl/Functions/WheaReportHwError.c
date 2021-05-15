// WheaReportHwError 
 
int __fastcall WheaReportHwError(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r8
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r7
  int v10; // r2
  int v11; // r6
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  _DWORD *v15; // r4
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v22[6]; // [sp+8h] [bp-18h] BYREF

  v22[0] = a4;
  if ( a1[5] == 3 )
    return 0;
  v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1388);
  if ( !v5 || (v6 = *(_DWORD *)(v5 + 4)) == 0 || !*(_DWORD *)(v6 + 4) )
  {
    v20 = a1[5];
    if ( v20 == 1 || !v20 )
      KeBugCheckEx(292, a1[7], 0, 0, 0);
    return 0;
  }
  v7 = WheapGetErrorSource(v6, a1[6]);
  v9 = v7;
  if ( !v7 )
  {
    v10 = a1[5];
    if ( (v10 == 1 || !v10) && (a1[3] & 1) == 0 )
      KeBugCheck2(290, 9, a1[7], v8, 0, 0);
    return -1073741632;
  }
  __dmb(0xBu);
  v12 = (unsigned int *)(v7 + 16);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 + 1, v12) );
  __dmb(0xBu);
  if ( a1[5] == 2 && !WheapApplyThresholdChecks(v7) )
    return 0;
  v14 = WheapAllocErrorRecord(v9, v22);
  v15 = (_DWORD *)v14;
  if ( v14 )
  {
    v17 = ((unsigned __int8)*(_DWORD *)(v14 + 16) ^ (unsigned __int8)(a1[3] >> 2)) & 4 ^ *(_DWORD *)(v14 + 16);
    *(_DWORD *)(v14 + 16) = v17;
    *(_DWORD *)(v14 + 16) = ((unsigned __int8)v17 ^ (unsigned __int8)(a1[3] >> 2)) & 8 ^ v17;
    v11 = WheapFillOutErrorRecord(v22[0] - 28, a1, v9, v14 + 28);
    if ( v11 < 0 )
    {
      v18 = a1[5];
      if ( (v18 == 1 || !v18) && (a1[3] & 1) == 0 )
        KeBugCheck2(290, 11, a1[7], a1[6], 0, 0);
LABEL_31:
      WheapFreeErrorRecord(v15);
      return v11;
    }
    v11 = 0;
    if ( (v15[33] & 2) != 0 )
    {
      WheapCompressErrorRecord(3, v15 + 7);
      goto LABEL_28;
    }
    if ( !WheapPolicyIgnoreDummyWrite )
    {
      WheapCompressErrorRecord(0, v15 + 7);
      PshedWriteErrorRecord(1, v15[12], v15 + 7);
    }
    v19 = a1[5];
    if ( v19 == 1 )
    {
      PshedFinalizeErrorRecord(v15 + 7, v9 + 73);
      WheapCompressErrorRecord(3, v15 + 7);
    }
    else
    {
      if ( v19 == 2 || v19 == 3 )
      {
        PshedFinalizeErrorRecord(v15 + 7, v9 + 73);
        WheapCompressErrorRecord(3, v15 + 7);
        goto LABEL_44;
      }
      if ( v19 )
      {
        WheapFreeErrorRecord(v15);
        return -1073741811;
      }
      PshedFinalizeErrorRecord(v15 + 7, v9 + 73);
      WheapAttemptErrorRecovery(v15 + 7);
      WheapCompressErrorRecord(3, v15 + 7);
      if ( v15[10] == 2 )
      {
        v15[33] |= 1u;
LABEL_28:
        if ( (v15[4] & 1) != 0 )
        {
          if ( WheapEventingInitialized == 1 )
            WheapGenerateETWEvents(v15 + 7);
          goto LABEL_31;
        }
LABEL_44:
        WheapWorkQueueAddItem(*(_DWORD *)(v5 + 8), v15);
        return v11;
      }
    }
    PshedWriteErrorRecord(0, v15[12], v15 + 7);
    WheapAddToDumpFile(v15 + 7, v15[12]);
    PshedBugCheckSystem(v9 + 73, v15 + 7);
    return v11;
  }
  ++*(_DWORD *)(v9 + 8);
  v16 = a1[5];
  if ( (v16 == 1 || !v16) && (a1[3] & 1) == 0 )
    KeBugCheck2(290, 10, a1[7], a1[6], 0, 0);
  return -1073741670;
}
