// KeEstimateClockTickDuration 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeEstimateClockTickDuration(__int64 a1, unsigned __int8 a2, int a3, unsigned __int64 a4, int *a5, int *a6)
{
  int v6; // r4
  unsigned int v7; // r5 OVERLAPPED
  unsigned int v8; // r6 OVERLAPPED
  int v9; // r2
  int *v10; // r3
  int v12[2]; // [sp+10h] [bp-28h] BYREF
  __int64 v13[4]; // [sp+18h] [bp-20h] BYREF

  v6 = 2;
  v12[0] = 2;
  *(_QWORD *)&v7 = KiClockTimerNextTickTime;
  if ( !*(_BYTE *)(a1 + 17) )
  {
    LODWORD(a1) = KiGetNextTimerExpirationDueTime((unsigned int)a1, a4, HIDWORD(a4), a2, (unsigned int *)v13, v12);
    if ( __PAIR64__(v8, v7) <= v13[0] )
    {
      v8 = HIDWORD(v13[0]);
      v7 = v13[0];
    }
    goto LABEL_4;
  }
  if ( HIDWORD(a1) )
  {
    if ( KiClockState || (_BYTE)KiDynamicTickDisableReason )
      HIDWORD(a1) = 0;
    if ( HIDWORD(a1) )
    {
      HIDWORD(a1) = 1;
      KiGetNextTimerExpirationDueTime(a1, a4, HIDWORD(a4), a2, (unsigned int *)v13, v12);
      LODWORD(a1) = HIDWORD(v13[0]);
      if ( a4 + (unsigned int)KiLastRequestedTimeIncrement < v13[0] )
      {
        v8 = HIDWORD(v13[0]);
        v7 = v13[0];
LABEL_4:
        v6 = v12[0];
        goto LABEL_5;
      }
      v6 = 2;
    }
  }
LABEL_5:
  v9 = -1;
  if ( (v7 & v8) != -1 )
  {
    if ( __PAIR64__(v8, v7) > a4 )
    {
      v10 = a5;
      v9 = v7 - a4;
      a5[1] = (__PAIR64__(v8, v7) - a4) >> 32;
      goto LABEL_7;
    }
    v9 = 0;
  }
  v10 = a5;
  a5[1] = v9;
LABEL_7:
  *v10 = v9;
  *a6 = v6;
  return a1;
}
