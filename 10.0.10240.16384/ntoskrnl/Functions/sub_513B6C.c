// sub_513B6C 
 
void sub_513B6C()
{
  unsigned int *v0; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x42F932);
}
