// IopCloseWaitCompletionPacket 
 
void __fastcall IopCloseWaitCompletionPacket(int a1, int a2, int a3, int a4)
{
  unsigned int *v5; // r4
  int v6; // r6
  unsigned int v7; // r2
  int v8; // r3

  if ( a4 == 1 )
  {
    v5 = (unsigned int *)(a2 + 48);
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      sub_52B024();
    }
    else
    {
      do
        v7 = __ldrex(v5);
      while ( __strex(1u, v5) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire(v5);
      v8 = *(unsigned __int8 *)(a2 + 52);
      __dmb(0xBu);
      if ( !v8 || !IopCancelWaitCompletionPacket(a2, 1, v6) )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v5);
        }
        else
        {
          __dmb(0xBu);
          *v5 = 0;
        }
        KfLowerIrql(v6);
      }
    }
  }
}
