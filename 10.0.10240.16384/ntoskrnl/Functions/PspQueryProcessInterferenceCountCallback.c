// PspQueryProcessInterferenceCountCallback 
 
int __fastcall PspQueryProcessInterferenceCountCallback(int a1, int a2, int a3, int a4)
{
  int v6; // r6
  unsigned int *v7; // r7
  unsigned int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r5
  unsigned int v11; // r4
  unsigned int v13; // [sp+0h] [bp-28h] BYREF
  unsigned int v14; // [sp+4h] [bp-24h] BYREF
  int v15; // [sp+8h] [bp-20h] BYREF
  unsigned int *v16; // [sp+Ch] [bp-1Ch]

  v13 = a1;
  v14 = a2;
  v15 = a3;
  v16 = (unsigned int *)a4;
  if ( (*(_DWORD *)(a1 + 188) & 1) != 0 || !ObReferenceObjectSafeWithTag(a1) )
    return 0;
  v7 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v8 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  do
    v9 = __ldrex(v7);
  while ( v9 == v8 && __strex(v8 + 2, v7) );
  __dmb(0xBu);
  if ( v9 == v8 || ExfAcquireRundownProtection((_DWORD *)(a1 + 172)) )
  {
    v6 = 0;
    v13 = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 232);
    if ( v13 <= 0xFFFFFFFD )
    {
      v15 = a1;
      v16 = &v14;
      v6 = PsInvokeWin32Callout(24, (int)&v15, 1, (int *)&v13);
      if ( v6 >= 0 )
        *(_QWORD *)*(_DWORD *)a2 += v14;
    }
    __pld(v7);
    v10 = *v7 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v11 = __ldrex(v7);
    while ( v11 == v10 && __strex(v10 - 2, v7) );
    if ( v11 != v10 )
      ExfReleaseRundownProtection((unsigned __int8 *)(a1 + 172));
  }
  else
  {
    v6 = 0;
  }
  ObfDereferenceObjectWithTag(a1);
  return v6;
}
