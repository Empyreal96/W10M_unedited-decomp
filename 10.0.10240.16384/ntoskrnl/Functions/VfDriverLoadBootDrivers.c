// VfDriverLoadBootDrivers 
 
int __fastcall VfDriverLoadBootDrivers(int result)
{
  _DWORD *v1; // r5
  _DWORD *v2; // r4

  v1 = (_DWORD *)result;
  v2 = *(_DWORD **)result;
  ViDriverKernelBase = *(_DWORD *)(*(_DWORD *)result + 24);
  ViDriverKernelEnd = v2[8] + ViDriverKernelBase;
  while ( 1 )
  {
    v2 = (_DWORD *)*v2;
    if ( v2 == v1 )
      break;
    result = VfDriverLoadImage((int)v2, 0, 0, 0);
  }
  return result;
}
