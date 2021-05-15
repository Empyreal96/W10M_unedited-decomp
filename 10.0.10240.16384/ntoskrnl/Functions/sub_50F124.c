// sub_50F124 
 
void sub_50F124()
{
  int v0; // r5
  int v1; // r8

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0 + v1);
  JUMPOUT(0x4E7070);
}
