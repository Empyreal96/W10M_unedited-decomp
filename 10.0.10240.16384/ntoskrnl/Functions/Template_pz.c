// Template_pz 
 
int __fastcall Template_pz(int a1, int a2, int a3, int a4, int a5, unsigned __int16 *a6)
{
  int varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  if ( a6 )
    wcslen(a6);
  return EtwWrite(a1, a2, (int)KMPnPEvt_ProcessNewDevice_InstancePath, 0);
}
