// PpmEstimateIdleDuration 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PpmEstimateIdleDuration(int a1, int a2, unsigned int a3, unsigned int a4, unsigned __int64 a5, _QWORD *a6, _DWORD *a7, int a8, _DWORD *a9)
{
  _QWORD *v9; // r8
  _DWORD *v10; // r9
  unsigned int v12; // r5 OVERLAPPED
  int v13; // r6 OVERLAPPED
  int result; // r0
  unsigned int v15; // r3
  unsigned int v16; // r4
  unsigned int i; // r2
  unsigned int v18; // r1
  __int64 v19; // r2
  _DWORD *v20; // lr
  unsigned int v21; // r0
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r10
  void **v25; // r7
  int v26; // t1
  int v27; // r3
  unsigned int v28; // r0
  unsigned int v29; // r4
  unsigned int v30; // r7
  int v31; // r3
  unsigned int v32; // r7
  unsigned int v33; // lr
  unsigned __int64 v34; // kr00_8
  unsigned __int64 v38; // [sp+28h] [bp-28h]

  v9 = a6;
  v10 = a7;
  *a9 = 0;
  v12 = -1;
  v13 = -1;
  if ( *(_BYTE *)(a1 + 17) )
    *a9 = 8;
  if ( a2 )
    return sub_54FCFC();
  KeEstimateClockTickDuration(a1);
  v15 = *(_DWORD *)(a1 + 1784);
  v16 = 0;
  for ( i = v15; i; v16 += KeMaximumIncrement )
    i >>= 4;
  if ( v15 )
  {
    v21 = v15 + 1;
    if ( v15 == -1 )
      __brkdiv0();
    v12 = KeMaximumIncrement / v21;
    if ( !(KeMaximumIncrement / v21) )
      v12 = 1;
    v13 = 0;
  }
  v18 = HIDWORD(v38);
  LODWORD(v19) = v38;
  if ( v38 > __PAIR64__(v13, v12) )
  {
    if ( v38 >= v16 )
    {
      LODWORD(v19) = v16;
      v18 = 0;
    }
    v20 = a9;
    *a9 |= 1u;
  }
  else
  {
    v20 = a9;
    v13 = HIDWORD(v38);
    v12 = v38;
  }
  if ( PpmIdleCheckIdleDurationExpiration )
  {
    if ( *(_BYTE *)(a1 + 17) )
    {
      v22 = (unsigned __int16)KeNumberNodes;
      v23 = 0;
      v24 = 0;
      if ( KeNumberNodes )
      {
        v25 = &KeNodeBlock;
        do
        {
          v26 = (int)*v25++;
          v27 = *(_DWORD *)(v26 + 132);
          v24 |= v27;
          if ( v27 )
            v23 = 1;
          --v22;
        }
        while ( v22 );
        if ( v23 )
        {
          v28 = 0;
          v29 = 0;
          while ( v24 )
          {
            v30 = __clz(__rbit(v24));
            v24 &= ~(1 << v30);
            if ( v30 >= KeNumberProcessors_0 )
              v31 = 0;
            else
              v31 = (int)*(&KiProcessorBlock + v30);
            v32 = *(_DWORD *)(v31 + 2976);
            v33 = *(_DWORD *)(v31 + 2980);
            if ( (v32 & v33) != -1 && __PAIR64__(v33, v32) > __PAIR64__(v29, v28) )
            {
              v28 = *(_DWORD *)(v31 + 2976);
              v29 = *(_DWORD *)(v31 + 2980);
            }
          }
          v9 = a6;
          v10 = a7;
          if ( v28 | v29 && (HIDWORD(v19) = a4, v19 + __PAIR64__(v18, a3) > __PAIR64__(v29, v28)) )
          {
            v20 = a9;
            *a9 |= 0x2000u;
            if ( v29 > a4 || v29 >= a4 && v28 > a3 )
              LODWORD(v19) = v28 - a3;
            else
              LODWORD(v19) = 1;
            v18 = 0;
            if ( v13 || (unsigned int)v19 < v12 )
            {
              v12 = v19;
              v13 = 0;
            }
          }
          else
          {
            v20 = a9;
          }
        }
      }
    }
  }
  result = HIDWORD(a5);
  if ( __PAIR64__(v13, v12) < a5 )
  {
    v34 = a5;
    v13 = HIDWORD(v34);
    v12 = v34;
    v18 = HIDWORD(a5);
    LODWORD(v19) = a5;
    *v20 |= 0x1000u;
  }
  *v10 = v19;
  v10[1] = v18;
  *v9 = *(_QWORD *)&v12;
  return result;
}
