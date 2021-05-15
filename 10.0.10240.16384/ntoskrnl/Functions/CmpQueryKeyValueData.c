// CmpQueryKeyValueData 
 
int __fastcall CmpQueryKeyValueData(int a1, int a2, int a3, int a4, _DWORD *a5, unsigned int a6, int *a7)
{
  int v9; // r5
  int v10; // r10
  int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r4
  int v14; // r9
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r1
  unsigned int v24; // r3
  unsigned int v25; // r2
  int v26; // r1
  unsigned int v27; // r4
  unsigned int v28; // r2
  int v29; // r0
  unsigned int v30; // r4
  char v32[4]; // [sp+10h] [bp-50h] BYREF
  int v33; // [sp+14h] [bp-4Ch]
  int v34; // [sp+18h] [bp-48h]
  unsigned int v35; // [sp+1Ch] [bp-44h]
  int v36; // [sp+20h] [bp-40h]
  int v37; // [sp+24h] [bp-3Ch]
  int v38; // [sp+28h] [bp-38h]
  int v39; // [sp+2Ch] [bp-34h] BYREF
  unsigned int v40; // [sp+30h] [bp-30h]
  int v41; // [sp+34h] [bp-2Ch] BYREF
  int v42; // [sp+38h] [bp-28h]
  int v43; // [sp+3Ch] [bp-24h] BYREF
  int v44[8]; // [sp+40h] [bp-20h] BYREF

  v42 = a2;
  v41 = a1;
  v9 = 0;
  v34 = 0;
  v10 = 0;
  v32[0] = 0;
  v39 = -1;
  v11 = *(_DWORD *)(a1 + 20);
  v36 = v11;
  v37 = v11;
  v38 = a3;
  v12 = *(unsigned __int16 *)(a3 + 2);
  if ( (*(_WORD *)(a3 + 16) & 1) != 0 )
    v12 = (unsigned __int16)(2 * v12);
  v13 = v12;
  if ( a4 == 2 )
  {
    v28 = *(_DWORD *)(a3 + 4);
    if ( v28 < 0x80000000 )
    {
      v29 = 0;
    }
    else
    {
      v28 += 0x80000000;
      v29 = 1;
    }
    v14 = 0;
    *a7 = v28 + 12;
    if ( a6 >= 0xC )
    {
      *a5 = 0;
      a5[1] = *(_DWORD *)(a3 + 12);
      a5[2] = v28;
      v30 = v28;
      if ( a6 - 12 < v28 )
      {
        v30 = a6 - 12;
        v14 = -2147483643;
        v33 = -2147483643;
      }
      if ( v28 )
      {
        if ( v29 == 1 )
        {
          v9 = a3 + 8;
          v34 = a3 + 8;
        }
        else
        {
          if ( CmpGetValueData(*(_DWORD *)(v41 + 20), v42, a3, &v43, v44, v32, &v39) )
            v9 = v44[0];
          else
            v9 = 0;
          v34 = v9;
          if ( !v9 )
          {
            v14 = -1073741670;
            v33 = -1073741670;
          }
          v10 = (unsigned __int8)v32[0];
        }
        if ( v9 )
          memmove((int)(a5 + 3), v9, v30);
      }
    }
    else
    {
      v14 = -1073741789;
      v33 = -1073741789;
    }
    v11 = v36;
  }
  else
  {
    switch ( a4 )
    {
      case 0:
        v14 = 0;
        *a7 = v12 + 12;
        if ( a6 >= 0xC )
        {
          *a5 = 0;
          a5[1] = *(_DWORD *)(a3 + 12);
          a5[2] = v12;
          if ( a6 - 12 < v12 )
          {
            v13 = a6 - 12;
            v14 = -2147483643;
            v33 = -2147483643;
          }
          v15 = (int)(a5 + 3);
          if ( (*(_WORD *)(a3 + 16) & 1) != 0 )
            CmpCopyCompressedName(v15, v13, a3 + 20, *(unsigned __int16 *)(a3 + 2));
          else
            memmove(v15, a3 + 20, v13);
        }
        else
        {
          v14 = -1073741789;
          v33 = -1073741789;
        }
        v11 = v36;
        break;
      case 1:
      case 3:
        v16 = *(_DWORD *)(a3 + 4);
        v35 = v16;
        if ( v16 < 0x80000000 )
        {
          v43 = 0;
        }
        else
        {
          v16 += 0x80000000;
          v35 = v16;
          v43 = 1;
        }
        v17 = v12 + v16 + 20;
        v40 = 0;
        if ( v16 )
        {
          v18 = v12 + 20;
          if ( a4 == 3 )
            v19 = (v12 + 27) & 0xFFFFFFF8;
          else
            v19 = (v12 + 23) & 0xFFFFFFFC;
          v40 = v19;
          if ( v19 > v18 )
            v17 += v19 - v18;
          v16 = v35;
        }
        v14 = 0;
        *a7 = v17;
        if ( a6 >= 0x14 )
        {
          v20 = 0;
          *a5 = 0;
          a5[1] = *(_DWORD *)(a3 + 12);
          a5[3] = v16;
          a5[4] = v13;
          if ( a6 - 20 >= v13 )
          {
            v44[0] = -2147483643;
          }
          else
          {
            v13 = a6 - 20;
            v44[0] = -2147483643;
            v14 = -2147483643;
            v33 = -2147483643;
          }
          if ( (*(_WORD *)(a3 + 16) & 1) != 0 )
          {
            v21 = v13 >> 1;
            if ( v13 >> 1 >= *(unsigned __int16 *)(a3 + 2) )
              v21 = *(unsigned __int16 *)(a3 + 2);
            while ( v20 < v21 )
            {
              *((_WORD *)a5 + v20 + 10) = *(unsigned __int8 *)(v20 + a3 + 20);
              ++v20;
            }
          }
          else
          {
            memmove((int)(a5 + 5), a3 + 20, v13);
          }
          v22 = v35;
          if ( v35 )
          {
            if ( v43 == 1 )
            {
              v9 = a3 + 8;
              v34 = a3 + 8;
            }
            else
            {
              if ( CmpGetValueData(*(_DWORD *)(v41 + 20), v42, a3, &v41, &v43, v32, &v39) )
                v9 = v43;
              else
                v9 = 0;
              v34 = v9;
              if ( !v9 )
              {
                v14 = -1073741670;
                v33 = -1073741670;
              }
              v22 = v35;
              v10 = (unsigned __int8)v32[0];
            }
            v23 = v40;
            a5[2] = v40;
            if ( a6 >= v23 )
              v24 = a6 - v23;
            else
              v24 = 0;
            if ( v24 < v22 )
            {
              v22 = v24;
              v14 = v44[0];
              v33 = v44[0];
            }
            if ( v9 )
              memmove((int)a5 + v23, v9, v22);
          }
          else
          {
            a5[2] = -1;
          }
        }
        else
        {
          v14 = -1073741789;
          v33 = -1073741789;
        }
        v11 = v36;
        break;
      case 4:
        v25 = *(_DWORD *)(a3 + 4);
        if ( v25 < 0x80000000 )
        {
          v26 = 0;
        }
        else
        {
          v25 += 0x80000000;
          v26 = 1;
        }
        v14 = 0;
        *a7 = v25 + 8;
        if ( a6 >= 8 )
        {
          *a5 = *(_DWORD *)(a3 + 12);
          a5[1] = v25;
          v27 = v25;
          if ( a6 - 8 < v25 )
          {
            v27 = a6 - 8;
            v14 = -2147483643;
            v33 = -2147483643;
          }
          if ( v25 )
          {
            if ( v26 == 1 )
            {
              v9 = a3 + 8;
              v34 = a3 + 8;
            }
            else
            {
              v9 = CmpGetValueDataFromCache(v41, v42, a3, v32, &v39);
              v34 = v9;
              if ( !v9 )
              {
                v14 = -1073741670;
                v33 = -1073741670;
              }
              v10 = (unsigned __int8)v32[0];
            }
            if ( v9 )
              memmove((int)(a5 + 2), v9, v27);
          }
        }
        else
        {
          v14 = -1073741789;
          v33 = -1073741789;
        }
        v11 = v36;
        break;
      default:
        v14 = -1073741811;
        break;
    }
  }
  if ( v9 && v9 != a3 + 8 )
  {
    if ( v10 == 1 )
      ExFreePoolWithTag(v9);
    else
      (*(void (__fastcall **)(int, int *))(v11 + 8))(v11, &v39);
  }
  return v14;
}
