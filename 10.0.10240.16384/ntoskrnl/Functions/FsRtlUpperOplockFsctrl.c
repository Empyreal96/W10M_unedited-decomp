// FsRtlUpperOplockFsctrl 
 
int __fastcall FsRtlUpperOplockFsctrl(int *a1, _DWORD *a2, int a3, char a4, int a5)
{
  int v5; // r4
  int v6; // lr
  int v7; // r5
  int v8; // r7
  unsigned __int8 *v11; // r1
  int v12; // r2
  int v13; // r6
  bool v14; // zf
  int v15; // r3
  int v16; // r9
  int v17; // r5
  int v18; // r0
  int v19; // r3
  int v21; // r2
  unsigned __int16 *v22; // r2
  int v23; // r3

  v5 = 0;
  v6 = 4096;
  v7 = 4096;
  if ( (a4 & 1) == 0 )
    v7 = 0;
  v8 = 0x4000;
  v11 = (unsigned __int8 *)a2[24];
  v12 = 0x4000;
  if ( (a4 & 4) == 0 )
    v12 = 0;
  v13 = 0x2000;
  v14 = (a4 & 2) == 0;
  v15 = 0x2000;
  v16 = *v11;
  if ( v14 )
    v15 = 0;
  v17 = v7 | v15 | v12;
  v18 = 0;
  if ( *v11 )
  {
    v21 = *((_DWORD *)v11 + 4);
    switch ( v21 )
    {
      case 589824:
        v18 = 2;
        break;
      case 589828:
        v18 = 16;
        break;
      case 589832:
        v18 = 4;
        break;
      case 589916:
        v18 = 8;
        break;
      case 590400:
        v22 = (unsigned __int16 *)a2[3];
        if ( *((_DWORD *)v11 + 3) >= 0xCu )
        {
          if ( *v22 <= 1u )
          {
            if ( (*((_DWORD *)v22 + 2) & 2) != 0 )
              return FsRtlpOplockFsctrlInternal(a1, a2, a3, a5, v17);
            v23 = *((_DWORD *)v22 + 1);
            if ( (v23 & 1) == 0 )
              v6 = 0;
            if ( (v23 & 4) == 0 )
              v8 = 0;
            if ( (v23 & 2) == 0 )
              v13 = 0;
            v18 = v13 | v8 | v6;
          }
          else
          {
            v5 = -1073741811;
          }
        }
        else
        {
          v5 = -1073741789;
        }
        break;
      default:
        return FsRtlpOplockFsctrlInternal(a1, a2, a3, a5, v17);
    }
    if ( !FsRtlpOplockUpperLowerCompatible(v18, v17) )
      v5 = -1073741598;
    if ( v5 )
      goto LABEL_11;
    return FsRtlpOplockFsctrlInternal(a1, a2, a3, a5, v17);
  }
  v19 = *((_DWORD *)v11 + 3);
  if ( ((v19 & 0x100000) == 0 || (v17 & 0x4000) != 0) && ((v19 & 0x10000) == 0 || (v17 & 0x2000) != 0) )
    return FsRtlpOplockFsctrlInternal(a1, a2, a3, a5, v17);
  v5 = -1073741598;
LABEL_11:
  if ( v16 == 13 )
  {
    a2[6] = v5;
    IofCompleteRequest((int)a2, 1);
  }
  return v5;
}
