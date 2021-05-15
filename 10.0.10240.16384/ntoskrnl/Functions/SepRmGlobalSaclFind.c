// SepRmGlobalSaclFind 
 
int __fastcall SepRmGlobalSaclFind(int *a1, int *a2, unsigned __int16 *a3, int a4)
{
  int v5; // r7
  int v6; // r1
  int v9; // r9
  unsigned int v10; // r4
  _DWORD *i; // r3
  int v12; // r4
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v5 = -1073741772;
  v6 = SepRmGlobalSaclHead;
  v9 = 0;
  if ( SepRmGlobalSaclHead )
  {
    if ( a4 )
    {
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v10 + 308);
      ExAcquireResourceSharedLite((int)&SepRmGlobalSaclLock, 1);
      v6 = SepRmGlobalSaclHead;
      v9 = 1;
    }
    *a1 = v6;
    if ( a2 )
      *a2 = 0;
    for ( i = (_DWORD *)*a1; i; *a1 = (int)i )
    {
      v12 = *a1;
      if ( !RtlCompareUnicodeString(a3, (unsigned __int16 *)(*a1 + 4), 0) )
      {
        v5 = 0;
        goto LABEL_14;
      }
      if ( a2 )
        *a2 = v12;
      i = *(_DWORD **)*a1;
    }
    if ( a2 )
      *a2 = 0;
LABEL_14:
    if ( v9 )
    {
      v13 = ExReleaseResourceLite((int)&SepRmGlobalSaclLock);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = *(_WORD *)(v14 + 0x134) + 1;
      *(_WORD *)(v14 + 308) = v15;
      if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
        KiCheckForKernelApcDelivery(v13);
    }
  }
  return v5;
}
