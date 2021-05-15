// KeFlushIoRectangle 
 
int *__fastcall KeFlushIoRectangle(int a1, unsigned int a2, unsigned int a3, int a4, unsigned int a5, char a6)
{
  int *result; // r0
  int v10; // r10
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // r1
  unsigned int v15; // r2
  int v16; // r0
  int v17; // [sp+8h] [bp-48h]
  int v18; // [sp+8h] [bp-48h]
  unsigned int v19; // [sp+Ch] [bp-44h]
  int v20; // [sp+18h] [bp-38h]

  result = &KeLargestCacheLine;
  v17 = a4;
  v10 = 1;
  if ( (dword_682610 & 0x4000000) != 0 )
    return (int *)sub_51EB78(&KeLargestCacheLine, a2, a3, KeLargestCacheLine);
  if ( a4 && a3 )
  {
    if ( !a1 )
      KeBugCheckEx(85, 4099, 2989);
    if ( a5 < a3 || ((KeLargestCacheLine - 1) & a5) != 0 )
      KeBugCheck2(85, 4100, a4, a3, a5, 0);
    if ( a6 && ((a2 | a3 | a5) & (KeLargestCacheLine - 1)) != 0 )
      KeBugCheck2(85, 4098, a2, a3, a5, 0);
    v12 = *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16);
    v13 = *(_DWORD *)(a1 + 20) + v12;
    v19 = a3 + (a4 - 1) * a5;
    if ( a2 < v12 || a3 + (a4 - 1) * a5 + a2 > v13 )
      KeBugCheck2(85, 4096, a2, v12, v13, 0);
    if ( (*(_WORD *)(a1 + 6) & 5) != 0 )
      v14 = *(_DWORD *)(a1 + 12);
    else
      v14 = MmMapLockedPagesSpecifyCache(a1, 0, 1, 0, 0, 1073741856);
    if ( v14 )
      v10 = 0;
    v15 = a3 * v17;
    if ( a6 )
    {
      if ( v15 <= KiCacheFlushReadPromoteThreshold )
        goto LABEL_17;
      v15 = (unsigned int)&KiCacheFlushReadPromoteCount;
    }
    else
    {
      if ( v15 <= KiCacheFlushWritePromoteThreshold )
      {
LABEL_17:
        if ( KiCacheFlushForcePromote )
          v10 = 1;
        if ( v10 )
        {
          if ( a6 )
            result = (int *)KeInvalidateAllCaches((int)&KeLargestCacheLine, v14, v15, 0);
          else
            result = (int *)KiCleanAllCaches(&KeLargestCacheLine, v14, v15);
        }
        else
        {
          v16 = a2 - *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 16) + v14;
          v18 = *(_DWORD *)(a1 + 16);
          v20 = v16;
          if ( a6 )
          {
            result = (int *)KiFlushRectangle(v16, v19 + v16, a3, a5, 1);
            if ( KiExternalCachePresent )
            {
              off_617AC0(a1, a2 - v18, a3, a4, a5, 1);
              result = (int *)KiFlushRectangle(v20, v19 + v20, a3, a5, 1);
            }
          }
          else
          {
            result = (int *)KiFlushRectangle(v16, v19 + v16, a3, a5, 0);
            if ( KiExternalCachePresent )
              result = (int *)off_617AC0(a1, a2 - v18, a3, a4, a5, 0);
          }
        }
        return result;
      }
      v15 = (unsigned int)&KiCacheFlushWritePromoteCount;
    }
    v10 = 1;
    ++*(_DWORD *)v15;
    goto LABEL_17;
  }
  return result;
}
