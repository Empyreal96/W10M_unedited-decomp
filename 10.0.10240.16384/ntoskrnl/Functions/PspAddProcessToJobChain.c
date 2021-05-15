// PspAddProcessToJobChain 
 
int __fastcall PspAddProcessToJobChain(int a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v5; // r8
  int v6; // r9
  int v7; // r10
  _DWORD *v9; // r5
  __int16 v10; // r8
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r0
  _DWORD *i; // r4
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int v18; // r2
  int v19; // r4
  unsigned int *v20; // r5
  unsigned int v21; // lr
  unsigned __int8 *v22; // r3
  unsigned int v23; // r2
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r0
  unsigned int v28; // r1
  int v29; // [sp+0h] [bp-28h] BYREF
  int v30; // [sp+4h] [bp-24h]
  _DWORD *v31; // [sp+8h] [bp-20h]

  v30 = a3;
  v5 = (_DWORD *)a1;
  v6 = 0;
  v7 = 0;
  v29 = a4;
  v31 = (_DWORD *)a1;
  v9 = (_DWORD *)a1;
  if ( (_DWORD *)a1 != a2 )
  {
    v10 = a4;
    do
    {
      v11 = v9[35];
      if ( v11 != -1 )
        v9[35] = v11 + 1;
      v12 = v9[170] + 1;
      ++v9[36];
      v9[170] = v12;
      if ( (v10 & 0x8000) != 0 )
        return sub_7C1B5C();
      v13 = PspValidateJobLimitsDuringAssignment(v9, a3);
      if ( v13 < 0 )
        goto LABEL_40;
      if ( !v7 )
      {
        v14 = v9[180];
        if ( v14 )
        {
          v25 = *(_DWORD *)(a3 + 804);
          v7 = 1;
          if ( v14 != v25 )
          {
            if ( v25 )
              PspRemoveProcessFromSilo();
            v13 = PspAddProcessToSilo(v9[180], a3);
            if ( v13 < 0 )
LABEL_40:
              v6 = v13;
          }
        }
      }
      v9 = (_DWORD *)v9[143];
    }
    while ( v9 != a2 );
    v5 = v31;
    if ( v6 < 0 )
      return v6;
  }
  for ( i = v5; i != a2; i = (_DWORD *)i[143] )
  {
    __dmb(0xBu);
    v16 = i + 186;
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 & 0xFFDFFFFF, v16) );
    __dmb(0xBu);
    if ( i[53] && (i[107] & 0x40) != 0 )
      PspSendJobNotification((int)i);
  }
  PspApplyJobLimitsToProcess(a3, 0);
  if ( v5[134] )
  {
    if ( a2 && a2[134] || PsCpuFairShareEnabled )
      PspSetProcessSchedulingGroup(a3, 0);
    PspSetProcessSchedulingGroup(a3, v5[134]);
  }
  v18 = v5[97];
  if ( !v18
    || a2 && a2[97]
    || ((v29 = v18 + 704, *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) != 1) ? (v26 = 0) : (v26 = 6),
        v30 = v26,
        v6 = PspIoRateControlProcessCallback(a3, &v29),
        v6 >= 0) )
  {
    v19 = 0;
    if ( v5[104] )
      v19 = 2;
    if ( v5[102] )
      v19 |= 1u;
    v20 = (unsigned int *)(a3 + 188);
    v21 = *(_DWORD *)(a3 + 188);
    __dmb(0xBu);
    do
    {
      v27 = v21;
      __dmb(0xBu);
      do
        v28 = __ldrex(v20);
      while ( v28 == v21 && __strex(v21 & 0xCFFFFFFF | (v19 << 28), v20) );
      v21 = v28;
      __dmb(0xBu);
    }
    while ( v28 != v27 );
    if ( v5[103] && (!a2 || !a2[103]) )
      PspNotifyProcessBackgroundTransition(a3, 1);
    if ( (v5[186] & 0x40000) != 0 )
    {
      __dmb(0xBu);
      v22 = (unsigned __int8 *)(a3 + 100);
      do
        v23 = __ldrex(v22);
      while ( __strex(v23 | 0x10, v22) );
      __dmb(0xBu);
    }
    RtlInterlockedSetClearBits((unsigned int *)(a3 + 188), 4);
  }
  return v6;
}
