// PopPluginQueryComponentPerfSetName 
 
int __fastcall PopPluginQueryComponentPerfSetName(int a1, int a2, int a3, __int16 *a4, int a5)
{
  __int64 v6; // kr00_8
  int result; // r0
  int v8[3]; // [sp+0h] [bp-20h] BYREF
  __int16 v9; // [sp+Ch] [bp-14h]
  int v10; // [sp+10h] [bp-10h]

  v8[1] = a2;
  v8[2] = a3;
  v6 = *(_QWORD *)(a1 + 36);
  v9 = *a4;
  v8[0] = HIDWORD(v6);
  v10 = a5;
  result = (*(int (__fastcall **)(int, int *))(v6 + 64))(30, v8);
  if ( !result )
    PopFxBugCheck(1541, 30, v6, 0);
  *a4 = v9;
  return result;
}
