// ExpUpdateProductSuiteType 
 
int __fastcall ExpUpdateProductSuiteType(int a1, int a2, int a3, int a4)
{
  int *v4; // r2
  int v5; // r6
  int v6; // r1
  int v8; // r3
  int v10[6]; // [sp+8h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  if ( a1 )
  {
    if ( a1 == 1 && ExpProductInfoMappedType )
    {
      if ( MEMORY[0xFFFF9264] == 2 && ExpProductInfoMappedType == 3 )
        ExpProductInfoMappedType = 2;
      else
        MEMORY[0xFFFF9264] = ExpProductInfoMappedType;
    }
  }
  else
  {
    ExpProductInfoMappedType = 0;
    if ( RtlGetProductInfo(6, 0, 0, 0, v10) && v10[0] != -1412584499 )
    {
      v4 = &ExpProductInfoSuiteTypeMap;
      v5 = 51;
      v6 = dword_6416B0;
      do
      {
        if ( *v4 == v10[0] )
          return sub_96C548(&dword_6416B0, v6);
        v8 = v4[1];
        v4 += 3;
        v6 &= ~v8;
        --v5;
      }
      while ( v5 );
      dword_6416B0 = v6;
    }
  }
  return a1;
}
