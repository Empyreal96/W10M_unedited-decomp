// RtlpMuiRegConfigListAddLanguage 
 
int __fastcall RtlpMuiRegConfigListAddLanguage(int *a1, __int16 *a2)
{
  int v3; // r4
  int v5; // r0
  unsigned __int16 v6; // r3
  int v7; // lr
  int v8; // r1
  int v9; // r7
  __int16 *v10; // r2
  int v11; // r2
  int v12; // r3
  int v13; // r0
  _DWORD *v14; // r2

  v3 = 0;
  if ( !a1 )
    return -1073741811;
  v5 = *a1;
  if ( !*a1 )
    return -1073741811;
  if ( !a2 )
    return -1073741811;
  v6 = a2[1];
  v7 = *a2;
  if ( !(v6 >> 14) )
    return -1073741811;
  v8 = *(unsigned __int16 *)(v5 + 4);
  v9 = 0;
  if ( !*(_WORD *)(v5 + 4) )
    goto LABEL_10;
  v10 = *(__int16 **)(v5 + 8);
  while ( (unsigned __int16)v10[1] >> 14 != v6 >> 14 || *v10 != v7 )
  {
    ++v9;
    v10 += 6;
    if ( v9 >= v8 )
      goto LABEL_10;
  }
  if ( v9 < 0 )
  {
LABEL_10:
    v11 = *(unsigned __int16 *)(v5 + 6);
    if ( v8 >= (unsigned int)v11 )
    {
      v12 = *a1;
      if ( v8 + 1 >= v11 )
        v12 = RtlpMuiRegResizeLanguageConfigList();
      if ( !v12 )
        return -1073741801;
      v5 = v12;
      *a1 = v12;
    }
    v14 = (_DWORD *)(*(_DWORD *)(v5 + 8) + 12 * *(unsigned __int16 *)(v5 + 4));
    *v14 = *(_DWORD *)a2;
    v14[1] = *((_DWORD *)a2 + 1);
    v14[2] = *((_DWORD *)a2 + 2);
    ++*(_WORD *)(v5 + 4);
    return v3;
  }
  v13 = 0;
  while ( ((((unsigned __int16)v10[1] >> (v13 * 2)) ^ (unsigned __int8)((unsigned __int16)a2[1] >> (v13 * 2))) & 3) == 0
       && v10[v13 + 3] == a2[v13 + 3] )
  {
    if ( ++v13 >= 3 )
      return v3;
  }
  return 0x40000000;
}
