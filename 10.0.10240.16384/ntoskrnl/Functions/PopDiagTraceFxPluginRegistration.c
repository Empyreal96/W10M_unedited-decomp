// PopDiagTraceFxPluginRegistration 
 
int __fastcall PopDiagTraceFxPluginRegistration(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+3Ch] [bp+8h]

  varg_r0 = result;
  if ( PopDiagHandleRegistered )
    result = sub_818BD0();
  return result;
}
