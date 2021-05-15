// VfIrpLogRetrieveWmiData 
 
int __fastcall VfIrpLogRetrieveWmiData(int a1, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int v6; // r10
  unsigned __int16 *v8; // r7
  int v9; // r4
  int v10; // r2
  _DWORD **v11; // r5
  _DWORD *v12; // r3
  int v13; // r8
  _DWORD **v14; // r3
  char *v15; // r9
  _DWORD *v16; // r2
  _DWORD *v17; // r6
  int v18; // r0
  _DWORD *v19; // r3
  unsigned int v20; // r6
  int v21; // r3
  unsigned int v22; // r10
  char *v23; // r9
  int v24; // r8
  _DWORD **v25; // r6
  _DWORD *v26; // r8
  int v27; // r9
  int v28; // r10
  _DWORD *i; // r7
  _DWORD *v30; // r2
  int v31; // r3
  int v32; // r5
  _DWORD *v33; // r1
  int v34; // r3
  int v35; // r8
  int v37; // [sp+0h] [bp-48h] BYREF
  _DWORD *v38; // [sp+4h] [bp-44h]
  int v39; // [sp+8h] [bp-40h]
  int v40; // [sp+Ch] [bp-3Ch]
  _DWORD **v41; // [sp+10h] [bp-38h]
  _DWORD *v42; // [sp+14h] [bp-34h]
  int v43; // [sp+18h] [bp-30h]
  int v44; // [sp+1Ch] [bp-2Ch]
  _DWORD *v45; // [sp+20h] [bp-28h]
  _DWORD *v46; // [sp+24h] [bp-24h]

  v6 = a2;
  v39 = a2;
  *a4 = 0;
  v45 = a3;
  v46 = a4;
  *a3 = 0;
  *a5 = 0;
  *a6 = 0;
  v40 = 8;
  v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 8, 1950967382);
  if ( !v8 )
    return -1073741670;
  v10 = 0;
  v43 = 3 * a1;
  v11 = (_DWORD **)(ViIrpLogDatabase + 12 * a1 + 4);
  v12 = *v11;
  while ( v12 != v11 )
  {
    v12 = (_DWORD *)*v12;
    ++v10;
  }
  v44 = 8 * v10 + 60;
  v13 = v44 + 4 * v10;
  v38 = (_DWORD *)(v44 + v6);
  v42 = (_DWORD *)(v6 + 60);
  v14 = (_DWORD **)*v11;
  v15 = (char *)(v13 + v6);
  v9 = 0;
  v16 = v11;
  while ( 1 )
  {
    v41 = (_DWORD **)v16;
    if ( v14 == v11 )
      break;
    v17 = (_DWORD *)*v16;
    v9 = ObQueryNameString(*(_DWORD *)(*v16 - 4), (int)v8, v40, &v37);
    if ( v9 == -1073741820 )
    {
      ExFreePoolWithTag((unsigned int)v8);
      v8 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v37, 1950967382);
      if ( !v8 )
        return -1073741670;
      v18 = *(v17 - 1);
      v40 = v37;
      v9 = ObQueryNameString(v18, (int)v8, v37, &v37);
    }
    if ( v9 < 0 )
      break;
    if ( *v8 )
    {
      v19 = v38;
      if ( v6 )
        *v38 = v13;
      v38 = v19 + 1;
      v20 = *v8 + 18;
      v21 = v39;
      v22 = v20 >> 1;
      if ( v39 )
        *(_WORD *)v15 = v20;
      v23 = v15 + 2;
      v24 = v13 + 2;
      if ( v21 )
      {
        qmemcpy(v23, "VERIFIER", 16);
        memmove((int)(v23 + 16), *((_DWORD *)v8 + 1), *v8);
        *(_WORD *)&v23[2 * v22 - 2] = 0;
      }
      v15 = &v23[2 * v22];
      v6 = v39;
      v13 = v24 + v20;
    }
    else
    {
      v17[2] |= 2u;
    }
    v16 = *v41;
    v14 = (_DWORD **)**v41;
  }
  ExFreePoolWithTag((unsigned int)v8);
  if ( v9 >= 0 )
  {
    v25 = (_DWORD **)((v13 + 7) & 0xFFFFFFF8);
    v26 = (_DWORD **)((char *)v25 + v6);
    v41 = v25;
    v27 = 0;
    v28 = ViIrpLogDatabase + 4 * v43 + 4;
    for ( i = (_DWORD *)v28; *i != v28; i = (_DWORD *)*i )
    {
      v30 = (_DWORD *)*i;
      v31 = *(_DWORD *)(*i + 8);
      if ( (v31 & 2) == 0 )
      {
        ++v27;
        if ( (v31 & 1) != 0 )
          v32 = v30[4];
        else
          v32 = v30[5];
        if ( v39 )
        {
          v33 = v42;
          *v42 = v25;
          v33[1] = 40 * v32 + 8;
          v34 = v30[3];
          v42 = v33 + 2;
          *v26 = v34;
          v26[1] = v32;
          v35 = (int)(v26 + 2);
          memmove(v35, (int)(v30 + 7), 40 * v32);
          v26 = (_DWORD *)(v35 + 40 * v32);
        }
        v25 += 10 * v32 + 2;
      }
    }
    v9 = 0;
    *v45 = v44;
    *v46 = v27;
    *a5 = v41;
    *a6 = v25;
  }
  return v9;
}
