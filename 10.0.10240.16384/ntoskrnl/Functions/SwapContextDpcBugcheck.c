// SwapContextDpcBugcheck 
 
void __noreturn SwapContextDpcBugcheck()
{
  int v0; // r4
  int v1; // r5

  KeBugCheckEx(184, v0, v1);
}
