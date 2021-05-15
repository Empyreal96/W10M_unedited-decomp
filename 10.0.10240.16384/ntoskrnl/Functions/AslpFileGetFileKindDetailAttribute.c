// AslpFileGetFileKindDetailAttribute 
 
int __fastcall AslpFileGetFileKindDetailAttribute(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r2
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  v5 = AslFileMappingGetFileKindDetail(v8, a2);
  if ( v5 >= 0 )
  {
    v6 = v8[0];
    *(_DWORD *)(a1 + 672) = 2;
    *(_DWORD *)(a1 + 676) = 4;
    *(_QWORD *)(a1 + 680) = v6;
    v5 = 0;
    *(_DWORD *)(a1 + 688) |= 1u;
  }
  else
  {
    AslLogCallPrintf(
      1,
      (int)"AslpFileGetFileKindDetailAttribute",
      3876,
      "AslFileMappingGetFileKindDetails failed [%x]",
      v5);
  }
  return v5;
}
