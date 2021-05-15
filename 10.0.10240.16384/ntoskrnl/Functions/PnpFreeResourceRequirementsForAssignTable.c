// PnpFreeResourceRequirementsForAssignTable 
 
unsigned int __fastcall PnpFreeResourceRequirementsForAssignTable(unsigned int result, unsigned int a2)
{
  unsigned int v3; // r4
  int v4; // r3

  v3 = result;
  if ( result < a2 )
  {
    while ( 1 )
    {
      result = IopFreeReqList(*(_DWORD *)(v3 + 24));
      v4 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)(v3 + 24) = 0;
      if ( (v4 & 0x200) != 0 )
        break;
      v3 += 40;
      if ( v3 >= a2 )
        return result;
    }
    result = sub_80DD1C(result);
  }
  return result;
}
