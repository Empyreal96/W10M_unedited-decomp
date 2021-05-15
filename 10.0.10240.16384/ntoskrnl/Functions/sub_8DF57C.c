// sub_8DF57C 
 
void sub_8DF57C()
{
  int v0; // r4
  int v1; // r6
  int v2; // r2
  char *v3; // r3

  DbgPrintEx(101, 0, (int)"BGFX Secondary Logo Bitmap Display Time (ms): %d\n", v1);
  BgpGxDrawBitmapImage(*(_DWORD *)(v0 + 156), v0 + 168, v2, v3);
  JUMPOUT(0x8DDB76);
}
