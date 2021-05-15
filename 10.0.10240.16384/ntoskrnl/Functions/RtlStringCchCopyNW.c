// RtlStringCchCopyNW 
 
int __fastcall RtlStringCchCopyNW(_WORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // r5
  _WORD *v6; // r4
  unsigned int v8; // r2
  int v9; // r0

  v4 = 0;
  v6 = a1;
  if ( !a2 || a2 > 0x7FFFFFFF )
    v4 = -1073741811;
  if ( v4 < 0 )
  {
    if ( !a2 )
      return v4;
  }
  else if ( a4 > 0x7FFFFFFE )
  {
    v4 = -1073741811;
  }
  else
  {
    v4 = 0;
    if ( !a2 )
      return sub_50A5F8();
    v8 = a4 - a2;
    v9 = a3 - (_DWORD)a1;
    do
    {
      if ( !(v8 + a2) )
        break;
      if ( !*(_WORD *)((char *)v6 + v9) )
        break;
      *v6 = *(_WORD *)((char *)v6 + v9);
      ++v6;
      --a2;
    }
    while ( a2 );
    if ( !a2 )
      return sub_50A5F8();
  }
  *v6 = 0;
  return v4;
}
