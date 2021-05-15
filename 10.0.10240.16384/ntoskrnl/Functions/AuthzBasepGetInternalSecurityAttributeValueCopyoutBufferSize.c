// AuthzBasepGetInternalSecurityAttributeValueCopyoutBufferSize 
 
int __fastcall AuthzBasepGetInternalSecurityAttributeValueCopyoutBufferSize(int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v5; // r2
  unsigned int v7; // r5
  int result; // r0
  unsigned int v9; // r2
  int *v10; // r1
  int *v11; // r4
  int *v12; // t1
  unsigned int v13; // r3
  unsigned int v14[4]; // [sp+0h] [bp-10h] BYREF

  v14[0] = a4;
  v5 = *a2;
  v7 = (*a2 + 7) & 0xFFFFFFF8;
  v14[0] = v7;
  if ( v7 < v5 )
    return -1073741675;
  result = RtlULongLongToULong(
             40 * *(_DWORD *)(a1 + 36),
             (40 * (unsigned __int64)*(unsigned int *)(a1 + 36)) >> 32,
             v14);
  if ( result < 0 )
    return result;
  v9 = v14[0] + v7;
  if ( v14[0] + v7 < v7 )
    return -1073741675;
  result = 0;
  if ( *(_WORD *)(a1 + 24) )
  {
    if ( *(unsigned __int16 *)(a1 + 24) > 2u )
    {
      if ( *(_WORD *)(a1 + 24) != 3 )
        return sub_520944(0);
      v12 = *(int **)(a1 + 44);
      v11 = (int *)(a1 + 44);
      v10 = v12;
      if ( v12 != v11 )
      {
        result = 0;
        do
        {
          v13 = *((unsigned __int16 *)v10 + 12) + v9;
          if ( v13 < v9 )
            return -1073741675;
          v10 = (int *)*v10;
          v9 = v13;
        }
        while ( v10 != v11 );
      }
    }
  }
  else
  {
    result = -1073741811;
  }
  if ( result >= 0 )
    *a2 = v9;
  return result;
}
