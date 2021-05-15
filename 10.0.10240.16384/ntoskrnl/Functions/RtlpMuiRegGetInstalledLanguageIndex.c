// RtlpMuiRegGetInstalledLanguageIndex 
 
int __fastcall RtlpMuiRegGetInstalledLanguageIndex(int a1, int a2, int a3, _WORD *a4)
{
  int v5; // r5
  int v8; // r6
  int v9; // r1
  __int16 *v10; // r0
  __int16 v11; // t1
  int v12; // r1
  unsigned __int16 *v13; // r1
  int v14[2]; // [sp+0h] [bp-20h] BYREF
  _DWORD v15[6]; // [sp+8h] [bp-18h] BYREF

  v14[0] = a1;
  v14[1] = a2;
  v15[0] = a3;
  v15[1] = a4;
  v5 = 1;
  a3 = (__int16)a3;
  if ( !a1 )
    return -1073741811;
  v8 = *(_DWORD *)(a1 + 20);
  if ( a2 == 3 )
  {
    v9 = 0;
    if ( *(_WORD *)(v8 + 6) )
    {
      v10 = *(__int16 **)(v8 + 12);
      while ( 1 )
      {
        v11 = *v10;
        v10 += 14;
        if ( (v11 & 0x1020) == 32 && *(v10 - 11) == (__int16)a3 && a4 )
          break;
        if ( ++v9 >= *(unsigned __int16 *)(v8 + 6) )
          goto LABEL_10;
      }
      *a4 = v9;
      return 0;
    }
LABEL_10:
    v12 = *(_DWORD *)(a1 + 24);
    if ( v12 && (a3 & 0x8000u) == 0 && (__int16)a3 < (int)*(unsigned __int16 *)(v12 + 6) )
      v13 = (unsigned __int16 *)(*(_DWORD *)(v12 + 16) + 2 * *(__int16 *)(*(_DWORD *)(v12 + 12) + 2 * (__int16)a3));
    else
      v13 = 0;
    if ( !v13 )
      return -1073741772;
    RtlInitUnicodeString((unsigned int)v15, v13);
    if ( !RtlCultureNameToLCID((unsigned __int16 *)v15, v14) )
      return -1073741772;
    a2 = 1;
    v5 = 0;
    a3 = SLOWORD(v14[0]);
  }
  if ( a2 == 1 )
    return RtlpMuiRegGetInstalledLanguageIndexByLangId(a1, (unsigned __int16)a3, v5, a4);
  if ( a2 == 2 )
  {
    if ( a3 <= 0 || a3 >= *(unsigned __int16 *)(v8 + 6) )
      return -1073741811;
    if ( a4 )
      *a4 = a3;
    return 0;
  }
  return -1073741772;
}
