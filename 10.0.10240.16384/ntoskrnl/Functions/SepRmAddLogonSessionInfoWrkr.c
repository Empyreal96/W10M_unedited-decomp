// SepRmAddLogonSessionInfoWrkr 
 
int __fastcall SepRmAddLogonSessionInfoWrkr(int a1, int a2)
{
  int result; // r0

  result = SepUpdateLogonSessionTrack(a1 + 28);
  *(_DWORD *)(a2 + 24) = result;
  return result;
}
