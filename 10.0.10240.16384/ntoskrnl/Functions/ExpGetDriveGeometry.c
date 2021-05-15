// ExpGetDriveGeometry 
 
int __fastcall ExpGetDriveGeometry(int a1, int a2)
{
  int v4; // r0
  unsigned __int16 *v5; // r5
  int v6; // r4
  char v8[8]; // [sp+28h] [bp-30h] BYREF
  int v9; // [sp+30h] [bp-28h]
  int v10; // [sp+34h] [bp-24h]
  char *v11; // [sp+38h] [bp-20h]
  int v12; // [sp+3Ch] [bp-1Ch]
  int v13; // [sp+40h] [bp-18h]
  int v14; // [sp+44h] [bp-14h]

  v4 = ExAllocatePoolWithTag(512, 76, 1920364101);
  v5 = (unsigned __int16 *)v4;
  if ( !v4 )
    return -1073741670;
  swprintf_s(v4, 38, (int)L"\\Device\\Harddisk%lu\\Partition0", a1);
  RtlInitUnicodeString((unsigned int)v8, v5);
  v9 = 24;
  v10 = 0;
  v12 = 576;
  v11 = v8;
  v13 = 0;
  v14 = 0;
  v6 = ZwOpenFile();
  if ( v6 >= 0 )
  {
    v6 = ZwDeviceIoControlFile();
    ZwClose();
    if ( v6 >= 0 && *(_DWORD *)(a2 + 20) < 0x200u )
      v6 = -1073741823;
  }
  ExFreePoolWithTag((unsigned int)v5);
  return v6;
}
