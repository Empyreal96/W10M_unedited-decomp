// RtlUpcaseUnicodeChar 
 
unsigned int __fastcall RtlUpcaseUnicodeChar(unsigned int result)
{
  if ( result >= 0x61 )
  {
    if ( result <= 0x7A )
      result = (unsigned __int16)(result - 32);
    else
      result = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                           + 2
                                           * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                  + 2
                                                                  * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                         + 2 * (result >> 8))
                                                                   + ((unsigned __int8)result >> 4)))
                                            + (result & 0xF)))
                                + result);
  }
  return result;
}
