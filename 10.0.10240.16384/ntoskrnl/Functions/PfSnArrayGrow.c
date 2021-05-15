// PfSnArrayGrow 
 
int __fastcall PfSnArrayGrow(unsigned int a1, int a2, int a3, unsigned int *a4, int *a5)
{
  unsigned int v6; // r4
  int v8; // r0
  int v9; // r6
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = a3;
  v10[1] = (int)a4;
  if ( a1 < *a4 )
    return 1;
  v6 = (3 * *a4) >> 1;
  if ( v6 < 4 )
    v6 = 4;
  if ( a1 >= v6 )
    return sub_7E9A68();
  if ( RtlULongLongToULong(4 * v6, (unsigned __int64)v6 >> 30, v10) >= 0 )
  {
    v8 = ExAllocatePoolWithTag(1, v10[0], 1448108867);
    v9 = v8;
    if ( v8 )
    {
      if ( 4 * *a4 )
        memmove(v8, *a5, 4 * *a4);
      if ( *a5 )
        ExFreePoolWithTag(*a5);
      *a5 = v9;
      *a4 = v6;
      return 1;
    }
  }
  return 0;
}
