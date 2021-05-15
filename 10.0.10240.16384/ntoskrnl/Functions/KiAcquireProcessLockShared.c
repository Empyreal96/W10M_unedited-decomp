// KiAcquireProcessLockShared 
 
int __fastcall KiAcquireProcessLockShared(int a1, _BYTE *a2)
{
  unsigned int *v3; // r4
  int result; // r0
  unsigned int v5; // r1

  *a2 = KfRaiseIrql(2);
  v3 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51F708();
  result = *v3 & 0x7FFFFFFF;
  do
    v5 = __ldrex(v3);
  while ( v5 == result && __strex(result + 1, v3) );
  __dmb(0xBu);
  if ( v5 != result )
    result = ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(a1 + 48));
  return result;
}
