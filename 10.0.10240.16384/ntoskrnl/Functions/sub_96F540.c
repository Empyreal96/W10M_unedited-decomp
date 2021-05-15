// sub_96F540 
 
void __fastcall sub_96F540(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  __int16 v8; // r5
  int v9; // r0
  int v10; // r4
  _WORD *v11; // r2

  if ( (unsigned __int16)a7 >= 4u )
  {
    v9 = ExAllocatePoolWithTag(1, HIWORD(a7) + 2, 1350005829);
    v10 = v9;
    if ( v9 )
    {
      memmove(v9, a8, HIWORD(a7));
      v11 = (_WORD *)(v10 + 2 * ((unsigned __int16)a7 >> 1));
      if ( *(v11 - 1) != 92 )
      {
        *v11 = 92;
        *(_WORD *)(v10 + 2 * ((unsigned __int16)a7 >> 1) + 2) = v8;
      }
    }
  }
  JUMPOUT(0x963250);
}
