// AdtpBuildMessageString 
 
int __fastcall AdtpBuildMessageString(int a1, int a2, unsigned __int16 **a3, int a4, unsigned int *a5, _BYTE *a6)
{
  unsigned int v8; // r1
  unsigned __int16 *v9; // r5
  _BYTE *v10; // r4
  unsigned int v11; // r0

  if ( !a3 )
    goto LABEL_11;
  v8 = *a5 + 13;
  if ( v8 >= 0x400 )
  {
    v9 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 26, 1799447891);
    if ( !v9 )
      return -1073741801;
    v10 = a6;
    *a6 = 1;
  }
  else
  {
    v9 = (unsigned __int16 *)(a4 + 2 * *a5);
    v10 = a6;
    *a5 = v8;
    *a6 = 0;
  }
  if ( StringCchPrintfW(v9, 0xDu, (int)L"%%%%%u", a1) >= 0 )
  {
    v11 = wcslen(v9);
    a3[1] = 0;
    a3[2] = (unsigned __int16 *)(2 * (v11 + 1));
    *a3 = v9;
    a3[3] = 0;
    return 0;
  }
  if ( *v10 != 1 )
LABEL_11:
    JUMPOUT(0x815E28);
  return sub_815E1C();
}
