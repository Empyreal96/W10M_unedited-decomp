// KiBugCheckDebugBreak 
 
void __fastcall __noreturn KiBugCheckDebugBreak(int a1, int a2)
{
  DbgBreakPointWithStatus();
}
