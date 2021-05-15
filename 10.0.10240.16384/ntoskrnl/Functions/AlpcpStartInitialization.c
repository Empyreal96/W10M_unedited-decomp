// AlpcpStartInitialization 
 
int __fastcall AlpcpStartInitialization(int a1)
{
  int v1; // r5
  unsigned __int8 *v2; // r6
  int result; // r0
  unsigned int v4; // r2

  v1 = a1 - 24;
  v2 = (unsigned __int8 *)(a1 - 4);
  result = KeAbPreAcquire(a1 - 4, 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7F6498(result);
  if ( result )
    *(_BYTE *)(result + 14) |= 1u;
  *(_BYTE *)(v1 + 8) |= 4u;
  return result;
}
