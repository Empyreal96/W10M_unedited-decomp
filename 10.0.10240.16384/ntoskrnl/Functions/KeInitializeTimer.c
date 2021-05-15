// KeInitializeTimer 
 
int __fastcall KeInitializeTimer(int a1)
{
  return KeInitializeTimerEx(a1, 0);
}
