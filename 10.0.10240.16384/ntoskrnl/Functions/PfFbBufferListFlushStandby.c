// PfFbBufferListFlushStandby 
 
int __fastcall PfFbBufferListFlushStandby(unsigned __int64 *a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1
  int result; // r0
  _DWORD *v6; // r7
  unsigned int v7; // r1
  _DWORD *v8; // r8
  unsigned int v9; // r5
  unsigned int v10; // r4

  __pld(a1);
  v2 = *(_DWORD *)a1 & 0xFFFFFFFE;
  v3 = v2 + 2;
  do
    v4 = __ldrex((unsigned int *)a1);
  while ( v4 == v2 && __strex(v3, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( v4 != v2 )
    return sub_54B76C(a1, v4, v3);
  v6 = (_DWORD *)RtlpInterlockedFlushSList(a1 + 2);
  while ( 1 )
  {
    __pld(a1);
    if ( !v6 )
      break;
    v8 = v6;
    v6 = (_DWORD *)*v6;
    v9 = *(_DWORD *)a1 & 0xFFFFFFFE;
    do
      v10 = __ldrex((unsigned int *)a1);
    while ( v10 == v9 && __strex(v9 + 2, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v10 == v9 || ExfAcquireRundownProtection(a1) )
      (*((void (__fastcall **)(_DWORD *))a1 + 15))(v8);
    else
      PfFbBufferListInsertInFree(a1, v8, v8[3] - (_DWORD)v8, v8[5]);
  }
  result = *(_DWORD *)a1 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)a1);
  while ( v7 == result && __strex(result - 2, (unsigned int *)a1) );
  if ( v7 != result )
    result = (int)ExfReleaseRundownProtection((unsigned __int8 *)a1);
  return result;
}
