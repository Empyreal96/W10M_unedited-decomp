// KeEnumerateProcessorDpcs 
 
int __fastcall KeEnumerateProcessorDpcs(int a1, int a2, int a3)
{
  unsigned int *v4; // r5
  int v5; // r7
  int v6; // r9
  unsigned int v7; // r2
  _DWORD *i; // r6
  int vars4; // [sp+2Ch] [bp+4h]

  v4 = (unsigned int *)((char *)*(&KiProcessorBlock + a1) + 1688);
  v5 = 2;
  v6 = KfRaiseIrql(15);
  do
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v4);
    }
    else
    {
      do
        v7 = __ldrex(v4);
      while ( __strex(1u, v4) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire(v4);
    }
    for ( i = (_DWORD *)*(v4 - 2); i; i = (_DWORD *)*i )
      (*(void (__fastcall **)(int, _DWORD *, int, _DWORD))(a3 + 168))(a3 + 128, i - 1, 32, 0);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    v4 += 6;
    --v5;
  }
  while ( v5 );
  return KfLowerIrql(v6);
}
