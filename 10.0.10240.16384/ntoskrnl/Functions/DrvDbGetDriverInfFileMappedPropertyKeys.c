// DrvDbGetDriverInfFileMappedPropertyKeys 
 
int __fastcall DrvDbGetDriverInfFileMappedPropertyKeys(int **a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r4
  int v7; // r4
  int v9[4]; // [sp+10h] [bp-10h] BYREF

  v6 = a3;
  *a6 = 0;
  v9[0] = 0;
  if ( !a3 )
  {
    a1 = (int **)DrvDbOpenObjectRegKey(a1, 0, 3, a2, 1, 0, (int)v9, 0);
    v7 = (int)a1;
    if ( (int)a1 < 0 )
      goto LABEL_5;
    v6 = v9[0];
  }
  v7 = DrvDbGetRegValueMappedPropertyKeys(a1, v6, &off_402608);
LABEL_5:
  if ( v9[0] )
    ZwClose();
  return v7;
}
