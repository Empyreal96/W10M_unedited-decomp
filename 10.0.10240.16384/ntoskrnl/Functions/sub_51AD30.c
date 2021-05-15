// sub_51AD30 
 
void sub_51AD30()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x441C72);
}
