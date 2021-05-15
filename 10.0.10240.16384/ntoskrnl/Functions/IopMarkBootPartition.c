// IopMarkBootPartition 
 
int __fastcall IopMarkBootPartition(int a1, int a2, unsigned __int16 *a3)
{
  int v5; // r4
  int v6; // r3
  int v8; // r4
  int v9; // r0
  int v10; // r6
  int v11; // r0
  int v12; // r3
  int v13; // [sp+8h] [bp-160h]
  int v14[2]; // [sp+10h] [bp-158h] BYREF
  _DWORD v15[8]; // [sp+18h] [bp-150h] BYREF
  char v16[16]; // [sp+40h] [bp-128h] BYREF
  char v17[280]; // [sp+50h] [bp-118h] BYREF

  RtlInitUnicodeString((unsigned int)v15, 0);
  strcpy(v16, "\\ArcName\\%s");
  v5 = RtlStringCchPrintfA(v17, 0x100u, (int)v16, *(_DWORD *)(a1 + 104));
  if ( v5 < 0 )
    return v5;
  RtlInitAnsiString((unsigned int)v14, (unsigned int)v17);
  v5 = RtlAnsiStringToUnicodeString(a3, (unsigned __int16 *)v14, 1, v6);
  if ( v5 < 0 )
    return v5;
  v15[2] = 24;
  v15[3] = 0;
  v15[4] = a3;
  v15[5] = 576;
  v15[6] = 0;
  v15[7] = 0;
  v5 = ZwOpenFile();
  if ( v5 < 0 )
    return v5;
  v5 = ObReferenceObjectByHandle(v13, 0, (int)IoFileObjectType, 0, (int)v14, 0);
  if ( v5 < 0 )
    return v5;
  v8 = v14[0];
  v9 = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(v14[0] + 4));
  v10 = v9;
  *(_DWORD *)(*(_DWORD *)(v8 + 4) + 28) |= 0x100u;
  *(_DWORD *)(v9 + 28) |= 0x100u;
  if ( !InitIsWinPEMode )
  {
    PnpHardwareConfigCreateBootDriverFlags(v9, v13);
    ObfReferenceObjectWithTag(*(_DWORD *)(v8 + 4));
    IopErrorLogObject = *(_DWORD *)(v8 + 4);
    ObCloseHandle(v13);
    ObfDereferenceObjectWithTag(v8);
    v11 = ObfDereferenceObjectWithTag(v10);
    IopAssignBootDriveLetter(v11);
    RtlInitAnsiString((unsigned int)v14, *(_DWORD *)(a1 + 116));
    v5 = RtlAnsiStringToUnicodeString((unsigned __int16 *)v15, (unsigned __int16 *)v14, 1, v12);
    if ( v5 >= 0 )
    {
      IopStoreSystemPartitionInformation();
      RtlFreeAnsiString(v15);
    }
    return v5;
  }
  return sub_968598();
}
