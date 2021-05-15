// PopPluginQuerySocSubsystemBlockingTime 
 
int __fastcall PopPluginQuerySocSubsystemBlockingTime(int a1, unsigned int a2, int a3, int a4)
{
  __int64 *v4; // r4
  __int64 v7; // kr00_8
  int v9; // r5
  unsigned __int16 *v10; // r4
  unsigned int v12[2]; // [sp+0h] [bp-28h] BYREF
  int v13; // [sp+8h] [bp-20h]
  int v14; // [sp+Ch] [bp-1Ch]

  v12[0] = a1;
  v12[1] = a2;
  v13 = a3;
  v14 = a4;
  v4 = *(__int64 **)(a3 + 8);
  v7 = *v4;
  v13 = *(_DWORD *)v4;
  v9 = (*(int (__fastcall **)(int, int))(a1 + 64))(39, a3);
  if ( !v9 )
    PopFxBugCheck(1541, 39, PopFxProcessorPlugin, 0);
  v10 = *(unsigned __int16 **)(a3 + 8);
  RtlHashUnicodeString(v10, 0, 0, v12);
  if ( __PAIR64__(v10[1], *v10) != __PAIR64__(HIWORD(v13), (unsigned __int16)v13)
    || *((_DWORD *)v10 + 1) != HIDWORD(v7)
    || v12[0] != a2 )
  {
    PopFxBugCheck(1797, a1, 39, 1315007845);
  }
  return v9;
}
