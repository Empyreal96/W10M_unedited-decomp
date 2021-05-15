// RtlpInitNlsSectionName 
 
int __fastcall RtlpInitNlsSectionName(int a1, int a2, unsigned __int16 *a3, int a4, unsigned int a5)
{
  const __int16 *v6; // r2
  int v7; // r4

  if ( a1 == 11 )
  {
    v6 = L"\\NLS\\NlsSectionCP%d";
  }
  else
  {
    if ( a1 != 12 )
      return -1073741585;
    v6 = L"\\NLS\\NlsSectionNORM%.8x";
  }
  v7 = RtlStringCchPrintfW(a3, 0x40u, (int)v6, a2);
  if ( v7 >= 0 )
    RtlInitUnicodeString(a5, a3);
  return v7;
}
