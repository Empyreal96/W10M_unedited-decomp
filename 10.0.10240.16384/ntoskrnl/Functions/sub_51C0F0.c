// sub_51C0F0 
 
void sub_51C0F0()
{
  int v0; // r4

  v0 = KfRaiseIrql(2);
  HalRequestSoftwareInterrupt(2);
  KfLowerIrql(v0);
  JUMPOUT(0x446666);
}
