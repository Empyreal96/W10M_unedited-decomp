// sub_524B0C 
 
void sub_524B0C()
{
  unsigned int *v0; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x45D990);
}
