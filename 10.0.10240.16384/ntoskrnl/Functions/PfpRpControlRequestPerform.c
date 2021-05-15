// PfpRpControlRequestPerform 
 
int __fastcall PfpRpControlRequestPerform(int a1, int a2)
{
  unsigned int *v2; // r6
  unsigned int v5; // r5
  unsigned int v6; // r4
  int v7; // r5
  int v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1

  v2 = (unsigned int *)(a1 + 80);
  __pld((void *)(a1 + 80));
  v5 = *(_DWORD *)(a1 + 80) & 0xFFFFFFFE;
  do
    v6 = __ldrex(v2);
  while ( v6 == v5 && __strex(v5 + 2, v2) );
  __dmb(0xBu);
  if ( v6 != v5 && !ExfAcquireRundownProtection((_DWORD *)(a1 + 80)) )
    return -1073741696;
  if ( *(_WORD *)(a2 + 2) )
  {
    if ( *(_WORD *)(a2 + 2) != 1 )
    {
      v7 = -1073741811;
      goto LABEL_13;
    }
    v8 = PfpRpControlRequestReset(a1);
  }
  else
  {
    v8 = PfpRpControlRequestUpdate(a1, a2);
  }
  v7 = v8;
LABEL_13:
  __pld(v2);
  v9 = *v2 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v10 = __ldrex(v2);
  while ( v10 == v9 && __strex(v9 - 2, v2) );
  if ( v10 != v9 )
    ExfReleaseRundownProtection((unsigned __int8 *)v2);
  return v7;
}
