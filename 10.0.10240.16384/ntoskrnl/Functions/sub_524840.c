// sub_524840 
 
void sub_524840()
{
  int v0; // r4
  int v1; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + v1));
  JUMPOUT(0x45D170);
}
