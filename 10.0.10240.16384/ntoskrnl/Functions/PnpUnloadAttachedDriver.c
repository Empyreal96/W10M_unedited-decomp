// PnpUnloadAttachedDriver 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpUnloadAttachedDriver(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r4 OVERLAPPED
  int v5; // r3
  int v7; // r7
  unsigned __int16 *v8; // r0
  unsigned __int16 *v9; // r5
  int v10; // [sp+8h] [bp-18h] BYREF
  unsigned int v11; // [sp+Ch] [bp-14h]

  v10 = a3;
  v11 = a4;
  *(_QWORD *)(&v4 - 1) = *(_QWORD *)(a1 + 20);
  if ( v5 && !*(_DWORD *)(a1 + 4) )
  {
    v7 = *(unsigned __int16 *)(v4 + 12) + (unsigned __int16)CmRegistryMachineSystemCurrentControlSetServices;
    v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v7 + 6, 1701081168);
    v9 = v8;
    if ( !v8 )
      return -1073741670;
    RtlStringCbPrintfW(v8, v7 + 6, (int)L"%s\\%s", dword_920914);
    RtlInitUnicodeString((unsigned int)&v10, v9);
    IopUnloadDriver(&v10, 1);
    ExFreePoolWithTag(v11);
  }
  return 0;
}
