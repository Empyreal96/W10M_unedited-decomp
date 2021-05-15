// sub_51084C 
 
void sub_51084C()
{
  int v0; // r6
  int v1; // r7

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0 + v1);
  JUMPOUT(0x428520);
}
