// -StDmEtaRefresh@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmEtaRefresh(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v5; // r7
  int v6; // r9
  int v7; // r4
  unsigned int v8; // r6
  unsigned int i; // r8
  int v10; // r0
  int v11; // r4
  _DWORD *v13; // [sp+0h] [bp-28h] BYREF
  int v14; // [sp+4h] [bp-24h] BYREF
  int v15[8]; // [sp+8h] [bp-20h] BYREF

  v13 = a1;
  v14 = a2;
  v15[0] = a3;
  v15[1] = a4;
  v5 = 0xFFFF;
  v6 = 0;
  if ( a1[20] <= 0xFFFFu )
    v5 = a1[20];
  while ( 2 )
  {
    v7 = a1[69];
    if ( StEtaCheckForRefresh(v7, v15, &v14, &v13) )
    {
      if ( v14 )
        v8 = v14 + (((unsigned int)v13 - v14) >> 1);
      else
        v8 = (unsigned int)v13;
      if ( v8 >= v5 )
        v8 = v5;
      if ( !StEtaStartRefresh(v7, v15[0], v8) )
        return -1073741637;
      for ( i = 0; i < 0x20; ++i )
      {
        v10 = ST_STORE<SM_TRAITS>::StDmPickRandomRegion(a1);
        if ( v10 == -1 )
        {
          v11 = -1073741448;
LABEL_18:
          StEtaEndRefresh(a1[69]);
          return v11;
        }
        v11 = ST_STORE<SM_TRAITS>::StDmEtaPerformIo(a1, v10, v8);
        if ( v11 < 0 )
          goto LABEL_18;
      }
      StEtaEndRefresh(a1[69]);
      if ( (unsigned int)++v6 < 0xA )
        continue;
    }
    return 0;
  }
}
