// sub_7EAAE8 
 
void __fastcall sub_7EAAE8(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  int v7; // r5
  _DWORD *v8; // r6
  int v9; // r2

  if ( (_BYTE)a7 )
  {
    if ( (unsigned __int8)a7 == 1 && a7 >> 8 < (unsigned __int16)KeNumberNodes && !*v8 )
    {
      v9 = (int)*(&KeNodeBlock + (a7 >> 8));
      if ( *(_DWORD *)(v9 + 260) )
        *v8 = v9;
    }
  }
  else if ( (a7 & 0xFFFFFF00) != 0 )
  {
    *(_DWORD *)(v7 + 188) |= 0x100000u;
  }
  JUMPOUT(0x7072B0);
}
