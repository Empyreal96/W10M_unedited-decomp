// RtlpTraceDatabaseAcquireLock 
 
int __fastcall RtlpTraceDatabaseAcquireLock(int a1)
{
  unsigned int *v2; // r5
  char v3; // r6
  unsigned int v4; // r2
  unsigned __int8 *v5; // r6
  int v6; // r5
  int v7; // r7
  unsigned int v8; // r2

  if ( (*(_DWORD *)(a1 + 4) & 4) != 0 )
  {
    v2 = (unsigned int *)(a1 + 32);
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v2);
    }
    else
    {
      do
        v4 = __ldrex(v2);
      while ( __strex(1u, v2) );
      __dmb(0xBu);
      if ( v4 )
        KxWaitForSpinLockAndAcquire(v2);
    }
    *(_BYTE *)(a1 + 24) = v3;
  }
  else
  {
    v5 = (unsigned __int8 *)(a1 + 32);
    v6 = KeAbPreAcquire(a1 + 32, 0, 0);
    v7 = KfRaiseIrql(1);
    do
      v8 = __ldrex(v5);
    while ( __strex(v8 & 0xFE, v5) );
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      ExpAcquireFastMutexContended(a1 + 32, v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    *(_DWORD *)(a1 + 36) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(a1 + 60) = v7;
  }
  *(_DWORD *)(a1 + 28) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return 1;
}
