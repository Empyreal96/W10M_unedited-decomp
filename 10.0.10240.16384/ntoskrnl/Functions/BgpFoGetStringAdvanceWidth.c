// BgpFoGetStringAdvanceWidth 
 
int __fastcall BgpFoGetStringAdvanceWidth(int a1, unsigned __int16 *a2, _DWORD *a3, int a4)
{
  int result; // r0
  unsigned int v8; // r6
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a4;
  *a3 = 0;
  result = 0;
  v8 = 0;
  if ( (*a2 & 0xFFFE) != 0 )
  {
    do
    {
      result = BgpRasGetGlyphAdvanceWidth(
                 a1,
                 *(unsigned __int16 *)(*((_DWORD *)a2 + 1) + 2 * v8),
                 v9,
                 *((_DWORD *)a2 + 1),
                 BcpWorkspace);
      if ( result < 0 )
        break;
      *a3 += v9[0];
      v8 = (unsigned __int16)(v8 + 1);
    }
    while ( v8 < *a2 >> 1 );
  }
  return result;
}
