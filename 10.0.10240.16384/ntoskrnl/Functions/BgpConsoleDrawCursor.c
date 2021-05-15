// BgpConsoleDrawCursor 
 
int BgpConsoleDrawCursor()
{
  int *v0; // r3
  int v1; // r4
  int v2; // r1
  int v3; // r6
  int v5; // [sp+10h] [bp-20h]
  char v6[4]; // [sp+18h] [bp-18h] BYREF
  char v7[20]; // [sp+1Ch] [bp-14h] BYREF

  if ( dword_61038C )
  {
    v2 = dword_610358;
    v3 = dword_610354;
    if ( (unsigned int)dword_61038C >= 0x22 )
    {
      v1 = 9608;
      if ( (unsigned int)dword_61038C < 0x43 )
        v1 = 9604;
    }
    else
    {
      v1 = 95;
    }
  }
  else
  {
    v0 = &dword_610348[75 * dword_610384 + 3 * dword_610388];
    v1 = *((unsigned __int16 *)v0 + 40);
    v2 = v0[19];
    v3 = v0[18];
  }
  return BgpDisplayCharacterEx(
           v1,
           (int *)dword_61036C,
           dword_61037C + dword_610370 * dword_610384,
           dword_610380 + dword_610374 * dword_610388,
           v2,
           v3,
           (int)v7,
           (int)v6,
           v5,
           0);
}
