// PopPluginQueryComponentPerfStates 
 
int __fastcall PopPluginQueryComponentPerfStates(int a1, int a2, int a3, int a4)
{
  unsigned __int64 v4; // kr00_8
  int v5; // r4
  int result; // r0
  _DWORD v7[6]; // [sp+0h] [bp-18h] BYREF

  v4 = *(_QWORD *)(a1 + 36);
  v7[0] = HIDWORD(v4);
  v5 = v4;
  v7[1] = a2;
  v7[2] = a3;
  v7[3] = a4;
  result = (*(int (__fastcall **)(int, _DWORD *))(v4 + 64))(31, v7);
  if ( !result )
    PopFxBugCheck(1541, 31, v4, 0);
  return result;
}
