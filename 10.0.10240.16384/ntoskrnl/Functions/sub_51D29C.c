// sub_51D29C 
 
void sub_51D29C()
{
  int v0; // r4

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x44A044);
}
