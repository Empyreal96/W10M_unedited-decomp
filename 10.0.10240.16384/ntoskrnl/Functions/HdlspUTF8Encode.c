// HdlspUTF8Encode 
 
unsigned int __fastcall HdlspUTF8Encode(unsigned int result, _BYTE *a2)
{
  if ( (result & 0xFF80) != 0 )
  {
    a2[2] = result & 0x3F | 0x80;
    if ( (result & 0xF800) != 0 )
    {
      a2[1] = (result >> 6) & 0x3F | 0x80;
      *a2 = ((unsigned __int16)result >> 12) | 0xE0;
    }
    else
    {
      a2[1] = (result >> 6) & 0x1F | 0xC0;
    }
  }
  else
  {
    a2[2] = result;
  }
  return result;
}
