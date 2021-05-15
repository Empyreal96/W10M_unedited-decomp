// PspGetJobAssignmentDisposition 
 
int __fastcall PspGetJobAssignmentDisposition(int a1, int a2, int *a3)
{
  unsigned int *v3; // r9
  unsigned int v7; // r6
  unsigned int v8; // r5
  int v9; // r3
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r3

  v3 = (unsigned int *)(a2 + 172);
  __pld((void *)(a2 + 172));
  v7 = *(_DWORD *)(a2 + 172) & 0xFFFFFFFE;
  do
    v8 = __ldrex(v3);
  while ( v8 == v7 && __strex(v7 + 2, v3) );
  __dmb(0xBu);
  if ( v8 != v7 )
    return sub_7C2298();
  v9 = *(_DWORD *)(a2 + 288);
  __dmb(0xBu);
  if ( !v9 )
  {
    *a3 = 1;
    v10 = 0;
    goto LABEL_7;
  }
  if ( PspIsProcessInJob(a2, a1) == 292 )
  {
    v16 = 2;
    goto LABEL_20;
  }
  v14 = *(_DWORD *)(a2 + 288);
  __dmb(0xBu);
  v15 = a1;
  if ( a1 )
  {
    while ( v15 != v14 )
    {
      v15 = *(_DWORD *)(v15 + 572);
      if ( !v15 )
        goto LABEL_17;
    }
    v16 = 3;
    goto LABEL_20;
  }
LABEL_17:
  if ( !*(_DWORD *)(a1 + 572) && !*(_DWORD *)(a1 + 140) )
  {
    v16 = 4;
LABEL_20:
    *a3 = v16;
    v10 = 0;
    goto LABEL_7;
  }
  v10 = -1073741637;
LABEL_7:
  __pld(v3);
  v11 = *v3 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v12 = __ldrex(v3);
  while ( v12 == v11 && __strex(v11 - 2, v3) );
  if ( v12 != v11 )
    ExfReleaseRundownProtection((unsigned __int8 *)v3);
  return v10;
}
