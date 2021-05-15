// VhdiGetVolumeNumber 
 
int __fastcall VhdiGetVolumeNumber(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r4
  char v7[8]; // [sp+40h] [bp-98h] BYREF
  int v8; // [sp+48h] [bp-90h]
  unsigned __int16 v9[60]; // [sp+60h] [bp-78h] BYREF

  if ( !a1 || !a4 )
    return -1073741811;
  v5 = RtlStringCbPrintfW(v9, 0x64u, (int)L"\\Device\\Harddisk%d\\Partition%d", a2);
  if ( v5 >= 0 )
  {
    v5 = RtlInitUnicodeStringEx((int)v7, v9);
    if ( v5 >= 0 )
    {
      v5 = ZwOpenFile();
      if ( v5 >= 0 )
      {
        v5 = ZwDeviceIoControlFile();
        if ( v5 >= 0 )
          *a4 = v8;
      }
    }
  }
  return v5;
}
