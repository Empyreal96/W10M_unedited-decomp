// VhdiVerifyBootDisk 
 
int __fastcall VhdiVerifyBootDisk(int a1)
{
  int v2; // r4
  int v3; // r8
  int v4; // r7
  int v5; // r0
  int v6; // r0
  int v8; // [sp+18h] [bp-30h]
  char v9[40]; // [sp+20h] [bp-28h] BYREF

  v2 = 0;
  if ( a1 )
  {
    if ( NtVhdBootFile )
    {
      v3 = 2 * (wcslen((unsigned __int16 *)NtVhdBootFile) + 1);
      v4 = ExAllocatePoolWithTag(512, v3, 1113876566);
      if ( v4 )
      {
        KeInitializeEvent((int)v9, 1, 0);
        v5 = IoBuildDeviceIoControlRequest(2971944, a1, 0, 0, v4, v3);
        if ( v5 )
        {
          v6 = IofCallDriver(a1, v5);
          if ( v6 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v9, 0, 0, 0, 0);
            v6 = v8;
          }
          if ( v6 >= 0 && !wcsicmp(v4, (unsigned __int16 *)(NtVhdBootFile + 2)) )
            v2 = 1;
        }
        ExFreePoolWithTag(v4);
      }
    }
  }
  return v2;
}
