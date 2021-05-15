// PiSwDeviceFree 
 
_DWORD *__fastcall PiSwDeviceFree(_DWORD *a1)
{
  unsigned int v2; // r0
  int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r1
  _DWORD *v6; // r4
  _DWORD *result; // r0
  __int64 v8; // r2

  PiSwInstanceInfoFree(a1 + 2);
  PiSwPnPInfoFree(a1 + 4);
  v2 = a1[11];
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    a1[10] = 0;
    a1[11] = 0;
  }
  v3 = a1[12];
  if ( v3 )
  {
    PiSwQueuedCreateInfoFree(v3);
    a1[12] = 0;
  }
  v4 = a1[20];
  if ( v4 )
  {
    ExFreePoolWithTag(v4);
    a1[20] = 0;
  }
  v5 = a1[22];
  if ( v5 )
  {
    PnpFreeDevPropertyArray(a1[23], v5);
    a1[22] = 0;
    a1[23] = 0;
  }
  PiSwFreeInterfaceList(a1 + 25);
  v6 = a1 + 17;
  while ( 1 )
  {
    result = (_DWORD *)*v6;
    if ( (_DWORD *)*v6 == v6 )
      break;
    v8 = *(_QWORD *)result;
    if ( (_DWORD *)result[1] != v6 || *(_DWORD **)(v8 + 4) != result )
      __fastfail(3u);
    *v6 = v8;
    *(_DWORD *)(v8 + 4) = v6;
    PiSwPdoAssociationFree();
  }
  return result;
}
