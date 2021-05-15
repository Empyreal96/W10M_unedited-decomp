// SmWdStopMonitoring 
 
int __fastcall SmWdStopMonitoring(int a1)
{
  return KeCancelTimer(a1);
}
