// PpmPerfGetCurrentState 
 
_DWORD *__fastcall PpmPerfGetCurrentState(_DWORD *result, _DWORD *a2, unsigned int *a3, _DWORD *a4, int *a5, _DWORD *a6)
{
  _DWORD *v6; // r7
  _DWORD *v7; // r4
  unsigned int v9; // r6
  int v10; // r3

  v6 = (_DWORD *)result[800];
  v7 = (_DWORD *)result[801];
  if ( v6 && v7 )
  {
    v9 = v7[11];
    if ( v9 >= v6[37] )
      v9 = v6[37];
    if ( a2 )
      *a2 = v7[12];
    if ( a3 )
      *a3 = v6[37] * v6[20] / 0x64u;
    if ( a5 )
    {
      if ( v9 < v6[22] )
        v10 = 2;
      else
        v10 = 1;
      *a5 = v10;
    }
    if ( a6 )
    {
      *a6 = v7[6];
      if ( v7[5] < 0x64u )
        return (_DWORD *)sub_5292E4();
    }
  }
  else
  {
    if ( a2 )
      *a2 = result[241];
    if ( a3 )
      *a3 = result[241];
    if ( a5 )
      *a5 = 0;
    if ( a6 )
      *a6 = 0;
  }
  if ( a4 )
  {
    result = (_DWORD *)PpmPerfGetCurrentFrequency();
    *a4 = result;
  }
  return result;
}
