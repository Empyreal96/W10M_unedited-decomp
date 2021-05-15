// sub_54602C 
 
void sub_54602C()
{
  unsigned int *v0; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4BFD16);
}
