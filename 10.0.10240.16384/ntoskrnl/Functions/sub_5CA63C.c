// sub_5CA63C 
 
int __fastcall sub_5CA63C(unsigned int *a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6, int *a7)
{
  unsigned int v9; // r4
  int v10; // r5
  _BYTE *v11; // r0
  int v12; // r4
  int v14[4]; // [sp+0h] [bp-10h] BYREF

  v14[0] = a4;
  if ( !a1 )
    return 0;
  if ( RtlULongLongToULong(a3 * a4, (a3 * (unsigned __int64)(unsigned int)a4) >> 32, v14) < 0 )
    return 0;
  v9 = v14[0] + a2;
  if ( v14[0] + a2 < a2 )
    return 0;
  if ( RtlULongLongToULong(0, 0, v14) < 0 )
    return 0;
  v10 = v9 + v14[0];
  if ( v9 + v14[0] < v9 )
    return 0;
  if ( a7 )
    *a7 = v10;
  if ( v10 )
  {
    v11 = (_BYTE *)ExAllocatePoolWithTag(1, v10);
    v12 = (int)v11;
    if ( !v11 )
      return 0;
    memset(v11, 0, v10);
  }
  else
  {
    v12 = 0;
  }
  if ( !v12 )
    return 0;
  memmove(v12, (int)a1, *a1);
  ExFreePoolWithTag(a1);
  return v12;
}
