// NtSetDefaultUILanguage 
 
int __fastcall NtSetDefaultUILanguage(unsigned int a1)
{
  int result; // r0

  if ( a1 )
    result = ExpSetCurrentUserUILanguage(L"MUILanguagePending", a1);
  else
    result = ExpSetCurrentUserUILanguage(0, 0);
  return result;
}
