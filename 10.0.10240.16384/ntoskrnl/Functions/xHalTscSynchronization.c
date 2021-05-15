// xHalTscSynchronization 
 
int xHalTscSynchronization()
{
  return KeAdjustInterruptTime(0, 0, 1);
}
