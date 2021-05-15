// EtwActivityIdControl 
 
int __fastcall EtwActivityIdControl(int a1, int *a2)
{
  int v3; // r5
  _DWORD *v4; // r3
  int *v6; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r4
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // [sp+4h] [bp-28h]
  int v21; // [sp+8h] [bp-24h]
  int v22; // [sp+Ch] [bp-20h]
  int v23; // [sp+10h] [bp-1Ch]

  v3 = 0;
  if ( a1 != 3 )
  {
    if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
      || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    {
      v4 = 0;
    }
    else
    {
      v4 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
    }
    if ( !v4 )
      return -1073741637;
    v6 = v4 + 980;
    switch ( a1 )
    {
      case 1:
        v13 = *v6;
        v14 = v4[981];
        v15 = v4[982];
        v16 = v4[983];
        break;
      case 2:
        v17 = a2[1];
        v18 = a2[2];
        v19 = a2[3];
        *v6 = *a2;
        v6[1] = v17;
        v6[2] = v18;
        v6[3] = v19;
        return v3;
      case 4:
        v20 = *v6;
        v21 = v4[981];
        v22 = v4[982];
        v23 = v4[983];
        v10 = a2[1];
        v11 = a2[2];
        v12 = a2[3];
        *v6 = *a2;
        v6[1] = v10;
        v6[2] = v11;
        v6[3] = v12;
        v13 = v20;
        v14 = v21;
        v15 = v22;
        v16 = v23;
        break;
      case 5:
        v7 = v4[981];
        v8 = v4[982];
        v9 = v6[3];
        *a2 = *v6;
        a2[1] = v7;
        a2[2] = v8;
        a2[3] = v9;
        EtwpCreateActivityId((int)v6);
        return v3;
      default:
        return -1073741811;
    }
    *a2 = v13;
    a2[1] = v14;
    a2[2] = v15;
    a2[3] = v16;
    return v3;
  }
  EtwpCreateActivityId((int)a2);
  return v3;
}
