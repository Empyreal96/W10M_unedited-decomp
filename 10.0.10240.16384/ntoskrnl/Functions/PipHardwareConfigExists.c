// PipHardwareConfigExists 
 
int __fastcall PipHardwareConfigExists(int a1, int a2)
{
  int v2; // r4
  int v4; // r7
  int v5; // r6
  int v6; // r0
  unsigned int v8; // [sp+8h] [bp-230h] BYREF
  int v9; // [sp+Ch] [bp-22Ch]
  int v10; // [sp+10h] [bp-228h] BYREF
  int v11; // [sp+14h] [bp-224h] BYREF
  char v12[544]; // [sp+18h] [bp-220h] BYREF

  v2 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v4 = a1;
  v5 = 0;
  do
  {
    v8 = 260;
    v6 = PnpCtxRegEnumKey(a1, v4, v5++, (int)v12, &v8);
    if ( v6 < 0 )
      break;
    a1 = PnpCtxRegOpenKey(0, v4, (int)v12, 0);
    if ( a1 >= 0 )
    {
      v8 = 4;
      if ( PnpCtxRegQueryValue(a1, v9, L"Id", &v11, (int)&v10, &v8) >= 0 && v11 == 4 && v8 == 4 && v10 == a2 )
        v2 = 1;
      a1 = ZwClose();
      v9 = 0;
    }
  }
  while ( !v2 );
  return v2;
}
