// PopDripsWatchdogWorkerRoutine 
 
int __fastcall PopDripsWatchdogWorkerRoutine(int a1)
{
  int v2; // r2
  int v3; // r3
  int result; // r0
  unsigned int v5; // r1
  int v6; // r3
  unsigned int v7; // r9
  unsigned int v8; // r10
  int v9; // r6
  int v10; // r7
  unsigned __int64 v11; // kr08_8
  unsigned int v12; // r1
  unsigned int v13; // r3
  __int64 v14; // r2
  __int64 v15; // kr20_8
  unsigned int v16; // r2
  int v17; // r0
  __int64 v18; // r0
  int v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  unsigned int v25; // r1
  int v26; // r0
  unsigned int v27; // [sp+0h] [bp-60h]
  int v28; // [sp+4h] [bp-5Ch]
  int v29; // [sp+8h] [bp-58h]
  int v30; // [sp+Ch] [bp-54h]
  char v31; // [sp+1Ch] [bp-44h]
  int v32; // [sp+20h] [bp-40h]
  int v33[14]; // [sp+28h] [bp-38h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite((int)&byte_637480[24], 1, v2, v3);
  if ( qword_637460 )
  {
    memset(v33, 0, 24);
    v31 = *(_BYTE *)(a1 + 4);
    v7 = *(_DWORD *)(a1 + 44);
    v8 = *(_DWORD *)(a1 + 40);
    v9 = *(_DWORD *)(a1 + 80);
    v10 = *(_DWORD *)(a1 + 8);
    v11 = *(_QWORD *)(a1 + 72) - *(_QWORD *)(a1 + 16);
    if ( v9 == v10 )
    {
      v12 = *(_DWORD *)(a1 + 28);
      v13 = *(_DWORD *)(a1 + 24);
    }
    else
    {
      v12 = *(_DWORD *)(a1 + 36);
      v13 = *(_DWORD *)(a1 + 32);
    }
    v32 = _rt_udiv64(10000i64, __PAIR64__(v7, v8) - __PAIR64__(v12, v13));
    v33[0] = v32;
    v33[1] = _rt_udiv64(10000i64, __PAIR64__(v7, v8) - *(_QWORD *)(a1 + 32));
    HIDWORD(v14) = 1000;
    if ( v9 == v10 )
    {
      v15 = 1000i64 * (unsigned int)v32;
      HIDWORD(v14) = v15 | HIDWORD(v15);
      if ( !v15
        || (HIDWORD(v14) = dword_61ED98, (dword_61ED98 & 0x40000000) != 0)
        || (v16 = *(_DWORD *)(a1 + 12), dword_61ED88 >= v16) )
      {
        v17 = 0;
      }
      else
      {
        v17 = PopBatteryCapacityToRate(v16 - dword_61ED88, v15);
      }
      v33[4] = v17;
    }
    LODWORD(v14) = a1 + 56;
    HIDWORD(v18) = a1 + 48;
    LODWORD(v18) = 0;
    PopAccumulateNonActivatedCpuTime(v18, v14);
    v33[2] = PpmConvertTimeTo(*(_DWORD *)(a1 + 56), *(_DWORD *)(a1 + 60));
    if ( v9 != v10 )
    {
      v19 = *(_DWORD *)(a1 + 72);
      *(_DWORD *)(a1 + 8) = v9;
      *(_DWORD *)(a1 + 24) = v8;
      *(_DWORD *)(a1 + 28) = v7;
      *(_DWORD *)(a1 + 16) = v19;
      *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 76);
      *(_DWORD *)(a1 + 12) = dword_61ED88;
    }
    *(_DWORD *)(a1 + 32) = v8;
    *(_DWORD *)(a1 + 36) = v7;
    PopSetDripsWatchdog();
    __dmb(0xBu);
    v20 = (unsigned int *)(a1 + 248);
    do
      v21 = __ldrex(v20);
    while ( __strex(0, v20) );
    __dmb(0xBu);
    v22 = ExReleaseResourceLite((int)&byte_637480[24]);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x134) + 1;
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v22);
    LOBYTE(v33[5]) = byte_635410 & 1;
    v25 = 100 * v33[2];
    if ( !v33[1] )
      __brkdiv0();
    result = v25 / v33[1];
    v33[3] = v25 / v33[1];
    if ( (PoDebug & 2) != 0 )
    {
      v30 = v33[1];
      v29 = v33[2];
      v28 = v33[4];
      v27 = v33[0] / 0x3E8u;
      v26 = _rt_udiv64(1000000i64, v11);
      result = DbgPrint(
                 "%s: %u DRIPS transitions spanned %u of the past %u sec along with %u mW energy drain; %u ms non-activat"
                 "ed CPU time over the past %u ms\n",
                 "PopDripsWatchdogWorkerRoutine",
                 v9 - v10,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30);
    }
    if ( v9 == v10 && !*(_QWORD *)algn_6353D8 )
      result = PopDripsWatchdogTakeAction((int)v33, v31);
  }
  else
  {
    result = ExReleaseResourceLite((int)&byte_637480[24]);
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = (__int16)(*(_WORD *)(v5 + 0x134) + 1);
    *(_WORD *)(v5 + 308) = v6;
    if ( !v6 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
