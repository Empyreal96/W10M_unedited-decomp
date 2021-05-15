// PdcPoVerifyProcessIntegrity 
 
int __fastcall PdcPoVerifyProcessIntegrity(_BYTE *a1)
{
  int v2; // r5

  v2 = PsQuerySectionSignatureInformation(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( v2 >= 0 && SeCompareSigningLevels() )
    *a1 = 12;
  return v2;
}
