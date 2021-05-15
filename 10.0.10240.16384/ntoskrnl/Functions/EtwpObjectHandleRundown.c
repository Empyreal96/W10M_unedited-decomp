// EtwpObjectHandleRundown 
 
unsigned __int8 *__fastcall EtwpObjectHandleRundown(int a1, int a2)
{
  unsigned __int8 *result; // r0
  unsigned __int8 *v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r1

  result = (unsigned __int8 *)ObReferenceProcessHandleTable(a1);
  v5 = result;
  if ( result )
  {
    *(_DWORD *)(a2 + 24) = PsGetProcessId(a1);
    *(_BYTE *)(a2 + 40) = PsIsSystemProcess(a1);
    ExEnumHandleTable(v5, EtwpObjectHandleEnumCallback, a2, 0);
    result = (unsigned __int8 *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v6 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)result);
    while ( v7 == v6 && __strex(v6 - 2, (unsigned int *)result) );
    if ( v7 != v6 )
      result = ExfReleaseRundownProtection(result);
  }
  return result;
}
