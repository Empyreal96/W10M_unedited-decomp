// PspEnableProcessTimerVirtualization 
 
int __fastcall PspEnableProcessTimerVirtualization(int a1)
{
  unsigned __int8 *v1; // r3
  unsigned int v2; // r2

  __dmb(0xBu);
  v1 = (unsigned __int8 *)(a1 + 100);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 0x10, v1) );
  __dmb(0xBu);
  return 0;
}
