// PspSetupUserProcessAddressSpace 
 
int __fastcall PspSetupUserProcessAddressSpace(int a1, int a2, unsigned int a3, int a4)
{
  int v5; // lr
  int v7; // r6
  int v8; // r3
  int v9; // r8
  int v11; // r4
  int v12; // r7
  int v13; // r0
  int v14; // r2
  char *v15; // [sp+Ch] [bp-44h]
  int v17; // [sp+18h] [bp-38h]
  char v19[48]; // [sp+20h] [bp-30h] BYREF

  v5 = a3;
  v17 = __mrc(15, 0, 13, 0, 3);
  v7 = *(_DWORD *)(a4 + 120);
  v8 = (*(unsigned __int8 *)(a4 + 9) >> 1) & 3;
  v15 = 0;
  if ( v8 == 1 )
  {
    if ( *(_DWORD *)(a4 + 44) == *(_DWORD *)(a4 + 168) )
    {
      v15 = v19;
      v11 = PspGetStandardHandleList(a1, (int)v19);
      if ( v11 < 0 )
        return v11;
      v5 = a3;
    }
  }
  else if ( v8 == 2 )
  {
    v15 = (char *)(v7 + 24);
  }
  v9 = *(_DWORD *)(v7 + 8) & 0x60;
  if ( (PspGlobalFlags & 1) != 0 )
    return sub_7F5814();
  if ( !*(_DWORD *)(v7 + 672) )
    *(_DWORD *)(v7 + 672) = PsDefaultLoaderThreads;
  if ( (PspGlobalFlags & 4) != 0 )
    *(_DWORD *)(v7 + 8) |= 0x20000000u;
  KiStackAttachProcess(a2, 0, v5);
  if ( (*(_BYTE *)(a4 + 8) & 0x10) == 0 || (v11 = PspLocateInPEManifest(a2, a4), v11 >= 0) )
  {
    if ( !v9 || (v11 = ZwAllocateVirtualMemory(), v11 >= 0) )
    {
      v12 = 0;
      if ( *(_DWORD *)(a4 + 152) )
      {
        while ( 1 )
        {
          v11 = ZwAllocateVirtualMemory();
          if ( v11 < 0 )
            break;
          if ( (unsigned int)++v12 >= *(_DWORD *)(a4 + 152) )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        *(_DWORD *)(a4 + 124) = 0;
        v11 = ZwAllocateVirtualMemory();
        if ( v11 >= 0 )
        {
          v13 = PspCopyAndFixupParameters(a1, v15, a4);
          v11 = v13;
          if ( v13 >= 0 )
          {
            __mrc(15, 0, 13, 0, 3);
            v11 = PspPrepareSystemDllInitBlock(v13, a4, v14);
            if ( v11 >= 0 )
            {
              PspWritePebAffinityInfo(v17 & 0xFFFFFFC0, a2);
              v11 = MmMapApiSetView(a2);
            }
          }
        }
      }
    }
  }
  KiUnstackDetachProcess(a3, 0);
  return v11;
}
