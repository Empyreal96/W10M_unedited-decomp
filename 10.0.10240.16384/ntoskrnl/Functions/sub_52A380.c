// sub_52A380 
 
void sub_52A380()
{
  unsigned int *v0; // r6

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x469C16);
}
