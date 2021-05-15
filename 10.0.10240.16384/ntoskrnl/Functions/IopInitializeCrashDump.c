// IopInitializeCrashDump 
 
int __fastcall IopInitializeCrashDump(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // [sp+0h] [bp-20h]
  int var18[9]; // [sp+8h] [bp-18h] BYREF
  int varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  var18[8] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = a1;
  var18[1] = a4;
  var18[0] = 0;
  IopReadDumpRegistry(a1, var18);
  if ( CrashdmpImageEntry && CrashdmpDumpBlock && CrashdmpInitialized || !var18[0] )
    return 1;
  if ( !CrashdmpImageEntry && IopLoadCrashdumpDriver() < 0 )
    JUMPOUT(0x80FAD8);
  if ( dword_63764C(a1, &CrashdmpDumpBlock, varg_r1, varg_r2, v7, a2) >= 0 )
  {
    CrashdmpInitialized = 1;
    v6 = *(_DWORD *)(CrashdmpDumpBlock + 484);
    if ( !v6 )
    {
      if ( !a1 )
        return 1;
      v6 = a1;
    }
    if ( ObReferenceObjectByHandle(v6, 0, (int)IoFileObjectType, 0, (int)var18, 0) >= 0 )
    {
      FsRtlIssueFileNotificationFsctl(var18[0]);
      ObfDereferenceObject(var18[0]);
    }
    return 1;
  }
  return sub_80FAD4();
}
