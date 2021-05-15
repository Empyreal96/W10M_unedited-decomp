// PfFbLogEntryReserve 
 
int __fastcall PfFbLogEntryReserve(unsigned __int64 *a1, _DWORD *a2, _DWORD *a3, int a4)
{
  unsigned int v7; // r7
  unsigned int v8; // r6
  int v9; // r4
  _DWORD *v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1

  while ( 2 )
  {
    __pld(a1);
    v7 = *(_DWORD *)a1 & 0xFFFFFFFE;
    do
      v8 = __ldrex((unsigned int *)a1);
    while ( v8 == v7 && __strex(v7 + 2, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v8 != v7 && !ExfAcquireRundownProtection(a1) )
      return -1073741431;
    while ( 1 )
    {
      v10 = (_DWORD *)RtlpInterlockedPopEntrySList(a1 + 2);
      if ( v10 )
        break;
      v10 = (_DWORD *)RtlpInterlockedPopEntrySList(a1 + 1);
      if ( v10 )
        break;
      v9 = (*((int (__fastcall **)(unsigned __int64 *))a1 + 14))(a1);
      if ( v9 < 0 )
        goto LABEL_14;
    }
    if ( a4 <= v10[3] - v10[2] )
    {
      v9 = 0;
      *a3 = v10[2];
      *a2 = v10;
      return v9;
    }
    if ( v10[4] )
    {
      (*((void (__fastcall **)(_DWORD *))a1 + 15))(v10);
      continue;
    }
    break;
  }
  RtlpInterlockedPushEntrySList(a1 + 1, v10);
  v9 = -1073741789;
LABEL_14:
  ++*((_DWORD *)a1 + 17);
  *((_DWORD *)a1 + 18) += a4;
  __pld(a1);
  v11 = *(_DWORD *)a1 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)a1);
  while ( v12 == v11 && __strex(v11 - 2, (unsigned int *)a1) );
  if ( v12 != v11 )
    ExfReleaseRundownProtection((unsigned __int8 *)a1);
  return v9;
}
