// RtlStdDeleteStackDatabase 
 
int __fastcall RtlStdDeleteStackDatabase(int a1, int a2, int a3, int a4)
{
  int var8[3]; // [sp+0h] [bp-8h] BYREF
  int vars8[2]; // [sp+10h] [bp+8h] BYREF

  vars8[1] = a2;
  var8[0] = a3;
  var8[1] = a4;
  vars8[0] = a1;
  var8[0] = *(_DWORD *)(a1 + 100) - a1;
  return NtFreeVirtualMemory(-1, vars8, var8, 0x8000);
}
