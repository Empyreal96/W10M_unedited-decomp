// PspAssignProcessToJobList 
 
int __fastcall PspAssignProcessToJobList(int a1, int *a2, unsigned int a3, char a4)
{
  char v4; // lr
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int v15; // [sp+8h] [bp-30h] BYREF
  unsigned int v16; // [sp+Ch] [bp-2Ch]
  int *v17; // [sp+10h] [bp-28h]
  int v18; // [sp+14h] [bp-24h]

  v4 = a4;
  v18 = a4;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = 0;
  v16 = v8;
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    if ( (*(_DWORD *)(v8 + 960) & 1) != 0 )
      return -1073741749;
    v10 = *a2;
    v17 = a2 + 1;
    v13 = ObReferenceObjectByHandle(v10, 1, PsJobType, v4, (int)&v15, 0);
    if ( v13 < 0 )
      break;
    v13 = PsAssignProcessToJobObject(v15, a1, v11, v12);
    if ( (PerfGlobalGroupMask[0] & 0x80000) != 0 )
      EtwTraceJobAssignProcess(v15, a1, v10);
    ObfDereferenceObject(v15);
    if ( v13 < 0 )
      return v13;
    if ( ++v9 >= a3 )
      return 0;
    v8 = v16;
    a2 = v17;
    v4 = v18;
  }
  if ( (PerfGlobalGroupMask[0] & 0x80000) != 0 )
    EtwTraceJobAssignProcess(v15, a1, v10);
  return v13;
}
