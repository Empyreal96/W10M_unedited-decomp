// PsSuspendThread 
 
int __fastcall PsSuspendThread(int a1, int *a2)
{
  int *v2; // r10
  int v3; // r9
  int v4; // r8
  unsigned int v5; // r6
  _DWORD *v6; // r0
  unsigned int v7; // r5
  unsigned int v8; // r4
  unsigned __int8 *v9; // r0
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r1
  __int16 v13; // r3

  v2 = a2;
  v3 = a1;
  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 0x134);
  v6 = (_DWORD *)(a1 + 940);
  __pld(v6);
  v7 = *v6 & 0xFFFFFFFE;
  do
    v8 = __ldrex(v6);
  while ( v8 == v7 && __strex(v7 + 2, v6) );
  __dmb(0xBu);
  if ( v8 == v7 || (v9 = (unsigned __int8 *)ExfAcquireRundownProtection(v6)) != 0 )
  {
    if ( (*(_DWORD *)(v3 + 960) & 1) != 0 )
    {
      v10 = -1073741749;
    }
    else
    {
      v4 = KeSuspendThread(v3);
      v10 = 0;
    }
    v9 = (unsigned __int8 *)(v3 + 940);
    __pld((void *)(v3 + 940));
    v11 = *(_DWORD *)(v3 + 940) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v9);
    while ( v12 == v11 && __strex(v11 - 2, (unsigned int *)v9) );
    if ( v12 != v11 )
      v9 = ExfReleaseRundownProtection(v9);
  }
  else
  {
    v10 = -1073741749;
  }
  v13 = *(_WORD *)(v5 + 308) + 1;
  *(_WORD *)(v5 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v5 + 100) != v5 + 100 && !*(_WORD *)(v5 + 310) )
    KiCheckForKernelApcDelivery((int)v9);
  if ( v2 )
    *v2 = v4;
  return v10;
}
