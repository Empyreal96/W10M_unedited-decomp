// KeRevertToUserAffinityThreadEx 
 
int __fastcall KeRevertToUserAffinityThreadEx(int a1, int a2, int a3)
{
  int v4; // [sp+0h] [bp-18h] BYREF
  int v5; // [sp+4h] [bp-14h]
  int v6; // [sp+8h] [bp-10h]

  v5 = 0;
  v6 = 0;
  v4 = a1;
  if ( KeForceGroupAwareness )
    return sub_555C90();
  LOWORD(v5) = 0;
  return KeRevertToUserGroupAffinityThread((int)&v4, a2, a3, 0);
}
