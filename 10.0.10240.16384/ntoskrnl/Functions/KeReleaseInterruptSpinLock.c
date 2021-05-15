// KeReleaseInterruptSpinLock 
 
int __fastcall KeReleaseInterruptSpinLock(int a1, int a2)
{
  _DWORD *v3; // r0

  if ( !*(_BYTE *)(a1 + 49) )
    sub_5237B0();
  v3 = *(_DWORD **)(a1 + 36);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(a2);
}
