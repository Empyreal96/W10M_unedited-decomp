// PopPluginInitializeSocSubsystemStaticInfo 
 
BOOL __fastcall PopPluginInitializeSocSubsystemStaticInfo(int a1, int a2)
{
  _WORD *v3; // r5
  _WORD *v4; // r6
  int v5; // r3
  int v6; // r3
  BOOL v7; // r5
  int v9; // [sp+0h] [bp-20h]
  int v10; // [sp+8h] [bp-18h]

  v3 = *(_WORD **)(a2 + 16);
  v4 = *(_WORD **)(a2 + 24);
  v9 = *(_DWORD *)(a2 + 12);
  v10 = *(_DWORD *)(a2 + 20);
  if ( !(*(int (__fastcall **)(int))(a1 + 64))(37) )
    PopFxBugCheck(1541, 37, PopFxProcessorPlugin, 0);
  if ( !PopFxValidateReturnedUnicodeString((unsigned __int16 *)(a2 + 12), v3, HIWORD(v9), v5) )
    PopFxBugCheck(1798, 37, 1347314029, a2 + 16);
  v7 = PopFxValidateReturnedUnicodeString((unsigned __int16 *)(a2 + 20), v4, HIWORD(v10), v6);
  if ( !v7 )
    PopFxBugCheck(1798, 37, 1397645677, a2 + 24);
  if ( !wcsncmp(*(_WORD **)(a2 + 24), *(unsigned __int16 **)(a2 + 16), 64) )
    PopFxBugCheck(1798, 37, 1315007845, a2 + 24);
  if ( *(_DWORD *)(a2 + 28) > 0x3E8u )
    PopFxBugCheck(1798, 37, 1296265077, a2 + 28);
  return v7;
}
