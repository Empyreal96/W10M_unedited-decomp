// KiMaskInterruptDpc 
 
int __fastcall KiMaskInterruptDpc(int a1, int a2, unsigned int a3, int a4)
{
  int v6; // r4

  v6 = KfRaiseIrql(15);
  KiMaskInterruptInternal(a3, a4);
  return KfLowerIrql(v6);
}
