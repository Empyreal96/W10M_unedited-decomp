// -StDmEtwPageRundown@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmEtwPageRundown(int a1)
{
  int v2; // r4
  unsigned int v3; // r4
  unsigned __int16 *v4; // r6
  int v5; // r3
  _DWORD **v6; // r3
  _DWORD **v7; // r3
  int v8; // r0
  int v9; // r2
  unsigned __int16 *v11; // [sp+10h] [bp-18h] BYREF
  int v12; // [sp+14h] [bp-14h]

  v11 = 0;
  v12 = 0;
  if ( (dword_636E9C & 0x80) != 0 )
  {
    if ( B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeIteratorAttachEx(
           (int *)&v11,
           a1) == -1 )
    {
LABEL_24:
      v2 = -1073741818;
      goto LABEL_26;
    }
    v4 = v11;
    v3 = v12;
    while ( 1 )
    {
      if ( !v4 )
      {
LABEL_25:
        v2 = 0;
        goto LABEL_26;
      }
      v5 = *v4;
      v3 += 16;
      v12 = v3;
      if ( v3 >= (unsigned int)&v4[8 * v5 + 4] )
      {
        v6 = (_DWORD **)(a1 + 8);
        if ( !a1 )
          v6 = 0;
        if ( **v6 == -1 )
        {
          v7 = (_DWORD **)(a1 + 8);
          if ( !a1 )
            v7 = 0;
          if ( **v7 == -1 )
            v8 = *((_DWORD *)v4 + 1);
          else
            v8 = 3358;
        }
        else
        {
          v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSibling(a1, v4);
          if ( v8 == -1 )
          {
            v9 = -1;
            goto LABEL_21;
          }
        }
        if ( !v8 )
        {
          v9 = 0;
          goto LABEL_21;
        }
        v3 = v8 + 8;
        v11 = (unsigned __int16 *)v8;
        v12 = v8 + 8;
        v4 = (unsigned __int16 *)v8;
      }
      v9 = v3;
LABEL_21:
      if ( !v9 )
        goto LABEL_25;
      if ( v9 == -1 )
        goto LABEL_24;
      SmEtwLogStoreOp(&unk_636E90, 2);
    }
  }
  v2 = -1073741637;
LABEL_26:
  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v11, a1);
  return v2;
}
