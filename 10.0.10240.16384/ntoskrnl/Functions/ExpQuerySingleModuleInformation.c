// ExpQuerySingleModuleInformation 
 
int __fastcall ExpQuerySingleModuleInformation(int a1, unsigned int a2, char a3, _DWORD *a4)
{
  int v6; // r4
  unsigned int v7; // r8
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int *v11; // r0
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r3

  *a4 = 0;
  if ( a3 )
    return -1073741790;
  if ( a2 < 0x130 )
    return -1073741820;
  v7 = *(_DWORD *)a1;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(__int16 *)(v8 + 0x134) - 1;
  *(_WORD *)(v8 + 308) = v9;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, v8, v9);
  v10 = 0;
  v11 = (int *)PsLoadedModuleList;
  if ( PsLoadedModuleList )
  {
    while ( v11 != &PsLoadedModuleList )
    {
      v15 = v11[6];
      if ( v7 >= v15 )
      {
        v16 = v11[8] + v15;
        if ( v7 < v16 )
        {
          *(_WORD *)(a1 + 4) = 0;
          ExpConvertLdrEntryToModuleInfo((int)v11, v10, a1 + 4, v16);
          v6 = 0;
          goto LABEL_6;
        }
      }
      v11 = (int *)*v11;
      ++v10;
    }
  }
  v6 = -1073741275;
LABEL_6:
  v12 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( v6 >= 0 )
    *a4 = 304;
  return v6;
}
