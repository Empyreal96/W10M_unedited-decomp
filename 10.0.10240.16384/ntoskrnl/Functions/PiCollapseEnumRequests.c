// PiCollapseEnumRequests 
 
int __fastcall PiCollapseEnumRequests(_DWORD *a1)
{
  int v2; // r9
  unsigned int v4; // r2
  _DWORD *v5; // r7
  int v6; // r2
  _DWORD *i; // r4
  int *v8; // r1
  int v9; // r3
  int **v10; // r0
  int *v11; // r0

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51FDE8();
  do
    v4 = __ldrex((unsigned int *)&PnpSpinLock);
  while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  v5 = (_DWORD *)a1[1];
  v6 = PnpEnumerationRequestList;
  if ( (int *)PnpEnumerationRequestList != &PnpEnumerationRequestList )
  {
    do
    {
      v8 = *(int **)v6;
      if ( *(_BYTE *)(v6 + 16) )
        break;
      v9 = *(_DWORD *)(v6 + 12);
      if ( v9 >= 9 && (v9 <= 10 || v9 == 14) )
      {
        v10 = *(int ***)(v6 + 4);
        if ( v8[1] != v6 || *v10 != (int *)v6 )
          __fastfail(3u);
        *v10 = v8;
        v8[1] = (int)v10;
        v11 = (int *)a1[1];
        *(_DWORD *)v6 = a1;
        *(_DWORD *)(v6 + 4) = v11;
        if ( (_DWORD *)*v11 != a1 )
          __fastfail(3u);
        *v11 = v6;
        a1[1] = v6;
      }
      v6 = (int)v8;
    }
    while ( v8 != &PnpEnumerationRequestList );
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  KfLowerIrql(v2);
  for ( i = (_DWORD *)*v5; i != a1; i = (_DWORD *)*i )
  {
    PiMarkDeviceTreeForReenumeration(*(_DWORD *)(*(_DWORD *)(i[2] + 176) + 20), 1);
    ObfDereferenceObjectWithTag(i[2]);
    i[2] = 0;
  }
  return v5 != (_DWORD *)a1[1];
}
