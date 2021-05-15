// ExTryAcquireSpinLockExclusiveAtDpcLevel 
 
int __fastcall ExTryAcquireSpinLockExclusiveAtDpcLevel(unsigned int *a1)
{
  unsigned int v2; // r1

  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50AB40();
  do
    v2 = __ldrex(a1);
  while ( !v2 && __strex(0x80000000, a1) );
  __dmb(0xBu);
  return v2 == 0;
}
