// CcCanIWriteStream 
 
int __fastcall CcCanIWriteStream(int a1, unsigned int a2, unsigned int a3, char a4)
{
  int v5; // r8
  int v6; // r2
  int v7; // r9
  BOOL v8; // r4
  int v10; // r3
  _DWORD *v11; // r2
  unsigned int v12; // r1
  int v13; // r3

  v5 = 0;
  v6 = ((a3 & 0xFFF) != 0) + (a3 >> 12);
  if ( a2 > 0x1000000 )
    a2 = 0x1000000;
  v7 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v8 = v6 + CcGlobalDirtyPageStatistics + v7 >= (unsigned int)CcGlobalDirtyPageThresholds;
  if ( !a1 )
    goto LABEL_18;
  if ( (a4 & 3) == 0
    && (*(_BYTE *)(*(_DWORD *)(a1 + 12) + 4) & 4) == 0
    && v6 + CcGlobalDirtyPageStatistics + v7 < (unsigned int)CcGlobalDirtyPageThresholds )
  {
    return MmEnoughMemoryForWrite() != 0;
  }
  if ( (a4 & 1) == 0 )
    return sub_50DD60();
  v10 = *(_DWORD *)(a1 + 20);
  if ( v10 )
  {
    v11 = *(_DWORD **)(v10 + 4);
    if ( v11 )
    {
      v12 = v11[42];
      if ( v12 )
      {
        v13 = v11[19];
        if ( v13 )
        {
          if ( v13 + v7 > v12 )
            v5 = 1;
        }
      }
      if ( *(_DWORD *)(v11[89] + 20) <= (unsigned int)CcMaxLazyWritePages && (a4 & 4) == 0 )
        v8 = 0;
    }
  }
  if ( (a4 & 1) == 0 )
    KeReleaseQueuedSpinLock(5, 0);
  if ( !v5 )
  {
LABEL_18:
    if ( !v8 )
      return MmEnoughMemoryForWrite() != 0;
  }
  return 0;
}
