// -StDmLazyRemoveKeysWorker@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmLazyRemoveKeysWorker(int a1)
{
  unsigned __int16 *v2; // r2
  unsigned int v3; // r4
  int v4; // r1
  unsigned int v5; // r6
  int v6; // r7
  int v7; // r8
  __int64 v8; // r0
  unsigned int v9; // r4
  _DWORD *v10; // r3
  int v11; // r1
  unsigned int v12; // r2
  int v14[12]; // [sp+20h] [bp-30h] BYREF

  __dmb(0xBu);
  v2 = (unsigned __int16 *)(a1 + 224);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 & 0xFFFE, v2) );
  __dmb(0xBu);
  memset(v14, 0, 24);
  v14[2] = 16;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v14[3] |= 3u;
  while ( 1 )
  {
    v8 = RtlpSparseBitmapCtxFindNextBitInternal(a1 + 160, v4, v6, v7);
    v7 = HIDWORD(v8);
    v6 = v8;
    if ( ((unsigned int)v8 & HIDWORD(v8)) == -1 )
      break;
    v9 = 16 * v8;
    if ( v5 >= 2 )
    {
      v10 = *(_DWORD **)(a1 + 92);
      v11 = v10[892];
      __dmb(0xBu);
      v12 = v10[893];
      __dmb(0xBu);
      if ( v10[967] + (v12 >> 8) + v11 )
      {
        ST_STORE<SM_TRAITS>::StDmLazyWorkItemQueue(a1, a1 + 216);
        return 0;
      }
      v9 = 16 * v8;
    }
    RtlpSparseBitmapCtxUpdateBitRanges(a1 + 160, 0, v9 >> 4, 0);
    ++v5;
    v14[1] = v9;
    ST_STORE<SM_TRAITS>::StDmPageRemove(a1, v14);
  }
  return 0;
}
