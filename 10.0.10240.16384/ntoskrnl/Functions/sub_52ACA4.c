// sub_52ACA4 
 
void __fastcall sub_52ACA4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r4
  int v11; // r5
  int v12; // r7
  __int64 *v13; // r8
  int v14; // r2
  bool v15; // zf
  __int64 v16; // kr00_8
  unsigned int v17; // r0
  int *v18; // r1
  __int64 v19; // kr08_8

  if ( !v10 )
    goto LABEL_20;
  if ( v10 <= 2 )
    goto LABEL_18;
  switch ( v10 )
  {
    case 3:
      v18 = (int *)(v12 + 24);
      LOWORD(a7) = *(_WORD *)v13;
      HIWORD(a7) = a7;
      a8 = *((_DWORD *)v13 + 1);
      break;
    case 4:
      v16 = *v13;
      v17 = *(_DWORD *)(v12 + 28);
      LOWORD(a7) = *((_WORD *)v13 + 4);
      HIWORD(a7) = a7;
      a8 = *((_DWORD *)v13 + 3);
      LOWORD(a9) = *(_WORD *)(v12 + 32);
      HIWORD(a9) = a9;
      a10 = *(_DWORD *)(v12 + 36);
      if ( v16 != __PAIR64__(v17, *(_DWORD *)(v12 + 24)) )
        goto LABEL_20;
      v18 = &a9;
      break;
    case 5:
LABEL_8:
      v14 = *((_DWORD *)v13 + 1);
      if ( v14 != *(_DWORD *)(v12 + 28) )
        goto LABEL_20;
      v15 = memcmp(*(_DWORD *)v13, *(_DWORD *)(v12 + 24), v14) == 0;
      goto LABEL_10;
    case 6:
LABEL_18:
      v19 = *(_QWORD *)(v12 + 24);
      if ( v13 != (__int64 *)v19 )
        goto LABEL_20;
      v15 = a2 == HIDWORD(v19);
LABEL_10:
      if ( !v15 )
      {
LABEL_20:
        if ( !v11 )
          JUMPOUT(0x46ACD8);
        JUMPOUT(0x46ACDE);
      }
LABEL_12:
      v11 = 1;
      goto LABEL_20;
    case 16:
      goto LABEL_8;
    default:
      goto LABEL_20;
  }
  if ( !AuthzBasepEqualUnicodeString((int)&a7, (int)v18) )
    goto LABEL_20;
  goto LABEL_12;
}
