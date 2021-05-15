// PfSnCleanupTrace 
 
unsigned __int8 *__fastcall PfSnCleanupTrace(int a1)
{
  unsigned __int8 *result; // r0
  unsigned int v3; // r0
  __int64 **v4; // r5
  unsigned int v5; // r0
  unsigned int v6; // r4
  __int64 *v7; // r0
  __int64 v8; // r2

  if ( *(_DWORD *)(a1 + 364) )
    return (unsigned __int8 *)sub_808E78();
  *(_DWORD *)(a1 + 364) = 0;
  *(_DWORD *)(a1 + 368) = 0;
  v3 = *(_DWORD *)(a1 + 400);
  if ( v3 )
    ExFreePoolWithTag(v3);
  v4 = (__int64 **)(a1 + 84);
  while ( *v4 != (__int64 *)v4 )
  {
    v7 = *v4;
    v8 = **v4;
    if ( (__int64 **)HIDWORD(v8) != v4 || *(__int64 **)(v8 + 4) != v7 )
      __fastfail(3u);
    *v4 = (__int64 *)v8;
    *(_DWORD *)(v8 + 4) = v4;
    --*(_DWORD *)(a1 + 92);
    ExFreePoolWithTag((unsigned int)v7);
  }
  v5 = *(_DWORD *)(a1 + 336);
  if ( v5 )
    ExFreePoolWithTag(v5);
  result = *(unsigned __int8 **)(a1 + 264);
  if ( result )
    result = (unsigned __int8 *)ObfDereferenceObjectWithTag((int)result);
  if ( (*(_WORD *)(a1 + 346) & 2) != 0 )
  {
    __pld(dword_63734C);
    v6 = dword_63734C[0] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      result = (unsigned __int8 *)__ldrex(dword_63734C);
    while ( result == (unsigned __int8 *)v6 && __strex(v6 - 2, dword_63734C) );
    if ( result != (unsigned __int8 *)v6 )
      result = ExfReleaseRundownProtection((unsigned __int8 *)dword_63734C);
  }
  return result;
}
