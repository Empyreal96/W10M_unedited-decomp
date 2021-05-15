// KeCancelTimer 
 
int __fastcall KeCancelTimer(int a1)
{
  int v2; // r4
  int v3; // r5

  v2 = KfRaiseIrql(2);
  v3 = KiCancelTimer(a1, 1);
  KfLowerIrql(v2);
  return v3;
}
