// DrvDbRegisterDatabase 
 
int __fastcall DrvDbRegisterDatabase(int a1, unsigned __int16 *a2, int a3, int a4, char a5, int a6, int a7)
{
  int v10; // r4
  unsigned __int16 *v12[6]; // [sp+10h] [bp-18h] BYREF

  v12[0] = 0;
  v10 = 0;
  if ( DrvDbFindDatabaseNode(a1, a2, v12, 0) >= 0 )
    return 0x40000000;
  if ( a5 )
    v10 = 16;
  return DrvDbCreateDatabaseNode(a1, a2, 0, a4, v10, PiDrvDbNodeActionCallback, a7, v12);
}
