// RtlpMuiRegGetInstalledLanguageIndexByLangId 
 
int __fastcall RtlpMuiRegGetInstalledLanguageIndexByLangId(int a1, int a2, int a3, _WORD *a4)
{
  int v4; // r4
  int v6; // r5
  int v9; // r3
  int v10; // r2
  int v11; // lr
  _WORD *v12; // r1
  _BYTE *v13; // r6
  char v16[4]; // [sp+8h] [bp-28h] BYREF
  _BYTE *v17; // [sp+Ch] [bp-24h]

  v4 = -1073741772;
  v6 = -1073741772;
  if ( !a1 || !a2 )
    return -1073741811;
  if ( a2 == 4096 )
    return v4;
  v9 = *(_DWORD *)(a1 + 20);
  v10 = 0;
  v11 = *(unsigned __int16 *)(v9 + 6);
  if ( !*(_WORD *)(v9 + 6) )
  {
LABEL_8:
    v13 = sub_4F4434(a1, 0x55u, v10, v9);
    if ( !v13 )
      return -1073741801;
    if ( a3 )
    {
      v17 = v13;
      if ( RtlLCIDToCultureName(a2, (unsigned int)v16) )
        v6 = RtlpMuiRegGetInstalledLanguageIndexByName(a1, v17);
    }
    ExFreePoolWithTag((unsigned int)v13);
    return v6;
  }
  v12 = *(_WORD **)(v9 + 12);
  while ( 1 )
  {
    v9 = (unsigned __int16)v12[2];
    if ( v9 == a2 )
      break;
    ++v10;
    v12 += 14;
    if ( v10 >= v11 )
      goto LABEL_8;
  }
  if ( (*v12 & 0x1020) == 32 )
  {
    if ( a4 )
      *a4 = v10;
    return 0;
  }
  return sub_817EFC();
}
