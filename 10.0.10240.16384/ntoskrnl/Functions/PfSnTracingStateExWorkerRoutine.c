// PfSnTracingStateExWorkerRoutine 
 
unsigned int __fastcall PfSnTracingStateExWorkerRoutine(unsigned int a1)
{
  int v2; // r5
  int v3; // r6
  unsigned int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r0
  __int64 v7; // kr00_8
  unsigned __int8 v8; // r5
  unsigned int v9; // r1

  v2 = KeAbPreAcquire((unsigned int)&dword_637384, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_637384);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&dword_637384) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&dword_637384, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_637388 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6373A0 = v3;
  if ( dword_6373A8 == 2 )
  {
    dword_637388 = 0;
    __dmb(0xBu);
    do
      v5 = __ldrex((unsigned int *)&dword_637384);
    while ( !v5 && __strex(1u, (unsigned int *)&dword_637384) );
    if ( v5 )
      ExpReleaseFastMutexContended((unsigned int *)&dword_637384, v5);
    KfLowerIrql((unsigned __int8)v3);
    KeAbPostRelease((unsigned int)&dword_637384);
  }
  else
  {
    dword_6373A8 = 1;
    while ( (int *)dword_63737C != &dword_63737C )
    {
      v6 = dword_637380;
      v7 = *(_QWORD *)dword_637380;
      if ( *(int **)dword_637380 != &dword_63737C || *(_DWORD *)HIDWORD(v7) != dword_637380 )
        __fastfail(3u);
      dword_637380 = *(_DWORD *)(dword_637380 + 4);
      *(_DWORD *)HIDWORD(v7) = &dword_63737C;
      ExFreePoolWithTag(v6);
      --dword_6373A4;
    }
    dword_637388 = 0;
    v8 = dword_6373A0;
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)&dword_637384);
    while ( !v9 && __strex(1u, (unsigned int *)&dword_637384) );
    if ( v9 )
      ExpReleaseFastMutexContended((unsigned int *)&dword_637384, v9);
    KfLowerIrql(v8);
    KeAbPostRelease((unsigned int)&dword_637384);
    if ( dword_6373AC )
      KeSetEvent(dword_6373AC, 0, 0);
  }
  return ExFreePoolWithTag(a1);
}
