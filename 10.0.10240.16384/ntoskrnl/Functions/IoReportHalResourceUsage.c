// IoReportHalResourceUsage 
 
int __fastcall IoReportHalResourceUsage(int a1, int a2, _DWORD *a3, unsigned int a4)
{
  int v8; // r5
  unsigned int v9; // r4
  _DWORD *v10; // r3
  int v11; // r6
  int v13; // r0
  int v14; // [sp+8h] [bp-40h] BYREF
  int v15; // [sp+Ch] [bp-3Ch] BYREF
  int v16[2]; // [sp+10h] [bp-38h] BYREF
  char v17[8]; // [sp+18h] [bp-30h] BYREF
  char v18[40]; // [sp+20h] [bp-28h] BYREF

  v15 = 0;
  RtlInitUnicodeString((unsigned int)v18, L"Hardware Abstraction Layer");
  v8 = IopCreateRegistryKeyEx(&v14, 0, (int)&CmRegistryMachineHardwareResourceMapName, 131103, 1, 0);
  if ( v8 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v17, L".Raw");
    v8 = HeadlessTerminalAddResources(a2, a4, 0, &v15, v16);
    v9 = v15;
    if ( v8 >= 0 )
    {
      v10 = (_DWORD *)(v15 ? v15 : a2);
      v8 = IopWriteResourceList(v14, (int)v18, a1, (int)v17, v10);
      if ( v8 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v17, L".Translated");
        v8 = HeadlessTerminalAddResources((int)a3, a4, 1, v16, &v15);
        if ( v8 >= 0 )
        {
          v11 = v16[0];
          if ( v16[0] )
            a3 = (_DWORD *)v16[0];
          v8 = IopWriteResourceList(v14, (int)v18, a1, (int)v17, a3);
          if ( v11 )
            return sub_969634();
        }
      }
    }
    ZwClose();
    if ( v8 < 0 )
    {
      if ( v9 )
        ExFreePoolWithTag(v9);
    }
    else if ( v9 )
    {
      IopInitHalResources = v9;
    }
    else
    {
      v13 = ExAllocatePoolWithTag(1, a4, 538996816);
      IopInitHalResources = v13;
      if ( v13 )
        memmove(v13, a2, a4);
      else
        v8 = -1073741670;
    }
  }
  return v8;
}
