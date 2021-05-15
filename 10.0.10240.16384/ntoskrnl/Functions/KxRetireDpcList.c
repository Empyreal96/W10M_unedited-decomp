// KxRetireDpcList 
 
int __fastcall KxRetireDpcList(int a1)
{
  KiRetireDpcList(a1);
  return KiDispatchInterruptContinue();
}
