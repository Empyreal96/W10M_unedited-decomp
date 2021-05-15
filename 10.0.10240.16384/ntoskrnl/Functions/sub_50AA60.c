// sub_50AA60 
 
void sub_50AA60()
{
  int v0; // r4

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x449D08);
}
