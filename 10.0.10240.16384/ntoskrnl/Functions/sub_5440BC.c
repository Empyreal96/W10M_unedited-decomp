// sub_5440BC 
 
void sub_5440BC()
{
  int v0; // r7
  int v1; // r9

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0 + v1);
  JUMPOUT(0x4B9B32);
}
