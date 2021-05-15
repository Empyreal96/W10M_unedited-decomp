// PopPluginRequestDebuggerTransitionRequirements 
 
int __fastcall PopPluginRequestDebuggerTransitionRequirements(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int result; // r0
  int v7; // r3
  int v8; // [sp+0h] [bp-18h] BYREF
  int v9; // [sp+4h] [bp-14h]
  int v10; // [sp+8h] [bp-10h]
  int v11; // [sp+Ch] [bp-Ch]

  v8 = a1;
  v9 = a2;
  v10 = a3;
  v11 = a4;
  v5 = *(_DWORD *)(a1 + 36);
  result = 0;
  if ( v5 == PopFxProcessorPlugin )
  {
    v7 = *(_DWORD *)(a1 + 40);
    v9 = a2;
    v10 = a3;
    v8 = v7;
    result = (*(int (__fastcall **)(int, int *))(v5 + 64))(35, &v8);
  }
  return result;
}
