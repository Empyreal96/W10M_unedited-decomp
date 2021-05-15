// NtFlushVirtualMemory 
 
int __fastcall NtFlushVirtualMemory(int a1, unsigned int *a2, unsigned int *a3, unsigned int a4)
{
  _DWORD *v4; // r9
  unsigned int *v5; // r8
  unsigned int *v6; // r6
  unsigned int *v7; // r4
  _DWORD *v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r2
  int v11; // r4
  char v13; // [sp+10h] [bp-40h]
  unsigned int v14; // [sp+14h] [bp-3Ch] BYREF
  unsigned int v15; // [sp+18h] [bp-38h] BYREF
  int v16[3]; // [sp+1Ch] [bp-34h] BYREF
  _DWORD _28[16]; // [sp+28h] [bp-28h] BYREF

  v4 = (_DWORD *)a4;
  _28[15] = a4;
  v5 = a3;
  _28[14] = a3;
  v6 = a2;
  _28[13] = a2;
  _28[12] = a1;
  v13 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v13 )
  {
    v7 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v7 = (unsigned int *)MmUserProbeAddress;
    *v7 = *v7;
    if ( (unsigned int)a3 >= MmUserProbeAddress )
      a3 = (unsigned int *)MmUserProbeAddress;
    *a3 = *a3;
    v8 = (_DWORD *)a4;
    if ( a4 >= MmUserProbeAddress )
      v8 = (_DWORD *)MmUserProbeAddress;
    *v8 = *v8;
    v9 = *a2;
    v15 = *a2;
    v10 = *v5;
    v14 = *v5;
  }
  else
  {
    v9 = *a2;
    v15 = *a2;
    v10 = *a3;
    v14 = *v5;
  }
  if ( v9 > MmHighestUserAddress || MmHighestUserAddress - v9 < v10 )
    return -1073741584;
  v11 = ObReferenceObjectByHandleWithTag(a1, 8, PsProcessType, v13, 1816554829, v16, 0);
  if ( v11 >= 0 )
  {
    v11 = MmFlushVirtualMemory(v16[0], &v15, &v14, _28);
    v16[2] = v11;
    ObfDereferenceObjectWithTag(v16[0]);
    *v5 = v14;
    *v6 = v15 & 0xFFFFF000;
    *v4 = _28[0];
    v4[1] = _28[1];
  }
  return v11;
}
