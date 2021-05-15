// SmKmStoreFileWriteHeader 
 
int __fastcall SmKmStoreFileWriteHeader(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r8
  int v6; // r0
  int v7; // r6
  int v8; // r4
  int v9; // r0
  char *v10; // r0
  int v12; // [sp+20h] [bp-58h]
  int v13; // [sp+24h] [bp-54h]
  char v14[16]; // [sp+30h] [bp-48h] BYREF

  v4 = 0;
  v5 = IoSetThreadHardErrorMode(0);
  v6 = SmAlloc(0x10000, 1749446003);
  v7 = v6;
  if ( !v6 )
  {
    v8 = -1073741670;
    goto LABEL_21;
  }
  if ( !a2 )
  {
    v9 = MmCreateMdl(0, v6, 0x10000u);
    v4 = v9;
    if ( !v9 )
    {
      v8 = -1073741670;
      goto LABEL_19;
    }
    MmBuildMdlForNonPagedPool(v9);
    MmMdlPageContentsState(v4, 1);
  }
  memset((_BYTE *)v7, 0, 0x10000);
  *(_DWORD *)v7 = 1164135783;
  *(_DWORD *)(v7 + 4) = 3;
  *(_DWORD *)(v7 + 40) = 1;
  *(_DWORD *)(v7 + 8) = RtlComputeCrc32(0, v7, 0x30u);
  if ( a2 )
  {
    v8 = ZwWriteFile();
    v10 = (char *)(*(_DWORD *)(a1 + 4) + 92);
  }
  else
  {
    v8 = ZwQueryInformationFile();
    if ( v8 == 259 )
    {
      KeWaitForSingleObject(*(_DWORD *)(a1 + 4) + 92, 0, 0, 0, 0);
      v8 = v12;
    }
    if ( v8 < 0 )
      goto LABEL_19;
    KeInitializeEvent((int)v14, 0, 0);
    v8 = IoSynchronousPageWrite();
    v10 = v14;
  }
  if ( v8 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v10, 0, 0, 0, 0);
    v8 = v12;
  }
  if ( v8 >= 0 )
  {
    if ( v13 == 0x10000 )
      v8 = 0;
    else
      v8 = -1073741462;
  }
LABEL_19:
  ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v7);
  if ( v4 )
    ExFreePoolWithTag(v4);
LABEL_21:
  IoSetThreadHardErrorMode(v5);
  return v8;
}
