// DrvDbGetObjectDatabaseNode 
 
int __fastcall DrvDbGetObjectDatabaseNode(int a1, _WORD *a2, _DWORD *a3, _DWORD *a4)
{
  if ( *a2 == 64 )
    return sub_7E2CA4();
  *a4 = *(_DWORD *)(a1 + 24);
  *a3 = a2;
  return 0;
}
