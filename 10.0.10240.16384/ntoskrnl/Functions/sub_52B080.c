// sub_52B080 
 
void sub_52B080()
{
  unsigned int *v0; // r4

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x46C280);
}
