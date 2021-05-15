// DrvDbInitializeDatabaseNodeVersion 
 
int __fastcall DrvDbInitializeDatabaseNodeVersion(int **a1, int a2)
{
  int v4; // r4

  v4 = PnpCtxRegOpenKey(*a1, *(_DWORD *)(a2 + 44), 0, 0);
  if ( v4 >= 0 )
    v4 = DrvDbSetDriverDatabaseMappedProperty(
           (int)a1,
           *(unsigned __int16 **)(a2 + 12),
           0,
           (unsigned int)DEVPKEY_DriverDatabase_Version,
           (int (*)[4])7,
           (unsigned __int16 *)(a2 + 32),
           4u);
  return v4;
}
