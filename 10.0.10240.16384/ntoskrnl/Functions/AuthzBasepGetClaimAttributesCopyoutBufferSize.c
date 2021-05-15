// AuthzBasepGetClaimAttributesCopyoutBufferSize 
 
int __fastcall AuthzBasepGetClaimAttributesCopyoutBufferSize(unsigned int *a1, unsigned int *a2, int a3, unsigned int a4)
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
  result = RtlULongLongToULong(20 * *a1, (20 * (unsigned __int64)*a1) >> 32, v13);
  if ( result >= 0 )
  {
    v7 = v13[0] + 12;
    if ( v13[0] < 0xFFFFFFF4 )
    {
      v10 = a1[1];
      v9 = a1 + 1;
      v8 = v10;
      while ( (unsigned int *)v8 != v9 )
      {
        v11 = (v7 + 1) & 0xFFFFFFFE;
        if ( v11 < v7 )
          goto LABEL_3;
        v12 = *(unsigned __int16 *)(v8 + 16) + v11;
        if ( v12 < v11 || v12 + 2 < v12 )
          goto LABEL_3;
        v13[0] = v12 + 2;
        result = AuthzBasepGetClaimAttributeValueCopyoutBufferSize(v8, v13, v12 + 2, v12);
        if ( result < 0 )
          return result;
        v8 = *(_DWORD *)v8;
        v7 = v13[0];
      }
      *a2 = v7;
    }
    else
    {
LABEL_3:
      result = -1073741675;
    }
  }
  return result;
}
