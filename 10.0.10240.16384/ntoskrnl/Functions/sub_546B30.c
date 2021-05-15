// sub_546B30 
 
void sub_546B30()
{
  int v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 768));
  JUMPOUT(0x4C2562);
}
