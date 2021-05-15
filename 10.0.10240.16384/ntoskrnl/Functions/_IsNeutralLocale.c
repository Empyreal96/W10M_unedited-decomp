// _IsNeutralLocale 
 
BOOL __fastcall IsNeutralLocale(char *a1)
{
  return !a1 || !wcscmp(a1, (char *)&word_5CB8A8);
}
