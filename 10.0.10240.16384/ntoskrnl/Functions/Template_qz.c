// Template_qz 
 
int __fastcall Template_qz(int a1, int a2, int a3, int a4, int a5, unsigned __int16 *a6)
{
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  if ( a6 )
    wcslen(a6);
  return EtwWrite(a1, a2, a3, 0);
}
