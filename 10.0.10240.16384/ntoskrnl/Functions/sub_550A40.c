// sub_550A40 
 
void sub_550A40()
{
  int v0; // r8

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 9344));
  JUMPOUT(0x4ED118);
}
