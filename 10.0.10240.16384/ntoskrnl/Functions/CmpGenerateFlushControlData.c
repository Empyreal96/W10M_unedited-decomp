// CmpGenerateFlushControlData 
 
int __fastcall CmpGenerateFlushControlData(int result, char a2, int *a3)
{
  int v5; // r5
  BOOL v6; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r2
  int v10; // r2
  int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14; // r1
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // r3

  *a3 = 0;
  a3[1] = 0;
  a3[2] = 0;
  a3[3] = 0;
  a3[5] = 0;
  v5 = result;
  v6 = *(_BYTE *)(result + 123) || *(_DWORD *)(result + 44) || *(_DWORD *)(result + 60);
  if ( *(_DWORD *)(result + 44) || *(_BYTE *)(result + 123) )
  {
    *a3 = 9;
    if ( *(_BYTE *)(result + 122) )
      *a3 = 27;
    if ( *(_DWORD *)(result + 3316) )
      return sub_7D3DFC();
    result = HvGetEffectiveLogSizeCapForHive(result);
    a3[6] = result;
  }
  if ( v6 && (a2 & 4) != 0 )
    *a3 |= 0x42u;
  if ( (*(_DWORD *)(v5 + 92) & 2) != 0 || (*(_DWORD *)(v5 + 3228) & 0x800) != 0 || (CmpGlobalFlushControlFlags & 1) != 0 )
  {
    if ( *(_DWORD *)(v5 + 44) || *(_BYTE *)(v5 + 123) )
    {
      v18 = *a3 | 0x46;
      *a3 = v18;
      if ( *(_BYTE *)(v5 + 122) )
        *a3 = v18 | 0x10;
      v12 = *a3 | 0x500;
      goto LABEL_39;
    }
    if ( (*(_DWORD *)(v5 + 3312) & 4) != 0 || (a2 & 0x20) == 0 )
      return result;
    v11 = *a3;
    goto LABEL_38;
  }
  if ( (a2 & 8) != 0 && (!*(_BYTE *)(v5 + 122) || (*a3 & 0x10) != 0) )
  {
    v15 = *a3 | 0x107;
    *a3 = v15;
    if ( (v15 & 8) == 0 )
      return result;
    result = HvGetHiveLogFileStatus(v5, a3[6], a3 + 2);
    v16 = a3[2];
    if ( (v16 & 8) == 0 && (v16 & 4) == 0 )
      return result;
    v12 = *a3 | 0x400;
LABEL_39:
    *a3 = v12;
    return result;
  }
  if ( (*a3 & 8) != 0 && (*a3 & 0x40) == 0 )
  {
    result = HvGetHiveLogFileStatus(v5, a3[6], a3 + 2);
    v7 = a3[2];
    if ( (v7 & 1) != 0 )
    {
      v12 = *a3 | 2;
      goto LABEL_39;
    }
    if ( (v7 & 8) != 0 || (v7 & 2) != 0 )
    {
      v17 = *a3 | 0x42;
    }
    else
    {
      if ( (v7 & 4) == 0 )
        goto LABEL_23;
      *a3 |= 2u;
      result = HvIsCurrentLogSwappable(v5);
      if ( result )
        v17 = v19 | 0x20;
      else
        v17 = v19 | 0x40;
    }
    *a3 = v17;
  }
LABEL_23:
  v8 = *a3;
  if ( (*a3 & 0x40) == 0 )
    goto LABEL_24;
  if ( (*(_DWORD *)(v5 + 3312) & 2) != 0 )
    return result;
  v13 = a3[2];
  if ( (v13 & 8) != 0 )
  {
    v20 = v8 | 0x504;
LABEL_72:
    *a3 = v20;
    goto LABEL_24;
  }
  *a3 = v8 | 1;
  if ( HvIsCurrentLogSwappable(v5) )
  {
    result = 32;
    *a3 = v14 | 0x20;
    goto LABEL_25;
  }
  *a3 = v14 | 4;
  if ( (v13 & 4) != 0 )
  {
    v20 = v14 | 0x404;
    goto LABEL_72;
  }
LABEL_24:
  result = 32;
LABEL_25:
  v9 = *a3;
  if ( (*a3 & 8) != 0 && (v9 & 0x40) == 0 )
  {
    if ( !*(_DWORD *)(v5 + 60) )
      *a3 = v9 | 0x800;
    v10 = a3[2];
    if ( (v10 & 0x10) != 0 || (v10 & 4) != 0 )
      *a3 |= 0x1000u;
    if ( (v10 & 0x20) != 0 && (*(_DWORD *)(v5 + 3312) & 2) != 0 )
      *a3 |= 0x2000u;
  }
  if ( (*(_DWORD *)(v5 + 3312) & 4) == 0 )
  {
    if ( *(_DWORD *)(v5 + 1776) )
    {
      v11 = *a3;
      if ( (*a3 & 8) != 0 || (a2 & 0x20) != 0 )
      {
LABEL_38:
        v12 = v11 | 0x202;
        goto LABEL_39;
      }
    }
  }
  return result;
}
