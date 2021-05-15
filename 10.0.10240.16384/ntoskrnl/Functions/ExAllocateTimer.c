// ExAllocateTimer 
 
int __fastcall ExAllocateTimer(int a1, int a2, char a3)
{
  if ( (a3 & 2) != 0 )
    sub_5545DC();
  return ExAllocateTimerInternal();
}
