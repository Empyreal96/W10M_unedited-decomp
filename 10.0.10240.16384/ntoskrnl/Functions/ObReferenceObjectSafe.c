// ObReferenceObjectSafe 
 
int __fastcall ObReferenceObjectSafe(int a1)
{
  _DWORD *v1; // r0
  unsigned int v2; // r1
  unsigned int v3; // r4
  int result; // r0

  v1 = (_DWORD *)(a1 - 24);
  __pld(v1);
  v2 = *v1;
  if ( !*v1 )
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
    result = sub_51B9D8();
  else
    result = 1;
  return result;
}
