// RtlpInheritAcl2 
 
int __fastcall RtlpInheritAcl2(int a1, unsigned __int8 *a2, __int16 a3, int a4, unsigned __int8 a5, char a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, unsigned int *a15, int a16, _BYTE *a17, int *a18)
{
  int v18; // r10
  unsigned __int8 *v20; // r2
  unsigned int v21; // r5
  int v22; // r6
  int v23; // lr
  int v24; // r3
  int v25; // r0
  int v26; // r2
  int result; // r0
  int v28; // r1
  unsigned int v29; // r2
  char v30; // r7
  int v31; // r2
  int v32; // r5
  unsigned int v33; // r2
  int v34; // r3
  char v35[4]; // [sp+30h] [bp-58h] BYREF
  unsigned __int8 *v36; // [sp+34h] [bp-54h]
  int v37; // [sp+38h] [bp-50h]
  unsigned int v38; // [sp+3Ch] [bp-4Ch]
  int v39; // [sp+40h] [bp-48h]
  int v40; // [sp+44h] [bp-44h]
  unsigned __int8 *v41; // [sp+48h] [bp-40h]
  int v42; // [sp+4Ch] [bp-3Ch] BYREF
  int v43; // [sp+50h] [bp-38h]
  int v44; // [sp+54h] [bp-34h]
  int v45; // [sp+58h] [bp-30h] BYREF
  int v46; // [sp+5Ch] [bp-2Ch]
  int v47; // [sp+60h] [bp-28h]
  int v48; // [sp+64h] [bp-24h]

  v45 = a4;
  v37 = 0;
  v43 = 0;
  v44 = 0;
  v18 = 0;
  v46 = 0;
  v47 = 0;
  v40 = 0;
  v41 = a2;
  v48 = 1;
  v20 = (unsigned __int8 *)a1;
  v21 = *a15;
  v39 = 0;
  v22 = 0;
  v38 = 2;
  v23 = (int)a2;
  v36 = (unsigned __int8 *)a1;
  v42 = 0;
  if ( v21 >= 8 && v21 <= 0xFFFC )
  {
    *(_WORD *)(a16 + 2) = v21 & 0xFFFC;
    *(_BYTE *)a16 = 2;
    *(_BYTE *)(a16 + 1) = 0;
    *(_WORD *)(a16 + 4) = 0;
    *(_WORD *)(a16 + 6) = 0;
  }
  *a17 = 0;
  if ( a5 )
    v24 = 1024;
  else
    v24 = 0;
  v25 = a12;
  *a18 = v24;
  if ( (a3 & 8) != 0 )
  {
    v28 = 0;
    goto LABEL_26;
  }
  if ( (a3 & 0x1000) != 0 )
  {
    v39 = 1;
    v25 = a12;
    *a18 = v24 | 0x1000;
  }
  if ( (a3 & 0x1004) == 0 )
    goto LABEL_25;
  if ( a2 )
  {
    if ( *a2 >= 2u )
      v38 = *a2;
    v48 = 0;
    if ( a5 )
    {
      if ( (a3 & 0x1000) != 0 )
        v26 = 2;
      else
        v26 = 1;
    }
    else
    {
      v26 = 2;
    }
    result = RtlpCopyAces(a2, a11, v26);
    v37 = v43;
    v18 = v43;
    if ( result == -1073741789 )
    {
      v40 = 1;
    }
    else if ( result < 0 )
    {
      return result;
    }
    if ( a6 )
      return sub_7FB390();
    v23 = (int)v41;
    v25 = a12;
LABEL_21:
    if ( v25 != 1 )
      goto LABEL_22;
    goto LABEL_24;
  }
  if ( !a5 )
    goto LABEL_21;
  if ( v25 == 1 )
  {
    if ( (a3 & 0x1004) == 4 )
      return -1073741705;
LABEL_24:
    *a17 = 1;
LABEL_25:
    v20 = v36;
    v28 = v39;
    goto LABEL_26;
  }
LABEL_22:
  v28 = v39;
  if ( v25 == 2 && (v37 || v39 || v23 && !*(_WORD *)(v23 + 4)) )
    *a17 = 1;
  v20 = v36;
LABEL_26:
  if ( (a5 || (a3 & 4) != 0) && (a3 & 8) == 0 && (!a5 || v28) || !v20 )
  {
    v32 = v37;
    v30 = v38;
  }
  else
  {
    v29 = *v20;
    if ( v29 < 2 || v29 > 4 )
      return -1073741736;
    v30 = v38;
    if ( v38 <= v29 )
    {
      v38 = v29;
      v30 = v29;
    }
    result = RtlpGenerateInheritAcl(v36, v45, a5, a7, a8, a9, a10, a11, a13, a14, a12, v40, &v42, a16, v35);
    if ( result == -1073741789 )
    {
      v31 = 1;
      v40 = 1;
    }
    else
    {
      if ( result < 0 )
        return result;
      v31 = v40;
    }
    v32 = v37;
    if ( a6 && v37 && v35[0] && !v31 )
    {
      if ( !RtlFirstFreeAce(a16, &v45) )
        goto LABEL_78;
      v34 = v45;
      if ( !v45 )
        v34 = *(unsigned __int16 *)(a16 + 2) + a16;
      memmove(a16 + 8, v46, v34 - v46);
      v22 = v42;
      v18 = 0;
      *(_WORD *)(a16 + 4) -= v47;
    }
    else
    {
      v22 = v42;
    }
  }
  if ( v22 + v18 )
    goto LABEL_41;
  if ( !*a17 )
  {
    *a15 = 0;
    return -2147483637;
  }
  if ( !v48 )
  {
LABEL_41:
    v33 = v22 + v18 + 8;
    if ( v33 <= 0xFFFF )
    {
      *a15 = v22 + v32 + 8;
      if ( v40 )
        return -1073741789;
      *(_WORD *)(a16 + 2) = v33;
      *(_BYTE *)a16 = v30;
      return 0;
    }
LABEL_78:
    JUMPOUT(0x7FB3AC);
  }
  *a15 = 0;
  return 0;
}
