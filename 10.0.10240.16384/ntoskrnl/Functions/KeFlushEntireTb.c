// KeFlushEntireTb 
 
int KeFlushEntireTb()
{
  int result; // r0
  int v1; // r4

  result = KxFlushEntireTb();
  if ( VmTbFlushEnabled )
    result = VmFlushTb(0, 0);
  if ( ExTbFlushActive )
  {
    v1 = KfRaiseIrql(15);
    ExFlushTb(0, 0, 0);
    result = KfLowerIrql(v1);
  }
  return result;
}
