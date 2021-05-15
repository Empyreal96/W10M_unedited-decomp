// IopFreePoDeviceNotifyListHead 
 
unsigned int __fastcall IopFreePoDeviceNotifyListHead(unsigned int result)
{
  _DWORD *v1; // r5
  _DWORD *v2; // r4
  __int64 v3; // r2
  unsigned int v4; // r0

  v1 = (_DWORD *)result;
  while ( 1 )
  {
    v2 = (_DWORD *)*v1;
    if ( (_DWORD *)*v1 == v1 )
      break;
    v3 = *(_QWORD *)v2;
    if ( (_DWORD *)v2[1] != v1 || *(_DWORD **)(v3 + 4) != v2 )
      __fastfail(3u);
    *v1 = v3;
    *(_DWORD *)(v3 + 4) = v1;
    ObfDereferenceObject(v2[8]);
    ObfDereferenceObject(v2[6]);
    v4 = v2[9];
    if ( v4 )
      ExFreePoolWithTag(v4);
    result = v2[10];
    if ( result )
      result = ExFreePoolWithTag(result);
  }
  return result;
}
