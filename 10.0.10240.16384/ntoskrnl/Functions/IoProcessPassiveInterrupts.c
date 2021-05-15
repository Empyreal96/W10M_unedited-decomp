// IoProcessPassiveInterrupts 
 
int __fastcall IoProcessPassiveInterrupts(int a1)
{
  int result; // r0
  int v2; // r4
  int v3; // r6
  unsigned int *v4; // r5
  unsigned int v5; // r2
  int v6; // r3

  result = IopFindPassiveInterruptBlock(a1);
  v2 = result;
  if ( result )
  {
    if ( !*(_DWORD *)(result + 20) )
      off_617A60(*(_DWORD *)(result + 12), 1);
    v3 = KfRaiseIrql(12);
    v4 = (unsigned int *)(v2 + 36);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_555558();
    }
    else
    {
      do
        v5 = __ldrex(v4);
      while ( __strex(1u, v4) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v2 + 36));
      v6 = *(unsigned __int8 *)(v2 + 40);
      *(_BYTE *)(v2 + 41) = 1;
      if ( !v6 )
      {
        *(_BYTE *)(v2 + 40) = 1;
        KiInsertQueueDpc(v2 + 60, 0, 0, 0, 0);
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v2 + 36);
      }
      else
      {
        __dmb(0xBu);
        *v4 = 0;
      }
      result = KfLowerIrql(v3);
    }
  }
  return result;
}
