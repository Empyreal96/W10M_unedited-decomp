// PiLookupInDDBCache 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiLookupInDDBCache(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r5
  int v8; // r8
  unsigned __int16 *v9; // r0
  unsigned __int16 *v10; // r0
  _DWORD *v11; // r0
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  void **v15; // r2
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // [sp-4h] [bp-40h] BYREF
  __int16 v20; // [sp+4h] [bp-38h]
  __int16 v21; // [sp+6h] [bp-36h]
  unsigned __int16 *v22; // [sp+8h] [bp-34h]
  int v23; // [sp+Ch] [bp-30h]

  v6 = -1073741823;
  dword_920AAC = 0;
  if ( !RtlIsGenericTableEmptyAvl((int)&PiDDBCacheTable) )
  {
    v8 = RtlImageNtHeader(a2);
    if ( v8 )
    {
      v9 = wcsrchr(*(unsigned __int16 **)(a1 + 4), 92);
      v10 = v9 ? v9 + 1 : *(_DWORD *)(a1 + 4);
      v22 = v10;
      v20 = 2 * wcslen(v10);
      v21 = v20;
      v23 = *(_DWORD *)(v8 + 8);
      v11 = (_DWORD *)RtlLookupElementGenericTableAvl((int)&PiDDBCacheTable, (int)&v19);
      if ( v11 )
      {
        *(_QWORD *)&v13 = *(_QWORD *)v11;
        if ( *(_DWORD **)(*v11 + 4) != v11 || (_DWORD *)*v14 != v11 )
          __fastfail(3u);
        *v14 = v13;
        *(_DWORD *)(v13 + 4) = v14;
        v15 = (void **)off_920A74;
        *v11 = &PiDDBCacheList;
        v11[1] = v15;
        if ( *v15 != &PiDDBCacheList )
          sub_7CC034();
        *v15 = v11;
        off_920A74 = v11;
        v6 = v11[5];
        if ( a4 )
        {
          v16 = v11[7];
          v17 = v11[8];
          v18 = v11[9];
          *a4 = v11[6];
          a4[1] = v16;
          a4[2] = v17;
          a4[3] = v18;
        }
      }
    }
  }
  return v6;
}
