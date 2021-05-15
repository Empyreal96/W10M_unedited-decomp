// sub_51A510 
 
void sub_51A510()
{
  int v0; // r5
  int v1; // r6

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + v1));
  JUMPOUT(0x440264);
}
