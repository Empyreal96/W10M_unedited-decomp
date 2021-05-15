// IopCheckHardErrorEmpty 
 
int IopCheckHardErrorEmpty()
{
  int v0; // r5
  int v1; // r7
  unsigned int v2; // r1
  int vars4; // [sp+14h] [bp+4h]

  v0 = 1;
  v1 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&dword_631A38);
  }
  else
  {
    do
      v2 = __ldrex((unsigned int *)&dword_631A38);
    while ( __strex(1u, (unsigned int *)&dword_631A38) );
    __dmb(0xBu);
    if ( v2 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_631A38);
  }
  IopCurrentHardError = 0;
  if ( (int *)dword_631A30 == &dword_631A30 )
  {
    byte_631A50 = 0;
    v0 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_631A38, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_631A38 = 0;
  }
  KfLowerIrql(v1);
  return v0;
}
