// sub_511FDC 
 
void sub_511FDC()
{
  int v0; // r5

  ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v0);
  JUMPOUT(0x42B794);
}
