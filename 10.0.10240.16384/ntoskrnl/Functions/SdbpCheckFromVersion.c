// SdbpCheckFromVersion 
 
BOOL __fastcall SdbpCheckFromVersion(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  BOOL result; // r0
  int v6; // r6
  unsigned int v7; // r7
  unsigned int v8; // r4

  result = 1;
  v6 = 48;
  while ( 1 )
  {
    v7 = (unsigned __int16)((a2 >> (v6 - 32)) | (a1 >> v6) | (a2 << (32 - v6)));
    v8 = (unsigned __int16)((a4 >> (v6 - 32)) | (a3 >> v6) | ((_WORD)a4 << (32 - v6)));
    if ( v7 != v8 && v7 != 0xFFFF )
      break;
    v6 -= 16;
    if ( v6 < 0 )
      return result;
  }
  return v7 < v8;
}
