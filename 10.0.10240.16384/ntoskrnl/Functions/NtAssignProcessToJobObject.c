// NtAssignProcessToJobObject 
 
int __fastcall NtAssignProcessToJobObject(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r8
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v12; // r0
  int v13; // [sp+10h] [bp-28h] BYREF
  int v14[9]; // [sp+14h] [bp-24h] BYREF

  v13 = 0;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( ObReferenceObjectByHandle(a1, 1, PsJobType, v7, v14, 0) < 0 )
    JUMPOUT(0x7C180E);
  if ( ObReferenceObjectByHandleWithTag(a2, 257, PsProcessType, v7, 1649046352, &v13, 0) >= 0 )
  {
    v12 = PsAssignProcessToJobObject(v14[0], v13);
    if ( (PerfGlobalGroupMask & 0x80000) != 0 )
      EtwTraceJobAssignProcess(v14[0], v13, a1, v12);
    ObfDereferenceObjectWithTag(v13);
    ObfDereferenceObject(v14[0]);
    JUMPOUT(0x7C1824);
  }
  return sub_7C1808(v14[0], v8, v9, v10, a5);
}
