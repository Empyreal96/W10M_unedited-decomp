// -StCompactionWorker@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCompactionWorker(int a1)
{
  char v1; // r3
  int v3; // r0
  int v4; // r5
  int v5; // r0
  char v6; // r7
  int v7; // r1
  unsigned int v8; // r2
  char v9; // r3
  unsigned int v10; // r6
  int v11; // r0

  v1 = *(_BYTE *)(a1 + 756);
  if ( (v1 & 4) != 0 )
  {
    *(_BYTE *)(a1 + 756) = v1 & 0xFB;
  }
  else
  {
    *(_BYTE *)(a1 + 756) = v1 & 0xFC;
    v3 = ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 0);
    if ( v3 != 2 )
    {
LABEL_3:
      v4 = 0;
      goto LABEL_16;
    }
  }
  *(_BYTE *)(a1 + 756) |= 3u;
  while ( 1 )
  {
    v5 = *(_BYTE *)(a1 + 72) ? ST_STORE<SM_TRAITS>::StCompactionPerformFile(a1) : ST_STORE<SM_TRAITS>::StCompactionPerformInMem(
                                                                                    (_DWORD *)a1,
                                                                                    1);
    v4 = v5;
    v3 = ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 0);
    if ( v4 < 0 )
      break;
    if ( v3 != 2 )
      goto LABEL_3;
  }
  if ( v3 == 2 )
  {
    if ( *(_BYTE *)(a1 + 72) )
      *(_BYTE *)(a1 + 756) |= 4u;
    v3 = 1;
  }
LABEL_16:
  v6 = *(_BYTE *)(a1 + 756) & 0xFC;
  *(_BYTE *)(a1 + 756) = v6;
  if ( v3 )
  {
    v7 = (*(_DWORD *)(a1 + 116) & 2) != 0;
    if ( v3 == 1 )
    {
      if ( *(_BYTE *)(a1 + 72) )
        v8 = 400;
      else
        v8 = 30;
      v9 = v6 & 0xFC | 1;
      v10 = -2;
    }
    else
    {
      v8 = 0;
      v9 = v6 & 0xFC | 2;
      v10 = 0;
    }
    v11 = *(_DWORD *)(a1 + 760);
    *(_BYTE *)(a1 + 756) = v9;
    ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(v11, v7, v8, v10);
  }
  return v4;
}
