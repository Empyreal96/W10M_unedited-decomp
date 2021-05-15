// BiCloseStore 
 
int __fastcall BiCloseStore(int a1, char a2)
{
  int v2; // r5

  v2 = 0;
  if ( (a2 & 4) != 0 )
    v2 = BiExportStoreAlterationsToFirmware();
  if ( (a2 & 2) != 0 )
    return sub_812CC0(a1);
  BiCloseKey(a1);
  return v2;
}
