// PspSafeReferenceQuotaBlock 
 
int __fastcall PspSafeReferenceQuotaBlock(int a1)
{
  unsigned int *v1; // r5
  unsigned int v2; // r4
  unsigned int v3; // r0
  unsigned int v4; // r1

  v1 = (unsigned int *)(a1 + 1024);
  v2 = *(_DWORD *)(a1 + 1024);
  __dmb(0xBu);
  while ( v2 )
  {
    v3 = v2;
    __dmb(0xBu);
    do
      v4 = __ldrex(v1);
    while ( v4 == v2 && __strex(v2 + 1, v1) );
    v2 = v4;
    __dmb(0xBu);
    if ( v4 == v3 )
      return 1;
  }
  return 0;
}
