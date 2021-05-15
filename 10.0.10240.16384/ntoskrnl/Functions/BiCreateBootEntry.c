// BiCreateBootEntry 
 
int __fastcall BiCreateBootEntry(int a1, int a2)
{
  unsigned int v2; // r5
  unsigned __int16 *v3; // r6
  int v5; // r8
  unsigned __int16 *v6; // r9
  unsigned int v7; // r7
  int v8; // r4
  unsigned __int16 *v9; // r4
  _DWORD *v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r4
  _DWORD *v13; // r0
  _DWORD *v14; // r4
  unsigned int v15; // r2
  unsigned int v16; // r0
  unsigned int v17; // r10
  unsigned __int16 *v18; // r2
  unsigned int v19; // r4
  int v20; // r1
  _DWORD *v21; // r0
  unsigned int v22; // r3
  unsigned __int16 *v23; // r1
  unsigned __int16 *v24; // r3
  char *v25; // r4
  int v26; // r1
  unsigned int v27; // r3
  char *v28; // r3
  _DWORD *v29; // r2
  int v31; // [sp+8h] [bp-40h] BYREF
  unsigned __int16 *v32; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD *v33; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 *v34; // [sp+14h] [bp-34h] BYREF
  unsigned int v35; // [sp+18h] [bp-30h] BYREF
  unsigned int v36; // [sp+1Ch] [bp-2Ch] BYREF
  unsigned int v37; // [sp+20h] [bp-28h]
  unsigned int v38; // [sp+24h] [bp-24h] BYREF
  _DWORD *v39; // [sp+28h] [bp-20h]

  v39 = (_DWORD *)a2;
  v35 = 0;
  v2 = 0;
  v3 = 0;
  v32 = 0;
  v33 = 0;
  v5 = 0;
  v31 = 0;
  v6 = 0;
  v34 = 0;
  v7 = 0;
  v8 = BiGetElement(a1, 301989892, (int *)&v35, &v36);
  if ( v8 >= 0 )
  {
    v8 = BiGetElement(a1, 285212673, (int *)&v33, &v38);
    if ( v8 < 0 )
    {
      v2 = (unsigned int)v33;
    }
    else
    {
      v8 = BiGetElement(a1, 301989890, (int *)&v32, &v38);
      v3 = v32;
      v2 = (unsigned int)v33;
      if ( v8 < 0 )
        goto LABEL_18;
      if ( *v33 != 2 )
      {
        v8 = -1073741637;
        goto LABEL_18;
      }
      v9 = (unsigned __int16 *)(wcslen(v32) + 1);
      v32 = v9;
      v10 = (_DWORD *)(2 * (wcslen((unsigned __int16 *)(v2 + 20)) + 1));
      v11 = (unsigned int)v10 + 2 * (_DWORD)v9;
      v33 = v10;
      if ( v11 < (unsigned int)v10 )
        goto LABEL_16;
      v12 = v11 + 12;
      if ( v11 + 12 < v11 )
        goto LABEL_16;
      v13 = (_DWORD *)ExAllocatePoolWithTag(1, v11 + 12, 1262764866);
      v7 = (unsigned int)v13;
      if ( !v13 )
      {
LABEL_9:
        v8 = -1073741670;
        goto LABEL_18;
      }
      v13[1] = v12;
      v14 = v33;
      v15 = (unsigned int)v33;
      *v13 = 1;
      v13[2] = 3;
      memmove((int)(v13 + 3), v2 + 20, v15);
      memmove((int)v14 + v7 + 12, (int)v3, 2 * (_DWORD)v32);
      v8 = BiTranslateFilePath(v7, 4, &v31);
      if ( v8 < 0 || (v8 = BiGetKeyName(a1, (int *)&v34), v6 = v34, v8 < 0) )
      {
        v5 = v31;
        goto LABEL_18;
      }
      v16 = wcslen(v34);
      v37 = (2 * v16 + 45) & 0xFFFFFFFC;
      v38 = v16;
      v17 = v37 + 16;
      v18 = (unsigned __int16 *)((v37 + 47) & 0xFFFFFFFC);
      v5 = v31;
      v19 = v36;
      v32 = v18;
      v20 = *(_DWORD *)(v31 + 4);
      if ( (unsigned int)v18 + v20 + v36 + 4 < v36 )
      {
LABEL_16:
        v8 = -1073741675;
      }
      else
      {
        v34 = (unsigned __int16 *)(((unsigned int)v18 + v36 + 3) & 0xFFFFFFFC);
        v36 = (unsigned int)v34 + v20;
        v21 = (_DWORD *)ExAllocatePoolWithTag(1, (int)v34 + v20, 1262764866);
        v33 = v21;
        if ( !v21 )
          goto LABEL_9;
        v22 = v36;
        *v21 = 1;
        v21[1] = v22;
        v21[2] = -1;
        v21[3] = 1;
        v23 = v34;
        v24 = v32;
        v21[6] = v17;
        v21[4] = v24;
        v21[5] = v23;
        memmove((int)v24 + (_DWORD)v21, v35, v19);
        v25 = (char *)v33;
        memmove((int)v34 + (_DWORD)v33, v5, *(_DWORD *)(v5 + 4));
        v26 = v38 + 11;
        *((_DWORD *)v25 + 7) = *(_DWORD *)"WINDOWS";
        v25 += 28;
        strcpy(v25 + 4, "OWS");
        *((_DWORD *)v25 + 2) = 1;
        v27 = v37;
        *((_DWORD *)v25 + 3) = v17;
        *((_DWORD *)v25 + 4) = v27;
        swprintf_s((int)(v25 + 20), v26, (int)L"%s%s", L"BCDOBJECT=", v6);
        v28 = &v25[*((_DWORD *)v25 + 4)];
        *(_DWORD *)v28 = 1;
        *((_DWORD *)v28 + 1) = 16;
        *((_DWORD *)v28 + 2) = 4;
        v28[12] = 127;
        v28[13] = -1;
        v28[15] = 0;
        v29 = v39;
        v28[14] = 4;
        v8 = 0;
        *v29 = v33;
      }
    }
  }
LABEL_18:
  if ( v35 )
    ExFreePoolWithTag(v35);
  if ( v2 )
    ExFreePoolWithTag(v2);
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  if ( v5 )
    ExFreePoolWithTag(v5);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
