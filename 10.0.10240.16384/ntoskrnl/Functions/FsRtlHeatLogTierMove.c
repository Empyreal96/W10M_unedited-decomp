// FsRtlHeatLogTierMove 
 
int __fastcall FsRtlHeatLogTierMove(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  if ( (Microsoft_Windows_Storage_Tiering_IoHeatEnableBits & 0x10) != 0 )
    Template_xxxqqqq(
      Microsoft_Windows_Storage_Tiering_IoHeatHandle,
      SHIDWORD(Microsoft_Windows_Storage_Tiering_IoHeatHandle),
      (int)&Microsoft_Windows_Storage_Tiering_IoHeatHandle,
      a8);
  return 0;
}
