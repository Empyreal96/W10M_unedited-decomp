// KeReleaseInStackQueuedSpinLockFromDpcLevel 
 
int __fastcall KeReleaseInStackQueuedSpinLockFromDpcLevel(int *a1)
{
  int result; // r0
  int v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int *v6; // r2

  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50D888();
  v3 = *a1;
  if ( *a1 )
    goto LABEL_9;
  v4 = (unsigned int *)a1[1];
  __dmb(0xBu);
  result = 0;
  do
    v5 = __ldrex(v4);
  while ( (int *)v5 == a1 && __strex(0, v4) );
  if ( (int *)v5 != a1 )
  {
    v3 = KxWaitForLockChainValid(a1);
LABEL_9:
    *a1 = 0;
    __dmb(0xBu);
    v6 = (unsigned int *)(v3 + 4);
    do
      result = __ldrex(v6);
    while ( __strex(result ^ 1, v6) );
  }
  return result;
}
