// BgpRasGetGlyphAdvanceWidth 
 
int __fastcall BgpRasGetGlyphAdvanceWidth(int a1, unsigned int a2, int *a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // r4
  int result; // r0
  int v7; // [sp+0h] [bp-18h]
  _DWORD v8[4]; // [sp+8h] [bp-10h] BYREF

  v5 = a5;
  if ( !a5 )
  {
    v5 = v8;
    v8[0] = 0;
    v8[1] = 0;
    v8[2] = 0;
  }
  result = RaspGetXExtent(a2, a1, a3, a2, v7, (int)v5);
  v5[2] = 0;
  return result;
}
