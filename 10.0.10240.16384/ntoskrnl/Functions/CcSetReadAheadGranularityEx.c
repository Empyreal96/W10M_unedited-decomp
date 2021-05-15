// CcSetReadAheadGranularityEx 
 
int __fastcall CcSetReadAheadGranularityEx(int result, _DWORD *a2)
{
  _DWORD *v2; // r2
  int v3; // r3
  int v4; // r3

  v2 = *(_DWORD **)(result + 24);
  if ( a2 )
  {
    v2[1] = a2[1] - 1;
    v3 = a2[2];
    if ( v3 )
    {
      v2[21] = v3;
      *v2 |= 0x200000u;
    }
    result = 0x800000;
    if ( v2[21] > 0x800000u )
      v2[21] = 0x800000;
    v4 = a2[3];
    if ( !v4 )
      v4 = 50;
    v2[22] = v4;
  }
  return result;
}
