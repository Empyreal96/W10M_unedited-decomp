// sub_540218 
 
void sub_540218()
{
  int v0; // r7

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0 + 44);
  JUMPOUT(0x4ABCDE);
}
