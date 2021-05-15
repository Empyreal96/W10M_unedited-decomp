// PfSnActivateTrace 
 
int __fastcall PfSnActivateTrace(int a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r1
  unsigned int v4; // r4
  int v6; // r8
  unsigned int v7; // r1
  int v8; // r5
  void **v9; // r1

  __pld(dword_63734C);
  v2 = dword_63734C[0] & 0xFFFFFFFE;
  v3 = (dword_63734C[0] & 0xFFFFFFFE) + 2;
  do
    v4 = __ldrex(dword_63734C);
  while ( v4 == v2 && __strex(v3, dword_63734C) );
  __dmb(0xBu);
  if ( v4 != v2 )
    return sub_54B6C4(&PfGlobals, v3, dword_63734C);
  *(_WORD *)(a1 + 346) |= 2u;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&dword_637378);
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)&dword_637378);
    while ( __strex(1u, (unsigned int *)&dword_637378) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_637378);
  }
  v8 = PfSnAddProcessTrace(*(_DWORD *)(a1 + 264), a1);
  if ( v8 >= 0 )
  {
    v9 = (void **)dword_637374;
    *(_DWORD *)(a1 + 4) = &PfSnGlobals;
    *(_DWORD *)(a1 + 8) = v9;
    if ( *v9 != &PfSnGlobals )
      __fastfail(3u);
    *v9 = (void *)(a1 + 4);
    dword_637374 = a1 + 4;
    ++PfSnNumActiveTraces;
    v8 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_637378);
  }
  else
  {
    __dmb(0xBu);
    dword_637378 = 0;
  }
  KfLowerIrql(v6);
  return v8;
}
