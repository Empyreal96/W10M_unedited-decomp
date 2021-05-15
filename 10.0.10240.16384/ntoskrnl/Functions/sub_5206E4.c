// sub_5206E4 
 
void sub_5206E4()
{
  int v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 768));
  JUMPOUT(0x452656);
}
