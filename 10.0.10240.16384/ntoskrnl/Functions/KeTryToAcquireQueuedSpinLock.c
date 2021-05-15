// KeTryToAcquireQueuedSpinLock 
 
int __fastcall KeTryToAcquireQueuedSpinLock(int a1, _BYTE *a2)
{
  int v4; // r5
  unsigned int v5; // r0
  unsigned int *v6; // r1
  int v7; // r0
  unsigned int v8; // r2

  v4 = KfRaiseIrql(2);
  v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 8 * a1;
  v6 = *(unsigned int **)(v5 + 4);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v7 = KiTryToAcquireQueuedSpinLockInstrumented(v5, v6);
  }
  else
  {
    do
      v8 = __ldrex(v6);
    while ( !v8 && __strex(v5, v6) );
    __dmb(0xBu);
    if ( v8 )
    {
      __dmb(0xAu);
      __yield();
LABEL_9:
      KfLowerIrql(v4);
      return 0;
    }
    v7 = 1;
  }
  if ( !v7 )
    goto LABEL_9;
  *a2 = v4;
  return 1;
}
