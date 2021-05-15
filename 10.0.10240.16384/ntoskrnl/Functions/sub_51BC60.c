// sub_51BC60 
 
void __fastcall sub_51BC60(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  unsigned int v5; // r3
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r3
  __int16 v9; // r3

  if ( a3 == 19 )
  {
    v5 = v4 & 0xF9FF03FF;
  }
  else
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = *(_DWORD *)(a1 + 24);
    if ( v7 == *(_DWORD *)(v6 + 0x10) )
    {
      v8 = *(unsigned __int16 *)(v6 + 398);
      if ( v8 > 0x400 )
      {
        *(_WORD *)(v6 + 398) = 0;
        JUMPOUT(0x444C7E);
      }
      v9 = v8 + 1;
    }
    else
    {
      v9 = 0;
      *(_DWORD *)(v6 + 16) = v7;
    }
    *(_WORD *)(v6 + 398) = v9;
    v5 = *(_DWORD *)(a2 + 68) & 0xF9FF03FF;
  }
  *(_DWORD *)(a2 + 64) = v3;
  *(_DWORD *)(a2 + 68) = v5 | 0x20;
  JUMPOUT(0x444C80);
}
