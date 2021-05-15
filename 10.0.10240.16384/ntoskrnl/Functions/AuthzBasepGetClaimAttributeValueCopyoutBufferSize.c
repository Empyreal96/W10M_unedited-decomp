// AuthzBasepGetClaimAttributeValueCopyoutBufferSize 
 
int __fastcall AuthzBasepGetClaimAttributeValueCopyoutBufferSize(int a1, unsigned int *a2, int a3, int a4)
{
  int v5; // r3
  unsigned int v7; // r2
  unsigned int v8; // r5
  int result; // r0
  unsigned int v10; // r2
  _DWORD *v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r5
  int *j; // r1
  unsigned int v15; // r3
  unsigned int v16; // r5
  int *i; // r1
  unsigned int v18; // r3
  unsigned int v19; // r5
  int v20[4]; // [sp+0h] [bp-10h] BYREF

  v20[0] = a4;
  v5 = *(unsigned __int16 *)(a1 + 24);
  v7 = *a2;
  if ( !*(_WORD *)(a1 + 24) )
    return -1073741811;
  if ( *(unsigned __int16 *)(a1 + 24) <= 2u )
    goto LABEL_35;
  switch ( v5 )
  {
    case 3:
      v16 = (v7 + 3) & 0xFFFFFFFC;
      if ( v16 < v7 )
        return -1073741675;
      result = RtlULongLongToULong(4 * *(_DWORD *)(a1 + 36), (unsigned __int64)*(unsigned int *)(a1 + 36) >> 30, v20);
      if ( result < 0 )
        return result;
      v10 = v20[0] + v16;
      if ( v20[0] + v16 < v16 )
        return -1073741675;
      for ( i = *(int **)(a1 + 44); i != (int *)(a1 + 44); i = (int *)*i )
      {
        v18 = *((unsigned __int16 *)i + 12) + v10;
        if ( v18 < v10 )
          return -1073741675;
        v10 = v18 + 2;
        if ( v18 + 2 < v18 )
          return -1073741675;
      }
      goto LABEL_38;
    case 4:
      v13 = (v7 + 7) & 0xFFFFFFF8;
      if ( v13 < v7 )
        return -1073741675;
      result = RtlULongLongToULong(16 * *(_DWORD *)(a1 + 36), (unsigned __int64)*(unsigned int *)(a1 + 36) >> 28, v20);
      if ( result < 0 )
        return result;
      v10 = v20[0] + v13;
      if ( v20[0] + v13 < v13 )
        return -1073741675;
      for ( j = *(int **)(a1 + 44); j != (int *)(a1 + 44); j = (int *)*j )
      {
        v15 = *((unsigned __int16 *)j + 16) + v10;
        if ( v15 < v10 )
          return -1073741675;
        v10 = v15 + 2;
        if ( v15 + 2 < v15 )
          return -1073741675;
      }
LABEL_38:
      result = 0;
      *a2 = v10;
      return result;
    case 5:
      goto LABEL_8;
    case 6:
LABEL_35:
      v19 = (v7 + 7) & 0xFFFFFFF8;
      if ( v19 < v7 )
        return -1073741675;
      result = RtlULongLongToULong(8 * *(_DWORD *)(a1 + 36), (unsigned __int64)*(unsigned int *)(a1 + 36) >> 29, v20);
      if ( result < 0 )
        return result;
      v10 = v20[0] + v19;
      if ( v20[0] + v19 < v19 )
        return -1073741675;
      goto LABEL_38;
  }
  if ( v5 != 16 )
    return -1073741811;
LABEL_8:
  v8 = (v7 + 3) & 0xFFFFFFFC;
  if ( v8 < v7 )
    return -1073741675;
  result = RtlULongLongToULong(8 * *(_DWORD *)(a1 + 36), (unsigned __int64)*(unsigned int *)(a1 + 36) >> 29, v20);
  if ( result >= 0 )
  {
    v10 = v20[0] + v8;
    if ( v20[0] + v8 < v8 )
      return -1073741675;
    v11 = *(_DWORD **)(a1 + 44);
    while ( v11 != (_DWORD *)(a1 + 44) )
    {
      v12 = v11[7] + v10;
      if ( v12 < v10 )
        return -1073741675;
      v11 = (_DWORD *)*v11;
      v10 = v12;
    }
    goto LABEL_38;
  }
  return result;
}
