// RtlLCIDToCultureName 
 
int __fastcall RtlLCIDToCultureName(int a1, unsigned int a2)
{
  unsigned __int16 v2; // r5
  int v3; // r4

  v2 = a1;
  v3 = 0;
  if ( !a1 || !a2 || a1 == 4096 )
    return 0;
  DbgPrint("!!! RTLMUI: Reusing LocaleBuffer !!!");
  if ( DownLevelLangIDToLanguageName(v2, word_647540, 64, 2) > 0 )
  {
    RtlInitUnicodeString(a2, word_647540);
    v3 = 1;
  }
  return v3;
}
