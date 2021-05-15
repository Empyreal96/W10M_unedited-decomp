// RtlDowncaseUnicodeChar 
 
unsigned int __fastcall RtlDowncaseUnicodeChar(unsigned int result)
{
  if ( result >= 0x41 )
  {
    if ( result > 0x5A )
      LOWORD(result) = *(_WORD *)(Nls844UnicodeLowercaseTable
                                + 2
                                * ((result & 0xF)
                                 + *(unsigned __int16 *)(Nls844UnicodeLowercaseTable
                                                       + 2
                                                       * (((unsigned __int8)result >> 4)
                                                        + *(unsigned __int16 *)(Nls844UnicodeLowercaseTable
                                                                              + 2 * (result >> 8))))))
                     + result;
    else
      LOWORD(result) = result + 32;
  }
  return (unsigned __int16)result;
}
