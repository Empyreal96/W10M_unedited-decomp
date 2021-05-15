// CmpQueryKeyData 
 
int __fastcall CmpQueryKeyData(int a1, int a2, int *a3, unsigned int a4, _DWORD *a5, int a6)
{
  int v10; // r4
  int v12; // r1
  int v13[6]; // [sp+10h] [bp-18h] BYREF

  v13[0] = -1;
  if ( a2 == 4 )
    return CmpQueryKeyDataFromCache(a1, 4, a3, a4, a5, a6);
  v12 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(a1 + 20) + 4))(
          *(_DWORD *)(a1 + 20),
          *(_DWORD *)(a1 + 24),
          v13);
  if ( !v12 )
    return -1073741670;
  v10 = CmpQueryKeyDataFromNode(*(_DWORD *)(a1 + 20), v12, a2, a3, a4, a5, a1, a6);
  (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), v13);
  return v10;
}
