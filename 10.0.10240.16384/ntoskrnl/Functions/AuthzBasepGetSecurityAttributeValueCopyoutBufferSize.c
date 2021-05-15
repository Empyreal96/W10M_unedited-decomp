// AuthzBasepGetSecurityAttributeValueCopyoutBufferSize 
 
int __fastcall AuthzBasepGetSecurityAttributeValueCopyoutBufferSize(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v6; // r2
  unsigned int v7; // r5
  int result; // r0
  unsigned int v9; // r2
  unsigned int v10; // r5
  int *v11; // r1
  unsigned int v12; // r3
  int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a4;
  v6 = *a2;
  if ( !*(_WORD *)(a1 + 24) )
    return -1073741811;
  if ( *(unsigned __int16 *)(a1 + 24) <= 2u )
  {
    v7 = (v6 + 7) & 0xFFFFFFF8;
    if ( v7 >= v6 )
    {
      result = RtlULongLongToULong(8 * *(_DWORD *)(a1 + 36), (unsigned __int64)*(unsigned int *)(a1 + 36) >> 29, v13);
      if ( result < 0 )
        return result;
      v9 = v13[0] + v7;
      if ( v13[0] + v7 >= v7 )
        goto LABEL_6;
    }
    goto LABEL_17;
  }
  if ( *(_WORD *)(a1 + 24) != 3 )
    return sub_517B78();
  v10 = (v6 + 3) & 0xFFFFFFFC;
  if ( v10 < v6 )
    goto LABEL_17;
  result = RtlULongLongToULong(8 * *(_DWORD *)(a1 + 36), (unsigned __int64)*(unsigned int *)(a1 + 36) >> 29, v13);
  if ( result >= 0 )
  {
    v9 = v13[0] + v10;
    if ( v13[0] + v10 >= v10 )
    {
      v11 = *(int **)(a1 + 44);
      while ( v11 != (int *)(a1 + 44) )
      {
        v12 = *((unsigned __int16 *)v11 + 12) + v9;
        if ( v12 < v9 )
          goto LABEL_17;
        v11 = (int *)*v11;
        v9 = v12;
      }
LABEL_6:
      result = 0;
      *a2 = v9;
      return result;
    }
LABEL_17:
    result = -1073741675;
  }
  return result;
}
