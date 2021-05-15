// sub_511EA0 
 
void sub_511EA0()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x42B554);
}
