// sub_81B62C 
 
void __fastcall sub_81B62C(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, int a9, int a10, char *a11, int a12, int a13, int a14)
{
  _DWORD *v14; // r5
  unsigned __int16 *v15; // r6

  RtlInitUnicodeString((unsigned int)&a7, v15);
  *v14 = 0;
  a9 = 24;
  a10 = a5;
  a11 = &a7;
  a13 = 0;
  a14 = 0;
  ZwOpenKey();
  JUMPOUT(0x7BA710);
}
