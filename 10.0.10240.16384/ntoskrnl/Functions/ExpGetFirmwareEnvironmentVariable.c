// ExpGetFirmwareEnvironmentVariable 
 
int __fastcall ExpGetFirmwareEnvironmentVariable(int a1, int a2, int a3, _DWORD *a4, int a5, char a6)
{
  int result; // r0
  char v7[4]; // [sp+8h] [bp-28h] BYREF
  char v8[36]; // [sp+Ch] [bp-24h] BYREF

  if ( !*a4 )
    JUMPOUT(0x7D5828);
  result = ExLockUserBuffer(a3, *a4, a6, 1, v8, v7);
  if ( result >= 0 )
    result = sub_7D5824();
  return result;
}
