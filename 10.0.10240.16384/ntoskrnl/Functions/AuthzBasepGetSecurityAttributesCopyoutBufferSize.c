// AuthzBasepGetSecurityAttributesCopyoutBufferSize 
 
int __fastcall AuthzBasepGetSecurityAttributesCopyoutBufferSize(unsigned int *a1, int a2, unsigned int a3, unsigned int *a4)
{
  int v4; // r6
  int result; // r0
  unsigned int v9; // r4
  unsigned int v10; // r5
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r3
  int v14; // r5
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a3;
  v17[1] = (unsigned int)a4;
  v4 = a2;
  if ( !a2 )
  {
    result = RtlULongLongToULong(24 * *a1, (24 * (unsigned __int64)*a1) >> 32, v17);
    if ( result < 0 )
      return result;
    v9 = v17[0] + 12;
    if ( v17[0] < 0xFFFFFFF4 )
    {
      v14 = a1[1];
      while ( (unsigned int *)v14 != a1 + 1 )
      {
        v15 = (v9 + 1) & 0xFFFFFFFE;
        if ( v15 < v9 )
          return -1073741675;
        v16 = *(unsigned __int16 *)(v14 + 16) + v15;
        if ( v16 < v15 )
          return -1073741675;
        v17[0] = *(unsigned __int16 *)(v14 + 16) + v15;
        result = AuthzBasepGetSecurityAttributeValueCopyoutBufferSize(v14, v17, v15, v16);
        if ( result < 0 )
          return result;
        v14 = *(_DWORD *)v14;
        v9 = v17[0];
      }
      goto LABEL_12;
    }
    return -1073741675;
  }
  result = RtlULongLongToULong(24 * a3, (24 * (unsigned __int64)a3) >> 32, v17);
  if ( result < 0 )
    return result;
  v9 = v17[0] + 12;
  if ( v17[0] >= 0xFFFFFFF4 )
    return -1073741675;
  v10 = 0;
  if ( !a3 )
  {
LABEL_12:
    *a4 = v9;
    return result;
  }
  while ( 1 )
  {
    v11 = AuthzBasepFindSecurityAttribute(a1, v4);
    if ( !v11 )
      return -1073741275;
    v12 = (v9 + 1) & 0xFFFFFFFE;
    if ( v12 < v9 )
      return -1073741675;
    v13 = *(unsigned __int16 *)(v11 + 16) + v12;
    if ( v13 < v12 )
      return -1073741675;
    v17[0] = *(unsigned __int16 *)(v11 + 16) + v12;
    result = AuthzBasepGetSecurityAttributeValueCopyoutBufferSize(v11, v17, v12, v13);
    if ( result < 0 )
      return result;
    ++v10;
    v9 = v17[0];
    v4 += 8;
    if ( v10 >= a3 )
      goto LABEL_12;
  }
}
