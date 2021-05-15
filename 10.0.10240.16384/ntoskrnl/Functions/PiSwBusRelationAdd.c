// PiSwBusRelationAdd 
 
int __fastcall PiSwBusRelationAdd(unsigned __int16 *a1)
{
  int v1; // r1
  int v2; // r5
  unsigned __int16 *v3; // r4
  int v4; // r0
  char v6[4]; // [sp+0h] [bp-28h] BYREF
  unsigned __int16 *v7; // [sp+4h] [bp-24h] BYREF
  __int16 v8; // [sp+8h] [bp-20h] BYREF
  __int64 v9; // [sp+Ah] [bp-1Eh]
  int v10; // [sp+12h] [bp-16h]
  __int16 v11; // [sp+16h] [bp-12h]

  v7 = 0;
  v8 = 0;
  v9 = 0i64;
  v10 = 0;
  v11 = 0;
  v6[0] = 0;
  v2 = PnpAllocatePWSTR(a1, 0xC8u, 1466986064, (int *)&v7);
  v3 = v7;
  if ( v2 >= 0 )
  {
    v2 = 0;
    v8 = 0;
    LOWORD(v9) = 0;
    *(_DWORD *)((char *)&v9 + 2) = 0;
    if ( v7 )
    {
      v2 = sub_455E68(v7, v1, (int *)&v7);
      if ( v2 < 0 )
        goto LABEL_10;
      *(_DWORD *)((char *)&v9 + 2) = v3;
      v8 = 2 * (_WORD)v7;
      LOWORD(v9) = 2 * (_WORD)v7 + 2;
    }
    v4 = RtlInsertElementGenericTableAvl((int)&PiSwBusRelationsTable, (int)&v8, 16, (int)v6);
    if ( v4 )
    {
      if ( v6[0] )
      {
        *(_DWORD *)(v4 + 8) = v4 + 8;
        *(_DWORD *)(v4 + 12) = v4 + 8;
        v3 = 0;
      }
    }
    else
    {
      v2 = -1073741670;
    }
    if ( v2 >= 0 )
      return sub_7E092C();
  }
LABEL_10:
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v2;
}
