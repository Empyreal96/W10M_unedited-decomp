// wctomb 
 
__int64 __fastcall wctomb(int a1, int a2)
{
  int v2; // r4
  int v4; // [sp+8h] [bp-8h] BYREF

  v2 = -1;
  v4 = -1;
  if ( !wctomb_s_l(&v4, a1, _mb_cur_max, a2) )
    v2 = v4;
  return (unsigned int)v2;
}
