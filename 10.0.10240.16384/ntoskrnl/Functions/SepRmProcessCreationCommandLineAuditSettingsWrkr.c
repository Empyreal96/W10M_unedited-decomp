// SepRmProcessCreationCommandLineAuditSettingsWrkr 
 
int __fastcall SepRmProcessCreationCommandLineAuditSettingsWrkr(int result, int a2)
{
  char v2; // r2

  *(_DWORD *)(a2 + 24) = 0;
  v2 = *(_BYTE *)(result + 28);
  __dmb(0xBu);
  SepRmAuditProcessCommandLine = v2;
  SepRmAuditingEnabled = 1;
  return result;
}
