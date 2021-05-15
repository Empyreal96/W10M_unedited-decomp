// IopTranslatorHandlerCm 
 
int __fastcall IopTranslatorHandlerCm(int a1, _DWORD *a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r2
  int v8; // r3
  int v9; // r4

  v7 = a2[1];
  v8 = a2[2];
  v9 = a2[3];
  *a7 = *a2;
  a7[1] = v7;
  a7[2] = v8;
  a7[3] = v9;
  return 0;
}
