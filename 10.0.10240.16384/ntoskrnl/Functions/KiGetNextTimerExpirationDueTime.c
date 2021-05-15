// KiGetNextTimerExpirationDueTime 
 
int __fastcall KiGetNextTimerExpirationDueTime(__int64 a1, unsigned int a2, unsigned int a3, unsigned __int8 a4, unsigned int *a5, int *a6)
{
  int v6; // r5
  unsigned int v7; // r10
  int v8; // r6
  int v9; // r8
  int v10; // r9
  unsigned int v11; // lr
  unsigned int v12; // r7
  unsigned __int64 v13; // r4
  int v14; // r3
  unsigned __int64 *v15; // r2
  unsigned __int64 v16; // kr08_8
  unsigned __int64 v17; // kr10_8
  int v18; // r3

  v6 = a1;
  v7 = a3;
  v8 = HIDWORD(a1);
  if ( *(_DWORD *)(a1 + 8) )
  {
    *a5 = 0;
    a5[1] = 0;
    *a6 = 1;
    return a1;
  }
  if ( !*(_BYTE *)(a1 + 17) && !KiSerializeTimerExpiration )
  {
    LODWORD(a1) = sub_54204C();
    return a1;
  }
  v9 = a4;
  v10 = 4;
  if ( a4 )
    LODWORD(a1) = ExGetNextWakeTimeForDeepSleep();
  else
    a1 = KiFindNextTimerDueTime(a1, HIDWORD(a1), a2, a3, HIDWORD(a1));
  v11 = HIDWORD(a1);
  v12 = a1;
  if ( KiGroupSchedulingEnabled )
  {
    if ( v8 )
    {
      if ( !dword_6162DC )
        goto LABEL_10;
    }
    else if ( (((unsigned int)dword_6162DC >> *(_DWORD *)(v6 + 20)) & 1) == 0 )
    {
      goto LABEL_10;
    }
    LODWORD(a1) = KeMaximumIncrement;
    if ( KiGenerationEndTick * (unsigned __int64)(unsigned int)KeMaximumIncrement < __PAIR64__(HIDWORD(a1), v12) )
    {
      v12 = KeMaximumIncrement * KiGenerationEndTick;
      v11 = (KiGenerationEndTick * (unsigned __int64)(unsigned int)KeMaximumIncrement) >> 32;
      v10 = 5;
    }
  }
LABEL_10:
  if ( *(_BYTE *)(v6 + 17) )
  {
    v13 = -1i64;
    if ( !a4 )
    {
      v14 = 0;
      v15 = &KiTimer2Collections[1];
      do
      {
        if ( v14 != 3 )
        {
          do
            v16 = __ldrexd(v15);
          while ( !v16 && __strexd(0i64, v15) );
          if ( v16 < v13 )
            v13 = v16;
        }
        ++v14;
        v15 += 2;
      }
      while ( v14 < 5 );
      v7 = a3;
    }
    LODWORD(a1) = 0;
    do
      v17 = __ldrexd(&KiTimer2Collections[3]);
    while ( !v17 && __strexd(0i64, &KiTimer2Collections[3]) );
    v9 = a4;
    if ( v17 < v13 )
    {
      v13 = v17;
      LODWORD(a1) = 1;
    }
    if ( v13 < __PAIR64__(v11, v12) )
    {
      v11 = HIDWORD(v13);
      v12 = v13;
      v10 = 6;
      if ( (_DWORD)a1 )
        v10 = 7;
    }
  }
  if ( v8 && !KdDebuggerNotPresent && KdDebuggerEnabled && v7 <= v11 && (v7 < v11 || a2 < v12) )
  {
    v18 = 20000000;
    if ( __PAIR64__(v11, v12) - __PAIR64__(v7, a2) > 0x1312D00 )
    {
      if ( v9 )
        v18 = 150000000;
      v11 = (__PAIR64__(v7, a2) + (unsigned int)v18) >> 32;
      v12 = a2 + v18;
      v10 = 8;
    }
  }
  *a5 = v12;
  a5[1] = v11;
  *a6 = v10;
  return a1;
}
