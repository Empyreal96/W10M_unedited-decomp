// AslpFileGetVersionAttributes 
 
int __fastcall AslpFileGetVersionAttributes(int a1, int a2)
{
  int v3; // r0
  int v4; // r2
  int v5; // r4
  int v6; // r1
  int v7; // r0
  int v8; // r4
  int v10; // [sp+8h] [bp-10h] BYREF
  int v11[3]; // [sp+Ch] [bp-Ch] BYREF

  v10 = 0;
  v11[0] = 0;
  v3 = AslpFileGetVersionBlock(&v10, v11, a2);
  if ( v3 >= 0 )
  {
    v5 = v10;
    v6 = v11[0];
  }
  else
  {
    if ( !AslFileResourceNotFound(v3) )
      AslLogCallPrintf(3, (int)"AslpFileGetVersionAttributes", 1093, "AslpFileGetVersionBlock failed [%x]", v4);
    v5 = 0;
    v6 = 0;
  }
  v7 = AslpFileMakeBinVersionAttributes(a1, v6);
  v8 = AslpFileMakeStringVersionAttributes(v7, v5);
  if ( v8 >= 0 )
    return 0;
  AslLogCallPrintf(1, (int)"AslpFileGetVersionAttributes", 1116, "AslpFileMakeStringVersionAttributes failed [%x]", v8);
  return v8;
}
