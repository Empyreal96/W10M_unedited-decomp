// NtSetSystemEnvironmentValueEx 
 
int __fastcall NtSetSystemEnvironmentValueEx(int *a1, _DWORD *a2, unsigned int a3, int a4, int a5)
{
  int v5; // r10
  unsigned int v6; // lr
  int v7; // r4
  unsigned int v8; // r9
  unsigned int v9; // r2
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  unsigned int v14; // r5
  int v18; // [sp+18h] [bp-40h]
  _DWORD _28[17]; // [sp+28h] [bp-30h] BYREF
  int varg_r3; // [sp+6Ch] [bp+14h]

  _28[14] = a1;
  _28[15] = a2;
  _28[16] = a3;
  v5 = a4;
  varg_r3 = a4;
  v6 = a3;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return ExSetFirmwareEnvironmentVariable(a1);
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v18 = *a1;
  v8 = a1[1];
  if ( !(unsigned __int16)*a1 )
    return -1073741819;
  if ( (v8 & 1) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v9 = (unsigned __int16)*a1 + v8;
  if ( v9 > MmUserProbeAddress || v9 < v8 )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( ((unsigned __int8)a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a2);
  if ( !v6 )
  {
    v5 = 0;
    varg_r3 = 0;
  }
  if ( v5 && (v6 + v5 > MmUserProbeAddress || v6 + v5 < v6) )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, 1, (int)&SeSystemEnvironmentPrivilege) )
    return -1073741727;
  v10 = a2[1];
  v11 = a2[2];
  v12 = a2[3];
  _28[0] = *a2;
  _28[1] = v10;
  _28[2] = v11;
  _28[3] = v12;
  v13 = ExAllocatePoolWithTag(512, (unsigned __int16)v18 + 2, 1920364101);
  v14 = v13;
  if ( !v13 )
    return -1073741670;
  memmove(v13, v8, (unsigned __int16)v18);
  *(_WORD *)(v14 + 2 * ((unsigned __int16)v18 >> 1)) = 0;
  if ( memcmp((unsigned int)_28, (unsigned int)ExpSecureBootVendorGuid, 16) || wcsnicmp(v14, L"Kernel_", 7) )
  {
    v7 = ExpSetFirmwareEnvironmentVariable(v14, _28, a3, v5, a5, 1);
    ExFreePoolWithTag(v14);
  }
  else
  {
    ExFreePoolWithTag(v14);
    v7 = -1073741790;
  }
  return v7;
}
