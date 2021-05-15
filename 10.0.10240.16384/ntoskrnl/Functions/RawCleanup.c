// RawCleanup 
 
int __fastcall RawCleanup(int a1)
{
  unsigned __int8 *v1; // r6
  unsigned int v2; // r4

  v1 = (unsigned __int8 *)(a1 + 160);
  KeAbPreAcquire(a1 + 160, 0, 0);
  KfRaiseIrql(1);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 & 0xFE, v1) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    JUMPOUT(0x7CFBA0);
  return sub_7CFB94();
}
