// sub_550F38 
 
void sub_550F38()
{
  int v0; // r4

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4EDE36);
}
