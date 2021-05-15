// _CmGetDeviceParent 
 
int __fastcall CmGetDeviceParent(int a1, unsigned __int16 *a2, _WORD *a3, unsigned int *a4)
{
  unsigned int v5; // r4
  int result; // r0
  unsigned int v10; // r3
  unsigned int v11; // [sp+20h] [bp-1C0h] BYREF
  int v12; // [sp+24h] [bp-1BCh] BYREF
  char v13[8]; // [sp+28h] [bp-1B8h] BYREF
  char v14[432]; // [sp+30h] [bp-1B0h] BYREF

  v5 = *a4;
  v12 = 0;
  *a4 = 0;
  if ( CmIsRootDevice(a2) )
    return -1073741810;
  result = RtlInitUnicodeStringEx((int)v13, a2);
  if ( result >= 0 )
  {
    result = NtPlugPlayGetDeviceRelatedDevice(a1, v13, 1, v14);
    if ( result == -1073741810 )
    {
      result = PnpGetObjectProperty(
                 a1,
                 (int)a2,
                 1,
                 0,
                 0,
                 (int)DEVPKEY_Device_LastKnownParent,
                 (int)&v12,
                 (int)v14,
                 400,
                 (int)&v11,
                 0);
      v10 = v11;
      if ( result < 0 )
      {
        result = -1073741810;
      }
      else
      {
        v10 = v11 >> 1;
        v11 >>= 1;
      }
      if ( result == -1073741810 )
        return sub_7C8868();
    }
    else
    {
      v10 = v11;
    }
    if ( result >= 0 )
    {
      *a4 = v10;
      if ( v5 < v10 )
        result = -1073741789;
      else
        result = RtlStringCchCopyExW(a3, v5, v14, 0, 0, 2304);
    }
  }
  return result;
}
