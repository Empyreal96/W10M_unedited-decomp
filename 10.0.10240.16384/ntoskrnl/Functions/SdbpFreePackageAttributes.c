// SdbpFreePackageAttributes 
 
_BYTE *__fastcall SdbpFreePackageAttributes(_BYTE *result, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned int v5; // r3
  unsigned int i; // r5
  unsigned __int16 *v7; // r1
  unsigned __int64 v8; // r0
  unsigned int v9; // r2
  int v10; // r2
  unsigned int v11; // r0
  unsigned int v12; // r0
  int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v4 = result;
  if ( result )
  {
    v5 = *((_DWORD *)result + 2);
    for ( i = 0; i < v5; ++i )
    {
      v7 = 0;
      if ( i < v5 )
      {
        v8 = *((unsigned int *)v4 + 1) * (unsigned __int64)i;
        if ( ULongLongToULong(v8, SHIDWORD(v8), v13) < 0
          || (v9 = *((_DWORD *)v4 + 5), v7 = (unsigned __int16 *)(v9 + v13[0]), v9 + v13[0] < v9) )
        {
          v7 = 0;
        }
      }
      v10 = *v7;
      if ( v10 == 24617 || v10 == 24618 || v10 == 24619 )
      {
        v11 = *((_DWORD *)v7 + 2);
        if ( v11 )
          ExFreePoolWithTag(v11);
      }
      v5 = *((_DWORD *)v4 + 2);
    }
    v12 = *((_DWORD *)v4 + 5);
    if ( v12 )
      ExFreePoolWithTag(v12);
    result = memset(v4, 0, 24);
  }
  return result;
}
