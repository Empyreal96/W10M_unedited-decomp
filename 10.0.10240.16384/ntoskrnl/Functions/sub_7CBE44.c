// sub_7CBE44 
 
void __fastcall sub_7CBE44(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10)
{
  int **v10; // r5
  int *v11; // r0

  v11 = *v10;
  a10 = 0;
  PnpCtxRegEnumKeyWithCallback(v11, a7, (int)PiCreateDriverSwDeviceCallback, (int)&a9);
  JUMPOUT(0x76F4E0);
}
