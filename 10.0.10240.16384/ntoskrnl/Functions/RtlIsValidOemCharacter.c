// RtlIsValidOemCharacter 
 
int __fastcall RtlIsValidOemCharacter(_WORD *a1)
{
  int v2; // r3
  unsigned int v3; // r5
  __int16 v4; // r2
  int v5; // r1
  unsigned int v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r0

  v2 = (unsigned __int16)*a1;
  if ( NlsMbOemCodePageTag )
  {
    v6 = *(unsigned __int16 *)(NlsUnicodeToMbOemData + 2 * v2);
    if ( NlsOemLeadByteInfoTable[v6 >> 8] )
    {
      v7 = (unsigned __int16)NlsOemLeadByteInfoTable[v6 >> 8] + (unsigned __int8)v6;
      v8 = NlsMbOemCodePageTables;
    }
    else
    {
      v8 = NlsOemToUnicodeData;
      v7 = (unsigned __int8)v6;
    }
    v9 = *(unsigned __int16 *)(v8 + 2 * v7);
    if ( v9 >= 0x61 )
    {
      if ( v9 > 0x7A )
        LOWORD(v9) = *(_WORD *)(Nls844UnicodeUpcaseTable
                              + 2
                              * ((v9 & 0xF)
                               + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                     + 2
                                                     * (((unsigned __int8)v9 >> 4)
                                                      + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable + 2 * (v9 >> 8))))))
                   + v9;
      else
        LOWORD(v9) = v9 - 32;
    }
    v4 = v9;
    v5 = *(unsigned __int16 *)(NlsUnicodeToMbOemData + 2 * (unsigned __int16)v9);
  }
  else
  {
    v3 = *(unsigned __int16 *)(NlsOemToUnicodeData + 2 * *(unsigned __int8 *)(v2 + NlsUnicodeToOemData));
    if ( v3 >= 0x61 )
    {
      if ( v3 > 0x7A )
        LOWORD(v3) = *(_WORD *)(Nls844UnicodeUpcaseTable
                              + 2
                              * ((v3 & 0xF)
                               + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                     + 2
                                                     * (((unsigned __int8)v3 >> 4)
                                                      + *(unsigned __int16 *)(Nls844UnicodeUpcaseTable + 2 * (v3 >> 8))))))
                   + v3;
      else
        LOWORD(v3) = v3 - 32;
    }
    v4 = v3;
    v5 = (unsigned __int16)*(char *)((unsigned __int16)v3 + NlsUnicodeToOemData);
  }
  if ( v5 == (unsigned __int16)OemDefaultChar )
    return 0;
  *a1 = v4;
  return 1;
}
