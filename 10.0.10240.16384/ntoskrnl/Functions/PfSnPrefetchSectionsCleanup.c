// PfSnPrefetchSectionsCleanup 
 
int __fastcall PfSnPrefetchSectionsCleanup(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // r8
  int v5; // r9
  int v9; // r0
  int v10; // r10
  unsigned int v11; // r4
  unsigned int v12; // r2
  unsigned int v13; // r1
  int result; // r0
  unsigned int v15; // r1
  unsigned int v16[16]; // [sp+0h] [bp-40h] BYREF

  v4 = *(_DWORD *)(a1 + 120);
  v5 = a3;
  memset((_BYTE *)v4, 0, 28 * a3);
  memset(v16, 0, 32);
  v16[0] = 0;
  v16[1] = a1;
  v16[5] = a2;
  v16[2] = a4;
  v9 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v10 = v9;
  if ( v5 )
  {
    while ( 1 )
    {
      *(_DWORD *)(v4 + 12) = v4;
      *(_DWORD *)(v4 + 16) = v16;
      *(_DWORD *)(v4 + 8) = PfSnSectionInfoCleanupWorkItem;
      *(_DWORD *)v4 = 0;
      v4 += 28;
      __pld(v16);
      v11 = v16[0] & 0xFFFFFFFE;
      v12 = (v16[0] & 0xFFFFFFFE) + 2;
      do
        v13 = __ldrex(v16);
      while ( v13 == v11 && __strex(v12, v16) );
      __dmb(0xBu);
      if ( v13 != v11 )
        break;
      v9 = ExQueueWorkItem((_DWORD *)(v4 - 28), v10 + 32);
      if ( !--v5 )
        goto LABEL_8;
    }
    result = sub_809010(v9, v13, v12);
  }
  else
  {
LABEL_8:
    result = 1;
    do
      v15 = __ldrex(v16);
    while ( !v15 && __strex(1u, v16) );
    __dmb(0xBu);
    if ( v15 )
    {
      if ( v15 != 1 )
        result = (int)ExfWaitForRundownProtectionRelease(v16, v15);
    }
  }
  return result;
}
