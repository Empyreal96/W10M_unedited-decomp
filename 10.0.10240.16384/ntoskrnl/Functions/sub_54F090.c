// sub_54F090 
 
void sub_54F090()
{
  int v0; // r5

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x4E959C);
}
