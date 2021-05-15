// sub_51F708 
 
void sub_51F708()
{
  int v0; // r4

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x44FB48);
}
