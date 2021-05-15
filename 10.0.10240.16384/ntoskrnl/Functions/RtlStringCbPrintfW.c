// RtlStringCbPrintfW 
 
int __fastcall RtlStringCbPrintfW(_WORD *a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r3
  int v6; // r4
  unsigned int v7; // r5
  int v8; // r0
  _WORD *varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  v5 = a2 >> 1;
  v6 = 0;
  if ( !(a2 >> 1) )
    v6 = -1073741811;
  if ( v6 < 0 )
  {
    if ( v5 )
      *a1 = 0;
  }
  else
  {
    v7 = v5 - 1;
    v6 = 0;
    v8 = vsnwprintf(a1, v5 - 1);
    if ( v8 < 0 )
      return sub_54B5FC();
    if ( v8 == v7 )
    {
      a1[v7] = 0;
    }
    else if ( v8 > v7 )
    {
      return sub_54B5FC();
    }
  }
  return v6;
}
