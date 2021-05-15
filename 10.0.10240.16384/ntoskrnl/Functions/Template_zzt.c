// Template_zzt 
 
int __fastcall Template_zzt(int a1, int a2, int a3, int a4, unsigned __int16 *a5, unsigned __int16 *a6)
{
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  if ( a5 )
    wcslen(a5);
  if ( a6 )
    wcslen(a6);
  return EtwWrite(a1, a2, (int)KMPnPEvt_CfgMgr_DeviceList_Start, 0);
}
