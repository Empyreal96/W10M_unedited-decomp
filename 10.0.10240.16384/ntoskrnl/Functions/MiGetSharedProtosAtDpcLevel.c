// MiGetSharedProtosAtDpcLevel 
 
int __fastcall MiGetSharedProtosAtDpcLevel(int a1, int a2, int a3)
{
  unsigned int *v5; // r5
  int v6; // r4
  unsigned int v7; // r1
  int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r2

  v5 = (unsigned int *)(a1 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(a1 + 36);
  }
  else
  {
    v6 = *v5 & 0x7FFFFFFF;
    do
      v7 = __ldrex(v5);
    while ( v7 == v6 && __strex(v6 + 1, v5) );
    __dmb(0xBu);
    if ( v7 != v6 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(a1 + 36));
  }
  v8 = MiLocateSessionProtosInSubsection(a3, a2);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v5);
  }
  else
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(v5);
    while ( __strex(v9 & 0xBFFFFFFF, v5) );
    __dmb(0xBu);
    do
      v10 = __ldrex(v5);
    while ( __strex(v10 - 1, v5) );
  }
  return v8;
}
