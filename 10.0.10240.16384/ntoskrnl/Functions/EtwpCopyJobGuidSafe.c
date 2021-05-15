// EtwpCopyJobGuidSafe 
 
_DWORD *__fastcall EtwpCopyJobGuidSafe(_DWORD *result, _DWORD *a2)
{
  int v2; // r2
  int v3; // r3
  int v4; // r4

  if ( a2 )
  {
    v2 = a2[177];
    v3 = a2[178];
    v4 = a2[179];
    *result = a2[176];
    result[1] = v2;
    result[2] = v3;
    result[3] = v4;
    result += 4;
  }
  else
  {
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
  }
  return result;
}
