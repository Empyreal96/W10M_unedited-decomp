// Template_qzq 
 
int __fastcall Template_qzq(int a1, int a2, int a3, int a4, int a5, unsigned __int16 *a6)
{
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  if ( a6 )
    wcslen(a6);
  return EtwWrite(a1, a2, (int)KMPnPEvt_DriverOverride_SetOverride, 0);
}
