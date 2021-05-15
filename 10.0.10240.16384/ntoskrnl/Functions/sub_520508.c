// sub_520508 
 
void sub_520508()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x452068);
}
