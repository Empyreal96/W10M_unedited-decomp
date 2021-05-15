// sub_815730 
 
void __fastcall sub_815730(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8)
{
  int v8; // r5
  _DWORD *v9; // r6
  unsigned int *v10; // r7

  if ( a8 >= 4 && SiGetDeviceNumberInformation(v8, &a8, &a7) >= 0 )
  {
    *v10 = a8;
    *v9 = a7;
  }
  JUMPOUT(0x7AADD2);
}
