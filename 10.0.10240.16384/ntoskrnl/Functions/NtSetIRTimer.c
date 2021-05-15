// NtSetIRTimer 
 
int __fastcall NtSetIRTimer(int a1, int a2)
{
  return ExpSetTimer2(a1, a2, 0);
}
