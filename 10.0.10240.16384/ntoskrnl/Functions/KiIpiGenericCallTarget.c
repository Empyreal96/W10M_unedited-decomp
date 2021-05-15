// KiIpiGenericCallTarget 
 
int __fastcall KiIpiGenericCallTarget(int a1, int (__fastcall *a2)(int), int a3, unsigned int *a4)
{
  unsigned int v7; // r4

  __dmb(0xBu);
  do
    v7 = __ldrex(a4);
  while ( __strex(v7 - 1, a4) );
  __dmb(0xBu);
  while ( *a4 )
    KiPollFreezeExecution();
  __dmb(0xBu);
  return a2(a3);
}
