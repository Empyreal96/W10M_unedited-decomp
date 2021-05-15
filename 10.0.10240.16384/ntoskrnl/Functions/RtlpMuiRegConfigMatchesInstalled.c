// RtlpMuiRegConfigMatchesInstalled 
 
int __fastcall RtlpMuiRegConfigMatchesInstalled(int a1, int a2, __int16 a3, int a4, __int16 a5, int *a6, _WORD *a7)
{
  int v7; // r4
  int v9; // r6
  int v10; // r7
  unsigned int v12; // r9
  int v13; // r5
  int v14; // r9
  int v15; // r1
  int v16; // r1
  int v17; // r1
  unsigned __int16 *v18; // r1
  _BYTE *v19; // r0
  int v20; // r1
  unsigned __int16 *v21; // r1
  int v22; // r1
  int v23; // r3
  __int16 v25; // [sp+0h] [bp-30h] BYREF
  int v26; // [sp+4h] [bp-2Ch] BYREF
  unsigned __int16 v27; // [sp+8h] [bp-28h] BYREF
  _BYTE *v28; // [sp+Ch] [bp-24h]

  v7 = a4;
  v9 = 0;
  v10 = a3;
  v12 = 0;
  if ( a2 == a4 )
  {
    v13 = a3 == a5;
LABEL_3:
    v14 = 0;
    goto LABEL_48;
  }
  if ( !a2 || !a4 )
    goto LABEL_43;
  if ( a7 )
  {
    a4 = -1;
    *a7 = -1;
  }
  if ( a2 == 2 )
  {
    if ( a1 )
    {
      if ( a3 >= 0 )
      {
        v15 = *(_DWORD *)(a1 + 20);
        if ( a3 < (int)*(unsigned __int16 *)(v15 + 6) )
        {
          v9 = *(_DWORD *)(v15 + 12) + 28 * a3;
          v13 = RtlpMuiRegLangInfoMatchesSpec(a1, v9, v7, a5);
          goto LABEL_3;
        }
      }
    }
    goto LABEL_43;
  }
  if ( v7 == 2 )
  {
    if ( a1 )
    {
      if ( a5 >= 0 )
      {
        v16 = *(_DWORD *)(a1 + 20);
        if ( a5 < (int)*(unsigned __int16 *)(v16 + 6) )
        {
          v14 = *(_DWORD *)(v16 + 12) + 28 * a5;
          v13 = RtlpMuiRegLangInfoMatchesSpec(a1, v14, a2, a3);
          if ( v13 && v14 && a7 )
            *a7 = a5;
          goto LABEL_47;
        }
      }
    }
    goto LABEL_43;
  }
  if ( a2 != 1 )
  {
    if ( a2 == 3 && v7 == 1 )
    {
      v19 = sub_4F4434(a1, 0x55u, a3, a4);
      v12 = (unsigned int)v19;
      if ( v19 )
      {
        v28 = v19;
        if ( RtlLCIDToCultureName(a5, (unsigned int)&v27) )
        {
          v20 = *(_DWORD *)(a1 + 24);
          if ( v20 && v10 >= 0 && v10 < *(unsigned __int16 *)(v20 + 6) )
            v21 = (unsigned __int16 *)(*(_DWORD *)(v20 + 16) + 2 * *(__int16 *)(*(_DWORD *)(v20 + 12) + 2 * v10));
          else
            v21 = 0;
          if ( v21 && !wcsicmp((int)v28, v21) )
          {
            v13 = 1;
            goto LABEL_44;
          }
        }
      }
    }
LABEL_43:
    v13 = 0;
LABEL_44:
    if ( v12 )
      ExFreePoolWithTag(v12);
    goto LABEL_46;
  }
  if ( v7 != 3 )
    goto LABEL_43;
  v17 = *(_DWORD *)(a1 + 24);
  if ( v17 && a5 >= 0 && a5 < (int)*(unsigned __int16 *)(v17 + 6) )
    v18 = (unsigned __int16 *)(*(_DWORD *)(v17 + 16) + 2 * *(__int16 *)(*(_DWORD *)(v17 + 12) + 2 * a5));
  else
    v18 = 0;
  if ( !v18 )
    goto LABEL_43;
  RtlInitUnicodeString((unsigned int)&v27, v18);
  if ( !RtlCultureNameToLCID(&v27, &v26) )
    goto LABEL_43;
  v13 = v10 == (__int16)v26;
LABEL_46:
  v14 = 0;
LABEL_47:
  v9 = 0;
LABEL_48:
  if ( a6 )
  {
    if ( !v13 )
    {
      v23 = 0;
      goto LABEL_59;
    }
    if ( v14 )
    {
      *a6 = v14;
      return v13;
    }
    if ( v9 )
    {
      *a6 = v9;
      return v13;
    }
    *a6 = 0;
    if ( RtlpMuiRegGetInstalledLanguageIndex(a1, a2, v10, &v25) >= 0 && v25 >= 0 )
    {
      v22 = *(_DWORD *)(a1 + 20);
      if ( v25 < (int)*(unsigned __int16 *)(v22 + 6) )
      {
        v23 = *(_DWORD *)(v22 + 12) + 28 * v25;
LABEL_59:
        *a6 = v23;
        return v13;
      }
    }
  }
  return v13;
}
