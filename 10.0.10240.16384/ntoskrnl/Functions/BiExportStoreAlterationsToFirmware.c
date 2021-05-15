// BiExportStoreAlterationsToFirmware 
 
int __fastcall BiExportStoreAlterationsToFirmware(int a1)
{
  int result; // r0

  if ( BiGetFirmwareType() == 2 )
    result = BiExportStoreAlterationsToEfi(a1);
  else
    result = sub_812CCC();
  return result;
}
