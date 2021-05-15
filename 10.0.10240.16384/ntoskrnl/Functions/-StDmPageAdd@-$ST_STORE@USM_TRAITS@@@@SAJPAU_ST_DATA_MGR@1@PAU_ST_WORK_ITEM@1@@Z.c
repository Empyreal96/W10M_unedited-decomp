// -StDmPageAdd@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmPageAdd(int a1, _DWORD *a2)
{
  int v2; // r3
  int v3; // r4
  int v6; // r0
  int result; // r0
  unsigned int v8; // r4
  unsigned int v9; // r5
  int v10; // r3
  int v11; // r8
  int v12; // r5
  _DWORD *v13; // r6
  unsigned __int64 v14; // r0
  int v15[2]; // [sp+0h] [bp-30h] BYREF
  unsigned int v16; // [sp+8h] [bp-28h] BYREF
  int i; // [sp+Ch] [bp-24h]
  int v18; // [sp+10h] [bp-20h]

  v2 = a2[2];
  v3 = a2[3];
  v16 = a2[1];
  i = v2;
  v18 = v3;
  v6 = SmMapPage(v2, v15);
  if ( v6 )
  {
    v9 = v15[0];
    for ( i = v6; ; i += 4096 )
    {
      v10 = *(_BYTE *)(a1 + 72) ? *(_DWORD *)(a1 + 108) : 1;
      v15[0] = v10;
      do
        result = ST_STORE<SM_TRAITS>::StDmpSinglePageAdd(a1, &v16, v15);
      while ( result == -1073741267 );
      if ( result )
        break;
      v16 ^= (((v16 & 0xFFFFFFF8) + 8) ^ v16) & 0x3FFFFFF8;
      v8 = v16;
      if ( ((v16 >> 3) & 0x7FFFFFF) >= v9 >> 12 )
        goto LABEL_14;
      ++v18;
    }
    v8 = v16;
    if ( result == -1073741818 )
    {
      v8 = v16 & 0xC0000007;
      goto LABEL_20;
    }
LABEL_14:
    v11 = (v8 >> 3) & 0x7FFFFFF;
    if ( v11 )
    {
      v12 = *(_DWORD *)(a1 + 680);
      if ( v12 )
      {
        v13 = *(_DWORD **)(v12 + 24);
        LODWORD(v14) = KeQueryInterruptTime();
        if ( v14 >= *(_QWORD *)(v12 + 32) )
          v13 = (_DWORD *)StIoCountsMovePeriod(v12 + 24, HIDWORD(v14), v14, HIDWORD(v14), v15[0]);
        *v13 += v11;
      }
      result = 0;
    }
  }
  else
  {
    result = -1073741670;
    v8 = v16;
  }
LABEL_20:
  a2[1] ^= (a2[1] ^ v8) & 0x3FFFFFF8;
  return result;
}
