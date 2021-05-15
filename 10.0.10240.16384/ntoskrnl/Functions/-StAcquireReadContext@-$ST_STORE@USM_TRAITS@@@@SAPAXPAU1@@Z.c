// -StAcquireReadContext@-$ST_STORE@USM_TRAITS@@@@SAPAXPAU1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StAcquireReadContext(int a1)
{
  _DWORD *v2; // r5
  int v3; // r1
  _BYTE *v4; // r0
  _BYTE *v5; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r7

  v2 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 1664));
  if ( !v2 )
  {
    v3 = *(_DWORD *)(a1 + 1652) + 228;
    if ( (*(_DWORD *)(a1 + 128) & 0x40000) != 0 )
      v3 = *(_DWORD *)(a1 + 1652) + 4324;
    v4 = (_BYTE *)ExAllocatePoolWithTag(512, v3, 1951624563);
    v2 = v4;
    if ( v4 )
    {
      v5 = memset(v4, 0, 28);
      if ( *(_DWORD *)(a1 + 1652) )
        return sub_5117F8(v5);
      v7 = (_DWORD *)(((((unsigned int)v2 + 43) & 0xFFFFFFF0) + 3) & 0xFFFFFFFC);
      v8 = (_DWORD *)(((unsigned int)v7 + 91) & 0xFFFFFFFC);
      v2[2] = v7;
      v2[3] = v8;
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultInit(v7, 0);
      *v7 = v7 + 6;
      v7[3] = 0;
      v7[4] = 8;
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultInit(v8, 0);
      *v8 = v8 + 6;
      v8[3] = 0;
      v8[4] = 8;
      if ( (*(_DWORD *)(a1 + 128) & 0x40000) != 0 )
        v2[5] = v8 + 22;
    }
    else
    {
      v2 = 0;
    }
  }
  return (int)v2;
}
