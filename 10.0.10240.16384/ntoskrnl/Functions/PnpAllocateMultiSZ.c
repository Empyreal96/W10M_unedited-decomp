// PnpAllocateMultiSZ 
 
int __fastcall PnpAllocateMultiSZ(int a1, int a2, int a3, int *a4)
{
  int v6; // r4
  int v7; // r5
  int v8; // r0
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[0] = (int)a4;
  v6 = 0;
  *a4 = 0;
  if ( a1 )
  {
    v6 = PnpGetMultiSzLength(a1, a2, v10);
    if ( v6 >= 0 )
    {
      v7 = v10[0];
      if ( v10[0] > 2u )
      {
        v6 = RtlULongLongToULong(2 * v10[0], (unsigned __int64)(unsigned int)v10[0] >> 31, v10);
        if ( v6 >= 0 )
        {
          v8 = ExAllocatePoolWithTag(1, v10[0], 1466986064);
          *a4 = v8;
          if ( v8 )
          {
            memmove(v8, a1, v10[0]);
            *(_WORD *)(*a4 + 2 * v7 - 2) = 0;
            *(_WORD *)(*a4 + 2 * v7 - 4) = 0;
          }
          else
          {
            v6 = -1073741670;
          }
        }
      }
    }
  }
  return v6;
}
