// PspReferenceCidTableEntry 
 
int __fastcall PspReferenceCidTableEntry(__int16 a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned __int64 *v5; // r0
  unsigned __int64 *v6; // r4
  int v7; // r0
  int v8; // r8
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r1
  bool v13; // zf
  unsigned int *v14; // r0
  int v15; // r7
  unsigned int v16; // r1
  unsigned int v17; // r6
  int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r8
  unsigned __int64 v21; // [sp+0h] [bp-20h] BYREF
  int v22; // [sp+8h] [bp-18h]

  v21 = __PAIR64__(a3, a2);
  v22 = a4;
  if ( (a1 & 0x7FC) == 0 )
    return 0;
  v5 = (unsigned __int64 *)ExpLookupHandleTableEntry(PspCidTable, a1);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = ExFastReferenceHandleTableEntry(PspCidTable, v5, &v21);
  if ( v7 < 0 )
  {
    if ( v7 != -1 )
      return 0;
    v8 = PspCidTable;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        __pld(v6);
        v10 = *(_DWORD *)v6;
        if ( (*(_DWORD *)v6 & 1) != 0 )
          break;
        if ( !v10 )
          return 0;
        ExpBlockOnLockedHandleEntry(v8, v6, *(_DWORD *)v6);
      }
      do
        v11 = __ldrex((unsigned int *)v6);
      while ( v11 == v10 && __strex(v10 - 1, (unsigned int *)v6) );
      __dmb(0xBu);
    }
    while ( v11 != v10 );
    v20 = *(_DWORD *)v6 & 0xFFFFFFF8;
    if ( (*(_BYTE *)v20 & 0x7F) == a2 )
    {
      if ( a2 == 3 )
        v13 = (*(_DWORD *)(v20 + 192) & 0x400000C) == 0x4000000;
      else
        v13 = (*(_DWORD *)(v20 + 960) & 3) == 2;
      if ( v13 )
        v9 = ExSlowReplenishHandleTableEntry((int)v6);
      v14 = (unsigned int *)(v20 - 24);
      __pld((void *)(v20 - 24));
      v15 = v9 + 1;
      v16 = *(_DWORD *)(v20 - 24);
      if ( v16 )
      {
        while ( 1 )
        {
          do
            v17 = __ldrex(v14);
          while ( v17 == v16 && __strex(v16 + v15, v14) );
          if ( v17 == v16 )
            break;
          v16 = v17;
          if ( !v17 )
            goto LABEL_39;
        }
        if ( ObpTraceFlags )
          ObpPushStackInfo((unsigned int)v14, 1, v15, 1953261124);
        goto LABEL_23;
      }
LABEL_39:
      *((_DWORD *)v6 + 1) &= 0x7FFFFFFu;
    }
    v20 = 0;
LABEL_23:
    v18 = PspCidTable;
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)v6);
    while ( __strex(v19 + 1, (unsigned int *)v6) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(v18 + 32) )
      ExfUnblockPushLock(v18 + 32, 0);
    return v20;
  }
  return sub_7C54F0(v7);
}
