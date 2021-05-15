// sub_53F868 
 
void __fastcall sub_53F868(int a1, int a2, int a3, int a4, int a5, int a6, int *a7, int a8, int a9, int a10, int a11, int a12)
{
  _DWORD *v12; // r7
  int v13; // r2
  int v14; // r3
  int v15; // r4

  a7 = &a9;
  v13 = v12[10];
  v14 = v12[11];
  v15 = v12[12];
  a9 = v12[9];
  a10 = v13;
  a11 = v14;
  a12 = v15;
  EtwActivityIdControlKernel(2, &a7);
  JUMPOUT(0x4A890E);
}
