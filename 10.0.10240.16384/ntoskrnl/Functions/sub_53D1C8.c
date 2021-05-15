// sub_53D1C8 
 
void sub_53D1C8()
{
  int v0; // r5
  int v1; // r6

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + v1));
  JUMPOUT(0x4A1836);
}
