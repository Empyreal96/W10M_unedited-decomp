// PopPrepChildWake 
 
__int64 *__fastcall PopPrepChildWake(__int64 *result, int a2)
{
  __int64 v2; // kr00_8
  int v3; // r2
  __int64 **v4; // r1

  if ( *((_DWORD *)result + 14) == *((_DWORD *)result + 13) )
  {
    v2 = *result;
    if ( *(__int64 **)(*(_DWORD *)result + 4) != result || *(__int64 **)HIDWORD(v2) != result )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v2) = v2;
    *(_DWORD *)(v2 + 4) = HIDWORD(v2);
    v3 = a2 + 40 * (*((unsigned __int8 *)result + 28) + 1);
    v4 = *(__int64 ***)(v3 + 4);
    *(_DWORD *)result = v3;
    *((_DWORD *)result + 1) = v4;
    if ( *v4 != (__int64 *)v3 )
      __fastfail(3u);
    *v4 = result;
    *(_DWORD *)(v3 + 4) = result;
  }
  --*((_DWORD *)result + 14);
  return result;
}
