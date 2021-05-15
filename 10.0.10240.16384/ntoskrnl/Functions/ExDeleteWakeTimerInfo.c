// ExDeleteWakeTimerInfo 
 
int __fastcall ExDeleteWakeTimerInfo(int a1)
{
  return ExFreePoolWithTag(a1);
}
