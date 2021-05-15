// MmAssignProcessToJob 
 
int __fastcall MmAssignProcessToJob(_DWORD *a1, int a2)
{
  int v4; // r7
  int v5; // r10
  int v6; // r1
  int v7; // r8
  unsigned int *v8; // r2
  unsigned int v9; // r5
  _BYTE v11[56]; // [sp-4h] [bp-38h] BYREF

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD **)(v5 + 0x74) != a1 )
  {
    v4 = 1;
    KiStackAttachProcess((int)a1, 0, (int)v11);
  }
  if ( !MiLockVadRange(a1, -1) )
    return sub_7C1B14();
  LOCK_PAGE_TABLE_COMMITMENT(v5, (int)a1);
  v6 = a1[121];
  a1[67] = a1[72];
  v7 = PspChangeJobMemoryUsageByProcess(20, v6, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a2);
  __dmb(0xBu);
  v8 = a1 + 47;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x10, v8) );
  __dmb(0xBu);
  UNLOCK_PAGE_TABLE_COMMITMENT(v5, (int)a1);
  MiUnlockVadRange(a1, -1);
  if ( v4 )
    KiUnstackDetachProcess((unsigned int)v11, 0);
  return v7;
}
