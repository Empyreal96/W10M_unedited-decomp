// DbgkWerAddSecondaryData 
 
int __fastcall DbgkWerAddSecondaryData(_DWORD *a1, _DWORD *a2, int a3, unsigned int a4)
{
  int v8; // r3
  _DWORD *v9; // r6
  int v10; // r3
  int result; // r0
  _BYTE *v12; // r0
  _DWORD *v13; // r5
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3

  if ( !a1 || !a3 || !a2 || !a4 )
  {
    DbgPrintEx(5, 0, (int)"DBGK: DbgkWerAddSecondaryData: Invalid parameter.\n\n", a4);
    return -1073741811;
  }
  v8 = a1[18];
  if ( v8 != 1 )
  {
    if ( v8 != 2 )
      return -1073741637;
    v10 = a1[22];
    if ( v10 )
    {
      v9 = (_DWORD *)(v10 + 24);
      goto LABEL_10;
    }
    return -1073741811;
  }
  v9 = a1 + 26;
LABEL_10:
  if ( a4 > a1[16] - a1[17] )
  {
    DbgPrintEx(
      5,
      0,
      (int)"DBGK: DbgkWerAddSecondaryData: Secondary data exceeds buffer. Size 0x%x Maxsize 0x%x Datasize 0x%x.\n\n",
      a4);
    return -1073741670;
  }
  v12 = (_BYTE *)ExAllocatePoolWithTag(1, 32, 1466393156);
  v13 = v12;
  if ( !v12 )
    return -1073741801;
  memset(v12, 0, 32);
  v14 = ExAllocatePoolWithTag(1, (a4 + 4095) & 0xFFFFF000, 1466393156);
  v13[4] = v14;
  if ( !v14 )
  {
    ExFreePoolWithTag((unsigned int)v13);
    return -1073741801;
  }
  memmove(v14, a3, a4);
  v15 = a2[1];
  v16 = a2[2];
  v17 = a2[3];
  *v13 = *a2;
  v13[1] = v15;
  v13[2] = v16;
  v13[3] = v17;
  v13[5] = a4;
  a1[17] += a4;
  if ( a1[18] == 1 )
    ++a1[29];
  result = 0;
  v13[7] = v9[2];
  v9[2] = v13;
  return result;
}
