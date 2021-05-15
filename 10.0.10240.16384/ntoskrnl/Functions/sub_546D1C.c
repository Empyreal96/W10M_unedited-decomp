// sub_546D1C 
 
void sub_546D1C()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4C30EC);
}
