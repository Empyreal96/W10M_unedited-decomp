// sub_565F48 
 
int __fastcall sub_565F48(_BYTE *a1, unsigned int a2, int a3, _DWORD *a4, unsigned int *a5, __int16 a6)
{
  unsigned int v8; // r5
  _WORD *v9; // r4
  _WORD *v10; // r3

  v8 = a2 >> 1;
  if ( a2 >> 1 && (a6 & 0x1000) != 0 )
  {
    v9 = &a1[2 * a3];
    *a5 = v8 - a3;
    *a4 = v9;
    *v9 = 0;
  }
  if ( (a6 & 0x400) != 0 )
  {
    memset(a1, (unsigned __int8)a6, a2);
    if ( (_BYTE)a6 )
    {
      if ( !v8 )
        return 0;
      v10 = &a1[2 * v8 - 2];
      *a5 = 1;
      *a4 = v10;
      *v10 = 0;
    }
    else
    {
      *a4 = a1;
      *a5 = v8;
    }
  }
  if ( v8 && (a6 & 0x800) != 0 )
  {
    *a4 = a1;
    *a5 = v8;
    *(_WORD *)a1 = 0;
  }
  return 0;
}
