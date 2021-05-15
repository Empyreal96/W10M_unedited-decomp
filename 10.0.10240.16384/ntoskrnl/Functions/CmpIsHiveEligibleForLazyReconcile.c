// CmpIsHiveEligibleForLazyReconcile 
 
int __fastcall CmpIsHiveEligibleForLazyReconcile(int a1)
{
  int result; // r0
  int v3; // r3
  __int64 v4; // kr00_8
  unsigned int v5; // r8
  unsigned int v6; // r9

  if ( !*(_DWORD *)(a1 + 60) )
    goto LABEL_2;
  v3 = CmpHoldLazyFlush;
  __dmb(0xBu);
  if ( v3 )
    goto LABEL_2;
  if ( !CmpUserPresent
    || *(_DWORD *)(a1 + 108) >= (unsigned int)HvGetEffectiveLogSizeCapForHive(a1)
    || !HvCountFreeLogsLockFree(a1) )
  {
    goto LABEL_11;
  }
  do
  {
    v4 = MEMORY[0xFFFF93B0];
    v5 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v6 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v5 != MEMORY[0xFFFF9010] )
      return sub_7D3A18();
  }
  while ( v4 != MEMORY[0xFFFF93B0] );
  if ( __PAIR64__(v5, v6) - v4 < (unsigned int)dword_60E320 * (unsigned __int64)(unsigned int)dword_989680
                               + *(_QWORD *)(a1 + 3248) )
LABEL_2:
    result = 0;
  else
LABEL_11:
    result = 1;
  return result;
}
