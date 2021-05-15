// IoInitializeCrashDump 
 
int __fastcall IoInitializeCrashDump(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r5
  int v6; // r3
  int v7; // r4
  int v8; // r0
  __int16 v9; // r3
  int result; // r0
  int varg_r0; // [sp+10h] [bp+8h]

  varg_r0 = a1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(__int16 *)(v5 + 0x134) - 1;
  *(_WORD *)(v5 + 308) = v6;
  ExAcquireResourceExclusiveLite((int)&IopCrashDumpLock, 1, a3, v6);
  v7 = IopInitializeCrashDump(a1, a2);
  if ( v7 )
    IopRemoveDumpCapsuleSupport();
  else
    IopInitDumpCapsuleSupport();
  v8 = ExReleaseResourceLite((int)&IopCrashDumpLock);
  v9 = *(_WORD *)(v5 + 308) + 1;
  *(_WORD *)(v5 + 308) = v9;
  if ( v9 || *(_DWORD *)(v5 + 100) == v5 + 100 )
    result = v7;
  else
    result = sub_80FA60(v8);
  return result;
}
