// SmKmInitialize 
 
_DWORD *__fastcall SmKmInitialize(unsigned int a1)
{
  int v2; // r6
  unsigned int *v3; // r5
  unsigned int *v4; // r0
  unsigned int v5; // r1
  unsigned int v7; // r1

  memset((_BYTE *)a1, 0, 3192);
  v2 = 32;
  v3 = (unsigned int *)(a1 + 8);
  do
  {
    *(v3 - 1) = 0;
    v4 = v3 - 1;
    do
      v5 = __ldrex(v4);
    while ( !v5 && __strex(1u, v4) );
    __dmb(0xBu);
    if ( v5 )
      return (_DWORD *)sub_8186C0();
    *v3 = 0;
    do
      v7 = __ldrex(v3);
    while ( !v7 && __strex(1u, v3) );
    __dmb(0xBu);
    if ( v7 )
    {
      if ( v7 != 1 )
        ExfWaitForRundownProtectionRelease(v3, v7);
    }
    v3[21] = 0;
    v3 += 24;
    --v2;
  }
  while ( v2 );
  *(_DWORD *)(a1 + 3188) = -1;
  *(_DWORD *)(a1 + 3176) = 0;
  *(_DWORD *)(a1 + 3072) = SMKM_STORE_MGR<SM_TRAITS>::SmStoreMgrCallback;
  return SmWdInitialize((_BYTE *)(a1 + 3080), a1);
}
