// CmpInitSecurityCache 
 
_DWORD *__fastcall CmpInitSecurityCache(_DWORD *result)
{
  _DWORD *v1; // r3
  int v2; // r2

  result[501] = 0;
  result[499] = 0;
  result[498] = 0;
  result[500] = -1;
  v1 = result + 502;
  v2 = 64;
  do
  {
    *v1 = v1;
    v1[1] = v1;
    v1 += 2;
    --v2;
  }
  while ( v2 );
  return result;
}
