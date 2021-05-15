// PopPluginUnregisterDevice 
 
int __fastcall PopPluginUnregisterDevice(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int *); // r3
  int result; // r0
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  v5 = *(int (__fastcall **)(int, int *))(a1 + 64);
  v7 = a2;
  result = v5(4, &v7);
  if ( !result )
    PopFxBugCheck(1541, 4, a1, 0);
  return result;
}
