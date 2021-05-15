// MI_DEREFERENCE_CONTROL_AREA_FILE 
 
unsigned int __fastcall MI_DEREFERENCE_CONTROL_AREA_FILE(int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  unsigned int v3; // r4
  unsigned int result; // r0

  v2 = (unsigned int *)(a1 + 32);
  __pld((void *)(a1 + 32));
  v3 = *(_DWORD *)(a1 + 32);
  if ( (v3 ^ a2) >= 7 )
    return ObDereferenceObjectDeferDeleteWithTag(a2);
  while ( 1 )
  {
    __dmb(0xBu);
    do
      result = __ldrex(v2);
    while ( result == v3 && __strex(v3 + 1, v2) );
    if ( result == v3 )
      break;
    v3 = result;
    if ( (result ^ a2) >= 7 )
      return ObDereferenceObjectDeferDeleteWithTag(a2);
  }
  return result;
}
