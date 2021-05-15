// MmGetPageFileForCrashDump 
 
int MmGetPageFileForCrashDump()
{
  int v0; // r8
  unsigned int v1; // r9
  unsigned int v2; // r7
  int v3; // r5
  unsigned int v4; // r1
  int v5; // r3
  __int16 *v6; // r2
  int v7; // r1
  __int16 v8; // r0
  unsigned int v9; // r0
  int v10; // r0
  __int16 v11; // r3

  v0 = 0;
  v1 = 0;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 310);
  v3 = KeAbPreAcquire((unsigned int)&dword_63F95C, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_63F95C);
  while ( __strex(v4 | 1, (unsigned __int8 *)&dword_63F95C) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_63F95C, v3, (unsigned int)&dword_63F95C);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = dword_64050C;
  __dmb(0xBu);
  if ( v5 )
  {
    v6 = MiSystemPartition;
    do
    {
      v7 = *((_DWORD *)v6 + 900);
      v8 = *(_WORD *)(v7 + 96);
      if ( (v8 & 0x10) == 0 && (v8 & 0x40) == 0 && *(_DWORD *)(v7 + 8) > v1 )
      {
        v0 = *(_DWORD *)(v7 + 112);
        v1 = *(_DWORD *)(v7 + 8);
      }
      v6 += 2;
      --v5;
    }
    while ( v5 );
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&dword_63F95C);
  while ( __strex(v9 - 1, (unsigned int *)&dword_63F95C) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_63F95C);
  v10 = KeAbPostRelease((unsigned int)&dword_63F95C);
  v11 = *(_WORD *)(v2 + 310) + 1;
  *(_WORD *)(v2 + 310) = v11;
  if ( !v11 && *(_DWORD *)(v2 + 100) != v2 + 100 )
    KiCheckForKernelApcDelivery(v10);
  return v0;
}
