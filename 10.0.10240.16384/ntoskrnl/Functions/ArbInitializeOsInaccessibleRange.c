// ArbInitializeOsInaccessibleRange 
 
int __fastcall ArbInitializeOsInaccessibleRange(char a1)
{
  int v2; // r4
  int v4[18]; // [sp+50h] [bp-60h] BYREF

  v2 = ZwOpenKey();
  if ( v2 >= 0 )
  {
    v2 = ZwCreateKey();
    if ( v2 >= 0 )
    {
      memset(v4, 0, sizeof(v4));
      v4[0] = 72;
      v4[7] = 1;
      v4[9] = 1;
      BYTE1(v4[10]) = 3;
      v4[15] = 1 << (a1 - 32);
      v4[14] = 1 << a1;
      v4[16] = -1;
      v4[17] = -1;
      v2 = ZwSetValueKey();
      if ( v2 >= 0 )
        v2 = 0;
      ZwClose();
    }
    ZwClose();
  }
  return v2;
}
