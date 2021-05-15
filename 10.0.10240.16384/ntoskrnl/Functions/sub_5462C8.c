// sub_5462C8 
 
void __fastcall sub_5462C8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, unsigned __int8 a17)
{
  int v17; // r6
  int v18; // r7

  if ( (((_WORD)v18 + (_WORD)v17) & 0xFFF) != 0 )
  {
    KeQueryTickCount((int *)&a17);
    memset((_BYTE *)(v18 + v17), a17 | 1, (unsigned __int16)(((v18 + v17) & 0xF000) - (v18 + v17) + 4096));
  }
  JUMPOUT(0x4C0450);
}
