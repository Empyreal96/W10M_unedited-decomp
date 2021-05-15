// sub_5204CC 
 
void sub_5204CC()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x451FE0);
}
