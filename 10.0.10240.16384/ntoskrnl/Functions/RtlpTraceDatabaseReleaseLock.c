// RtlpTraceDatabaseReleaseLock 
 
int __fastcall RtlpTraceDatabaseReleaseLock(int a1)
{
  int v1; // r3
  int v2; // r4
  unsigned int *v3; // r4
  int v4; // r5
  unsigned int v5; // r1
  int vars4; // [sp+Ch] [bp+4h]

  v1 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 28) = 0;
  if ( (v1 & 4) != 0 )
  {
    v2 = *(unsigned __int8 *)(a1 + 24);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 32), vars4);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(a1 + 32) = 0;
    }
    KfLowerIrql(v2);
  }
  else
  {
    v3 = (unsigned int *)(a1 + 32);
    v4 = *(_DWORD *)(a1 + 60);
    *(_DWORD *)(a1 + 36) = 0;
    __dmb(0xBu);
    do
      v5 = __ldrex(v3);
    while ( !v5 && __strex(1u, v3) );
    if ( v5 )
      ExpReleaseFastMutexContended((unsigned int *)(a1 + 32), v5);
    KfLowerIrql((unsigned __int8)v4);
    KeAbPostRelease((unsigned int)v3);
  }
  return 1;
}
