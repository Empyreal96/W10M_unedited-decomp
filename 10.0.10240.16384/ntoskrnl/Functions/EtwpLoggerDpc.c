// EtwpLoggerDpc 
 
int __fastcall EtwpLoggerDpc(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r5
  int result; // r0

  __dmb(0xBu);
  v2 = (unsigned int *)(a2 + 612);
  do
  {
    v3 = __ldrex(v2);
    result = v3 & 0xFFFFFCFF;
  }
  while ( __strex(v3 & 0xFFFFFCFF, v2) );
  __dmb(0xBu);
  if ( (v3 & 0x100) != 0 )
    return sub_54CEA8();
  if ( (v3 & 0x200) != 0 )
    result = EtwpRequestFlushTimer(a2, 0);
  return result;
}
