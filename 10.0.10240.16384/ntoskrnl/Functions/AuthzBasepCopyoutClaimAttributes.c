// AuthzBasepCopyoutClaimAttributes 
 
int __fastcall AuthzBasepCopyoutClaimAttributes(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v6; // r9
  int result; // r0
  unsigned int v8; // r8
  int v9; // r6
  unsigned int v10; // r2
  int v11; // r6
  unsigned int *v12; // r10
  unsigned int v13; // r2
  int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r4
  unsigned int v17; // r4
  unsigned int v18; // [sp+8h] [bp-28h] BYREF
  unsigned int v19; // [sp+Ch] [bp-24h]

  if ( !a2 || !a3 )
  {
    result = -1073741811;
    goto LABEL_17;
  }
  v6 = a2 + a3;
  if ( a2 + a3 < a2 )
  {
    result = -1073741811;
    goto LABEL_18;
  }
  memset((_BYTE *)a2, 0, a3);
  v8 = a2 + 12;
  v18 = 12;
  if ( a2 + 12 > v6 )
  {
    result = -1073741789;
    goto LABEL_18;
  }
  v9 = *a1;
  result = RtlULongLongToULong(20 * *a1, (20 * (unsigned __int64)*a1) >> 32, &v18);
  if ( result >= 0 )
  {
    v10 = v18 + v8;
    if ( v18 + v8 > v6 )
    {
LABEL_9:
      result = -2147483643;
      goto LABEL_18;
    }
    *(_WORD *)a2 = 1;
    *(_WORD *)(a2 + 2) = 0;
    *(_DWORD *)(a2 + 4) = v9;
    *(_DWORD *)(a2 + 8) = v8;
    v11 = a1[1];
    v12 = a1 + 1;
    while ( (unsigned int *)v11 != v12 )
    {
      v13 = v10 + 1;
      *(_WORD *)(v8 + 4) = *(_WORD *)(v11 + 24);
      v14 = *(_DWORD *)(v11 + 36);
      *(_WORD *)(v8 + 6) = 0;
      *(_DWORD *)(v8 + 12) = v14;
      *(_DWORD *)(v8 + 8) = *(_DWORD *)(v11 + 28);
      v18 = *(unsigned __int16 *)(v11 + 16) + 2;
      v15 = v18;
      v19 = v18;
      if ( (v13 & 0xFFFFFFFE) + v18 > v6 )
        goto LABEL_9;
      v16 = v13 & 0xFFFFFFFE;
      *(_DWORD *)v8 = v13 & 0xFFFFFFFE;
      v8 += 20;
      RtlStringCbCopyNW((_WORD *)(v13 & 0xFFFFFFFE), v15, *(_DWORD *)(v11 + 20), v15 - 2);
      v17 = v16 + v19;
      result = AuthzBasepCopyoutClaimAttributeValues(v11, v8 - 20, v17, v6 - v17, &v18);
      if ( result < 0 )
        goto LABEL_18;
      v11 = *(_DWORD *)v11;
      v10 = v18 + v17;
    }
LABEL_17:
    if ( result >= 0 )
      return result;
  }
LABEL_18:
  if ( a3 >= 0xC )
  {
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 8) = 0;
  }
  return result;
}
