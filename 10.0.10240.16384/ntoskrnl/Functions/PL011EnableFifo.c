// PL011EnableFifo 
 
int __fastcall PL011EnableFifo(int result, int a2)
{
  char v2; // r3
  char v3; // r3

  __dsb(0xFu);
  v2 = *(_BYTE *)(result + 44);
  if ( a2 )
    v3 = v2 | 0x10;
  else
    v3 = v2 & 0xEF;
  __dsb(0xFu);
  *(_BYTE *)(result + 44) = v3;
  return result;
}
