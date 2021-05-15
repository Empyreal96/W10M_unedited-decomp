// sub_520994 
 
void __fastcall sub_520994(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r6
  unsigned int v6; // r9
  unsigned int v7; // r2
  int v8; // r2
  int v9; // r3

  if ( a4 == 4 )
  {
    v8 = *(unsigned __int16 *)(v5 + 32);
    if ( v8 + a1 <= v6 )
    {
      *(_DWORD *)(v4 + 24) = *(_DWORD *)(v5 + 24);
      v9 = *(_DWORD *)(v5 + 28);
      *(_DWORD *)(v4 + 36) = a1;
      *(_WORD *)(v4 + 34) = v8;
      *(_DWORD *)(v4 + 28) = v9;
      *(_WORD *)(v4 + 32) = 0;
      JUMPOUT(0x452EDE);
    }
  }
  else
  {
    if ( a4 != 5 )
    {
      if ( a4 == 6 )
        JUMPOUT(0x452E8C);
      if ( a4 != 16 )
        JUMPOUT(0x452EF6);
    }
    v7 = *(_DWORD *)(v5 + 28);
    if ( v7 + a1 <= v6 )
    {
      *(_DWORD *)(v4 + 24) = a1;
      *(_DWORD *)(v4 + 28) = v7;
      memmove(a1, *(_DWORD *)(v5 + 24), v7);
      JUMPOUT(0x452EE2);
    }
  }
  JUMPOUT(0x452EEE);
}
