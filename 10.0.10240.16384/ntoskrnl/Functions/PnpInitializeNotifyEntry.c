// PnpInitializeNotifyEntry 
 
int __fastcall PnpInitializeNotifyEntry(int a1, int a2, unsigned int a3, int a4, int a5, int a6)
{
  int v9; // r4
  int v10; // r0
  int v12; // r7
  char v14[8]; // [sp+20h] [bp-228h] BYREF
  unsigned __int16 v15[272]; // [sp+28h] [bp-220h] BYREF

  v9 = 0;
  if ( MmIsSessionAddress(a3) )
  {
    v12 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    if ( v12 != -1 )
    {
      swprintf_s((int)v15, 256, (int)L"\\KernelObjects\\Session%d", v12);
      RtlInitUnicodeString((unsigned int)v14, v15);
      ZwOpenSession();
    }
    v9 = -1073741811;
  }
  else
  {
    *(_DWORD *)a1 = a1;
    *(_DWORD *)(a1 + 4) = a1;
    *(_DWORD *)(a1 + 8) = a2;
    *(_DWORD *)(a1 + 12) = 0;
    *(_DWORD *)(a1 + 24) = a4;
    *(_DWORD *)(a1 + 28) = a5;
    *(_WORD *)(a1 + 32) = 1;
    *(_BYTE *)(a1 + 34) = 0;
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = a3;
    *(_DWORD *)(a1 + 36) = a6;
    v10 = ExAllocatePoolWithTag(512, 56, 1450208848);
    *(_DWORD *)(a1 + 40) = v10;
    if ( v10 )
      ExInitializeResourceLite(v10);
    else
      v9 = -1073741670;
  }
  return v9;
}
