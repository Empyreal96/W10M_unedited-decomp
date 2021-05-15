// SepCleanupLUIDDeviceMapDirectory 
 
int __fastcall SepCleanupLUIDDeviceMapDirectory(_DWORD *a1, int a2)
{
  int v3; // r5
  unsigned int v4; // r6
  int v7; // r9
  _DWORD *v8; // r0
  int v9; // r8
  int v10; // r4
  int v11; // r7
  _DWORD *v12; // r10
  int v13; // r8
  int v14; // r0
  unsigned int v15; // r8
  int v16; // r4
  int v17; // [sp+14h] [bp-F4h]
  int v18; // [sp+18h] [bp-F0h]
  int v19; // [sp+1Ch] [bp-ECh]
  unsigned int v20; // [sp+20h] [bp-E8h]
  int v21; // [sp+24h] [bp-E4h]
  char v22[8]; // [sp+48h] [bp-C0h] BYREF
  char v23[24]; // [sp+50h] [bp-B8h] BYREF
  unsigned __int16 v24[80]; // [sp+68h] [bp-A0h] BYREF

  v20 = 100;
  v3 = 0;
  v4 = 0;
  if ( !a1 )
    return sub_80A4F0();
  v7 = ObReferenceObjectSafeWithTag(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( v7 )
    ObfDereferenceObjectWithTag(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  else
    KiStackAttachProcess(PsInitialSystemProcess, 0, (int)v23);
  v8 = PsGetServerSiloGlobals(a2);
  swprintf_s((int)v24, 64, (int)L"\\Sessions\\%d\\DosDevices\\%08x-%08x", *v8, a1[1], *a1);
  RtlInitUnicodeString((unsigned int)v22, v24);
  v9 = PsAttachSiloToCurrentThread(a2);
  v21 = v9;
  v10 = ZwOpenDirectoryObject();
  if ( v10 < 0 )
  {
    v14 = v9;
    goto LABEL_20;
  }
  v11 = ExAllocatePoolWithTag(1, 400, 1632134483);
  if ( !v11 )
  {
LABEL_41:
    ZwClose();
    if ( v3 )
      ExFreePoolWithTag(v3);
    PsDetachSiloFromCurrentThread(v9);
    if ( !v7 )
      KiUnstackDetachProcess((unsigned int)v23, 0);
    return -1073741801;
  }
LABEL_7:
  v12 = (_DWORD *)v11;
  while ( 1 )
  {
    do
    {
      v10 = ZwQueryDirectoryObject();
      if ( v10 != -1073741789 )
        goto LABEL_9;
      if ( v3 )
        ExFreePoolWithTag(v3);
      v3 = ExAllocatePoolWithTag(1, v18, 1648649555);
    }
    while ( v3 );
    v10 = -1073741670;
LABEL_9:
    if ( v10 < 0 )
      break;
    if ( !wcscmp(*(char **)(v3 + 12), (char *)L"SymbolicLink") )
    {
      v15 = v20;
      if ( v4 >= v20 )
      {
        if ( v4 )
        {
          v16 = v11;
          do
          {
            v16 += 4;
            ZwClose();
            --v4;
          }
          while ( v4 );
        }
        v20 += 20;
        v4 = 0;
        ExFreePoolWithTag(v11);
        v11 = ExAllocatePoolWithTag(1, 4 * (v15 + 20), 1632134483);
        if ( !v11 )
        {
          v9 = v21;
          goto LABEL_41;
        }
        goto LABEL_7;
      }
      if ( ZwOpenSymbolicLinkObject() >= 0 )
      {
        if ( ZwMakeTemporaryObject() < 0 )
        {
          ZwClose();
        }
        else
        {
          ++v4;
          *v12++ = v19;
        }
      }
    }
  }
  if ( v10 == -2147483622 )
    v10 = 0;
  if ( v4 )
  {
    v13 = v11;
    do
    {
      v13 += 4;
      ZwClose();
      --v4;
    }
    while ( v4 );
  }
  ExFreePoolWithTag(v11);
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( v17 )
    ZwClose();
  v14 = v21;
LABEL_20:
  PsDetachSiloFromCurrentThread(v14);
  if ( !v7 )
    KiUnstackDetachProcess((unsigned int)v23, 0);
  return v10;
}
