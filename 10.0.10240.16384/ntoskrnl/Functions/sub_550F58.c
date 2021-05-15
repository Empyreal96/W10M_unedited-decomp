// sub_550F58 
 
void sub_550F58()
{
  int v0; // r4

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4EDF18);
}
