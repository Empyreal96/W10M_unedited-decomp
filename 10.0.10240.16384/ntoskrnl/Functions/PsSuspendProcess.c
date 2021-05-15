// PsSuspendProcess 
 
int __fastcall PsSuspendProcess(int a1)
{
  unsigned int v2; // r5
  unsigned int *v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r1
  unsigned __int8 *i; // r1
  unsigned __int8 *v8; // r0
  unsigned __int8 *v9; // r4
  unsigned int v10; // r4
  unsigned int v11; // r1
  __int16 v12; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 0x134);
  v3 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v4 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  do
    v5 = __ldrex(v3);
  while ( v5 == v4 && __strex(v4 + 2, v3) );
  __dmb(0xBu);
  if ( v5 != v4 )
    return sub_7E697C();
  for ( i = 0; ; i = v9 )
  {
    v8 = (unsigned __int8 *)PsGetNextProcessThread(a1, i);
    v9 = v8;
    if ( !v8 )
      break;
    PsSuspendThread(v8, 0);
  }
  __pld(v3);
  v10 = *v3 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v11 = __ldrex(v3);
  while ( v11 == v10 && __strex(v10 - 2, v3) );
  if ( v11 != v10 )
    v8 = ExfReleaseRundownProtection((unsigned __int8 *)v3);
  v12 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery((int)v8);
  return 0;
}
