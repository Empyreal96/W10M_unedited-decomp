// IopConnectLinkTrackingPort 
 
int __fastcall IopConnectLinkTrackingPort(int a1)
{
  int v1; // r4
  int v4; // [sp+10h] [bp-38h] BYREF
  int v5; // [sp+14h] [bp-34h] BYREF
  int v6; // [sp+18h] [bp-30h] BYREF
  char v7[8]; // [sp+20h] [bp-28h] BYREF
  int v8[2]; // [sp+28h] [bp-20h] BYREF
  char v9; // [sp+30h] [bp-18h]
  char v10; // [sp+31h] [bp-17h]

  v1 = 0;
  if ( !IopLinkTrackingServiceObject )
  {
    if ( *((_DWORD *)IopLinkTrackingServiceEvent + 1) )
    {
      v8[1] = 2;
      v9 = 1;
      v10 = 1;
      RtlInitUnicodeString((unsigned int)v7, L"\\Security\\TRKWKS_PORT");
      v1 = NtConnectPort(&v4, (int)v7, v8, 0, 0, &v6, 0, 0);
      if ( v1 >= 0 )
      {
        if ( (unsigned int)(v6 - 128) > 0x80 )
        {
          NtClose();
          v1 = -1073741811;
        }
        else
        {
          v1 = ObReferenceObjectByHandle(v4, 0, LpcPortObjectType, 0, (int)&v5, 0);
          IopLinkTrackingServiceObject = v5;
          NtClose();
        }
      }
    }
    else
    {
      v1 = -1073741772;
    }
  }
  *(_DWORD *)(a1 + 32) = v1;
  return KeSetEvent(a1 + 16, 0, 0);
}
