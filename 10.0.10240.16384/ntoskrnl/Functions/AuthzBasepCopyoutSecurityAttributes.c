// AuthzBasepCopyoutSecurityAttributes 
 
int __fastcall AuthzBasepCopyoutSecurityAttributes(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v9; // r8
  int result; // r0
  unsigned int v11; // r6
  unsigned int v12; // r4
  unsigned int v13; // r10
  _DWORD *v14; // r0
  _DWORD *v15; // r2
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r4
  int v19; // r4
  int v20; // r3
  int *v21; // r7
  int v22; // r3
  unsigned int v23; // r2
  int v24; // r4
  unsigned int v25; // r4
  unsigned int v26; // [sp+8h] [bp-38h] BYREF
  _DWORD *v27; // [sp+Ch] [bp-34h]
  _DWORD *i; // [sp+10h] [bp-30h]
  unsigned int v29; // [sp+14h] [bp-2Ch]
  int v30; // [sp+18h] [bp-28h]
  _DWORD *v31; // [sp+1Ch] [bp-24h]

  v27 = a1;
  v29 = a3;
  if ( a4 && a5 )
  {
    v9 = a4 + a5;
    if ( a4 + a5 < a4 )
      return sub_5209EC();
    memset((_BYTE *)a4, 0, a5);
    v11 = a4 + 12;
    v26 = 12;
    if ( a4 + 12 > v9
      || (!a2 ? (v12 = *a1) : (v12 = a3),
          (result = RtlULongLongToULong(24 * v12, (24 * (unsigned __int64)v12) >> 32, &v26), result < 0)
       || (v13 = v26 + v11, v26 + v11 > v9)) )
    {
LABEL_28:
      JUMPOUT(0x5209EE);
    }
    *(_WORD *)a4 = 1;
    *(_WORD *)(a4 + 2) = 0;
    *(_DWORD *)(a4 + 4) = v12;
    *(_DWORD *)(a4 + 8) = v11;
    if ( a2 )
    {
      for ( i = 0; (unsigned int)i < v29; i = (_DWORD *)((char *)i + 1) )
      {
        v14 = AuthzBasepFindSecurityAttribute((int)v27, a2);
        v15 = v14;
        v31 = v14;
        if ( !v14 )
          goto LABEL_28;
        v16 = v13 + 1;
        *(_WORD *)(v11 + 8) = *((_WORD *)v14 + 12);
        *(_DWORD *)(v11 + 16) = v14[9];
        *(_WORD *)(v11 + 10) = 0;
        *(_DWORD *)(v11 + 12) = v14[7];
        v17 = *((unsigned __int16 *)v14 + 8);
        v30 = *((unsigned __int16 *)v15 + 8);
        v26 = v17;
        if ( ((v13 + 1) & 0xFFFFFFFE) + v17 > v9 )
          goto LABEL_28;
        v18 = v16 & 0xFFFFFFFE;
        *(_DWORD *)(v11 + 4) = v16 & 0xFFFFFFFE;
        *(_WORD *)v11 = v17;
        *(_WORD *)(v11 + 2) = v17;
        memmove(v16 & 0xFFFFFFFE, v15[5], v17);
        v19 = v18 + v30;
        result = AuthzBasepCopyoutSecurityAttributeValues(v31, v11, v19, v9 - v19, &v26);
        if ( result < 0 )
          goto LABEL_28;
        a2 += 8;
        v11 += 24;
        v13 = v26 + v19;
      }
    }
    else
    {
      v20 = (int)(v27 + 1);
      v21 = (int *)v27[1];
      i = v27 + 1;
      while ( v21 != (int *)v20 )
      {
        *(_WORD *)(v11 + 8) = *((_WORD *)v21 + 12);
        v22 = v21[9];
        *(_WORD *)(v11 + 10) = 0;
        *(_DWORD *)(v11 + 16) = v22;
        *(_DWORD *)(v11 + 12) = v21[7];
        v23 = *((unsigned __int16 *)v21 + 8);
        v29 = v23;
        v26 = v23;
        if ( ((v13 + 1) & 0xFFFFFFFE) + v23 > v9 )
          goto LABEL_28;
        v24 = (v13 + 1) & 0xFFFFFFFE;
        *(_DWORD *)(v11 + 4) = v24;
        *(_WORD *)v11 = v23;
        *(_WORD *)(v11 + 2) = v23;
        memmove(v24, v21[5], v23);
        v25 = v24 + v29;
        result = AuthzBasepCopyoutSecurityAttributeValues(v21, v11, v25, v9 - v25, &v26);
        if ( result < 0 )
          goto LABEL_28;
        v21 = (int *)*v21;
        v11 += 24;
        v13 = v26 + v25;
        v20 = (int)i;
      }
    }
  }
  else
  {
    result = -1073741811;
  }
  if ( result < 0 )
    goto LABEL_28;
  return result;
}
