// PfSnRemoveProcessTrace 
 
int __fastcall PfSnRemoveProcessTrace(int a1)
{
  unsigned int *v1; // r2
  unsigned int v2; // r1
  unsigned int v3; // r7
  int v4; // r5
  unsigned int *v5; // r0
  int v6; // r1
  unsigned int v7; // r4
  int v9; // r6
  unsigned int v10; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 420);
  do
    v2 = __ldrex(v1);
  while ( __strex(0, v1) );
  __dmb(0xBu);
  v3 = v2 & 0xFFFFFFF8;
  v4 = v2 & 7;
  if ( (v2 & 7) != 0 )
  {
    v5 = (unsigned int *)(v3 + 268);
    __pld((void *)(v3 + 268));
    v6 = *(_DWORD *)(v3 + 268);
    if ( (v6 & 1) != 0 )
      JUMPOUT(0x54B83C);
    __dmb(0xBu);
    do
      v7 = __ldrex(v5);
    while ( v7 == v6 && __strex(v6 - 2 * v4, v5) );
    __dmb(0xBu);
    if ( v7 != v6 )
      return sub_54B834();
  }
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&dword_637378);
  }
  else
  {
    do
      v10 = __ldrex((unsigned int *)&dword_637378);
    while ( __strex(1u, (unsigned int *)&dword_637378) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_637378);
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
  KfLowerIrql(v9);
  return v3;
}
