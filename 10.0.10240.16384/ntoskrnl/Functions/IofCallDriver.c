// IofCallDriver 
 
int __fastcall IofCallDriver(int a1, int a2)
{
  int result; // r0
  int v3; // r3
  unsigned __int8 *v4; // r3
  int v5; // r2
  int v6; // r3

  if ( pIofCallDriver )
    return sub_50C394();
  v3 = (char)(*(_BYTE *)(a2 + 35) - 1);
  *(_BYTE *)(a2 + 35) = v3;
  if ( v3 <= 0 )
    KeBugCheckEx(53, a2, 0);
  v4 = (unsigned __int8 *)(*(_DWORD *)(a2 + 96) - 40);
  *(_DWORD *)(a2 + 96) = v4;
  v5 = *v4;
  *((_DWORD *)v4 + 6) = a1;
  if ( v5 == 22 && ((v6 = v4[1], v6 == 2) || v6 == 3) )
    result = IopPoHandleIrp(a2);
  else
    result = (*(int (__fastcall **)(int))(*(_DWORD *)(a1 + 8) + 4 * v5 + 56))(a1);
  return result;
}
