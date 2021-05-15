// PL011PutByte 
 
_DWORD *__fastcall PL011PutByte(_DWORD *result, char a2)
{
  _BYTE *v2; // r3
  _BYTE *v3; // r3

  do
  {
    v2 = (_BYTE *)*result;
    __dsb(0xFu);
  }
  while ( (*((_WORD *)v2 + 12) & 0x20) != 0 );
  v3 = (_BYTE *)*result;
  __dsb(0xFu);
  *v3 = a2;
  return result;
}
