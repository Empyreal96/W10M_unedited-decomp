// sub_5469E8 
 
void sub_5469E8()
{
  int v0; // r5
  int v1; // r6

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + v1));
  JUMPOUT(0x4C1C32);
}
