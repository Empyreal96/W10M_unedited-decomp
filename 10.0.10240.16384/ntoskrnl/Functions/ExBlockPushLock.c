// ExBlockPushLock 
 
int *__fastcall ExBlockPushLock(int *result, unsigned int a2)
{
  int v2; // r2
  unsigned int v3; // r5

  __pld(result);
  *(_DWORD *)(a2 + 32) = 2;
  v2 = *result;
  *(_DWORD *)(a2 + 16) = *result;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)result);
  while ( v3 == v2 && __strex(a2, (unsigned int *)result) );
  __dmb(0xBu);
  if ( v3 != v2 )
    result = (int *)sub_529160();
  return result;
}
