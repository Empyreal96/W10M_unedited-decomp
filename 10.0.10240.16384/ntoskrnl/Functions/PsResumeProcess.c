// PsResumeProcess 
 
int __fastcall PsResumeProcess(int a1)
{
  unsigned int v2; // r5
  unsigned int *v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r4
  int i; // r1
  int v9; // r4
  unsigned int v10; // r4
  unsigned int v11; // r1
  __int16 v13; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 0x134);
  v3 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v4 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  do
    v5 = __ldrex(v3);
  while ( v5 == v4 && __strex(v4 + 2, v3) );
  __dmb(0xBu);
  if ( v5 == v4 || (v6 = ExfAcquireRundownProtection((_DWORD *)(a1 + 172)), v6 == 1) )
  {
    for ( i = 0; ; i = v9 )
    {
      v6 = PsGetNextProcessThread(a1, i);
      v9 = v6;
      if ( !v6 )
        break;
      KeResumeThread(v6);
    }
    __pld(v3);
    v10 = *v3 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v11 = __ldrex(v3);
    while ( v11 == v10 && __strex(v10 - 2, v3) );
    if ( v11 != v10 )
      return sub_7EB094();
    v7 = 0;
  }
  else
  {
    v7 = -1073741558;
  }
  v13 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v6);
  return v7;
}
