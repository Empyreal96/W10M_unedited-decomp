// sub_52AF7C 
 
void sub_52AF7C()
{
  int v0; // r4

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x46AFD8);
}
