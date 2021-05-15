// ExReleaseSpinLockExclusive 
 
int __fastcall ExReleaseSpinLockExclusive(_DWORD *a1, int a2)
{
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50DF48();
  __dmb(0xBu);
  *a1 = 0;
  return KfLowerIrql(a2);
}
