// -BTreeWalkPostOrderInternal@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@PAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU_SINGLE_LIST_ENTRY@@P6AJPAX3PAK@Z3PAPAU23@@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeWalkPostOrderInternal(int a1, int a2, unsigned __int16 **a3, int (__fastcall *a4)(unsigned __int16 *, int, int), int a5, int a6)
{
  unsigned __int16 *v6; // r6
  int (__fastcall *v7)(unsigned __int16 *, int, int); // lr
  unsigned __int16 *v10; // r5
  int result; // r0
  unsigned __int16 *v12; // r7
  unsigned int v13; // r9
  _DWORD **v14; // r3
  unsigned __int16 *v15; // r4
  int v16; // r10
  int v17; // r2
  unsigned __int16 *v18; // r3
  unsigned __int16 *v19; // r3

  v6 = *a3;
  v7 = a4;
  if ( *a3 )
  {
    v10 = *a3;
    *a3 = *(unsigned __int16 **)v6;
    memmove((int)v6, a2, 0x1000u);
    v7 = a4;
  }
  else
  {
    v10 = (unsigned __int16 *)a2;
  }
  if ( *((_BYTE *)v10 + 3) )
  {
    result = v7(v10, a5, a6);
    goto LABEL_26;
  }
  v12 = v10 + 4;
  v13 = (unsigned int)&v10[4 * *v10 + 4];
  v14 = (_DWORD **)(a1 + 8);
  if ( !a1 )
    v14 = 0;
  v15 = v10 + 4;
  if ( **v14 != -1 && *((_BYTE *)v10 + 2) == 2 )
  {
    v16 = a5;
    if ( (unsigned int)v12 <= v13 )
    {
      do
      {
        v17 = (int)(v15 <= v12 ? v10 + 2 : v15 - 2);
        result = v7(0, a5, v17);
        if ( result < 0 )
          goto LABEL_26;
        v15 += 4;
        v7 = a4;
      }
      while ( (unsigned int)v15 <= v13 );
    }
LABEL_24:
    result = a4(v10, v16, a6);
    if ( result >= 0 )
      result = 0;
    goto LABEL_26;
  }
  if ( (unsigned int)v12 > v13 )
  {
LABEL_23:
    v16 = a5;
    goto LABEL_24;
  }
  while ( 1 )
  {
    v18 = v15 <= v12 ? v10 + 2 : v15 - 2;
    result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeWalkPostOrderInternal(
               a1,
               *(_DWORD *)v18,
               a3,
               v7);
    if ( result < 0 )
      break;
    v15 += 4;
    v7 = a4;
    if ( (unsigned int)v15 > v13 )
      goto LABEL_23;
  }
LABEL_26:
  if ( v6 )
  {
    v19 = *a3;
    *a3 = v6;
    *(_DWORD *)v6 = v19;
  }
  return result;
}
