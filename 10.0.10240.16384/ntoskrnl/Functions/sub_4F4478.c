// sub_4F4478 
 
_BYTE *__fastcall sub_4F4478(unsigned int a1, unsigned int a2, unsigned int a3, int a4, unsigned int a5, int *a6)
{
  unsigned int v8; // r4
  int v9; // r5
  _BYTE *v10; // r0
  _BYTE *v11; // r4
  int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a4;
  if ( RtlULongLongToULong(a2 * a3, (a2 * (unsigned __int64)a3) >> 32, v13) < 0 )
    return 0;
  v8 = v13[0] + a1;
  if ( v13[0] + a1 < a1 )
    return 0;
  if ( RtlULongLongToULong(a4 * a5, ((unsigned int)a4 * (unsigned __int64)a5) >> 32, v13) < 0 )
    return 0;
  v9 = v8 + v13[0];
  if ( v8 + v13[0] < v8 )
    return 0;
  if ( a6 )
    *a6 = v9;
  if ( !v9 )
    return 0;
  v10 = (_BYTE *)ExAllocatePoolWithTag(1, v9);
  v11 = v10;
  if ( v10 )
    memset(v10, 0, v9);
  return v11;
}
