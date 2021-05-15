// sub_54CA8C 
 
void __fastcall sub_54CA8C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int *v10; // r4
  int v11; // r6
  unsigned int v12; // r2

  __dmb(0xAu);
  __yield();
  v11 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v10);
  }
  else
  {
    do
      v12 = __ldrex(v10);
    while ( __strex(1u, v10) );
    __dmb(0xBu);
    if ( v12 )
      KxWaitForSpinLockAndAcquire(v10);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v10, a10);
  }
  else
  {
    __dmb(0xBu);
    *v10 = 0;
  }
  KfLowerIrql(v11);
  JUMPOUT(0x4D65C2);
}
