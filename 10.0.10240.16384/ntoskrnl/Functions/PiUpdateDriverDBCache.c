// PiUpdateDriverDBCache 
 
_DWORD *__fastcall PiUpdateDriverDBCache(int a1, int a2, int a3, int a4, int *a5)
{
  _DWORD *result; // r0
  _DWORD *v8; // r7
  unsigned __int16 *v9; // r0
  unsigned __int16 *v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  unsigned __int16 *v14; // r0
  unsigned __int16 *v15; // r0
  unsigned __int16 *v16; // r4
  void **v17; // r2
  _BYTE v18[8]; // [sp-4h] [bp-48h] BYREF
  unsigned __int16 v19; // [sp+4h] [bp-40h]
  unsigned __int16 v20; // [sp+6h] [bp-3Eh]
  unsigned __int16 *v21; // [sp+8h] [bp-3Ch]
  int v22; // [sp+Ch] [bp-38h]
  int v23; // [sp+10h] [bp-34h]
  int v24; // [sp+14h] [bp-30h]
  int v25; // [sp+18h] [bp-2Ch]
  int v26; // [sp+1Ch] [bp-28h]
  int v27; // [sp+20h] [bp-24h]

  result = (_DWORD *)RtlImageNtHeader(a2);
  v8 = result;
  if ( result )
  {
    dword_920AAC = 1;
    v9 = wcsrchr(*(unsigned __int16 **)(a1 + 4), 92);
    if ( v9 )
      v10 = v9 + 1;
    else
      v10 = *(unsigned __int16 **)(a1 + 4);
    v21 = v10;
    v19 = 2 * wcslen(v10);
    v20 = v19;
    if ( RtlLookupElementGenericTableAvl((int)&PiDDBCacheTable, (int)v18) )
      JUMPOUT(0x7CD5DA);
    if ( (unsigned int)RtlNumberGenericTableElementsAvl((int)&PiDDBCacheTable) < 0x100 )
    {
      v11 = a5[1];
      v12 = a5[2];
      v13 = a5[3];
      v24 = *a5;
      v25 = v11;
      v26 = v12;
      v27 = v13;
      v23 = a4;
      v14 = *(unsigned __int16 **)(a1 + 4);
      v22 = v8[2];
      v15 = wcsrchr(v14, 92);
      if ( v15 )
        v16 = v15 + 1;
      else
        v16 = *(unsigned __int16 **)(a1 + 4);
      v20 = 2 * wcslen(v16);
      v19 = v20;
      result = (_DWORD *)ExAllocatePoolWithTag(1, v20, 538996816);
      v21 = (unsigned __int16 *)result;
      if ( result )
      {
        memmove((int)result, (int)v16, v19);
        result = (_DWORD *)RtlInsertElementGenericTableAvl((int)&PiDDBCacheTable, (int)v18, 40, 0);
        if ( result )
        {
          v17 = (void **)off_920A74;
          *result = &PiDDBCacheList;
          result[1] = v17;
          if ( *v17 != &PiDDBCacheList )
            __fastfail(3u);
          *v17 = result;
          off_920A74 = result;
        }
      }
    }
    else
    {
      result = (_DWORD *)sub_7CD5C0();
    }
  }
  return result;
}
