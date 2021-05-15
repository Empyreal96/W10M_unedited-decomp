// NtOpenJobObject 
 
int __fastcall NtOpenJobObject(unsigned int a1, int a2, int a3, int a4)
{
  int v5; // r2
  _DWORD *v6; // r9
  int v7; // r8
  int v8; // r1
  _DWORD *v9; // r2
  int v10; // r4
  int v11; // r6
  int v12; // r0
  int v14; // [sp+14h] [bp-2Ch] BYREF
  int v15; // [sp+18h] [bp-28h]
  int v16; // [sp+1Ch] [bp-24h]
  _DWORD _20[14]; // [sp+20h] [bp-20h] BYREF

  _20[13] = a4;
  _20[12] = a3;
  v5 = a2;
  _20[0] = a2;
  _20[11] = a2;
  v6 = (_DWORD *)a1;
  _20[10] = a1;
  v14 = 0;
  v7 = 0;
  v16 = 0;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v15 = v8;
  if ( v8 )
  {
    v9 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    v5 = _20[0];
  }
  v10 = ObOpenObjectByName(a3, PsJobType, v8, 0, v5, 0, &v14);
  v11 = v14;
  if ( v10 >= 0 )
    *v6 = v14;
  if ( (PerfGlobalGroupMask[0] & 0x80000) != 0 )
  {
    v12 = ObReferenceObjectByHandle(v11, 4, PsJobType, v15, (int)_20, 0);
    v7 = _20[0];
    if ( v12 < 0 )
      v7 = 0;
  }
  if ( (PerfGlobalGroupMask[0] & 0x80000) != 0 )
    EtwTraceJob(v7, v11);
  return v10;
}
