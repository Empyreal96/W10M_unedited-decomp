// DbgkpStartSystemErrorHandler 
 
int DbgkpStartSystemErrorHandler()
{
  int v0; // r4
  int result; // r0
  int v2; // [sp+10h] [bp-30h]
  int v3; // [sp+14h] [bp-2Ch]
  int v4; // [sp+18h] [bp-28h]
  _DWORD v5[8]; // [sp+20h] [bp-20h] BYREF

  v0 = 0;
  if ( ZwQueryWnfStateNameInformation() >= 0 && v4 && ZwUpdateWnfStateData() >= 0 )
    v0 = 1;
  if ( EtwRegister(dword_402190, 0, 0) >= 0 )
  {
    v5[0] = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    if ( EtwEventEnabled(v2, v3, (int)v5) && EtwWrite(v2, v3, (int)v5, 0) >= 0 )
      ++v0;
    EtwUnregister();
  }
  if ( v0 )
    result = 0;
  else
    result = -1073741696;
  return result;
}
