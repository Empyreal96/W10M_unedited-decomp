// CmEqualTrans 
 
int __fastcall CmEqualTrans(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  bool v5; // zf

  if ( !a1 || !a2 )
    return 0;
  if ( a1 == a2 )
    return 1;
  v3 = *(_DWORD *)(a1 + 24);
  if ( v3 && (v4 = *(_DWORD *)(a2 + 24)) != 0 )
    v5 = v3 == v4;
  else
    v5 = RtlCompareMemory((unsigned __int8 *)(a1 + 40), a2 + 40, 16) == 16;
  return v5;
}
