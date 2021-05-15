// MY_WRITE_REGISTER_UCHAR 
 
_BYTE *__fastcall MY_WRITE_REGISTER_UCHAR(_BYTE *result, char a2)
{
  __dsb(0xFu);
  *result = a2;
  return result;
}
