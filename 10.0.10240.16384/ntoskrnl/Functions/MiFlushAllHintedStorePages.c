// MiFlushAllHintedStorePages 
 
int MiFlushAllHintedStorePages()
{
  int v0; // r7
  int v1; // r3
  int v2; // r4
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r1
  unsigned int v6; // r9
  int v7; // r10
  unsigned int v8; // r4
  int v9; // r5
  __int64 v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r0
  int v13; // r0
  __int16 v14; // r3
  int v16; // [sp+0h] [bp-20h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = dword_63F9A0;
  __dmb(0xBu);
  if ( !v1 )
    return 1;
  --*(_WORD *)(v0 + 310);
  v16 = KeSetActualBasePriorityThread(v0, 18);
  v3 = KeQueryInterruptTime();
  v4 = dword_63F99C;
  v6 = v5;
  v7 = v3;
  do
    v8 = __ldrex(&dword_63F998);
  while ( __strex(v8 + 2, &dword_63F998) );
  __dmb(0xBu);
  v2 = 0;
  v9 = 5 * v4;
  while ( *(_DWORD *)&MiSystemPartition[2 * v9 + 960] )
  {
    if ( MiCanFlushMakeProgress(MiSystemPartition, 1) )
    {
      MiWakeModifiedPageWriter(MiSystemPartition, -1);
      KeDelayExecutionThread(0, 0, (unsigned int *)Mi30Milliseconds);
      LODWORD(v10) = KeQueryInterruptTime();
      if ( v10 - __PAIR64__(v6, v7) <= 0x2FAF080 )
        continue;
    }
    goto LABEL_10;
  }
  v2 = 1;
  do
LABEL_10:
    v11 = __ldrex(&dword_63F998);
  while ( __strex(v11 | 1, &dword_63F998) );
  __dmb(0xBu);
  do
    v12 = __ldrex(&dword_63F998);
  while ( __strex(v12 - 2, &dword_63F998) );
  KeSetEvent((int)&unk_63F908, 0, 0);
  v13 = KeSetActualBasePriorityThread(v0, v16);
  v14 = *(_WORD *)(v0 + 310) + 1;
  *(_WORD *)(v0 + 310) = v14;
  if ( !v14 && *(_DWORD *)(v0 + 100) != v0 + 100 )
    KiCheckForKernelApcDelivery(v13);
  return v2;
}
