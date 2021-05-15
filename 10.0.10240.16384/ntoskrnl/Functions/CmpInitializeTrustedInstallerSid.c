// CmpInitializeTrustedInstallerSid 
 
int __fastcall CmpInitializeTrustedInstallerSid(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int result; // r0
  _DWORD *v6; // r4
  char v7[6]; // [sp+0h] [bp-10h] BYREF
  __int16 v8; // [sp+6h] [bp-Ah]
  int v9; // [sp+8h] [bp-8h]

  v8 = HIWORD(a3);
  v9 = a4;
  v7[0] = 0;
  v7[1] = 0;
  v7[2] = 0;
  v7[3] = 0;
  v7[4] = 0;
  v7[5] = 5;
  v4 = RtlLengthRequiredSid(6u);
  result = ExAllocatePoolWithTag(1, v4, 1699966275);
  v6 = (_DWORD *)result;
  CmpTrustedInstallerSid = result;
  if ( result )
  {
    result = RtlInitializeSid(result, (int)v7, 6u);
    v6[2] = 80;
    v6[3] = 956008885;
    v6[4] = -876444647;
    v6[5] = 1831038044;
    v6[6] = 1853292631;
    v6[7] = -2023488832;
  }
  return result;
}
