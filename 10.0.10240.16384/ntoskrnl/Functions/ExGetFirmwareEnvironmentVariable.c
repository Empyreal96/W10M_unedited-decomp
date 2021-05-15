// ExGetFirmwareEnvironmentVariable 
 
int __fastcall ExGetFirmwareEnvironmentVariable(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r4

  if ( dword_61A1F0 != 2 )
    return -1073741822;
  v8 = ExpUnicodeStringToNonpagedWStr();
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  v10 = ExpGetFirmwareEnvironmentVariable(v8, a2, a3, a4, a5, 0);
  ExFreePoolWithTag(v9);
  return v10;
}
