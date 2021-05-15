// MxMemoryLicense 
 
int MxMemoryLicense()
{
  int result; // r0
  int v1; // [sp+8h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-1Ch] BYREF
  int v3; // [sp+10h] [bp-18h] BYREF
  __int16 v4[2]; // [sp+18h] [bp-10h] BYREF
  const __int16 *v5; // [sp+1Ch] [bp-Ch]

  v4[0] = 60;
  v4[1] = 62;
  v5 = L"Kernel-WindowsMaxMemAllowedArm";
  v3 = 0;
  v1 = 0;
  v2 = 4;
  if ( NtQueryLicenseValue((int)v4, (unsigned int)&v3, (int)&v1, 4, (unsigned int)&v2) >= 0 && v1 )
    result = v1 << 8;
  else
    result = 0x80000;
  return result;
}
