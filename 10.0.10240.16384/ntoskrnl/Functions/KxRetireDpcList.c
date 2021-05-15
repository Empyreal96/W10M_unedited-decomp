// KxRetireDpcList 
 
int KxRetireDpcList()
{
  KiRetireDpcList();
  return KiDispatchInterruptContinue();
}
