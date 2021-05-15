// sub_525A2C 
 
void sub_525A2C()
{
  unsigned int *v0; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x45F7DA);
}
