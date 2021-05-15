// FopReadNameRecord 
 
int __fastcall FopReadNameRecord(_DWORD *a1, int a2, unsigned __int16 *a3)
{
  int result; // r0

  result = FioFwReadBytesAtOffset(a1, a2, 0xCu, (int)a3);
  if ( result >= 0 )
  {
    result = 0;
    *a3 = __rev16(*a3);
    a3[1] = __rev16(a3[1]);
    a3[2] = __rev16(a3[2]);
    a3[3] = __rev16(a3[3]);
    a3[4] = __rev16(a3[4]);
    a3[5] = __rev16(a3[5]);
  }
  return result;
}
