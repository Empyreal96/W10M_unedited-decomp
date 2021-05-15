// IopInitCrashDumpRegCallback 
 
int __fastcall IopInitCrashDumpRegCallback(int a1, int a2, unsigned __int16 *a3, int a4, int a5, _BYTE *a6)
{
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v10; // [sp+28h] [bp-38h] BYREF
  int v11[2]; // [sp+30h] [bp-30h] BYREF
  char v12[8]; // [sp+38h] [bp-28h] BYREF
  int v13[8]; // [sp+40h] [bp-20h] BYREF

  if ( a6 )
  {
    if ( !*a6 )
    {
      if ( a3 )
      {
        if ( a4 )
        {
          if ( a5 )
          {
            if ( RtlInitUnicodeStringEx((int)v11, a3) >= 0 )
            {
              v13[0] = 24;
              v13[1] = 0;
              v13[3] = 64;
              v13[2] = (int)v11;
              v13[4] = 0;
              v13[5] = 0;
              if ( IoCreateFile((int)&v10, -1072693248, (int)v13, (int)v12, 0, 6, 2, 1, 32776, 0, 0, 0, 0, 274) >= 0 )
              {
                ExAcquireResourceExclusiveLite((int)&IopCrashDumpLock, 1, v6, v7);
                if ( IopInitializeCrashDump(v10, v11[0], v11[1], v8) )
                  *a6 = 1;
                ExReleaseResourceLite((int)&IopCrashDumpLock);
                NtClose();
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
