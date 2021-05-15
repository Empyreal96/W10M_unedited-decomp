// AdtpBuildUlongString 
 
int __fastcall AdtpBuildUlongString(int a1, int a2, unsigned __int16 **a3, int a4, unsigned int *a5, _BYTE *a6)
{
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned __int16 *v12; // r6
  unsigned int v13; // r0

  if ( !a3 && !a2 )
    return -1073741811;
  if ( a4 && a5 && (v10 = *a5, v11 = *a5 + 11, v11 < 0x400) )
  {
    *a5 = v11;
    v12 = (unsigned __int16 *)(a4 + 2 * v10);
    *a6 = 0;
  }
  else
  {
    v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 22, 1799447891);
    if ( !v12 )
      return -1073741801;
    *a6 = 1;
  }
  ultow(a1, (int)v12, 10);
  v13 = wcslen(v12);
  if ( a3 )
  {
    a3[1] = 0;
    a3[2] = (unsigned __int16 *)(2 * (v13 + 1));
    *a3 = v12;
    a3[3] = 0;
  }
  else
  {
    *(_WORD *)a2 = 2 * v13;
    *(_WORD *)(a2 + 2) = 22;
    *(_DWORD *)(a2 + 4) = v12;
  }
  return 0;
}
