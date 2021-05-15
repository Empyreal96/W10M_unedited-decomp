// PopFxResetSocSubsystemAccounting 
 
int __fastcall PopFxResetSocSubsystemAccounting(int a1, int a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v6 = a2;
  v7 = a3;
  v8 = a4;
  if ( !PopFxLookupSocSubsystemsByPlatformIdleState() )
    return -1073741585;
  v6 = a1;
  v7 = 0;
  if ( !(*(int (__fastcall **)(int, int *))(PopFxProcessorPlugin + 64))(38, &v6) )
    PopFxBugCheck(1541, 38, PopFxProcessorPlugin, 0);
  return 0;
}
