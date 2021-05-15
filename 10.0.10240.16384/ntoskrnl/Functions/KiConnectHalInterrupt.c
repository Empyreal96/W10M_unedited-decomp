// KiConnectHalInterrupt 
 
int __fastcall KiConnectHalInterrupt(int a1)
{
  return KiConnectInterruptInternal(a1, 1);
}
