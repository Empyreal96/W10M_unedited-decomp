// AlpcpEndInitialization 
 
unsigned int __fastcall AlpcpEndInitialization(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r1
  unsigned int result; // r0

  __dmb(0xFu);
  v1 = (unsigned int *)(a1 - 4);
  *(_BYTE *)(a1 - 16) &= 0xFBu;
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 - 1, v1) );
  if ( (v2 & 2) != 0 )
    result = sub_7F7D3C();
  else
    result = KeAbPostRelease(a1 - 4);
  return result;
}
