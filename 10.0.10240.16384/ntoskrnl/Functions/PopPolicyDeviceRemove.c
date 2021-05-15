// PopPolicyDeviceRemove 
 
_DWORD *__fastcall PopPolicyDeviceRemove(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r2
  _DWORD *v3; // r1

  v1 = result;
  v2 = *result;
  if ( *result )
  {
    v3 = (_DWORD *)result[1];
    if ( *(_DWORD **)(v2 + 4) != result || (_DWORD *)*v3 != result )
      __fastfail(3u);
    *v3 = v2;
    *(_DWORD *)(v2 + 4) = v3;
    *result = 0;
    PopPolicyDeviceParameters[5 * result[2] + 4]();
    IoFreeIrp(v1[7]);
    result = (_DWORD *)ObfDereferenceObject(v1[6]);
  }
  return result;
}
