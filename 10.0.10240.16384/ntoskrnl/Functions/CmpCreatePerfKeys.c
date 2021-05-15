// CmpCreatePerfKeys 
 
int CmpCreatePerfKeys()
{
  int result; // r0
  int v1; // r0
  int v2; // r3
  int v3; // [sp+8h] [bp-38h] BYREF
  int v4[6]; // [sp+10h] [bp-30h] BYREF
  _WORD v5[12]; // [sp+28h] [bp-18h] BYREF

  v4[0] = 24;
  v4[1] = 0;
  v4[3] = 64;
  v4[2] = (int)&CmpPerflibPathString;
  v4[4] = 0;
  v4[5] = 0;
  result = CmOpenKey(&v3, 0x20006u, (int)v4, 0, 0);
  if ( result >= 0 )
  {
    CmpCreatePredefined(v3, L"009", -2147483568);
    v1 = CmpCreatePredefined(v3, L"CurrentLanguage", -2147483552);
    if ( PsDefaultSystemLocaleId != 1033 )
    {
      v2 = PsDefaultUILanguageId & 0x3FF;
      if ( v2 == 4 )
        JUMPOUT(0x80B32E);
      if ( v2 == 22 )
        return sub_80B31C(v1);
      RtlStringCbPrintfW(v5, 0xAu, (int)L"%0*X", 3);
      CmpCreatePredefined(v3, v5, -2147483552);
    }
    result = NtClose();
  }
  return result;
}
