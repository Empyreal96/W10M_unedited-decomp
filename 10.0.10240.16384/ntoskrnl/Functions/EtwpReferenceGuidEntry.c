// EtwpReferenceGuidEntry 
 
int __fastcall EtwpReferenceGuidEntry(int a1)
{
  unsigned int *v1; // r5
  int v2; // r1
  unsigned int v3; // r4

  v1 = (unsigned int *)(a1 + 8);
  v2 = *(_DWORD *)(a1 + 8);
  __dmb(0xBu);
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(v1);
    while ( v3 == v2 && __strex(v2 + 1, v1) );
    __dmb(0xBu);
    if ( v3 == v2 )
      break;
    v2 = v3;
    if ( !v3 )
      return 0;
  }
  if ( v2 < 0 )
    sub_7C5004(a1);
  return 1;
}
