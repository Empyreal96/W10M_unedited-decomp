// sub_524F48 
 
void sub_524F48()
{
  int v0; // r4
  int v1; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + v1));
  JUMPOUT(0x45E862);
}
