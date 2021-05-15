// sub_51A158 
 
void sub_51A158()
{
  unsigned int *v0; // r5

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x43EC98);
}
