// NtQuerySystemEnvironmentValueEx 
 
int __fastcall NtQuerySystemEnvironmentValueEx(int *a1, _DWORD *a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // r4
  unsigned int v6; // r9
  unsigned int v7; // r2
  _DWORD *v8; // r2
  int v9; // r1
  _DWORD *v10; // r2
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v15; // r5
  _DWORD *v18; // [sp+Ch] [bp-5Ch]
  int v20; // [sp+14h] [bp-54h] BYREF
  int v21; // [sp+18h] [bp-50h]
  int v22; // [sp+1Ch] [bp-4Ch]
  _DWORD v23[2]; // [sp+20h] [bp-48h] BYREF
  int v24; // [sp+28h] [bp-40h]
  unsigned int v25; // [sp+2Ch] [bp-3Ch]
  _DWORD *v26; // [sp+30h] [bp-38h]
  _DWORD v27[12]; // [sp+38h] [bp-30h] BYREF

  v18 = a4;
  v22 = a3;
  v23[1] = a4;
  v26 = a5;
  v21 = 0;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    return ExGetFirmwareEnvironmentVariable(a1);
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v24 = *a1;
  v6 = a1[1];
  v25 = v6;
  if ( !(_WORD)v24 )
    return -1073741819;
  if ( (v6 & 1) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v7 = (unsigned __int16)v24 + v6;
  if ( v7 > MmUserProbeAddress || v7 < v6 )
    *(_BYTE *)MmUserProbeAddress = 0;
  if ( ((unsigned __int8)a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v8 = a4;
  if ( (unsigned int)a4 >= MmUserProbeAddress )
    v8 = (_DWORD *)MmUserProbeAddress;
  *v8 = *v8;
  v9 = *a4;
  v20 = *a4;
  if ( !a3 )
  {
    v9 = 0;
    v20 = 0;
  }
  if ( v9 )
    ProbeForWrite(a3, v9, 1);
  if ( a5 )
  {
    v10 = a5;
    if ( (unsigned int)a5 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
  }
  if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, 1, (int)&SeSystemEnvironmentPrivilege) )
    return -1073741727;
  v11 = a2[1];
  v12 = a2[2];
  v13 = a2[3];
  v27[0] = *a2;
  v27[1] = v11;
  v27[2] = v12;
  v27[3] = v13;
  v14 = ExAllocatePoolWithTag(512, (unsigned __int16)v24 + 2, 1920364101);
  v15 = v14;
  v21 = v14;
  if ( !v14 )
    return -1073741670;
  memmove(v14, v6, (unsigned __int16)v24);
  *(_WORD *)(v15 + 2 * ((unsigned __int16)v24 >> 1)) = 0;
  v5 = ExpGetFirmwareEnvironmentVariable(v15, v27, a3, &v20, v23, 1);
  ExFreePoolWithTag(v15);
  *v18 = v20;
  if ( a5 )
    *a5 = v23[0];
  return v5;
}
