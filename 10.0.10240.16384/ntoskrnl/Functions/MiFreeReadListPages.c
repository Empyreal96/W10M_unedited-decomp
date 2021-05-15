// MiFreeReadListPages 
 
int __fastcall MiFreeReadListPages(int result)
{
  int v1; // r6
  __int16 *v2; // r5
  int v3; // r4
  _DWORD *v4; // r0

  v1 = result;
  v2 = 0;
  v3 = 0;
  if ( *(_DWORD *)(result + 20) )
  {
    do
    {
      v4 = *(_DWORD **)(v1 + 20);
      *(_DWORD *)(v1 + 20) = *v4;
      if ( !v2 )
        v2 = MiSystemPartition;
      result = MiReleaseFreshPage((int)v4);
      ++v3;
    }
    while ( *(_DWORD *)(v1 + 20) );
    if ( v3 )
      result = MiReturnFaultCharges(v2, v3, 1);
  }
  return result;
}
