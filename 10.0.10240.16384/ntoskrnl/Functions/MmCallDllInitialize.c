// MmCallDllInitialize 
 
int __fastcall MmCallDllInitialize(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v6)(unsigned __int16 *); // r7
  unsigned int v7; // r2
  unsigned int v8; // r1
  int v9; // r0
  _WORD *v10; // r5
  unsigned int v11; // r6
  int v12; // r1
  unsigned __int16 v13; // r2
  unsigned int v15; // r1
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r3
  _WORD *v19; // r0
  unsigned int v20; // r0
  int v21; // r5
  int v22; // r4
  unsigned __int16 v23[2]; // [sp+0h] [bp-28h] BYREF
  unsigned int v24; // [sp+4h] [bp-24h]
  unsigned __int16 v25[2]; // [sp+8h] [bp-20h] BYREF
  int v26; // [sp+Ch] [bp-1Ch]

  v6 = (int (__fastcall *)(unsigned __int16 *))RtlFindExportedRoutineByName(
                                                 *(_DWORD *)(a1 + 24),
                                                 (int)"DllInitialize",
                                                 a3,
                                                 a4);
  if ( !v6 )
    return 0;
  v7 = *(unsigned __int16 *)(a1 + 44);
  v8 = (unsigned __int16)(v7 + 2);
  if ( v8 <= v7 )
    JUMPOUT(0x80C1E0);
  v25[1] = v7 + 2;
  v9 = ExAllocatePoolWithTag(1, v8, 1413770573);
  v10 = (_WORD *)v9;
  v26 = v9;
  if ( !v9 )
    return -1073741670;
  v12 = *(_DWORD *)(a1 + 48);
  v25[0] = *(_WORD *)(a1 + 44);
  v11 = v25[0];
  memmove(v9, v12, v25[0]);
  v13 = CmRegistryMachineSystemCurrentControlSetServices + v25[0];
  if ( (unsigned __int16)(CmRegistryMachineSystemCurrentControlSetServices + v25[0]) <= (unsigned int)(unsigned __int16)CmRegistryMachineSystemCurrentControlSetServices )
    return sub_80C1D8();
  v15 = (unsigned __int16)(v13 + 4);
  if ( v15 <= v13 )
  {
    v22 = -1073741562;
  }
  else
  {
    v23[1] = v13 + 4;
    v16 = ExAllocatePoolWithTag(512, v15, 1413770573);
    v24 = v16;
    if ( v16 )
    {
      v23[0] = CmRegistryMachineSystemCurrentControlSetServices;
      memmove(v16, dword_920914, (unsigned __int16)CmRegistryMachineSystemCurrentControlSetServices);
      RtlAppendUnicodeToString(v23, (int)L"\\", v17, v18);
      v10[v11 >> 1] = 0;
      v19 = wcschr(v10, 46);
      if ( v19 )
      {
        v11 = (unsigned __int16)(2 * (v19 - v10));
        v25[0] = 2 * (v19 - v10);
      }
      v10[v11 >> 1] = 0;
      RtlAppendUnicodeStringToString(v23, v25);
      v20 = ExFreePoolWithTag((unsigned int)v10);
      v21 = VfDriverInitStarting(v20);
      v22 = v6(v23);
      ExFreePoolWithTag(v24);
      if ( v22 >= 0 && !byte_632F2C )
        VfDriverInitSuccess(v21, a2);
      return v22;
    }
    v22 = -1073741670;
  }
  ExFreePoolWithTag((unsigned int)v10);
  return v22;
}
