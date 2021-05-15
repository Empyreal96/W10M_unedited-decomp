// sub_53086C 
 
void sub_53086C()
{
  int *v0; // r6
  int v1; // r7
  int v2; // r9
  int v3; // r10
  int v4; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r1
  unsigned int *v7; // r2
  unsigned int v8; // r0

  if ( (*(_DWORD *)(v2 + 4) & v3) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v0, *(_DWORD *)(v1 + 76));
    goto LABEL_11;
  }
  v4 = *v0;
  if ( !*v0 )
  {
    v5 = (unsigned int *)v0[1];
    __dmb(0xBu);
    do
      v6 = __ldrex(v5);
    while ( (int *)v6 == v0 && __strex(0, v5) );
    if ( (int *)v6 == v0 )
LABEL_11:
      JUMPOUT(0x4869CE);
    v4 = KxWaitForLockChainValid(v0);
  }
  *v0 = 0;
  __dmb(0xBu);
  v7 = (unsigned int *)(v4 + 4);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 ^ 1, v7) );
  goto LABEL_11;
}
