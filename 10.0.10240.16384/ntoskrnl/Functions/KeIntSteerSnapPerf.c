// KeIntSteerSnapPerf 
 
int __fastcall KeIntSteerSnapPerf(int a1, unsigned int *a2)
{
  unsigned int *v2; // r7
  __int64 v3; // r0
  unsigned int v4; // r8
  unsigned int v5; // r10
  int v6; // r0
  unsigned int v7; // r1
  unsigned __int64 v8; // kr00_8
  unsigned int v9; // r5
  unsigned int v10; // r6
  unsigned int v12; // r2
  int *v13; // r9
  int v14; // r4
  int v15; // r1
  int v16; // r8
  int v17; // r6
  unsigned int v18; // r7
  unsigned int v19; // r0
  unsigned int v20; // r5
  unsigned int v21; // lr
  int *v22; // r8
  int v23; // t1
  unsigned __int64 v24; // kr08_8
  unsigned __int64 v25; // kr10_8
  __int64 v26; // kr20_8
  __int64 v27; // kr28_8
  __int64 v28; // kr38_8
  __int64 v29; // kr40_8
  int v30; // r0
  int *v31; // r3
  __int64 v32; // kr30_8
  __int64 v33; // kr48_8
  unsigned __int64 v34; // [sp+0h] [bp-58h]
  unsigned __int64 v35; // [sp+8h] [bp-50h]
  unsigned int v37; // [sp+14h] [bp-44h]
  unsigned int v38; // [sp+18h] [bp-40h]
  int v39; // [sp+1Ch] [bp-3Ch]
  unsigned int v40; // [sp+24h] [bp-34h]
  unsigned int v41; // [sp+30h] [bp-28h] BYREF
  int *v42; // [sp+38h] [bp-20h]

  v2 = a2;
  v42 = (int *)a1;
  v3 = RtlGetInterruptTimePrecise(&v41);
  v4 = HIDWORD(v3);
  v37 = HIDWORD(v3);
  v38 = v3;
  v5 = v3;
  v6 = _rt_udiv64(1000000i64, *(_QWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x948));
  v40 = v7;
  v41 = v6;
  v8 = __PAIR64__(v4, v5) - KiIntSteerPreviousPerfSnap;
  if ( __PAIR64__(v4, v5) - KiIntSteerPreviousPerfSnap < 0x186A0 )
  {
    v30 = KiIntSteerLoadPercent;
  }
  else
  {
    v9 = 0;
    v10 = 0;
    KiIntSteerPreviousPerfSnap = __PAIR64__(v4, v5);
    v35 = 0i64;
    v39 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_540FE4();
    do
      v12 = __ldrex((unsigned int *)&KiIntTrackSpinlock);
    while ( __strex(1u, (unsigned int *)&KiIntTrackSpinlock) );
    __dmb(0xBu);
    if ( v12 )
      KxWaitForSpinLockAndAcquire(&KiIntTrackSpinlock);
    v13 = (int *)KiIntTrackRootList;
    if ( (int *)KiIntTrackRootList != &KiIntTrackRootList )
    {
      do
      {
        v14 = v13[2];
        v15 = 0;
        v34 = 0i64;
        v16 = 0;
        if ( (int *)v14 != v13 + 2 )
        {
          do
          {
            v17 = *(_DWORD *)(v14 + 12);
            v18 = 0;
            v19 = 0;
            v20 = 0;
            v21 = 0;
            if ( v17 )
            {
              v22 = *(int **)(v14 + 16);
              do
              {
                v23 = *v22++;
                v24 = __PAIR64__(v20, v19) + *(_QWORD *)(v23 + 104);
                v20 = HIDWORD(v24);
                v19 = v24;
                v25 = __PAIR64__(v21, v18) + *(_QWORD *)(v23 + 128);
                v21 = HIDWORD(v25);
                v18 = v25;
                --v17;
              }
              while ( v17 );
              v16 = HIDWORD(v34);
              v15 = v34;
            }
            v26 = *(_QWORD *)(v14 + 24);
            *(_DWORD *)(v14 + 24) = v19;
            *(_DWORD *)(v14 + 28) = v20;
            v27 = __PAIR64__(v20, v19) - v26;
            if ( (__int64)(__PAIR64__(v20, v19) - v26) > 0 )
            {
              v32 = __PAIR64__(v16, v15) + v27;
              v16 = (__PAIR64__(v16, v15) + v27) >> 32;
              v15 = v32;
              v34 = __PAIR64__(v16, v32);
            }
            v28 = *(_QWORD *)(v14 + 32);
            *(_DWORD *)(v14 + 32) = v18;
            *(_DWORD *)(v14 + 36) = v21;
            v29 = __PAIR64__(v21, v18) - v28;
            if ( (__int64)(__PAIR64__(v21, v18) - v28) > 0 )
            {
              v33 = __PAIR64__(v16, v15) + v29;
              v16 = (__PAIR64__(v16, v15) + v29) >> 32;
              v15 = v33;
              v34 = __PAIR64__(v16, v33);
            }
            v14 = *(_DWORD *)v14;
          }
          while ( (int *)v14 != v13 + 2 );
          v10 = HIDWORD(v35);
          v9 = v35;
        }
        v13[36] = v15;
        v13[37] = v16;
        v13 = (int *)*v13;
        v10 = (__PAIR64__(v10, v9) + __PAIR64__(v16, v15)) >> 32;
        v9 += v15;
        v35 = __PAIR64__(v10, v9);
      }
      while ( v13 != &KiIntTrackRootList );
      v2 = a2;
      v4 = v37;
      v5 = v38;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KiIntTrackSpinlock);
    }
    else
    {
      __dmb(0xBu);
      KiIntTrackSpinlock = 0;
    }
    KfLowerIrql(v39);
    if ( !(v8 * __PAIR64__(v40, v41)) )
      __brkdiv0();
    v30 = _rt_udiv64(v8 * __PAIR64__(v40, v41), 10000 * __PAIR64__(v10, v9));
    KiIntSteerLoadPercent = v30;
  }
  v31 = v42;
  *v2 = v5;
  v2[1] = v4;
  *v31 = v30;
  return 0;
}
