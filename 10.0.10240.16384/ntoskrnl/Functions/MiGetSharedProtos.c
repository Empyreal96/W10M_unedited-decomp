// MiGetSharedProtos 
 
int __fastcall MiGetSharedProtos(int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r4

  v6 = KfRaiseIrql(2);
  v7 = MiGetSharedProtosAtDpcLevel(a1, a2, a3);
  KfLowerIrql(v6);
  return v7;
}
