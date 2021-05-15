// ExReleaseSpinLockShared 
 
int __fastcall ExReleaseSpinLockShared(unsigned int *a1, int a2)
{
  unsigned int v4; // r1
  unsigned int v5; // r2

  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50AB48();
  __dmb(0xBu);
  do
    v4 = __ldrex(a1);
  while ( __strex(v4 & 0xBFFFFFFF, a1) );
  __dmb(0xBu);
  do
    v5 = __ldrex(a1);
  while ( __strex(v5 - 1, a1) );
  return KfLowerIrql(a2);
}
