// KeReleaseInStackQueuedSpinLockForDpc 
 
unsigned int __fastcall KeReleaseInStackQueuedSpinLockForDpc(int *a1)
{
  unsigned int result; // r0
  int v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int *v6; // r2
  int vars4; // [sp+Ch] [bp+4h]

  if ( (*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C) & 0x10000) != 0 )
    return KeReleaseInStackQueuedSpinLock((int)a1);
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseQueuedSpinLockInstrumented(a1, vars4);
  v3 = *a1;
  if ( *a1 )
    goto LABEL_11;
  v4 = (unsigned int *)a1[1];
  __dmb(0xBu);
  result = 0;
  do
    v5 = __ldrex(v4);
  while ( (int *)v5 == a1 && __strex(0, v4) );
  if ( (int *)v5 != a1 )
  {
    v3 = KxWaitForLockChainValid(a1);
LABEL_11:
    *a1 = 0;
    __dmb(0xBu);
    v6 = (unsigned int *)(v3 + 4);
    do
      result = __ldrex(v6);
    while ( __strex(result ^ 1, v6) );
  }
  return result;
}
