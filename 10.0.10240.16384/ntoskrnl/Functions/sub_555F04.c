// sub_555F04 
 
int __fastcall sub_555F04(_BYTE *a1, int a2, int a3, _DWORD *a4, int *a5, __int16 a6)
{
  _BYTE *v9; // r3

  if ( a2 && (a6 & 0x1000) != 0 )
  {
    *a5 = a2 - a3;
    *a4 = &a1[a3];
    a1[a3] = 0;
  }
  if ( (a6 & 0x400) != 0 )
  {
    memset(a1, (unsigned __int8)a6, a2);
    if ( (_BYTE)a6 )
    {
      if ( !a2 )
        return 0;
      v9 = &a1[a2 - 1];
      *a5 = 1;
      *a4 = v9;
      *v9 = 0;
    }
    else
    {
      *a4 = a1;
      *a5 = a2;
    }
  }
  if ( a2 && (a6 & 0x800) != 0 )
  {
    *a4 = a1;
    *a5 = a2;
    *a1 = 0;
  }
  return 0;
}
