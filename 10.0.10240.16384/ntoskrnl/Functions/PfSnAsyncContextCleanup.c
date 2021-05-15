// PfSnAsyncContextCleanup 
 
int __fastcall PfSnAsyncContextCleanup(_DWORD *a1)
{
  int v1; // r3
  unsigned int *v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r1
  unsigned int v6; // r0
  int result; // r0

  v1 = a1[34];
  if ( v1 )
  {
    v3 = (unsigned int *)(v1 + 268);
    __pld((void *)(v1 + 268));
    v4 = *(_DWORD *)(v1 + 268) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v5 = __ldrex(v3);
    while ( v5 == v4 && __strex(v4 - 2, v3) );
    if ( v5 != v4 )
      ExfReleaseRundownProtection((unsigned __int8 *)v3);
  }
  v6 = a1[32];
  if ( v6 )
    ExFreePoolWithTag(v6);
  result = a1[33];
  if ( result )
    result = ObfDereferenceObject(result);
  return result;
}
