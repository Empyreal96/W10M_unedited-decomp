// KeQueryCpuSetsProcess 
 
int __fastcall KeQueryCpuSetsProcess(int a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v6; // r5
  unsigned int *v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r2
  int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a4;
  if ( a4 )
    v6 = (_DWORD *)(a1 + 880);
  else
    v6 = (_DWORD *)(a1 + 884);
  KiAcquireProcessLockShared(a1, v11);
  v7 = (unsigned int *)(a1 + 48);
  *a2 = *v6;
  a2[1] = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7);
  }
  else
  {
    __dmb(0xBu);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 & 0xBFFFFFFF, v7) );
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( __strex(v9 - 1, v7) );
  }
  KfLowerIrql(LOBYTE(v11[0]));
  return 1;
}
