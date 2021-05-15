// ObpReferenceObjectByHandle 
 
int __fastcall ObpReferenceObjectByHandle(int a1, int a2, int a3, unsigned int **a4)
{
  unsigned __int64 *v8; // r0
  unsigned __int64 *v9; // r5
  int v10; // r0
  unsigned int *v12; // r4
  int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r0
  unsigned int *v17; // r4
  int v18; // r0
  int v19; // r1
  unsigned int v20; // r1

  if ( (a2 & 0x7FC) == 0 || (v8 = (unsigned __int64 *)ExpLookupHandleTableEntry(a1, a2), (v9 = v8) == 0) )
  {
LABEL_23:
    if ( a2 )
      ExHandleLogBadReference(a1, a2, *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A));
    return 0;
  }
  v10 = ExFastReferenceHandleTableEntry(a1, v8, (unsigned __int64 *)a3);
  if ( !v10 )
  {
    *a4 = (unsigned int *)(*(_DWORD *)a3 & 0xFFFFFFF8);
    return (int)v9;
  }
  if ( v10 <= 0 )
  {
    do
    {
      while ( 1 )
      {
        __pld(v9);
        v14 = *(_DWORD *)v9;
        if ( (*(_DWORD *)v9 & 1) != 0 )
          break;
        if ( !v14 )
          goto LABEL_23;
        ExpBlockOnLockedHandleEntry(a1, v9, *(_DWORD *)v9);
      }
      do
        v15 = __ldrex((unsigned int *)v9);
      while ( v15 == v14 && __strex(v14 - 1, (unsigned int *)v9) );
      __dmb(0xBu);
    }
    while ( v15 != v14 );
    *a4 = (unsigned int *)(*(_DWORD *)v9 & 0xFFFFFFF8);
    *(_DWORD *)a3 = *(_DWORD *)v9;
    *(_DWORD *)(a3 + 4) = *((_DWORD *)v9 + 1);
    v16 = ExSlowReplenishHandleTableEntry((int)v9);
    v17 = *a4;
    v18 = v16 + 1;
    do
      v19 = __ldrex(v17);
    while ( __strex(v19 + v18, v17) );
    __dmb(0xBu);
    if ( v19 <= 0 )
      KeBugCheckEx(24, 0, (int)(v17 + 6), 16, v19 + v18);
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v9);
    while ( __strex(v20 + 1, (unsigned int *)v9) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(a1 + 32) )
      ExfUnblockPushLock(a1 + 32, 0);
    return (int)v9;
  }
  v12 = (unsigned int *)(*(_DWORD *)a3 & 0xFFFFFFF8);
  *a4 = v12;
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 + v10, v12) );
  __dmb(0xBu);
  if ( v13 <= 0 )
    KeBugCheckEx(24, 0, (int)(v12 + 6), 16, v13 + v10);
  if ( !ExFastReplenishHandleTableEntry(v9, (unsigned int *)a3, v10) )
    return (int)v9;
  return sub_7FA448();
}
