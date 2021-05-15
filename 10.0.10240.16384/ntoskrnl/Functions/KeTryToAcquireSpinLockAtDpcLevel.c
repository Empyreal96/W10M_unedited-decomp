// KeTryToAcquireSpinLockAtDpcLevel 
 
int __fastcall KeTryToAcquireSpinLockAtDpcLevel(unsigned int *a1, int a2)
{
  int result; // r0
  unsigned int v3; // r2

  if ( (dword_682604 & 0x210000) != 0 )
    return KiTryToAcquireSpinLockInstrumented(a1, a2);
  do
    v3 = __ldrex(a1);
  while ( __strex(1u, a1) );
  __dmb(0xBu);
  result = v3 == 0;
  if ( v3 )
  {
    __dmb(0xAu);
    __yield();
  }
  return result;
}
