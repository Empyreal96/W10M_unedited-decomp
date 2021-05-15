// ExTimerResume 
 
void __fastcall ExTimerResume(int a1, int a2, int a3, int a4)
{
  unsigned int *v7; // r4
  int v8; // r1
  unsigned int v9; // r2
  int vars4; // [sp+1Ch] [bp+4h]

  v7 = (unsigned int *)(a1 - 116);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    sub_50F844();
  }
  else
  {
    v8 = 1;
    do
      v9 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 - 116));
    ExpTimerResume(a1 - 164, v8, a3, a4);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v7, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
  }
}
