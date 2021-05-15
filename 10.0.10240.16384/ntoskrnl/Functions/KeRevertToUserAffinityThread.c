// KeRevertToUserAffinityThread 
 
int __fastcall KeRevertToUserAffinityThread(int a1, int a2, int a3)
{
  _DWORD v4[6]; // [sp+0h] [bp-18h] BYREF

  v4[0] = 0;
  v4[1] = 0;
  v4[2] = 0;
  return KeRevertToUserGroupAffinityThread((int)v4, a2, a3, 0);
}
