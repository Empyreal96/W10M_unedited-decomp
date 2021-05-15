// KiReleaseQueuedSpinLockInstrumented 
 
int __fastcall KiReleaseQueuedSpinLockInstrumented(int *a1, int a2)
{
  int v4; // r8
  int v5; // r0
  int v6; // r1
  int v7; // r7
  unsigned int *v8; // r2
  unsigned int v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r0

  v4 = ReadTimeStampCounter();
  v5 = *a1;
  v7 = v6;
  if ( *a1 )
    goto LABEL_7;
  v8 = (unsigned int *)a1[1];
  __dmb(0xBu);
  do
    v9 = __ldrex(v8);
  while ( (int *)v9 == a1 && __strex(0, v8) );
  if ( (int *)v9 != a1 )
  {
    v5 = KxWaitForLockChainValid(a1);
LABEL_7:
    *a1 = 0;
    __dmb(0xBu);
    v10 = (unsigned int *)(v5 + 4);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 ^ 1, v10) );
  }
  return PerfLogSpinLockRelease(a1[1], a2, v4, v7);
}
