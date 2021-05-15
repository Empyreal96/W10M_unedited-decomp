// sub_8A12F4 
 
int __fastcall sub_8A12F4(_DWORD *a1, _DWORD *a2, unsigned int a3, int a4, _BYTE *a5)
{
  _DWORD *v5; // r10
  int v6; // r4
  int v7; // r0
  int v8; // r1
  unsigned __int8 *v9; // lr
  int v10; // r6
  int i; // r4
  int v12; // t1
  int v13; // r1
  char *v14; // r0
  int v15; // t1
  int result; // r0
  _DWORD *v17; // [sp+8h] [bp-98h]
  unsigned int v18; // [sp+Ch] [bp-94h]
  _DWORD *v19; // [sp+10h] [bp-90h]
  int v20; // [sp+14h] [bp-8Ch] BYREF
  _DWORD *v21; // [sp+18h] [bp-88h]
  int v22; // [sp+20h] [bp-80h] BYREF
  int v23; // [sp+24h] [bp-7Ch]
  int v24; // [sp+28h] [bp-78h]
  int v25; // [sp+30h] [bp-70h]
  int v26; // [sp+34h] [bp-6Ch]
  int v27; // [sp+38h] [bp-68h]
  int v28; // [sp+3Ch] [bp-64h]
  int v29; // [sp+40h] [bp-60h]
  int v30; // [sp+44h] [bp-5Ch]
  char v31; // [sp+48h] [bp-58h]
  char v32[8]; // [sp+50h] [bp-50h] BYREF
  int v33; // [sp+58h] [bp-48h]

  v17 = a2;
  v18 = a3;
  v5 = (_DWORD *)a4;
  v21 = (_DWORD *)a4;
  v19 = a1;
  if ( !dword_922C44 )
  {
    v6 = dword_920284;
    goto LABEL_20;
  }
  v7 = sub_6E2570((int)v32, (int)a2, a3, a4);
  if ( v7 < 0 )
  {
    if ( v7 != -1073741275 || !dword_922C44 )
      goto LABEL_18;
    v25 = 0;
    v26 = 0;
    v24 = 4;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    v8 = *(_DWORD *)(dword_922C44 + 4);
    v31 = 1;
    v9 = (unsigned __int8 *)(dword_922C44 + 20);
    if ( dword_922C44 == -20 )
      goto LABEL_16;
    v10 = 0;
    for ( i = 0; v8; --v8 )
    {
      v12 = *v9++;
      i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v12 - 23737705 + i), 21), 21), 21);
      v10 += v12 - 23737705 + i;
    }
    v22 = v10;
    v23 = i;
    if ( !dword_922C3C )
      goto LABEL_17;
    if ( RtlULongLongToULong(8 * dword_922C3C, (unsigned __int64)(unsigned int)dword_922C3C >> 29, &v20) )
    {
LABEL_16:
      v22 = 0;
      v23 = 0;
      v24 = 4;
    }
    else
    {
      v13 = v20;
      v14 = byte_922C48;
      if ( v20 )
      {
        do
        {
          v15 = (unsigned __int8)*v14++;
          i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v15 - 23737705 + i), 21), 21), 21);
          v10 += v15 - 23737705 + i;
          --v13;
        }
        while ( v13 );
        v5 = v21;
      }
      v22 = v10;
      v23 = i;
    }
LABEL_17:
    memmove((int)v32, (int)&v22, 0x30u);
    v33 = 4;
    sub_6E34A4((int)v32, -1, 0);
LABEL_18:
    v6 = 4;
    goto LABEL_19;
  }
  v6 = v33;
LABEL_19:
  a3 = v18;
  a1 = v19;
  a2 = v17;
LABEL_20:
  if ( v6 )
  {
    *a5 = 1;
    result = sub_6E29F0(a1, a2, a3, v5, 4);
  }
  else
  {
    result = -1073741772;
    *a5 = 0;
  }
  return result;
}
