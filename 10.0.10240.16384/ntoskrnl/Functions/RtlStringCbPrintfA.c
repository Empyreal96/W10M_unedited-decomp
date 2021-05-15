// RtlStringCbPrintfA 
 
int __fastcall RtlStringCbPrintfA(int a1, unsigned int a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r2
  int result; // r0
  int varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  if ( sub_43E028(a1, a2) >= 0 )
    result = sub_4E23A8(a1, v5, 0, v6);
  else
    result = sub_54D980();
  return result;
}
