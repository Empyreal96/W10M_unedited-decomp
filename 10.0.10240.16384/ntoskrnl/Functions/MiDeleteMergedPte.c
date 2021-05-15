// MiDeleteMergedPte 
 
int __fastcall MiDeleteMergedPte(int a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r7
  int v7; // r4
  _DWORD v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  if ( !*a2 )
    return 0;
  v6 = MiLockProtoPoolPage(a2, v9);
  v7 = MiDeleteTransitionPte(a2, 1);
  if ( v7 == 1 )
    MiReleasePageFileSpace(a1, *a2, 1);
  MiUnlockProtoPoolPage(v6, LOBYTE(v9[0]));
  return v7;
}
