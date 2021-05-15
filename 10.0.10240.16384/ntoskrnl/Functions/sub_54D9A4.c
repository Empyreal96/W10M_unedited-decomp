// sub_54D9A4 
 
void sub_54D9A4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r7
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( RaspMapGlyphIndexToLocation(v8, 0, (int *)va, a4) < 0 )
    JUMPOUT(0x4E2528);
  JUMPOUT(0x4E24F0);
}
