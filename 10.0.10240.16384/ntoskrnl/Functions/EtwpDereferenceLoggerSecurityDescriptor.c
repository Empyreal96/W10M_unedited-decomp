// EtwpDereferenceLoggerSecurityDescriptor 
 
int __fastcall EtwpDereferenceLoggerSecurityDescriptor(int a1, int a2)
{
  unsigned int *v2; // r5
  int v4; // r1
  int result; // r0

  v2 = (unsigned int *)(a1 + 576);
  __pld((void *)(a1 + 576));
  v4 = *(_DWORD *)(a1 + 576);
  if ( (v4 ^ (unsigned int)a2) >= 7 )
    return ObDereferenceSecurityDescriptor(a2, 1);
  __dmb(0xBu);
  do
    result = __ldrex(v2);
  while ( result == v4 && __strex(v4 + 1, v2) );
  if ( result != v4 )
    result = sub_809824();
  return result;
}
