// sub_5271C4 
 
void sub_5271C4()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x462F8C);
}
