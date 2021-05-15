// IopFreeBandwidthContract 
 
int __fastcall IopFreeBandwidthContract(_DWORD *a1, _DWORD *a2)
{
  int result; // r0
  BOOL v4; // r6
  int v5; // r7
  int v6; // r0
  int v7; // r4
  int v8; // r3
  char *v9; // r0
  int v10[2]; // [sp+8h] [bp-50h] BYREF
  unsigned int v11[2]; // [sp+10h] [bp-48h] BYREF
  char v12[16]; // [sp+18h] [bp-40h] BYREF
  char v13[20]; // [sp+28h] [bp-30h] BYREF

  v10[0] = 0;
  v10[1] = 0;
  if ( (_DWORD *)*a2 == a2 )
    return 0;
  v4 = (a1[11] & 2) != 0;
  while ( 1 )
  {
    KeInitializeEvent((int)v12, 1, 0);
    if ( (a1[11] & 0x4000000) == 0 )
      KeResetEvent((int)(a1 + 23));
    memset(v13, 0, sizeof(v13));
    v5 = IoGetRelatedDeviceObject(a1);
    v6 = IopAllocateIrpMustSucceed(v5, *(_BYTE *)(v5 + 48));
    v7 = v6;
    *(_DWORD *)(v6 + 100) = a1;
    *(_DWORD *)(v6 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_BYTE *)(v6 + 32) = 0;
    if ( v4 )
    {
      *(_DWORD *)(v6 + 40) = v10;
      *(_DWORD *)(v6 + 44) = 0;
    }
    else
    {
      *(_DWORD *)(v6 + 44) = v12;
      *(_DWORD *)(v6 + 40) = v10;
      *(_DWORD *)(v6 + 8) = 4;
    }
    v8 = *(_DWORD *)(v6 + 96);
    *(_DWORD *)(v6 + 48) = 0;
    *(_BYTE *)(v8 - 40) = 6;
    *(_DWORD *)(v8 - 32) = 20;
    *(_DWORD *)(v8 - 28) = 44;
    *(_DWORD *)(v8 - 12) = a1;
    *(_DWORD *)(v6 + 12) = v13;
    *(_DWORD *)(v6 + 60) = 0;
    *(_DWORD *)(v6 + 4) = 0;
    ObfReferenceObject((int)a1);
    IopQueueThreadIrp(v7);
    if ( IofCallDriver(v5, v7) == 259 )
    {
      if ( v4 )
        v9 = (char *)(a1 + 23);
      else
        v9 = v12;
      KeWaitForSingleObject((unsigned int)v9, 0, 0, 0, 0);
    }
    result = v10[0];
    if ( v10[0] != -1073741670 && v10[0] != -1073741801 )
      break;
    v11[0] = -1000000;
    v11[1] = -1;
    KeDelayExecutionThread(0, 0, v11);
  }
  return result;
}
