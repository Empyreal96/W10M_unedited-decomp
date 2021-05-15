// RtlUnicodeStringPrintf 
 
int __fastcall RtlUnicodeStringPrintf(_WORD *a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  unsigned int v8; // [sp+8h] [bp-18h]
  _WORD *varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = a1;
  v5 = sub_4DBF00();
  if ( v5 >= 0 )
  {
    v5 = 0;
    v6 = vsnwprintf();
    if ( v6 < 0 || v6 > v8 )
      return sub_5201F8();
    *a1 = 2 * v6;
  }
  return v5;
}
