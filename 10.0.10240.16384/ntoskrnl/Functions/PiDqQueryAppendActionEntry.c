// PiDqQueryAppendActionEntry 
 
int __fastcall PiDqQueryAppendActionEntry(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // r2
  int result; // r0
  unsigned int v5; // r3
  int v6; // r0

  v2 = a1 + 25;
  result = a1[26];
  *a2 = v2;
  a2[1] = result;
  if ( *(_DWORD **)result != v2 )
    sub_7C750C();
  *(_DWORD *)result = a2;
  v2[1] = a2;
  v5 = a1[27] + 1;
  a1[27] = v5;
  if ( v5 > 0x3E8 )
  {
    v6 = PiDqGetPnpObjectType(*(_DWORD *)(a1[3] + 16));
    result = PiDmGetObjectCount(v6);
    if ( a1[27] > (unsigned int)(2 * result) )
    {
      a1[29] |= 1u;
      result = PiDqQueryFreeActiveData(a1);
    }
  }
  return result;
}
