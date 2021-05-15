// -IsNeutralLanguageItem@@YAHPBUCultureDataType@@@Z 
 
BOOL __fastcall IsNeutralLanguageItem(const struct CultureDataType *a1)
{
  return *((_DWORD *)a1 + 2) == 117 && *(_WORD *)a1 != 127;
}
