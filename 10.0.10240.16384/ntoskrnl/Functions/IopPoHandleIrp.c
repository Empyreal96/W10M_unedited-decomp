// IopPoHandleIrp 
 
int __fastcall IopPoHandleIrp(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  if ( PoHandleIrp(a1, v6) )
    result = v6[0];
  else
    result = (*(int (__fastcall **)(_DWORD, int))(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 96) + 24) + 8)
                                                + 4 * **(unsigned __int8 **)(a1 + 96)
                                                + 56))(
               *(_DWORD *)(*(_DWORD *)(a1 + 96) + 24),
               a1);
  return result;
}
