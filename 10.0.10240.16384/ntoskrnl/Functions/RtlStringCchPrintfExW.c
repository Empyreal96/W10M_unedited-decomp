// RtlStringCchPrintfExW 
 
int __fastcall RtlStringCchPrintfExW(int a1, int a2, _DWORD *a3, _DWORD *a4, int a5, _WORD *a6)
{
  int v6; // r5

  v6 = 0;
  if ( (a5 & 0x100) != 0 )
    return sub_518740();
  if ( !a2 )
    v6 = -1073741811;
  if ( v6 < 0 )
    return v6;
  v6 = 0;
  if ( (a5 & 0xFFFFE000) != 0 )
  {
    v6 = -1073741811;
  }
  else
  {
    if ( !*a6 )
      goto LABEL_8;
    if ( a1 )
      v6 = -2147483643;
    else
      v6 = -1073741811;
  }
  if ( v6 != -2147483643 )
    return v6;
LABEL_8:
  if ( a3 )
    *a3 = a1;
  if ( !a4 )
    return v6;
  *a4 = a2;
  return v6;
}
