// BgpGxBlendColor 
 
int __fastcall BgpGxBlendColor(int a1, int a2, int a3, int a4)
{
  int v5; // [sp+0h] [bp-10h]

  HIWORD(v5) = (unsigned __int8)(-(char)(BYTE2(a1) * (-1 - a3)) - BYTE2(a2) * a3);
  BYTE1(v5) = -(char)(BYTE1(a1) * (-1 - a3)) - BYTE1(a2) * a3;
  LOBYTE(v5) = ((int)((unsigned __int64)(2155905153i64 * (unsigned __int8)a2 * a3) >> 32) >> 7)
             + ((int)((unsigned __int64)(2155905153i64 * (unsigned __int8)a2 * a3) >> 32) >> 7 < 0)
             - a1 * (-1 - a3);
  return v5;
}
