// SepRmInteractiveLogoffLogonSessionWrkr 
 
int __fastcall SepRmInteractiveLogoffLogonSessionWrkr(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-10h] BYREF
  int v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v6 = a2;
  v7 = a3;
  v8 = a4;
  v6 = *(_DWORD *)(a1 + 28);
  v7 = *(_DWORD *)(a1 + 32);
  result = SepDeleteLogonSessionTrack(&v6, 1);
  *(_DWORD *)(a2 + 24) = result;
  return result;
}
