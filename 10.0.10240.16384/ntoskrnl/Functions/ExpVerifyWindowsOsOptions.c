// ExpVerifyWindowsOsOptions 
 
int __fastcall ExpVerifyWindowsOsOptions(_DWORD *a1, unsigned int a2)
{
  int v4; // r0
  unsigned int v5; // r3
  unsigned int v6; // r3
  unsigned int v7; // r3
  int result; // r0

  v4 = ExpSafeWcslen(a1 + 5, (char *)a1 + a2);
  v5 = a1[3];
  if ( v5 < 0x14
    || v5 > a2
    || (v6 = a1[2]) == 0
    || v6 > 1
    || (v7 = a1[4], (v7 & 3) != 0)
    || v7 >= a2
    || v4 == -1
    || (char *)a1 + 2 * v4 + 22 > (char *)a1 + v7 )
  {
    result = -1073741811;
  }
  else
  {
    result = ExpVerifyFilePath((char *)a1 + v7);
  }
  return result;
}
