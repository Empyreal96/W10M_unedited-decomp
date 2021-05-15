// HvpBuildMap 
 
int __fastcall HvpBuildMap(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v3; // r6
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r9
  int v8; // r8
  unsigned int v9; // r3
  int v10; // r3
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r3
  char *v14; // r2
  char *v16; // [sp+8h] [bp-20h]

  v3 = (_DWORD *)a1[7];
  v5 = HvpInitMap((int)a1);
  v6 = v5;
  if ( v5 >= 0 )
  {
    v7 = a1[238];
    v8 = 0;
    v16 = (char *)a2 + v7;
    if ( a2 >= (_DWORD *)((char *)a2 + v7) )
    {
LABEL_23:
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v9 = a2[2];
        if ( v9 > v7 || v9 < 0x1000 || (v9 & 0xFFF) != 0 || *a2 != 1852400232 || a2[1] != v8 )
        {
          v10 = (unsigned __int8)CmpSelfHeal;
          v3[63] = v7;
          v3[64] = v8;
          v3[65] = a2;
          if ( !v10 && (CmpBootType & 6) == 0 )
          {
            v6 = -1073741492;
            SetFailureLocation((int)v3, 0, 3, -1073741492, 32);
            goto LABEL_28;
          }
          v11 = a2[2];
          *a2 = 1852400232;
          a2[1] = v8;
          if ( v11 + v8 > v7 || v11 < 0x1000 || (v11 & 0xFFF) != 0 )
            a2[2] = 4096;
          SetFailureLocation((int)v3, 1, 3, 1073741833, 16);
          *(_DWORD *)(a1[8] + 4088) |= 4u;
        }
        v12 = HvpEnlistBinInMap((int)a1, v7, (int)a2, 0, v8);
        v6 = v12;
        if ( (CmpSelfHeal || (CmpBootType & 6) != 0) && v12 == 1073741833 )
        {
          *(_DWORD *)(a1[8] + 4088) |= 4u;
          SetFailureLocation((int)v3, 1, 3, 1073741833, 48);
          v6 = 0;
        }
        if ( v6 < 0 )
          break;
        v13 = a2[2];
        v14 = (char *)a2 + v13;
        v8 += v13;
        if ( (unsigned int)a2 + v13 < v13 )
        {
          v6 = -1073741492;
          SetFailureLocation((int)v3, 0, 3, -1073741492, 80);
          v3[63] = a2[2];
          v3[64] = a2[1];
          v3[65] = a2;
          goto LABEL_28;
        }
        a2 = (_DWORD *)((char *)a2 + v13);
        if ( v14 >= v16 )
          goto LABEL_23;
      }
      SetFailureLocation((int)v3, 0, 3, v6, 64);
LABEL_28:
      HvpCleanMap(a1);
    }
  }
  else
  {
    SetFailureLocation((int)v3, 0, 3, v5, 0);
  }
  return v6;
}
