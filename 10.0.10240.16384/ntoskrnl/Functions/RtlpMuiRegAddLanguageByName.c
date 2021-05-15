// RtlpMuiRegAddLanguageByName 
 
int __fastcall RtlpMuiRegAddLanguageByName(int a1, int a2, unsigned __int16 *a3, int a4, int a5, int a6)
{
  int result; // r0
  __int16 v10[24]; // [sp+0h] [bp-30h] BYREF

  result = RtlpMuiRegInitAnyLanguage(a1, v10, a3, a4);
  if ( result >= 0 )
  {
    if ( (v10[0] & 4) != 0 )
    {
      result = sub_80C0B8();
    }
    else
    {
      if ( (v10[0] & 2) != 0 )
        JUMPOUT(0x80C0C4);
      if ( (v10[0] & 4) != 0 )
        result = RtlpIsALicensedLIPLanguage(a1, a3);
      else
        result = RtlpIsALicensedRegularLanguage(a1, a3);
      if ( result >= 0 )
      {
        v10[0] |= 0x820u;
        RtlpMuiRegAddAlternateCodePage((int)v10, a2);
        result = RtlpMuiRegGetOrAddLangInfo(a1 + 20, v10, a6);
      }
    }
  }
  return result;
}
