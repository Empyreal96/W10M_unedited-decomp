// KeSynchronizeTimeToQpc 
 
int __fastcall KeSynchronizeTimeToQpc(int a1, int a2, int a3, int a4)
{
  int _0[3]; // [sp+0h] [bp-8h] BYREF
  int vars8[2]; // [sp+10h] [bp+8h] BYREF

  vars8[0] = a1;
  vars8[1] = a2;
  _0[0] = a3;
  _0[1] = a4;
  return KiUpdateTimeAssist(vars8, _0, _0);
}
