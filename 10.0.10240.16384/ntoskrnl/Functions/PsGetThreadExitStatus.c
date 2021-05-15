// PsGetThreadExitStatus 
 
int __fastcall PsGetThreadExitStatus(int a1)
{
  unsigned int *v1; // r5
  unsigned int v3; // r4
  unsigned int v4; // r1
  unsigned int v6; // r4
  unsigned int v7; // r1

  v1 = (unsigned int *)(a1 + 940);
  __pld((void *)(a1 + 940));
  v3 = *(_DWORD *)(a1 + 940) & 0xFFFFFFFE;
  do
    v4 = __ldrex(v1);
  while ( v4 == v3 && __strex(v3 + 2, v1) );
  __dmb(0xBu);
  if ( v4 != v3 && !ExfAcquireRundownProtection((_DWORD *)(a1 + 940)) )
    return *(_DWORD *)(a1 + 984);
  __pld(v1);
  v6 = *v1 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v7 = __ldrex(v1);
  while ( v7 == v6 && __strex(v6 - 2, v1) );
  if ( v7 != v6 )
    ExfReleaseRundownProtection((unsigned __int8 *)v1);
  return 259;
}
