// RtlPcToFileName 
 
int __fastcall RtlPcToFileName(unsigned int a1, unsigned __int16 *a2, int a3, int a4)
{
  int *v6; // r2
  int v7; // r4
  int *v9; // r4
  unsigned int v10; // r6
  int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a4;
  MmLockLoadedModuleListShared(v11);
  v6 = (int *)PsLoadedModuleList;
  if ( PsLoadedModuleList )
  {
    while ( v6 != &PsLoadedModuleList )
    {
      v9 = v6;
      v10 = v6[6];
      v6 = (int *)*v6;
      if ( a1 >= v10 && a1 < v9[8] + v10 )
      {
        RtlCopyUnicodeString(a2, (unsigned __int16 *)v9 + 22);
        v7 = 0;
        goto LABEL_3;
      }
    }
  }
  v7 = -1073741275;
LABEL_3:
  MmUnlockLoadedModuleListShared(LOBYTE(v11[0]));
  return v7;
}
