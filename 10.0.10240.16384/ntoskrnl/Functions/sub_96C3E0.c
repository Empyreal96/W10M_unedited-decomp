// sub_96C3E0 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_96C3E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  __int64 v13; // r0
  unsigned __int64 v14; // kr00_8
  unsigned int v15; // r5
  unsigned int v16; // r4
  __int64 v17; // kr08_8
  unsigned __int64 v18; // r0
  int v19; // r5
  int *v20; // r7
  __int64 *v21; // r8
  unsigned int v22; // r9
  unsigned int v23; // r10
  __int64 v24; // r0
  int v25; // r4
  unsigned int v26; // r6
  unsigned int v27; // r5
  unsigned int v28; // r4
  unsigned int v29; // r0
  char v30; // r0

  while ( 1 )
  {
    LODWORD(v24) = ReadTimeStampCounter();
    __pld(v21);
    *(_QWORD *)(v20 + 1) = v24;
    v25 = *(_DWORD *)v21;
    __dmb(0xBu);
    do
      v26 = __ldrex((unsigned int *)v21);
    while ( v26 == v25 && __strex(v25 + 1, (unsigned int *)v21) );
    __dmb(0xBu);
    if ( v26 != v25 )
    {
      do
      {
        v27 = v26;
        __dmb(0xBu);
        do
          v28 = __ldrex((unsigned int *)v21);
        while ( v28 == v26 && __strex(v26 + 1, (unsigned int *)v21) );
        v26 = v28;
        __dmb(0xBu);
      }
      while ( v28 != v27 );
      v19 = *v20;
    }
    LODWORD(v13) = ReadTimeStampCounter();
    v14 = __PAIR64__(v22, v23) + v13 - *(_QWORD *)(v20 + 1);
    v22 = HIDWORD(v14);
    v23 = v14;
    *v20 = --v19;
    if ( !v19 )
    {
      KfLowerIrql(v20[4]);
      v15 = (__int64)v14 >> 10;
      v16 = HIDWORD(v14) >> 10;
      KeGenericCallDpc((int)ExpAeThresholdInitWorker, (int)v21);
      v17 = v21[16];
      v20[4] = v17 >> 9;
      if ( !*((_DWORD *)v21 + 34) )
        __brkdiv0();
      LODWORD(v18) = _rt_udiv64(
                       *((int *)v21 + 34),
                       (__int64)(__PAIR64__(*((_DWORD *)v21 + 33), v17) + ((unsigned int)(SHIDWORD(v17) >> 9) >> 22)) >> 10);
      if ( v18 >= 4 * __PAIR64__(v16, v15) )
      {
        if ( v16 )
          v29 = 63 - __clz(v16);
        else
          v29 = 31 - __clz(v15);
        if ( v29 < 2 )
          v30 = 0;
        else
          v30 = v29 - 2;
        if ( (unsigned int)((__int64)((v14 >> 12) + (v14 >> 10)) >> 25) >> v30 )
          ExpAeCycleCountThreshold = -1;
        else
          ExpAeCycleCountThreshold = ((v14 >> 12) + (v14 >> 10)) << 7 >> v30;
        ExpAeSamplingPeriodMask = 15728640;
        ExpAeCycleCountScaler = v30;
      }
      else
      {
        ExpAeCycleCountThreshold = -1;
        ExpAeCycleCountScaler = -1;
        ExpAeSamplingPeriodMask = -1;
      }
      __asm { POP.W           {R4-R11,PC} }
    }
  }
}
