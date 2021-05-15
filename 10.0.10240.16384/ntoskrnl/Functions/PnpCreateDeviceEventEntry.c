// PnpCreateDeviceEventEntry 
 
_BYTE *__fastcall PnpCreateDeviceEventEntry(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, a1, 1265659472);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, a1);
    *((_DWORD *)v3 + 8) = 1;
  }
  return v3;
}
