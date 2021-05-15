// -SmStUnmapVirtualRegion@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@KKKPAXK@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  int v6; // r3
  int result; // r0
  unsigned __int16 *v9; // r5
  _DWORD *v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned __int16 v13; // r2

  v6 = a1[915];
  result = a1[913];
  v9 = (unsigned __int16 *)(v6 + 4 * a2);
  if ( (a6 & 4) != 0 )
  {
    v10 = (_DWORD *)SMKM_STORE<SM_TRAITS>::SmStFindVirtualLockedRegion(
                      (int)a1,
                      (a6 >> 3) & 7,
                      *(_DWORD *)v9 & 0x7FFF0000);
    SmKmUnlockMdl(*v10, a1[952], a1 + 935);
    result = SmFpFree(a1[952], 2, a1 + 935, *v10);
    *v10 = 0;
    *(_DWORD *)v9 &= 0x7FFFFFFFu;
    return result;
  }
  if ( (a6 & 2) != 0 )
  {
    __dmb(0xBu);
    do
      result = __ldrex(v9);
    while ( __strex(result & 0x7FFF, v9) );
LABEL_6:
    __dmb(0xBu);
    return result;
  }
  if ( (a6 & 1) == 0 )
  {
    if ( (*v9 & 0x2000) != 0 && (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) == a1[953] )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( __strex(v11 & 0xDFFF, v9) );
      goto LABEL_6;
    }
    __dmb(0xBu);
    do
    {
      v12 = __ldrex(v9);
      v13 = v12 - 1;
    }
    while ( __strex(v13, v9) );
    __dmb(0xBu);
    if ( (v13 & 0x1FFF) == 0 )
      result = SmAcquireReleaseCharges(result, 1, 1);
  }
  return result;
}
