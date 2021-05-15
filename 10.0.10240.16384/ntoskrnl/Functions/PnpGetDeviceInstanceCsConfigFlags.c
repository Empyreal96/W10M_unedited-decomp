// PnpGetDeviceInstanceCsConfigFlags 
 
int __fastcall PnpGetDeviceInstanceCsConfigFlags(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  int v4; // r4
  unsigned int v5; // r0
  int result; // r0
  unsigned int v7; // [sp+10h] [bp-18h] BYREF
  char v8[20]; // [sp+14h] [bp-14h] BYREF

  *a3 = 0;
  v4 = PnpUnicodeStringToWstr((int *)&v7, 0, a1);
  if ( v4 < 0
    || (v4 = CmOpenDeviceRegKey(PiPnpRtlCtx, v7, 528, 0, 131097, 0, (int)v8, 0),
        v5 = PnpUnicodeStringToWstrFree(v7, (int)a1),
        v4 < 0) )
  {
    result = v4;
  }
  else
  {
    result = sub_7C9BFC(v5);
  }
  return result;
}
