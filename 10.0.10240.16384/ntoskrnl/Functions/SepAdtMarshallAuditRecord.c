// SepAdtMarshallAuditRecord 
 
int __fastcall SepAdtMarshallAuditRecord(int a1, int *a2, int *a3, int a4)
{
  unsigned int v4; // r7
  int v6; // r4
  int *v7; // r6
  int v8; // r10
  unsigned int v9; // r1
  int v10; // r9
  unsigned int v11; // lr
  _DWORD *v12; // r5
  unsigned int v14; // r4
  int v15; // r5
  int v16; // r0
  int v17; // r3
  _DWORD *v18; // r7
  unsigned int v19; // r0
  int v20; // r1
  int v21; // r9
  unsigned int *v22; // r6
  unsigned __int16 *v23; // r5
  unsigned int *v24; // r4
  __int16 v25; // r3
  int v26; // r3
  unsigned int *v27; // r5
  unsigned int *v28; // r4
  unsigned int v29; // r10
  unsigned int v30; // r7
  unsigned int *v31; // r9
  int v32; // r1
  unsigned int v33; // r4
  unsigned int v34; // [sp+0h] [bp-38h]
  _DWORD *v36; // [sp+8h] [bp-30h]
  int v37; // [sp+Ch] [bp-2Ch]
  unsigned int v38; // [sp+10h] [bp-28h]
  unsigned int *v39; // [sp+14h] [bp-24h]

  v4 = *(_DWORD *)(a1 + 8);
  v6 = a4;
  v7 = a3;
  v8 = 0;
  v9 = 0;
  v10 = a1;
  v11 = 0;
  v12 = (_DWORD *)(a1 + 24);
  if ( v4 )
  {
    while ( 1 )
    {
      if ( *v12 == 17 )
        return sub_51DAD8();
      v14 = (v12[1] + 3) & 0xFFFFFFFC;
      if ( v14 + v9 < v9 )
        break;
      ++v11;
      v12 += 5;
      v9 += v14;
      if ( v11 >= v4 )
      {
        v7 = a3;
        v6 = a4;
        v10 = a1;
        goto LABEL_7;
      }
    }
    v8 = -1073741811;
  }
  else
  {
LABEL_7:
    v15 = v9 + 20 * v4 + 24;
    v16 = ExAllocatePoolWithTag(v6, v15);
    *a2 = v16;
    if ( v16 )
    {
      if ( v6 == 1 )
        v17 = 4;
      else
        v17 = 5;
      *v7 = v17;
      memmove(*a2, v10, 20 * *(_DWORD *)(v10 + 8) + 24);
      v18 = (_DWORD *)(v10 + 24);
      v19 = 0;
      *(_DWORD *)(*a2 + 12) = v15;
      v36 = (_DWORD *)(v10 + 24);
      v34 = 0;
      *(_DWORD *)(*a2 + 20) |= 1u;
      v20 = *(_DWORD *)(a1 + 8);
      v21 = *a2 + 24;
      v37 = v21;
      v22 = (unsigned int *)(*a2 + 20 * v20 + 24);
      if ( v20 )
      {
        do
        {
          switch ( *v18 )
          {
            case 1:
            case 2:
            case 0x22:
              v23 = (unsigned __int16 *)v18[4];
              v24 = v22;
              *(_DWORD *)(v21 + 16) = (char *)v22 - *a2;
              v22 += 2;
              memmove((int)v22, *((_DWORD *)v23 + 1), *v23);
              v25 = *v23;
              *(_WORD *)v24 = *v23;
              *((_WORD *)v24 + 1) = v25;
              v24[1] = (unsigned int)v22 - *a2;
              v26 = *v23;
              goto LABEL_16;
            case 4:
            case 8:
            case 9:
            case 0xD:
            case 0x17:
            case 0x18:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
            case 0x21:
              goto LABEL_20;
            case 0x11:
              v27 = (unsigned int *)v18[4];
              v28 = v22;
              *v22 = *v27;
              v22[1] = v27[1];
              *(_DWORD *)(v21 + 16) = (char *)v22 - *a2;
              v22 += 2;
              v38 = v27[1];
              v39 = v22;
              if ( *v27 )
              {
                memmove((int)v22, v27[1], 8 * *v27);
                v19 = v34;
                v28[1] = (unsigned int)v22 - *a2;
                v22 += 2 * *v27;
              }
              else
              {
                v28[1] = 0;
              }
              v29 = 0;
              if ( !*v27 )
                break;
              v30 = v38;
              v31 = v39;
              do
              {
                v31[1] = (unsigned int)v22 - *a2;
                v32 = *(_DWORD *)(v30 + 4);
                v33 = 4 * (*(unsigned __int8 *)(v32 + 1) + 2);
                memmove((int)v22, v32, v33);
                v22 = (unsigned int *)((char *)v22 + ((v33 + 3) & 0xFFFFFFFC));
                ++v29;
                v30 += 8;
                v31 += 2;
              }
              while ( v29 < *v27 );
              v18 = v36;
              v21 = v37;
              goto LABEL_17;
            case 0x16:
              *(_DWORD *)(*a2 + 20) |= 2u;
              break;
            case 0x20:
              *(_DWORD *)(*a2 + 20) |= 2u;
LABEL_20:
              memmove((int)v22, v18[4], v18[1]);
              *(_DWORD *)(v21 + 16) = (char *)v22 - *a2;
              v26 = v18[1];
LABEL_16:
              v22 = (unsigned int *)((char *)v22 + ((v26 + 3) & 0xFFFFFFFC));
LABEL_17:
              v19 = v34;
              break;
            default:
              break;
          }
          ++v19;
          v18 += 5;
          v21 += 20;
          v34 = v19;
          v36 = v18;
          v37 = v21;
        }
        while ( v19 < *(_DWORD *)(a1 + 8) );
        v8 = 0;
      }
    }
    else
    {
      v8 = -1073741670;
      *v7 = 0;
    }
  }
  return v8;
}
