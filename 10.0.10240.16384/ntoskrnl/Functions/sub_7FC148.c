// sub_7FC148 
 
void __fastcall sub_7FC148(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r4
  int v11; // r6
  unsigned __int16 v12; // r2

  a10 = v10 + 76;
  v12 = *(_WORD *)(v11 + 72);
  LOWORD(a9) = *(_WORD *)(v10 + 72);
  HIWORD(a9) = a9;
  CmpCompareCompressedName((unsigned __int16 *)&a9, (unsigned __int8 *)(v11 + 76), v12, 0);
  JUMPOUT(0x730F3A);
}
