// IoSetIrpExtraCreateParameter 
 
int __fastcall IoSetIrpExtraCreateParameter(int a1, int a2)
{
  if ( (*(_DWORD *)(a1 + 8) & 0x80) == 0 )
    return -1073741585;
  if ( *(_DWORD *)(a1 + 60) )
    return -1073741584;
  *(_DWORD *)(a1 + 60) = a2;
  return 0;
}
