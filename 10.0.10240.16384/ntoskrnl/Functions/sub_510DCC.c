// sub_510DCC 
 
void sub_510DCC()
{
  int v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 1084));
  JUMPOUT(0x428D6E);
}
