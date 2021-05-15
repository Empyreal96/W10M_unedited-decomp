// sub_5207BC 
 
void sub_5207BC()
{
  int v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 768));
  JUMPOUT(0x45282A);
}
