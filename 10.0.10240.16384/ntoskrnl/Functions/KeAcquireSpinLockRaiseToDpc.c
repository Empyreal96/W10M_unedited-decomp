// KeAcquireSpinLockRaiseToDpc 
 
int __fastcall KeAcquireSpinLockRaiseToDpc(unsigned int *a1)
{
  int result; // r0
  int v3; // r4
  unsigned int v4; // r2

  result = KfRaiseIrql(2);
  v3 = result;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50C388();
  do
    v4 = __ldrex(a1);
  while ( __strex(1u, a1) );
  __dmb(0xBu);
  if ( v4 )
  {
    KxWaitForSpinLockAndAcquire(a1);
    result = v3;
  }
  return result;
}
