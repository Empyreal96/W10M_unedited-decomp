// CcReleaseByteRangeFromWrite 
 
int __fastcall CcReleaseByteRangeFromWrite(int result, unsigned int *a2, int a3, _WORD *a4, char a5)
{
  _WORD *v5; // r4
  __int64 v6; // r6
  int v8; // lr
  unsigned __int64 v9; // r8
  int v10; // r7
  unsigned int v11; // r4
  bool i; // zf
  int v13; // [sp+8h] [bp-38h]
  unsigned int v14; // [sp+10h] [bp-30h] BYREF
  unsigned int v15; // [sp+14h] [bp-2Ch]
  unsigned int v16; // [sp+18h] [bp-28h]

  v5 = a4;
  LODWORD(v6) = a3;
  v8 = result;
  v13 = result;
  if ( a4 )
  {
    if ( *a4 != 765 )
      KeBugCheckEx(52, 5118, -1073740768);
    v9 = __PAIR64__(v14, v15);
    do
    {
      v10 = *((_DWORD *)v5 + 4);
      if ( *v5 == 765 )
      {
        LODWORD(v9) = *((_DWORD *)v5 + 3);
        HIDWORD(v9) = *((_DWORD *)v5 + 2);
        if ( (*(_DWORD *)(v8 + 96) & 0x200) != 0 )
          CcUnpinFileDataEx(v5, (*(_DWORD *)(v8 + 96) & 2) != 0, 2);
        if ( a5 )
          CcSetDirtyPinnedData(v5, 0);
        result = CcUnpinFileDataEx(v5, 1, 0);
        v8 = v13;
      }
      v5 = (_WORD *)(v10 - 16);
    }
    while ( __PAIR64__(*a2, a2[1]) != v9 );
  }
  else if ( a5 )
  {
    HIDWORD(v6) = a2[1];
    v11 = *a2;
    for ( i = a3 == 0; ; i = 1 )
    {
      v14 = v11;
      v15 = HIDWORD(v6);
      if ( i )
        break;
      v16 = (HIDWORD(v6) << 9) | (v11 >> 23);
      if ( __SPAIR64__(HIDWORD(v6), v11) / 0x1000000 < (v6 + v11 - 1) / 0x1000000 )
        return sub_53B23C();
      if ( (unsigned int)v6 > 0x1000000 )
        KeBugCheckEx(52, 5099, -1073740768);
      result = CcSetDirtyInMask(v8, &v14, v6, 0);
      v8 = v13;
      HIDWORD(v6) = (v6 + (unsigned __int64)v11) >> 32;
      v11 += v6;
      LODWORD(v6) = 0;
    }
  }
  return result;
}
