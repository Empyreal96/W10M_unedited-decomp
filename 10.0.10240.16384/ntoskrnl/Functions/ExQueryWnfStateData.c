// ExQueryWnfStateData 
 
int __fastcall ExQueryWnfStateData(int a1, _DWORD *a2, int a3, unsigned int *a4)
{
  unsigned int v7; // r4
  unsigned __int8 *v8; // r0
  unsigned __int8 *v9; // r4
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r1
  __int16 v14; // r3

  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = (unsigned __int8 *)ExpWnfAcquireSubscriptionNameInstance(PsInitialSystemProcess, a1);
  v9 = v8;
  if ( v8 )
  {
    v10 = ExpWnfReadStateData((int)v8, a2, a3, *a4, a4);
    if ( v10 >= 0 )
      v10 = 0;
    v8 = v9 + 4;
    __pld(v9 + 4);
    v11 = *((_DWORD *)v9 + 1) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)v8);
    while ( v12 == v11 && __strex(v11 - 2, (unsigned int *)v8) );
    if ( v12 != v11 )
      v8 = ExfReleaseRundownProtection(v8);
  }
  else
  {
    v10 = -1073741772;
  }
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery((int)v8);
  return v10;
}
