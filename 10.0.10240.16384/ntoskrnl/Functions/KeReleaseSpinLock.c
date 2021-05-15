// KeReleaseSpinLock 
 
int __fastcall KeReleaseSpinLock(_DWORD *a1, int a2)
{
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50C37C();
  __dmb(0xBu);
  *a1 = 0;
  return KfLowerIrql(a2);
}
