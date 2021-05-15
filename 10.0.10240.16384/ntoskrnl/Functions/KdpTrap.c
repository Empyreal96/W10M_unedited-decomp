// KdpTrap 
 
int __fastcall KdpTrap(int a1, int a2, int *a3, _DWORD *a4, char a5, char a6)
{
  int v6; // r5
  int v11; // r9
  int v13; // r3
  int v14; // r6
  int v15; // r0
  int v16; // r3
  int v17; // [sp+0h] [bp-30h]
  char v18[32]; // [sp+10h] [bp-20h] BYREF

  v6 = 0;
  v18[0] = 0;
  v11 = 0;
  if ( !a5 && KdpSysCheckMsrFault((int)a4) )
    return 1;
  if ( *a3 != -2147483645 )
    return KdpReport(a1, a2, a3, (int)a4, v17, a6);
  v13 = a3[5];
  if ( !v13 || v13 == 8 || v13 == 6 || v13 == 7 )
    return KdpReport(a1, a2, a3, (int)a4, v17, a6);
  v14 = a4[16];
  switch ( v13 )
  {
    case 1:
      v15 = KdpPrint(a4[3], a4[4], a4[1], (unsigned __int16)a4[2], a5, a1, a2, v18);
      v6 = (unsigned __int8)v18[0];
      a4[1] = v15;
      goto LABEL_12;
    case 3:
      goto LABEL_15;
    case 4:
      v11 = 1;
LABEL_15:
      KdpSymbol(a4[1], a4[2], v11, a5, a4, a1, a2);
      goto LABEL_16;
  }
  if ( v13 != 2 )
  {
    if ( v13 != 5 )
    {
LABEL_12:
      v16 = a4[16];
      if ( v16 == v14 )
        a4[16] = v16 + 2;
      return v6;
    }
    KdpCommandString(a4[1], a4[2], a5, a4, a1, a2);
LABEL_16:
    v6 = 1;
    goto LABEL_12;
  }
  return sub_903A30();
}
