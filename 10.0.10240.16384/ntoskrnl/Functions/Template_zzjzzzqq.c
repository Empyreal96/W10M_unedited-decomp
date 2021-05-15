// Template_zzjzzzqq 
 
int __fastcall Template_zzjzzzqq(int a1, int a2, int a3, int a4, unsigned __int16 *a5, unsigned __int16 *a6, int a7, unsigned __int16 *a8, unsigned __int16 *a9, unsigned __int16 *a10)
{
  int varg_r0; // [sp+A8h] [bp+8h]
  int varg_r1; // [sp+ACh] [bp+Ch]
  int varg_r2; // [sp+B0h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  if ( a5 )
    wcslen(a5);
  if ( a6 )
    wcslen(a6);
  if ( a8 )
    wcslen(a8);
  if ( a9 )
    wcslen(a9);
  if ( a10 )
    wcslen(a10);
  return EtwWrite(a1, a2, a3, 0);
}
