// sub_520C04 
 
void sub_520C04()
{
  int v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 768));
  JUMPOUT(0x4537D4);
}
