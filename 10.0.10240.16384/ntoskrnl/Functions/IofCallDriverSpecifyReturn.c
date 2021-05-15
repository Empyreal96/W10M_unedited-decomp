// IofCallDriverSpecifyReturn 
 
int __fastcall IofCallDriverSpecifyReturn(int a1, int a2)
{
  int v2; // r3
  unsigned __int8 *v3; // r3
  int v4; // r2
  int v5; // r3
  int result; // r0

  if ( pIofCallDriver )
    return pIofCallDriver(a1);
  v2 = (char)(*(_BYTE *)(a2 + 35) - 1);
  *(_BYTE *)(a2 + 35) = v2;
  if ( v2 <= 0 )
    sub_527290();
  v3 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
  *(_DWORD *)(a2 + 96) = v3;
  v4 = *v3;
  *((_DWORD *)v3 + 6) = a1;
  if ( v4 == 22 && ((v5 = v3[1], v5 == 2) || v5 == 3) )
    result = IopPoHandleIrp(a2);
  else
    result = (*(int (__fastcall **)(int))(*(_DWORD *)(a1 + 8) + 4 * v4 + 56))(a1);
  return result;
}
