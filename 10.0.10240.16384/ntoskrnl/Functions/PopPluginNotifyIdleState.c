// PopPluginNotifyIdleState 
 
int __fastcall PopPluginNotifyIdleState(int a1, int a2, int a3, char a4)
{
  __int64 v4; // kr00_8
  int result; // r0
  _DWORD v6[3]; // [sp+0h] [bp-18h] BYREF
  char v7; // [sp+Ch] [bp-Ch]
  unsigned __int8 v8; // [sp+Dh] [bp-Bh]

  v4 = *(_QWORD *)(a1 + 36);
  v7 = a4;
  v6[0] = HIDWORD(v4);
  v6[1] = a2;
  v6[2] = a3;
  v8 = 0;
  if ( (*(int (__fastcall **)(int, _DWORD *))(v4 + 64))(19, v6) )
    result = v8;
  else
    result = 1;
  return result;
}
