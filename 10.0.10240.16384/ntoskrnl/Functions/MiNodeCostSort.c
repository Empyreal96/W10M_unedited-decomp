// MiNodeCostSort 
 
int __fastcall MiNodeCostSort(int a1, int a2)
{
  unsigned __int64 v2; // kr00_8
  unsigned __int64 v3; // kr08_8
  int result; // r0

  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(a2 + 8);
  if ( HIDWORD(v2) > HIDWORD(v3) )
    goto LABEL_6;
  if ( HIDWORD(v2) < HIDWORD(v3) || (unsigned int)v2 < (unsigned int)v3 )
    return -1;
  if ( v2 <= v3 )
    result = 0;
  else
LABEL_6:
    result = 1;
  return result;
}
