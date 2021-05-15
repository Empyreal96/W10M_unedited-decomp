// CmpMigrateOOBELanguageToInstallationLanguage 
 
int CmpMigrateOOBELanguageToInstallationLanguage()
{
  int result; // r0

  if ( CmInstallUILanguageFallbackToOOBm )
    result = sub_966F48();
  else
    result = 0;
  return result;
}
