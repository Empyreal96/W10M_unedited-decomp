// BiIsWinPEBoot 
 
int BiIsWinPEBoot()
{
  int v0; // r4
  char *v2; // [sp+8h] [bp-10h] BYREF
  char v3[12]; // [sp+Ch] [bp-Ch] BYREF

  v0 = 0;
  if ( BiGetRegistryValue(
         0,
         L"SystemStartOptions",
         L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control",
         1,
         &v2,
         v3) >= 0 )
  {
    if ( wcsstr(v2, (char *)L"MININT") )
      v0 = 1;
    ExFreePoolWithTag((unsigned int)v2);
  }
  return v0;
}
