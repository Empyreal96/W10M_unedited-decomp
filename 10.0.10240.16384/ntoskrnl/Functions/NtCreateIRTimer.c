// NtCreateIRTimer 
 
int __fastcall NtCreateIRTimer(unsigned int a1, int a2)
{
  return NtCreateTimer2(a1, 0, 0, 2, a2);
}
