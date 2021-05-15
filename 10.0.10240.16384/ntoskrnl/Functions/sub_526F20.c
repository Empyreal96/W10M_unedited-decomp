// sub_526F20 
 
void sub_526F20()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x462626);
}
