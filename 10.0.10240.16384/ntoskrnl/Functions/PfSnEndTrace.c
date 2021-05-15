// PfSnEndTrace 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfSnEndTrace(_DWORD *a1)
{
  char v2; // r10
  int v4; // r2
  int v5; // r1
  int v6; // r0
  int v7; // r0
  int *v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r9
  unsigned int v12; // r1
  unsigned __int8 v13; // r5
  unsigned int v14; // r1
  unsigned int v15; // r1
  int **v16; // r1
  unsigned int i; // r2
  unsigned int v18; // r0
  int v19; // r1 OVERLAPPED
  int *v20; // [sp+4h] [bp-78h] BYREF

  v2 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) = 0;
  PfSnDeactivateTrace((int)a1);
  if ( a1 && qword_637408 && EtwEventEnabled(qword_637408, SHIDWORD(qword_637408), (int)PfSnEvt_EndTrace_Info) )
    return sub_808D40();
  v4 = a1[62];
  if ( a1[60] > v4 )
    a1[60] = v4;
  v5 = a1[61];
  if ( v5 < dword_637274 )
  {
    a1[v5 + 50] = v4 - a1[60];
    a1[60] = a1[62];
    ++a1[61];
  }
  else
  {
    if ( v5 > 10 )
      a1[61] = 10;
    v6 = a1[60];
    if ( v6 != v4 )
      a1[a1[61] + 49] += v4 - v6;
  }
  if ( a1[19] != 1 || a1[72] == 8 )
  {
    v7 = PfSnBuildDumpFromTrace(&v20, a1);
    v8 = v20;
    v9 = v7;
  }
  else
  {
    v8 = 0;
    v9 = -2147483614;
  }
  a1[79] = v8;
  a1[80] = v9;
  PfSnCleanupTrace(a1);
  ExFreePoolWithTag((unsigned int)a1);
  if ( v9 >= 0 )
  {
    PfFbBufferListFlushStandby(qword_6439A0);
    v10 = KeAbPreAcquire((unsigned int)&dword_637384, 0, 0);
    v11 = KfRaiseIrql(1);
    do
      v12 = __ldrex((unsigned __int8 *)&dword_637384);
    while ( __strex(v12 & 0xFE, (unsigned __int8 *)&dword_637384) );
    __dmb(0xBu);
    if ( (v12 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&dword_637384, v10);
    if ( v10 )
      *(_BYTE *)(v10 + 14) |= 1u;
    dword_637388 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6373A0 = v11;
    if ( dword_6373A8 == 1 )
    {
      dword_637388 = 0;
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)&dword_637384);
      while ( !v15 && __strex(1u, (unsigned int *)&dword_637384) );
      if ( v15 )
        ExpReleaseFastMutexContended((unsigned int *)&dword_637384, v15);
      KfLowerIrql((unsigned __int8)v11);
      KeAbPostRelease((unsigned int)&dword_637384);
      ExFreePoolWithTag((unsigned int)v8);
    }
    else
    {
      v16 = (int **)dword_637380;
      *v8 = (int)&dword_63737C;
      v8[1] = (int)v16;
      if ( *v16 != &dword_63737C )
        __fastfail(3u);
      *v16 = v8;
      dword_637380 = (int)v8;
      for ( i = dword_6373A4 + 1; ; i = dword_6373A4 - 1 )
      {
        dword_6373A4 = i;
        if ( i <= dword_63710C )
          break;
        v18 = dword_63737C;
        if ( (int *)dword_63737C == &dword_63737C )
          break;
        *(_QWORD *)&v19 = *(_QWORD *)dword_63737C;
        if ( *(int **)(dword_63737C + 4) != &dword_63737C || *(_DWORD *)(v19 + 4) != dword_63737C )
          __fastfail(3u);
        dword_63737C = v19;
        *(_DWORD *)(v19 + 4) = &dword_63737C;
        ExFreePoolWithTag(v18);
      }
      dword_637388 = 0;
      v13 = dword_6373A0;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)&dword_637384);
      while ( !v14 && __strex(1u, (unsigned int *)&dword_637384) );
      if ( v14 )
        ExpReleaseFastMutexContended((unsigned int *)&dword_637384, v14);
      KfLowerIrql(v13);
      KeAbPostRelease((unsigned int)&dword_637384);
      if ( dword_6373AC )
        KeSetEvent(dword_6373AC, 0, 0);
      v9 = 0;
    }
  }
  *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) = v2;
  return v9;
}
