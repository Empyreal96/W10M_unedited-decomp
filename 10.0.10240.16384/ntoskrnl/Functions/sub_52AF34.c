// sub_52AF34 
 
void sub_52AF34()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x46AF4E);
}
