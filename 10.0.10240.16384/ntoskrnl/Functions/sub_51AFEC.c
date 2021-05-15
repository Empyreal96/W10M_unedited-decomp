// sub_51AFEC 
 
void sub_51AFEC()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x442814);
}
