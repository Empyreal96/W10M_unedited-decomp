// RtlpComputeMergedAcl2 
 
int __fastcall RtlpComputeMergedAcl2(_BYTE *a1, int a2, unsigned __int8 *a3, __int16 a4, int a5, int a6, _DWORD *a7, int a8, unsigned int *a9, unsigned __int8 *a10, _DWORD *a11)
{
  int v12; // r10
  unsigned int v13; // r1
  unsigned int v15; // r7
  BOOL v16; // r9
  unsigned int v17; // r8
  int result; // r0
  int v19; // r3
  unsigned __int8 *v20; // r5
  unsigned int v21; // r3
  unsigned int v22; // r3
  unsigned int v23; // r2
  int v24; // [sp+4h] [bp-54h]
  int v25; // [sp+Ch] [bp-4Ch]
  char v26; // [sp+18h] [bp-40h]
  int v27; // [sp+1Ch] [bp-3Ch]
  unsigned int v28; // [sp+28h] [bp-30h] BYREF
  unsigned int v29; // [sp+2Ch] [bp-2Ch] BYREF
  int v30; // [sp+30h] [bp-28h]
  _BYTE *v31; // [sp+34h] [bp-24h]

  v29 = 0;
  v30 = a2;
  v12 = 0;
  v31 = a1;
  v13 = *a9;
  v15 = 0;
  v28 = 0;
  v16 = 1;
  v17 = 2;
  RtlCreateAcl((int)a10, v13, 2);
  result = -1073741789;
  *a11 = 1024;
  if ( (a4 & 0x1000) != 0 )
  {
    *a11 = 5120;
    if ( a3 )
    {
      v26 = 0;
      if ( *a3 >= 2u )
        LOBYTE(v17) = *a3;
      v27 = a8;
      v25 = a5;
      v24 = a5;
      v19 = 16;
LABEL_6:
      v20 = a10;
      result = RtlpCopyAces((int)a3, a7, 2, v19, 1u, v24, a6, v25, a6, 1, v26, v27, &v28, a10);
      if ( result == -1073741789 )
      {
        v12 = 1;
        result = 0;
      }
      if ( result < 0 )
        return result;
      v15 = v28;
      v16 = 0;
      goto LABEL_36;
    }
    goto LABEL_34;
  }
  if ( (v30 & 0x1000) != 0 )
  {
    if ( a3 )
    {
      if ( *a3 >= 2u )
        LOBYTE(v17) = *a3;
      v26 = 1;
      v27 = a8;
      v25 = a5;
      v24 = a5;
      v19 = 0;
      goto LABEL_6;
    }
    if ( a8 != 1 )
    {
LABEL_34:
      v20 = a10;
      v21 = 0;
      goto LABEL_38;
    }
    return -1073741705;
  }
  v16 = a8 != 1;
  if ( a3 )
  {
    if ( *a3 >= 2u )
      v17 = *a3;
    result = RtlpCopyAces((int)a3, a7, 1, 0, 1u, a5, a6, a5, a6, 1, 0, a8, &v28, a10);
    if ( result == -1073741789 )
    {
      v12 = 1;
      result = 0;
    }
    if ( result < 0 )
      return result;
    v15 = v28;
    if ( !*((_WORD *)a3 + 2) )
      v16 = 0;
  }
  else if ( a8 == 1 )
  {
    return -1073741705;
  }
  if ( v31 )
  {
    if ( v17 <= (unsigned __int8)*v31 )
      LOBYTE(v17) = *v31;
    result = RtlpCopyAces((int)v31, a7, 0, 0, 0, 0, 0, 0, 0, 1, 0, a8, &v29, a10);
    if ( result == -1073741789 )
    {
      v12 = 1;
      result = 0;
    }
    if ( result < 0 )
      return result;
    v21 = v29;
    v20 = a10;
    goto LABEL_37;
  }
  v20 = a10;
LABEL_36:
  v21 = 0;
LABEL_37:
  result = -1073741789;
LABEL_38:
  v22 = v21 + v15;
  if ( !v22 && v16 )
  {
    *a9 = 0;
    return 0;
  }
  v23 = v22 + 8;
  if ( v22 + 8 > 0xFFFF )
    return -1073741699;
  *a9 = v23;
  if ( !v12 )
  {
    *((_WORD *)v20 + 1) = v23;
    *v20 = v17;
    return 0;
  }
  return result;
}
