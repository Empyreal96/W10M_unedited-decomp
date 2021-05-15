// DrvDbGetDriverDatabaseMappedPropertyKeys 
 
int __fastcall DrvDbGetDriverDatabaseMappedPropertyKeys(int a1, unsigned __int16 *a2, int a3, _DWORD *a4, unsigned int a5, unsigned int *a6)
{
  int v10; // r3
  int v11; // r4
  int v12; // r0
  unsigned __int16 *v13; // r8
  int v14; // r0
  int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch] BYREF
  unsigned __int16 *v18[10]; // [sp+18h] [bp-28h] BYREF

  *a6 = 0;
  v17 = 0;
  v18[0] = 0;
  v16 = 0;
  v18[1] = 0;
  v11 = DrvDbGetCompositeMappedPropertyKeys(a1, (_DWORD **)off_6174D8, 5u, a4, a5, a6);
  if ( v11 >= 0 )
  {
    if ( *a6 && a4 )
      v10 = 5 * *a6;
    v12 = DrvDbFindDatabaseNode(a1, a2, v18, v10);
    v11 = v12;
    if ( v12 >= 0 )
    {
      v13 = v18[0];
      if ( (*((_DWORD *)v18[0] + 7) & 0x10) != 0 )
      {
        v14 = DrvDbOpenObjectRegKey((int **)a1, *(_DWORD *)(a1 + 20), 1, (int)a2, 1, 0, (int)&v17, 0);
        v11 = v14;
        if ( v14 < 0 )
          goto LABEL_15;
        v12 = DrvDbGetRegValueMappedPropertyKeys(v14, v17, &off_41E27C);
        v11 = v12;
        if ( v12 < 0 )
          goto LABEL_15;
        if ( (*((_DWORD *)v13 + 7) & 4) != 0 )
        {
          v11 = 0;
LABEL_15:
          if ( v16 )
            ZwClose();
          if ( v17 )
            ZwClose();
          return v11;
        }
      }
      if ( !a3 )
      {
        v12 = DrvDbOpenDriverDatabaseRegKey((int **)a1, a2, 1, 0, (int)&v16, 0);
        v11 = v12;
        if ( v12 < 0 )
          goto LABEL_15;
        a3 = v16;
      }
      v11 = DrvDbGetRegValueMappedPropertyKeys(v12, a3, &off_406F48);
      goto LABEL_15;
    }
  }
  return v11;
}
