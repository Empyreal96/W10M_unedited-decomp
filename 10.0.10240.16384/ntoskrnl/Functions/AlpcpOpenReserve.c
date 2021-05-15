// AlpcpOpenReserve 
 
int __fastcall AlpcpOpenReserve(int a1)
{
  unsigned int *v1; // r2
  int result; // r0
  unsigned int v3; // r1

  __dmb(0xBu);
  v1 = (unsigned int *)(a1 + 16);
  result = 1;
  do
    v3 = __ldrex(v1);
  while ( !v3 && __strex(1u, v1) );
  __dmb(0xBu);
  if ( v3 )
    result = 0;
  return result;
}
