// MiApplyMov32Fixup 
 
int __fastcall MiApplyMov32Fixup(int result, int a2)
{
  __int16 v2; // r4
  unsigned int v3; // r5
  unsigned int v4; // r1

  v2 = *(_WORD *)(result + 4);
  v3 = *(unsigned __int16 *)(result + 6);
  v4 = ((unsigned __int8)v3 | (v3 >> 4) & 0x700 | (2 * (v2 & 0x400 | ((v2 & 0xF) << 11)))) + (a2 >> 16);
  *(_WORD *)(result + 4) = v2 & 0xFBF0 | (v4 >> 1) & 0x400 | ((unsigned __int16)v4 >> 12);
  *(_WORD *)(result + 6) = (unsigned __int8)v4 | v3 & 0x8F00 | (16 * (v4 & 0x700));
  return result;
}
