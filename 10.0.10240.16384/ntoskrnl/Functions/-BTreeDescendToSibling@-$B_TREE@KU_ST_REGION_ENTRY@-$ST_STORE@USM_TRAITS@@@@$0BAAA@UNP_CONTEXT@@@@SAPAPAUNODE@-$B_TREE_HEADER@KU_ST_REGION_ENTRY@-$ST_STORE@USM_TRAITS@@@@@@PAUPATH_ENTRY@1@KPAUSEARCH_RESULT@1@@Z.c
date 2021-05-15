// -BTreeDescendToSibling@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAPAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAUPATH_ENTRY@1@KPAUSEARCH_RESULT@1@@Z 
 
_DWORD *__fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(__int64 *a1, char a2, _DWORD *a3)
{
  __int64 v3; // r4
  _QWORD *v4; // r2
  int v5; // r1
  _DWORD *result; // r0

  v3 = *a1;
  if ( a3 )
    v4 = (_QWORD *)(*a3 + 8 * (a3[3] - *(unsigned __int8 *)(v3 + 2)));
  else
    v4 = 0;
  v5 = a2 & 1;
  if ( !v5 )
  {
    if ( HIDWORD(v3) > (unsigned int)(v3 + 8) )
      goto LABEL_14;
    goto LABEL_7;
  }
  result = (_DWORD *)(HIDWORD(v3) + 4);
  HIDWORD(v3) += 8;
  while ( 1 )
  {
    if ( v4 )
      *v4++ = v3;
    if ( *(_BYTE *)(v3 + 2) == 2 )
      break;
    LODWORD(v3) = *result;
    if ( v5 )
    {
      HIDWORD(v3) = v3 + 8;
LABEL_7:
      result = (_DWORD *)(v3 + 4);
    }
    else
    {
      HIDWORD(v3) = v3 + 8 * (*(unsigned __int16 *)v3 + 1);
LABEL_14:
      result = (_DWORD *)(HIDWORD(v3) - 4);
    }
  }
  return result;
}
