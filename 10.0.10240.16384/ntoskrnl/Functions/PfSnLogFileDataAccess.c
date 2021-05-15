// PfSnLogFileDataAccess 
 
unsigned __int8 *__fastcall PfSnLogFileDataAccess(int a1, int *a2, int a3, int a4, unsigned int a5, unsigned int *a6, int a7)
{
  unsigned __int8 *result; // r0
  int v11; // r4
  int v12; // r5
  unsigned int v13; // r3
  bool v14; // cf
  __int64 v16; // r6
  unsigned int v17; // r4
  unsigned int v18; // r1

  result = (unsigned __int8 *)PfSnReferenceProcessTrace(*(_DWORD *)(a3 + 336));
  v11 = (int)result;
  if ( result )
  {
    if ( PfSnCheckLoggingForThread(a3, result, 0) )
    {
      v12 = a7;
      v13 = a5 & 0xFFF;
      v14 = a5 >= v13;
      LODWORD(v16) = a5 - v13;
      for ( HIDWORD(v16) = (char *)a6 - !v14; v12; v16 += 4096i64 )
      {
        if ( PfSnLogPageFaultCommon(v11, a1, a2, a6, v16, 0) < 0 )
          break;
        --v12;
      }
    }
    result = (unsigned __int8 *)(v11 + 268);
    __pld((void *)(v11 + 268));
    v17 = *(_DWORD *)(v11 + 268) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)result);
    while ( v18 == v17 && __strex(v17 - 2, (unsigned int *)result) );
    if ( v18 != v17 )
      result = ExfReleaseRundownProtection(result);
  }
  return result;
}
