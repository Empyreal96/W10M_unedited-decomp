// MiObtainReferencedSecureVad 
 
int __fastcall MiObtainReferencedSecureVad(int a1, _DWORD *a2)
{
  unsigned int v4; // r5
  int v5; // r7
  int v6; // r2
  unsigned int v7; // r8
  _DWORD *v8; // r0
  _DWORD *v9; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r7
  int v14; // r3

  *a2 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_DWORD *)(v4 + 0x74);
  LOCK_ADDRESS_SPACE_SHARED(v4, v5);
  if ( (*(_DWORD *)(v5 + 192) & 0x20) != 0 )
  {
    UNLOCK_ADDRESS_SPACE_SHARED(v4, v5, v6);
    v9 = 0;
    *a2 = -1073741558;
  }
  else
  {
    v7 = *(_DWORD *)(a1 + 8);
    v8 = MiLocateAddress(v7);
    v9 = v8;
    if ( !v8 )
      return sub_546CE8();
    v11 = v8 + 5;
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
    __dmb(0xBu);
    --*(_WORD *)(v4 + 310);
    UNLOCK_ADDRESS_SPACE_SHARED(v4, v5, v11);
    v13 = v7 >> 12;
    MiLockVad(v4, v9);
    v14 = (__int16)(*(_WORD *)(v4 + 310) + 1);
    *(_WORD *)(v4 + 310) = v14;
    if ( !v14 )
      JUMPOUT(0x546CF2);
    if ( MiVadDeleted(v9) == 1 )
      JUMPOUT(0x546D06);
    if ( v13 < v9[3] || v13 > v9[4] )
      JUMPOUT(0x546D0C);
  }
  return (int)v9;
}
