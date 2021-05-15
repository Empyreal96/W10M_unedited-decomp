// CmpSetValueDataNew 
 
int __fastcall CmpSetValueDataNew(int a1, int a2, unsigned int a3, int a4, int *a5)
{
  unsigned int v5; // r4
  int v6; // r5
  unsigned int v8; // r7
  int v10; // r0
  int *v11; // r1
  int v13; // r0
  _WORD *v14; // r4
  unsigned int v15; // r5
  int v16; // r0
  _WORD *v17; // r5
  unsigned int v18; // r2
  unsigned int v19; // r2
  unsigned int v20; // r3
  int v21; // r1
  __int16 v22; // r2
  int v23; // [sp+8h] [bp-38h] BYREF
  int v24; // [sp+Ch] [bp-34h]
  _WORD *v25; // [sp+10h] [bp-30h] BYREF
  int v26; // [sp+14h] [bp-2Ch] BYREF
  int v27; // [sp+18h] [bp-28h] BYREF
  unsigned int v28; // [sp+1Ch] [bp-24h]

  v5 = *(_DWORD *)(a1 + 148);
  v6 = a2;
  v8 = a3;
  v23 = -1;
  v24 = a2;
  if ( v5 < 4 )
  {
LABEL_4:
    v10 = HvAllocateCell(a1, a3, a4, &v25, &v23);
    *a5 = v10;
    if ( v10 != -1 )
    {
      memmove((int)v25, v6, v8);
      v11 = &v23;
LABEL_6:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v11);
      return 0;
    }
LABEL_25:
    JUMPOUT(0x7E8258);
  }
  if ( a3 - 16345 > 0x7FFFC026 )
  {
    v6 = a2;
    goto LABEL_4;
  }
  v26 = -1;
  v27 = -1;
  v13 = HvAllocateCell(a1, 8, a4, &v25, &v27);
  *a5 = v13;
  if ( v13 == -1 )
    goto LABEL_25;
  v14 = v25;
  *v25 = 25188;
  v14[1] = 0;
  *((_DWORD *)v14 + 1) = -1;
  v15 = (unsigned __int16)((v8 + 16343) / 0x3FD8);
  v28 = v15;
  v16 = HvAllocateCell(a1, 4 * v15, a4, &v25, &v26);
  *((_DWORD *)v14 + 1) = v16;
  if ( v16 != -1 )
  {
    if ( (unsigned __int16)v14[1] >= v15 )
    {
LABEL_15:
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
      v11 = &v27;
      goto LABEL_6;
    }
    v17 = v25;
    while ( 1 )
    {
      v16 = HvAllocateCell(a1, 16344, a4, &v25, &v23);
      *(_DWORD *)&v17[2 * (unsigned __int16)v14[1]] = v16;
      if ( *(_DWORD *)&v17[2 * (unsigned __int16)v14[1]] == -1 )
        break;
      if ( v8 <= 0x3FD8 )
        v18 = v8;
      else
        v18 = 16344;
      memmove((int)v25, v24, v18);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23);
      v25 = 0;
      v19 = v28;
      v8 -= 16344;
      v24 += 16344;
      v20 = (unsigned __int16)(v14[1] + 1);
      v14[1] = v20;
      if ( v20 >= v19 )
        goto LABEL_15;
    }
    if ( v17 )
    {
      if ( v14[1] )
      {
        do
        {
          v21 = *(_DWORD *)&v17[2 * (unsigned __int16)v14[1]];
          if ( v21 != -1 )
            HvFreeCell(a1, v21);
          v22 = v14[1];
          v14[1] = v22 - 1;
        }
        while ( v22 != 1 );
      }
      v16 = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
    }
  }
  if ( *((_DWORD *)v14 + 1) == -1 )
    JUMPOUT(0x7E8242);
  return sub_7E823C(v16);
}
