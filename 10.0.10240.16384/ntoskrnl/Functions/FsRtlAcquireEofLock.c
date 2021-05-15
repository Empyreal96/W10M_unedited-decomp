// FsRtlAcquireEofLock 
 
unsigned int __fastcall FsRtlAcquireEofLock(int a1)
{
  unsigned int v2; // r6
  unsigned int v3; // r7
  int v4; // r5
  int v5; // r1
  int v6; // r8
  unsigned int v7; // r2
  unsigned int *v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 40);
  v4 = KeAbPreAcquire(v3, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)v3) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended(v3, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  *(_DWORD *)(v3 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v3 + 28) = v6;
  if ( *(_DWORD *)a1 == v2 )
  {
    ++*(_WORD *)(a1 + 22);
  }
  else if ( *(_DWORD *)a1 )
  {
    FsRtlpWaitForIoAtEof(a1, v5, -1, -1);
  }
  else
  {
    *(_DWORD *)a1 = v2;
    *(_WORD *)(a1 + 22) = 1;
  }
  v8 = *(unsigned int **)(*(_DWORD *)(a1 + 12) + 40);
  v9 = v8[7];
  v8[1] = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex(v8);
  while ( !v10 && __strex(1u, v8) );
  if ( v10 )
    ExpReleaseFastMutexContended(v8, v10);
  KfLowerIrql((unsigned __int8)v9);
  return KeAbPostRelease((unsigned int)v8);
}
