// WmipProbeWnodeSingleInstance 
 
int __fastcall WmipProbeWnodeSingleInstance(_DWORD *a1, unsigned int a2, unsigned int a3, int a4)
{
  int v6; // r0
  int result; // r0
  int v8; // r2

  if ( a2 < 0x40 )
    return -1073741823;
  if ( a4 )
  {
    if ( a3 < 0x40 )
      return -1073741823;
    v6 = 0;
  }
  else
  {
    v6 = 1;
  }
  result = WmipProbeWnodeWorker(a1, 64, a1[12], a1[14], a1[15], a2, a3, a4, v6);
  if ( result < 0 )
    return result;
  v8 = a1[11];
  if ( (v8 & 2) == 0 || a2 != *a1 || (v8 & 0xFFFFFF7D) != 0 )
    return -1073741823;
  return 0;
}
