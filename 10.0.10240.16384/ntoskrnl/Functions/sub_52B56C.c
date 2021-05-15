// sub_52B56C 
 
void sub_52B56C()
{
  unsigned int *v0; // r7

  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  JUMPOUT(0x46D46C);
}
