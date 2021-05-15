// sub_54489C 
 
void sub_54489C()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4BB658);
}
