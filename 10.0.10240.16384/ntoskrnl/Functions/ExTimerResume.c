// ExTimerResume 
 
int __fastcall ExTimerResume(int a1, int a2, int a3, int a4)
{
  unsigned int *v7; // r4
  int result; // r0
  int v9; // r1
  unsigned int v10; // r2

  v7 = (unsigned int *)(a1 - 116);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50F844();
  v9 = 1;
  do
    v10 = __ldrex(v7);
  while ( __strex(1u, v7) );
  __dmb(0xBu);
  if ( v10 )
    KxWaitForSpinLockAndAcquire(a1 - 116);
  result = ExpTimerResume(a1 - 164, v9, a3, a4);
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseSpinLockInstrumented(v7);
  __dmb(0xBu);
  *v7 = 0;
  return result;
}
