// PspEnableTimerVirtualization 
 
int __fastcall PspEnableTimerVirtualization(int a1)
{
  unsigned __int8 *v1; // r3
  unsigned int v2; // r2

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(a1 + 746);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 4, v1) );
  __dmb(0xBu);
  return 0;
}
