// RtlpMuiRegLangInfoMatchesSpec 
 
int __fastcall RtlpMuiRegLangInfoMatchesSpec(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r6
  int v5; // r4
  BOOL v9; // r4
  int v10; // r2
  int v11; // r1
  unsigned __int16 *v12; // r1
  int v13; // r2
  int v14; // r1
  unsigned __int16 *v15; // r1
  int v16; // r0
  int v17; // r1
  unsigned __int16 *v18; // r1
  int v20; // r1
  int v21[2]; // [sp+0h] [bp-20h] BYREF
  int v22; // [sp+8h] [bp-18h] BYREF
  _BYTE *v23; // [sp+Ch] [bp-14h]

  v21[0] = a1;
  v21[1] = a2;
  v22 = a3;
  v23 = (_BYTE *)a4;
  v4 = 0;
  v5 = (__int16)a4;
  if ( a3 == 1 )
  {
    if ( *(_WORD *)(a2 + 4) )
      return *(unsigned __int16 *)(a2 + 4) == (__int16)a4;
    v10 = *(__int16 *)(a2 + 6);
    if ( v10 >= 0 )
    {
      v11 = *(_DWORD *)(a1 + 24);
      if ( v11 && v10 < *(unsigned __int16 *)(v11 + 6) )
        v12 = (unsigned __int16 *)(*(_DWORD *)(v11 + 16) + 2 * *(__int16 *)(*(_DWORD *)(v11 + 12) + 2 * v10));
      else
        v12 = 0;
      if ( v12 )
      {
        RtlInitUnicodeString((unsigned int)&v22, v12);
        if ( RtlCultureNameToLCID((unsigned __int16 *)&v22, v21) )
          return SLOWORD(v21[0]) == v5;
      }
    }
    return 0;
  }
  if ( a3 != 3 )
  {
    if ( a3 == 2 && (a4 & 0x8000u) == 0 )
    {
      v20 = *(_DWORD *)(a1 + 20);
      if ( (__int16)a4 < (int)*(unsigned __int16 *)(v20 + 6) )
        return a2 == *(_DWORD *)(v20 + 12) + 28 * (__int16)a4;
    }
    return 0;
  }
  v13 = *(__int16 *)(a2 + 6);
  v23 = 0;
  if ( v13 < 0 )
  {
    if ( !*(_WORD *)(a2 + 4) )
      return 0;
    v4 = sub_4F4434(a1, 0x55u, v13, *(unsigned __int16 *)(a2 + 4));
    if ( !v4 )
      return 0;
    v16 = *(unsigned __int16 *)(a2 + 4);
    v23 = v4;
    if ( !RtlLCIDToCultureName(v16, (unsigned int)&v22) )
    {
      ExFreePoolWithTag((unsigned int)v4);
      return 0;
    }
  }
  else
  {
    if ( v13 == (__int16)a4 )
      return 1;
    v14 = *(_DWORD *)(a1 + 24);
    if ( v14 && v13 < *(unsigned __int16 *)(v14 + 6) )
      v15 = (unsigned __int16 *)(*(_DWORD *)(v14 + 16) + 2 * *(__int16 *)(*(_DWORD *)(v14 + 12) + 2 * v13));
    else
      v15 = 0;
    if ( !v15 )
      return 0;
    RtlInitUnicodeString((unsigned int)&v22, v15);
  }
  v17 = *(_DWORD *)(a1 + 24);
  if ( v17 && v5 >= 0 && v5 < *(unsigned __int16 *)(v17 + 6) )
    v18 = (unsigned __int16 *)(*(_DWORD *)(v17 + 16) + 2 * *(__int16 *)(*(_DWORD *)(v17 + 12) + 2 * v5));
  else
    v18 = 0;
  v9 = v18 && !wcsicmp((int)v23, v18);
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  return v9;
}
