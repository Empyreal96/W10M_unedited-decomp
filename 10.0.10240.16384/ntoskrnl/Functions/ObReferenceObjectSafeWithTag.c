// ObReferenceObjectSafeWithTag 
 
int __fastcall ObReferenceObjectSafeWithTag(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r0
  unsigned int v3; // r5
  int result; // r0

  v1 = (unsigned int *)(a1 - 24);
  __pld((void *)(a1 - 24));
  v2 = *(_DWORD *)(a1 - 24);
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    do
      v3 = __ldrex(v1);
    while ( v3 == v2 && __strex(v2 + 1, v1) );
    if ( v3 == v2 )
      break;
    v2 = v3;
    if ( !v3 )
      return 0;
  }
  if ( ObpTraceFlags )
    result = sub_52F44C();
  else
    result = 1;
  return result;
}
