// MiFlushAllPages 
 
int MiFlushAllPages()
{
  int v0; // r6
  unsigned int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r1
  int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r1
  __int16 v7; // r3

  v0 = 255;
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  do
    v2 = __ldrex(&dword_63F8BC);
  while ( __strex(v2 + 1, &dword_63F8BC) );
  do
    v3 = __ldrex(&dword_63F8C0);
  while ( __strex(v3 + 1, &dword_63F8C0) );
  __dmb(0xBu);
  do
  {
    v4 = MiCanFlushMakeProgress(MiSystemPartition, 0);
    if ( !v4 )
      break;
    KeSetEvent((int)&unk_63F8C4, 0, 0);
    MiWakeModifiedPageWriter(MiSystemPartition, -1);
    CcNotifyWriteBehind(2);
    v4 = KeDelayExecutionThread(0, 0, (unsigned int *)Mi30Milliseconds);
    --v0;
    if ( (unsigned int)dword_640680 <= 0x32 )
      break;
  }
  while ( v0 );
  do
    v5 = __ldrex(&dword_63F8BC);
  while ( __strex(v5 - 1, &dword_63F8BC) );
  __dmb(0xBu);
  do
    v6 = __ldrex(&dword_63F8C0);
  while ( __strex(v6 - 1, &dword_63F8C0) );
  v7 = *(_WORD *)(v1 + 308) + 1;
  *(_WORD *)(v1 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(v4);
  return 1;
}
