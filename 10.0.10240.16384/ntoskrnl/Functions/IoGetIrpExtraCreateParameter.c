// IoGetIrpExtraCreateParameter 
 
int __fastcall IoGetIrpExtraCreateParameter(int a1, _DWORD *a2)
{
  int v2; // r3
  int result; // r0

  if ( (*(_DWORD *)(a1 + 8) & 0x80) == 0 )
    return -1073741811;
  v2 = *(_DWORD *)(a1 + 60);
  result = 0;
  *a2 = v2;
  return result;
}
