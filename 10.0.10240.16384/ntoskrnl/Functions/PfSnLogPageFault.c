// PfSnLogPageFault 
 
int __fastcall PfSnLogPageFault(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v9; // r7
  int v10; // r0
  int v11; // r5
  unsigned int *v12; // r3
  unsigned int *v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  int v16; // [sp+0h] [bp-28h]

  v16 = a1;
  if ( (a5 & 4) == 0 || !*(_DWORD *)(a1 + 16) )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = PfSnReferenceProcessTrace(*(_DWORD *)(v9 + 0x74));
    v11 = v10;
    if ( v10 )
    {
      if ( PfSnCheckLoggingForThread(v9, v10, a5) )
        PfSnLogPageFaultCommon(v11, a1, *(int **)(a1 + 12), v12, __SPAIR64__(a4, a3), a5);
      v13 = (unsigned int *)(v11 + 268);
      __pld((void *)(v11 + 268));
      v14 = *(_DWORD *)(v11 + 268) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v15 = __ldrex(v13);
      while ( v15 == v14 && __strex(v14 - 2, v13) );
      if ( v15 != v14 )
        ExfReleaseRundownProtection((unsigned __int8 *)v13);
    }
  }
  return v16;
}
