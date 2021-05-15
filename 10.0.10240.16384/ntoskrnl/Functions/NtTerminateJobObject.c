// NtTerminateJobObject 
 
int __fastcall NtTerminateJobObject(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r4
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 8, PsJobType, v5, v11, 0);
  v9 = v6;
  if ( v6 < 0 )
    return sub_7C0320(v6, v7, v8);
  PspTerminateAllProcessesInJobHierarchy(v11[0], a2, 0);
  ObfDereferenceObject(v11[0]);
  return v9;
}
