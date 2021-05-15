// PopPluginQueryComponentPerfSet 
 
int __fastcall PopPluginQueryComponentPerfSet(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, _DWORD *a8)
{
  __int64 v8; // kr00_8
  int result; // r0
  int v11; // r1
  int v12; // r3
  _DWORD v13[16]; // [sp+0h] [bp-40h] BYREF

  v8 = *(_QWORD *)(a1 + 36);
  v13[0] = *(_DWORD *)(a1 + 40);
  v13[1] = a2;
  v13[2] = a3;
  v13[4] = 0;
  v13[5] = 0;
  result = (*(int (__fastcall **)(int, _DWORD *))(v8 + 64))(29, v13);
  if ( !result )
    PopFxBugCheck(1541, 29, v8, 0);
  v11 = v13[8];
  *a4 = v13[6];
  *a5 = v13[7];
  *a6 = v11;
  v12 = v13[9];
  *a7 = v11;
  a7[1] = v12;
  *a8 = v13[10];
  a8[1] = v13[11];
  return result;
}
