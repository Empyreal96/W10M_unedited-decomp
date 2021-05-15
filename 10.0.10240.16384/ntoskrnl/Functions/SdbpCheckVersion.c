// SdbpCheckVersion 
 
int __fastcall SdbpCheckVersion(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r6
  int v5; // r7

  v4 = 48;
  while ( 1 )
  {
    v5 = (unsigned __int16)((a2 >> (v4 - 32)) | (a1 >> v4) | (a2 << (32 - v4)));
    if ( v5 != (unsigned __int16)((a4 >> (v4 - 32)) | (a3 >> v4) | ((_WORD)a4 << (32 - v4))) && v5 != 0xFFFF )
      break;
    v4 -= 16;
    if ( v4 < 0 )
      return 1;
  }
  return 0;
}
