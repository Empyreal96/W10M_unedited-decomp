// PopMarkComponentsBootPhase 
 
char *__fastcall PopMarkComponentsBootPhase(char *result)
{
  char *v1; // r4
  int *i; // r5
  char *v3; // r0

  v1 = result;
  if ( !byte_61EED1 )
  {
    PoSetHiberRange(0, 0x10000, PopSaveHiberContext, 0, 1852990795);
    PoSetHiberRange(0, 0x10000, HalAllocateCrashDumpRegisters, 0, 1665687916);
    for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
    {
      PoSetHiberRange(0, 0x10000, i, (const void *)0x5C, 1852990795);
      PoSetHiberRange(0, 0x10000, (const void *)i[12], (const void *)*((unsigned __int16 *)i + 22), 1852990795);
      PoSetHiberRange(0, 0x10000, (const void *)i[10], (const void *)*((unsigned __int16 *)i + 18), 1852990795);
    }
    FirstEntrySList((int)&unk_61F2B0);
    off_61797C(0);
    PopMarkHiberPhase(v1);
    v3 = KdMarkHiberPhase();
    VfMarkHiberPhase(v3);
    BgkResumePrepare(0);
    RtlMarkHiberPhase();
    MmMarkHiberPhase();
    result = IoMarkTriageDumpBlock();
    if ( PopShutdownNotificationCallback )
      v1[3] = 1;
    else
      v1[4] = 1;
  }
  v1[20] = 1;
  return result;
}
