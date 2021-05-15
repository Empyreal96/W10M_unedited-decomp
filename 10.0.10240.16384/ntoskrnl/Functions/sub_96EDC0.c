// sub_96EDC0 
 
void __fastcall sub_96EDC0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, __int16 a10)
{
  _DWORD *v10; // r4
  _BYTE *v11; // r5
  int v12; // r0
  int v13; // r6

  v12 = ZwQuerySystemInformation();
  v13 = v12;
  if ( v12 >= 0 && (a10 & 0x10) != 0 || v12 == -2143092730 )
  {
    if ( SepIsUmciDisabled() )
      *v11 = 0;
    if ( (*v10 & 1) == 0 && (v13 < 0 || (a10 & 0x8000) == 0) )
      *v10 |= 4u;
  }
  JUMPOUT(0x96271C);
}
