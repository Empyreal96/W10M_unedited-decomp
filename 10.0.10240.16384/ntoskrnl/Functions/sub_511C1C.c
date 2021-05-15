// sub_511C1C 
 
void sub_511C1C()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x42AF5A);
}
