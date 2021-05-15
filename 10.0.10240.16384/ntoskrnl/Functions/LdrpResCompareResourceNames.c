// LdrpResCompareResourceNames 
 
int __fastcall LdrpResCompareResourceNames(int a1, int a2, int a3, int a4, int a5, int *a6, __int16 a7, _DWORD *a8)
{
  int v8; // r4
  int v10; // r2

  if ( !a5 || !a6 )
    return -1073741811;
  v8 = 0;
  if ( (a4 & 0xFFFF0000) != 0 )
    return sub_7E7830();
  v10 = *a6;
  if ( *a6 < 0 )
  {
    if ( (a7 & 0x1000) == 0 || (v10 & 0xFFFF0000) != 0 )
      JUMPOUT(0x7E7884);
    return -1073741701;
  }
  if ( (a7 & 0x1000) != 0 && (v10 & 0xFFFF0000) != 0 )
    return -1073741701;
  *a8 = a4 - v10;
  return v8;
}
