// sub_7E2BE0 
 
void __fastcall sub_7E2BE0(int a1, int a2, int a3, int a4, int a5, char a6)
{
  int **v6; // r5
  int ***v7; // r7
  int v8; // r9
  int v9[16]; // [sp+10h] [bp-40h] BYREF

  if ( *v7 == v6 + 3 )
  {
    if ( a6 )
    {
      if ( DrvDbAcquireDatabaseNodeBaseKey(v6, v6[5], v8, v9) >= 0 )
        PnpCtxRegCreateTree(*v6, v9[0], v9[15], 0, a5, 0);
      JUMPOUT(0x77B1C4);
    }
    JUMPOUT(0x77B1C6);
  }
  JUMPOUT(0x77B1F0);
}
