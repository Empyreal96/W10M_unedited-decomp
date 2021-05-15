// RtlStringCchPrintfW 
 
int __fastcall RtlStringCchPrintfW(_WORD *a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v6; // r5
  int v7; // r0
  _WORD *varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  v4 = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    v4 = -1073741811;
  if ( v4 < 0 )
  {
    if ( a2 )
      *a1 = 0;
  }
  else
  {
    v6 = a2 - 1;
    v4 = 0;
    v7 = vsnwprintf(a1, a2 - 1);
    if ( v7 < 0 || v7 > v6 )
      return sub_524658();
    if ( v7 == v6 )
      a1[v6] = 0;
  }
  return v4;
}
