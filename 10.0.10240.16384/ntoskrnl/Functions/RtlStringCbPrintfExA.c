// RtlStringCbPrintfExA 
 
int __fastcall RtlStringCbPrintfExA(_BYTE *a1, unsigned int a2, _DWORD *a3, _DWORD *a4, int a5, char *a6)
{
  int v6; // r5
  char *v9; // r1
  int v10; // r10
  unsigned int v11; // r4
  _BYTE *v13; // [sp+8h] [bp-30h] BYREF
  unsigned int v14; // [sp+Ch] [bp-2Ch] BYREF
  int *v15; // [sp+10h] [bp-28h]
  unsigned int *v16; // [sp+14h] [bp-24h]
  _BYTE *varg_r0; // [sp+40h] [bp+8h]
  unsigned int varg_r1; // [sp+44h] [bp+Ch]
  _DWORD *varg_r2; // [sp+48h] [bp+10h]
  _DWORD *varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = 0;
  v15 = a3;
  v16 = a4;
  if ( (a5 & 0x100) != 0 )
  {
    if ( !a1 && a2 || a2 > 0x7FFFFFFF )
      v6 = -1073741811;
  }
  else
  {
    v6 = sub_43E028((int)a1, a2);
  }
  if ( v6 < 0 )
  {
    if ( a2 )
      *a1 = 0;
  }
  else
  {
    v9 = a6;
    v10 = (int)a1;
    v13 = a1;
    v14 = a2;
    v11 = a2;
    if ( (a5 & 0x100) != 0 && !a6 )
      v9 = &byte_5CB13F;
    v6 = 0;
    if ( (a5 & 0xFFFFE000) != 0 )
    {
      v6 = -1073741811;
      if ( a2 )
        *a1 = 0;
    }
    else if ( a2 )
    {
      v14 = 0;
      v6 = sub_4E23A8((int)a1, a2, (int *)&v14);
      v10 = (int)&a1[v14];
      v11 = a2 - v14;
      v13 = &a1[v14];
      v14 = a2 - v14;
      if ( v6 >= 0 )
      {
        if ( (a5 & 0x200) != 0 && v11 > 1 )
          memset((_BYTE *)(v10 + 1), (unsigned __int8)a5, v11 - 1);
        goto LABEL_18;
      }
    }
    else
    {
      if ( !*v9 )
      {
LABEL_18:
        if ( v15 )
          *v15 = v10;
        if ( v16 )
          *v16 = v11;
        return v6;
      }
      if ( a1 )
        v6 = -2147483643;
      else
        v6 = -1073741811;
    }
    if ( (a5 & 0x1C00) != 0 && a2 )
    {
      sub_555F04(a1, a2, 0, &v13, &v14, a5);
      v10 = (int)v13;
      v11 = v14;
    }
    if ( v6 == -2147483643 )
      goto LABEL_18;
  }
  return v6;
}
