// sub_51A620 
 
void sub_51A620()
{
  unsigned int *v0; // r10

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4404E4);
}
