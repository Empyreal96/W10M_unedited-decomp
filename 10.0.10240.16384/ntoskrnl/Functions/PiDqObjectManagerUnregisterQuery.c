// PiDqObjectManagerUnregisterQuery 
 
int __fastcall PiDqObjectManagerUnregisterQuery(int a1)
{
  unsigned __int8 *v1; // r4
  int v2; // r0
  unsigned int v3; // r2

  v1 = (unsigned __int8 *)(a1 + 56);
  KeAbPreAcquire(a1 + 56, 0, 0);
  v2 = KfRaiseIrql(1);
  do
    v3 = __ldrex(v1);
  while ( __strex(v3 & 0xFE, v1) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    JUMPOUT(0x7C8110);
  return sub_7C8108(v2);
}
