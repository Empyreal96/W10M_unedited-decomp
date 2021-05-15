// SmcProcessStoreDeleteRequest 
 
int __fastcall SmcProcessStoreDeleteRequest(int a1, _DWORD *a2, int a3, char a4)
{
  int v5; // r6

  if ( a3 != 16 )
    return -1073741306;
  if ( a4 && ((unsigned __int8)a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v5 = a2[2];
  if ( (unsigned __int8)*a2 != 1 || (*a2 & 0xFFFFFF00) != 0 )
    return -1073741811;
  if ( v5 < 2 )
    return ((int (__fastcall *)(int, _DWORD, _DWORD, int, int))SmcStoreDelete)(a1, a2[1], a2[3], v5, a1);
  return -1073741822;
}
