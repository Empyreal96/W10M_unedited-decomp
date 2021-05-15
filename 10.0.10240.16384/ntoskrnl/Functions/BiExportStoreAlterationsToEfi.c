// BiExportStoreAlterationsToEfi 
 
int __fastcall BiExportStoreAlterationsToEfi(int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r0
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = (int)v7;
  v7[0] = (int)v7;
  v3 = BiBuildIdentifierList(a1, a2, v7);
  if ( v3 >= 0 )
  {
    v4 = BiExportBcdObjects(a1, v7);
    if ( v4 < 0 )
      v3 = v4;
    v5 = BiExportEfiBootManager(a1, v7);
    if ( v5 < 0 )
      v3 = v5;
  }
  BiFreeIdentifierList(v7);
  return v3;
}
