// CmpGetValueData 
 
int __fastcall CmpGetValueData(int a1, int a2, int a3, unsigned int *a4, int *a5, _BYTE *a6, int a7)
{
  unsigned int v8; // r4
  int v10; // r0
  int result; // r0
  int v12; // r1
  int v13; // r10
  int v14; // r0
  unsigned int v15; // r4
  unsigned int v16; // r7
  int v17; // r1
  int (__fastcall *v18)(int, int, int *); // r3
  int v19; // r1
  unsigned int v20; // r2
  int v21; // r4
  int v22; // r0
  int v23; // [sp+0h] [bp-38h] BYREF
  int v24; // [sp+4h] [bp-34h]
  int v25; // [sp+8h] [bp-30h] BYREF
  int v26; // [sp+Ch] [bp-2Ch] BYREF
  int v27; // [sp+10h] [bp-28h]
  unsigned int v28; // [sp+14h] [bp-24h]

  *a6 = 0;
  *a5 = 0;
  v8 = *(_DWORD *)(a3 + 4);
  if ( v8 >= 0x80000000 )
  {
    *a4 = v8 + 0x80000000;
    if ( !(*(int (__fastcall **)(int, int, int))(a1 + 4))(a1, a2, a7) )
      goto LABEL_25;
    *a5 = a3 + 8;
    return 1;
  }
  *a4 = v8;
  if ( *(_DWORD *)(a1 + 148) < 4u || v8 <= 0x3FD8 )
  {
    v10 = (*(int (__fastcall **)(int, _DWORD, int))(a1 + 4))(a1, *(_DWORD *)(a3 + 8), a7);
    *a5 = v10;
    if ( v10 )
      return 1;
LABEL_25:
    JUMPOUT(0x804BAC);
  }
  v12 = *(_DWORD *)(a3 + 8);
  v25 = -1;
  v26 = -1;
  v23 = -1;
  v13 = 0;
  v14 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v12, &v26);
  v24 = v14;
  if ( !v14 )
    goto LABEL_25;
  v27 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v14 + 4), &v25);
  if ( v27 )
  {
    v15 = *(_DWORD *)(a3 + 4);
    v13 = ExAllocatePoolWithTag(1, v15, 1685474627);
    if ( v13 )
    {
      v16 = 0;
      if ( !*(_WORD *)(v24 + 2) )
      {
LABEL_16:
        v21 = 1;
LABEL_17:
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v25);
        goto LABEL_18;
      }
      while ( 1 )
      {
        v17 = *(_DWORD *)(v27 + 4 * v16);
        v18 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
        v28 = v16;
        v19 = v18(a1, v17, &v23);
        if ( !v19 )
          break;
        if ( v15 <= 0x3FD8 )
          v20 = v15;
        else
          v20 = 16344;
        memmove(v13 + 16344 * v28, v19, v20);
        v15 -= 16344;
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v23);
        v16 = (unsigned __int16)(v16 + 1);
        if ( v16 >= *(unsigned __int16 *)(v24 + 2) )
          goto LABEL_16;
      }
    }
    v21 = 0;
    goto LABEL_17;
  }
  v21 = 0;
LABEL_18:
  v22 = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v26);
  if ( v21 )
  {
    *a5 = v13;
    *a6 = 1;
    result = 1;
  }
  else
  {
    if ( !v13 )
      goto LABEL_25;
    result = sub_804BA4(v22);
  }
  return result;
}
