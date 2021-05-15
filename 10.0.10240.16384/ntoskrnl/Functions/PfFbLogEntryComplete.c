// PfFbLogEntryComplete 
 
unsigned __int8 *__fastcall PfFbLogEntryComplete(_DWORD *a1, int a2, int a3)
{
  unsigned __int64 *v3; // r5
  int v4; // r2
  int v5; // r3
  unsigned __int8 *result; // r0
  unsigned int v7; // r4
  unsigned int v8; // r1

  v3 = (unsigned __int64 *)a1[1];
  if ( a3 )
  {
    v4 = a3 + a1[2];
    v5 = a1[4];
    a1[2] = v4;
    a1[4] = v5 + 1;
    if ( a1[3] - v4 < *((_DWORD *)v3 + 12) )
      return (unsigned __int8 *)(*((int (**)(void))v3 + 15))();
  }
  result = (unsigned __int8 *)RtlpInterlockedPushEntrySList(v3 + 2, a1);
  __pld(v3);
  v7 = *(_DWORD *)v3 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)v3);
  while ( v8 == v7 && __strex(v7 - 2, (unsigned int *)v3) );
  if ( v8 != v7 )
    result = ExfReleaseRundownProtection((unsigned __int8 *)v3);
  return result;
}
