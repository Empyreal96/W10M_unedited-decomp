// PiSwDeviceCreate 
 
int __fastcall PiSwDeviceCreate(_DWORD *a1)
{
  int v2; // r4
  _BYTE *v3; // r0
  _DWORD *v4; // r3
  _DWORD *v5; // r3
  _DWORD *v6; // r3

  v2 = 0;
  v3 = (_BYTE *)ExAllocatePoolWithTag(1, 108, 1466986064);
  *a1 = v3;
  if ( !v3 )
    return -1073741670;
  memset(v3, 0, 108);
  v4 = (_DWORD *)*a1;
  __dmb(0xBu);
  *v4 = 1;
  v5 = (_DWORD *)(*a1 + 68);
  *v5 = v5;
  v5[1] = v5;
  v6 = (_DWORD *)(*a1 + 100);
  *v6 = v6;
  v6[1] = v6;
  return v2;
}
