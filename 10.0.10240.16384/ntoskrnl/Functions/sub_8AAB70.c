// sub_8AAB70 
 
int __fastcall sub_8AAB70(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // r4
  int v7; // lr
  unsigned int v9; // r6
  int v10; // r4
  int i; // r8
  int v12; // r0
  unsigned int v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  _WORD *v17; // r2
  unsigned int v19; // [sp+10h] [bp-30h] BYREF
  int v20; // [sp+14h] [bp-2Ch] BYREF
  int v21; // [sp+18h] [bp-28h]
  int v22; // [sp+1Ch] [bp-24h]

  v6 = a3;
  v19 = 0;
  v21 = a3;
  v22 = a2;
  v7 = a2;
  if ( a4 == 18 )
  {
    v9 = 2;
  }
  else if ( a4 == 8210 )
  {
    v9 = 4;
  }
  else
  {
    v9 = 0;
  }
  if ( *(unsigned __int16 *)(a5 + 2) < v9 )
  {
    v10 = sub_8AA984(a5, v9);
    if ( v10 < 0 )
    {
LABEL_36:
      sub_8AA96C(a5);
      return v10;
    }
    v6 = v21;
    v7 = v22;
  }
  for ( i = 0; ; i = 1 )
  {
    v12 = a1 ? IoGetDevicePropertyData(a1) : PnpGetDeviceInterfacePropertyData(
                                               v7,
                                               v6,
                                               0,
                                               *(_DWORD *)(a5 + 8),
                                               *(unsigned __int16 *)(a5 + 2) - v9,
                                               *(_DWORD *)(a5 + 8),
                                               (int)&v19,
                                               (int)&v20);
    v10 = v12;
    if ( v12 >= 0 )
      break;
    if ( v12 != -1073741789 )
      goto LABEL_35;
    if ( i )
      goto LABEL_36;
    v13 = v19;
    v14 = v9 + v19;
    v19 = v14;
    if ( v14 < v13 )
    {
      v10 = -1073741670;
      goto LABEL_35;
    }
    v10 = sub_8AA984(a5, v14);
    if ( v10 < 0 )
      goto LABEL_36;
    v6 = v21;
    v7 = v22;
  }
  v15 = v20;
  if ( v20 != a4 )
  {
    v10 = -1073741788;
    goto LABEL_36;
  }
  if ( a4 == 18 || a4 == 8210 )
  {
    v16 = v19;
    if ( (v19 & 1) != 0 )
    {
      v10 = -1073741820;
      goto LABEL_36;
    }
    v17 = (_WORD *)(*(_DWORD *)(a5 + 8) + 2 * (v19 >> 1));
    if ( v19 < 2 || *(v17 - 1) )
    {
      *v17 = 0;
      v15 = v20;
      ++v17;
      v16 = v19 + 2;
      v19 += 2;
    }
    if ( v15 == 8210 && (v16 < 4 || *(v17 - 2)) )
    {
      *v17 = 0;
      v15 = v20;
      LOWORD(v16) = v19 + 2;
    }
  }
  else
  {
    LOWORD(v16) = v19;
  }
  *(_WORD *)a5 = v16;
  *(_DWORD *)(a5 + 4) = v15;
LABEL_35:
  if ( v10 < 0 )
    goto LABEL_36;
  return v10;
}
