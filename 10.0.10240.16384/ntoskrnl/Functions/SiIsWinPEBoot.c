// SiIsWinPEBoot 
 
int __fastcall SiIsWinPEBoot(int a1)
{
  int v1; // r4
  char *v3; // [sp+8h] [bp-10h]

  v1 = 0;
  if ( SiGetRegistryValue(a1, L"SystemStartOptions") >= 0 )
  {
    if ( wcsstr(v3, (char *)L"MININT") )
      v1 = 1;
    ExFreePoolWithTag((unsigned int)v3);
  }
  return v1;
}
