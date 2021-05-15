// sub_524B58 
 
void sub_524B58()
{
  int v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 656));
  JUMPOUT(0x45DA58);
}
