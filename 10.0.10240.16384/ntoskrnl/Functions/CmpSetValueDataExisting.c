// CmpSetValueDataExisting 
 
int __fastcall CmpSetValueDataExisting(int a1, int a2, int a3, int a4, int a5)
{
  int (__fastcall *v6)(int, int, _DWORD *); // r4
  unsigned int v7; // r9
  int v8; // r0
  int v9; // r7
  int v10; // r6
  unsigned int v11; // r4
  unsigned int v12; // r3
  unsigned int v14; // r8
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r4
  int v18; // r2
  unsigned __int16 v19; // r8
  int v20; // r0
  int v21; // [sp+8h] [bp-38h] BYREF
  int v22; // [sp+Ch] [bp-34h] BYREF
  int v23; // [sp+10h] [bp-30h]
  int v24; // [sp+14h] [bp-2Ch]
  int v25; // [sp+18h] [bp-28h] BYREF
  _DWORD v26[9]; // [sp+1Ch] [bp-24h] BYREF

  v6 = *(int (__fastcall **)(int, int, _DWORD *))(a1 + 4);
  v23 = a2;
  v24 = a3;
  v7 = a3;
  v26[0] = -1;
  v26[1] = a4;
  v25 = -1;
  v22 = -1;
  v8 = v6(a1, a5, v26);
  v9 = v8;
  if ( !v8 )
    return -1073741670;
  v10 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v8 + 4), &v22);
  if ( v10 )
  {
    v11 = (unsigned __int16)((v7 + 16343) / 0x3FD8);
    v12 = *(unsigned __int16 *)(v9 + 2);
    if ( v11 > v12 )
      return sub_7F04AC();
    if ( v11 < v12 )
    {
      v18 = (unsigned __int16)((v7 + 16343) / 0x3FD8);
      v19 = (v7 + 16343) / 0x3FD8;
      do
      {
        HvFreeCell(a1, *(_DWORD *)(v10 + 4 * v18));
        v18 = ++v19;
      }
      while ( v19 < (unsigned int)*(unsigned __int16 *)(v9 + 2) );
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
      v21 = 0;
      v20 = HvReallocateCell(a1, *(_DWORD *)(v9 + 4), 4 * v11, 1, &v21, &v22);
      v10 = v21;
      if ( v20 == -1 )
        goto LABEL_20;
      *(_DWORD *)(v9 + 4) = v20;
    }
    v14 = 0;
    if ( !(unsigned __int16)((v7 + 16343) / 0x3FD8) )
    {
LABEL_12:
      *(_WORD *)(v9 + 2) = v11;
      v17 = 0;
      goto LABEL_13;
    }
    while ( 1 )
    {
      v15 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v10 + 4 * v14), &v25);
      if ( !v15 )
        break;
      if ( v7 <= 0x3FD8 )
        v16 = v7;
      else
        v16 = 16344;
      memmove(v15, v23, v16);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
      v7 -= 16344;
      v23 += 16344;
      v14 = (unsigned __int16)(v14 + 1);
      if ( v14 >= v11 )
        goto LABEL_12;
    }
LABEL_20:
    v17 = -1073741670;
LABEL_13:
    if ( v10 )
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
    goto LABEL_15;
  }
  v17 = -1073741670;
LABEL_15:
  (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v26);
  return v17;
}
