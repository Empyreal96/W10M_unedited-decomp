// PiCollapseRebalanceRequests 
 
BOOL __fastcall PiCollapseRebalanceRequests(_DWORD *a1)
{
  int v2; // r9
  unsigned int v3; // r2
  _DWORD *v4; // r7
  int v5; // r2
  int *v6; // r1
  int **v7; // r0
  int *v8; // r0
  _DWORD *i; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PnpSpinLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&PnpSpinLock);
    while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  }
  v4 = (_DWORD *)a1[1];
  v5 = PnpEnumerationRequestList;
  if ( (int *)PnpEnumerationRequestList != &PnpEnumerationRequestList )
  {
    do
    {
      v6 = *(int **)v5;
      if ( *(_BYTE *)(v5 + 16) )
        break;
      if ( *(_DWORD *)(v5 + 12) == 6 && *(_BYTE *)(v5 + 20) )
      {
        v7 = *(int ***)(v5 + 4);
        if ( v6[1] != v5 || *v7 != (int *)v5 )
          __fastfail(3u);
        *v7 = v6;
        v6[1] = (int)v7;
        v8 = (int *)a1[1];
        *(_DWORD *)v5 = a1;
        *(_DWORD *)(v5 + 4) = v8;
        if ( (_DWORD *)*v8 != a1 )
          __fastfail(3u);
        *v8 = v5;
        a1[1] = v5;
      }
      v5 = (int)v6;
    }
    while ( v6 != &PnpEnumerationRequestList );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  KfLowerIrql(v2);
  for ( i = (_DWORD *)*v4; i != a1; i = (_DWORD *)*i )
  {
    ObfDereferenceObjectWithTag(i[2]);
    i[2] = 0;
  }
  return v4 != (_DWORD *)a1[1];
}
