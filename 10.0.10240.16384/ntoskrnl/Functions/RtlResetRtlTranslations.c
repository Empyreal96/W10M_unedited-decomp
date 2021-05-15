// RtlResetRtlTranslations 
 
_BYTE *__fastcall RtlResetRtlTranslations(int a1, int a2)
{
  _BYTE *result; // r0
  int v3; // r7
  int v4; // r6

  if ( word_9821C0 )
    return (_BYTE *)sub_81B354(NlsLeadByteInfoTable, a2, 512);
  memset(NlsLeadByteInfoTable, 0, sizeof(NlsLeadByteInfoTable));
  NlsMbAnsiCodePageTables = dword_9821DC;
  NlsAnsiToUnicodeData = dword_9821D0;
  NlsUnicodeToAnsiData = dword_9821D4;
  NlsUnicodeToMbAnsiData = dword_9821D4;
  v3 = (unsigned __int16)word_982194;
  v4 = dword_9821B0;
  NlsMbCodePageTag = word_9821C0 != 0;
  NlsAnsiCodePage = word_9821B4;
  if ( word_982194 )
    result = (_BYTE *)memmove((int)NlsOemLeadByteInfoTable, dword_9821B0, 0x200u);
  else
    result = memset(NlsOemLeadByteInfoTable, 0, sizeof(NlsOemLeadByteInfoTable));
  NlsMbOemCodePageTables = v4;
  NlsOemToUnicodeData = dword_9821A4;
  NlsUnicodeToOemData = dword_9821A8;
  NlsUnicodeToMbOemData = dword_9821A8;
  NlsMbOemCodePageTag = v3 != 0;
  NlsOemCodePage = InitTableInfo;
  OemDefaultChar = word_98218C;
  OemTransUniDefaultChar = word_982190;
  Nls844UnicodeUpcaseTable = dword_9821E0;
  Nls844UnicodeLowercaseTable = dword_9821E4;
  UnicodeDefaultChar = word_9821BA;
  return result;
}
