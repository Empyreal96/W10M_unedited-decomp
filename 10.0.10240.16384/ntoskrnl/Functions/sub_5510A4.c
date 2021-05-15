// sub_5510A4 
 
void sub_5510A4()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4EE25A);
}
