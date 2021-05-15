// PopPluginAbandonDevice 
 
int __fastcall PopPluginAbandonDevice(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int *); // r3
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  v5 = *(int (__fastcall **)(int, int *))(a1 + 64);
  v7 = a2;
  if ( !v5(2, &v7) )
    PopFxBugCheck(1541, 2, a1, 0);
  return (unsigned __int8)v8;
}
