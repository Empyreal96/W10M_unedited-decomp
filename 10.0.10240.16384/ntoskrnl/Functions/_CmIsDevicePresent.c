// _CmIsDevicePresent 
 
int __fastcall CmIsDevicePresent(int a1, unsigned __int16 *a2, _BYTE *a3)
{
  int result; // r0
  char v6[4]; // [sp+Ch] [bp-24h] BYREF
  char v7[8]; // [sp+10h] [bp-20h] BYREF
  char v8[24]; // [sp+18h] [bp-18h] BYREF

  if ( !a3 )
    return -1073741811;
  result = RtlInitUnicodeStringEx((int)v8, a2);
  if ( result < 0 || (result = NtPlugPlayGetDeviceStatus(a1, (int)v8, (int)v7, (int)v6), result < 0) )
  {
    if ( result == -1073741810 )
    {
      result = 0;
      *a3 = 0;
    }
  }
  else
  {
    *a3 = 1;
  }
  return result;
}
