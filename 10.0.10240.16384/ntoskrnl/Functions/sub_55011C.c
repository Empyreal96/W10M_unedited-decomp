// sub_55011C 
 
void __fastcall sub_55011C(int a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  int v6; // r9
  int v7; // r10
  int v8; // r0
  unsigned int *v9; // r1
  int *v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13[12]; // [sp+0h] [bp-30h] BYREF

  if ( (*(_DWORD *)(v7 + 4) & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v13, v13[11]);
    goto LABEL_12;
  }
  v8 = a5;
  if ( !a5 )
  {
    v9 = a6;
    __dmb(0xBu);
    do
      v10 = (int *)__ldrex(v9);
    while ( v10 == &a5 && __strex(0, v9) );
    if ( v10 == v13 )
    {
LABEL_12:
      KfLowerIrql(v6);
      JUMPOUT(0x4EBDFC);
    }
    v8 = KxWaitForLockChainValid(v13);
  }
  v13[0] = 0;
  __dmb(0xBu);
  v11 = (unsigned int *)(v8 + 4);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 ^ 1, v11) );
  goto LABEL_12;
}
