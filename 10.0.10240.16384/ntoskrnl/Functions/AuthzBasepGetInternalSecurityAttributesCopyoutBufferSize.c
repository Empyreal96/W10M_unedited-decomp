// AuthzBasepGetInternalSecurityAttributesCopyoutBufferSize 
 
int __fastcall AuthzBasepGetInternalSecurityAttributesCopyoutBufferSize(unsigned int *a1, unsigned int *a2, int a3, unsigned int a4)
{
  int result; // r0
  unsigned int v7; // r2
  int v8; // r4
  unsigned int *v9; // r5
  int v10; // t1
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a4;
  if ( !a1 || !a2 )
    return -1073741811;
  result = RtlULongLongToULong(*a1 << 6, (unsigned __int64)*a1 >> 26, v13);
  if ( result >= 0 )
  {
    v7 = v13[0] + 24;
    if ( v13[0] >= 0xFFFFFFE8 )
    {
LABEL_13:
      result = -1073741675;
    }
    else
    {
      v10 = a1[1];
      v9 = a1 + 1;
      v8 = v10;
      result = 0;
      while ( (unsigned int *)v8 != v9 )
      {
        v11 = (v7 + 1) & 0xFFFFFFFE;
        if ( v11 < v7 )
          goto LABEL_13;
        v12 = *(unsigned __int16 *)(v8 + 16) + v11;
        if ( v12 < v11 )
          goto LABEL_13;
        v13[0] = *(unsigned __int16 *)(v8 + 16) + v11;
        result = AuthzBasepGetInternalSecurityAttributeValueCopyoutBufferSize(v8, v13, v7, v12);
        if ( result < 0 )
          return result;
        v8 = *(_DWORD *)v8;
        v7 = v13[0];
      }
      *a2 = v7;
    }
  }
  return result;
}
