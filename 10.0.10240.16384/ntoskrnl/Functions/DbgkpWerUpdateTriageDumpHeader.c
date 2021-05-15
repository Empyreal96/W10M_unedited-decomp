// DbgkpWerUpdateTriageDumpHeader 
 
int __fastcall DbgkpWerUpdateTriageDumpHeader(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r5
  int v7; // r8
  int v8; // r4
  unsigned int v9; // r3
  int v10; // r2
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a4;
  v5 = a1[17];
  v6 = a1[25];
  if ( !v5 )
    goto LABEL_7;
  v7 = a1[29];
  v8 = RtlULongLongToULong(32 * v7, (unsigned __int64)(unsigned int)v7 >> 27, v12);
  if ( v8 >= 0 )
  {
    v9 = v12[0] + v6 + 16;
    if ( v9 < v6 + 16 )
      return -1073741675;
    v6 = v5 + v9;
    if ( v5 + v9 < v9 )
      return -1073741675;
LABEL_7:
    v10 = a1[24];
    *(_DWORD *)(v10 + 4000) = v6;
    *(_DWORD *)(v10 + 4004) = 0;
    DbgPrintEx(5, 3, (int)"DBGK: Required total aize: 0x%X\n", v6);
    return 0;
  }
  DbgPrintEx(5, 0, (int)"DBGK: Overflow calculating total blocks. Block count %i\n", v7);
  return v8;
}
