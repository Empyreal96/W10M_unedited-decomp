// RtlStringCbCopyExW 
 
int __fastcall RtlStringCbCopyExW(_WORD *a1, unsigned int a2, __int16 *a3, _DWORD *a4, _DWORD *a5, int a6)
{
  __int16 *v6; // lr
  int v7; // r5
  _WORD *v9; // r6
  _WORD *v11; // r10
  int v12; // r4
  unsigned int v13; // r3
  _WORD *v14; // [sp+8h] [bp-28h]
  int v15; // [sp+Ch] [bp-24h] BYREF
  _DWORD *v16; // [sp+10h] [bp-20h]

  v6 = a3;
  v7 = a2 >> 1;
  v16 = a4;
  v9 = a1;
  if ( (a6 & 0x100) == 0 )
    JUMPOUT(0x50ABAC);
  if ( !a1 )
    return sub_50ABA4();
  v11 = a1;
  v14 = a1;
  v15 = a2 >> 1;
  if ( !a3 && (a6 & 0x100) != 0 )
    v6 = &word_5CB8A8;
  v12 = 0;
  if ( (a6 & 0xFFFFE000) != 0 )
  {
    v12 = -1073741811;
    if ( v7 )
      *a1 = 0;
    goto LABEL_18;
  }
  if ( v7 )
  {
    v15 = 0;
    v12 = sub_4562C8(a1, a2 >> 1, &v15, v6);
    v11 = &v9[v15];
    v7 -= v15;
    v14 = v11;
    v15 = v7;
    if ( v12 >= 0 )
    {
      if ( (a6 & 0x200) != 0 )
      {
        v13 = (a2 & 1) + 2 * v7;
        if ( v13 > 2 )
          memset((_BYTE *)v11 + 2, (unsigned __int8)a6, v13 - 2);
      }
      goto LABEL_9;
    }
LABEL_18:
    if ( (a6 & 0x1C00) != 0 && a2 )
    {
      sub_568498(v9, a2);
      v11 = v14;
      v7 = v15;
    }
    if ( v12 != -2147483643 )
      return v12;
    goto LABEL_9;
  }
  if ( *v6 )
  {
    v12 = -2147483643;
    goto LABEL_18;
  }
LABEL_9:
  if ( v16 )
    *v16 = v11;
  if ( a5 )
    *a5 = (a2 & 1) + 2 * v7;
  return v12;
}
