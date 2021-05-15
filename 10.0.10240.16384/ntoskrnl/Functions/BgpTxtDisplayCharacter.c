// BgpTxtDisplayCharacter 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BgpTxtDisplayCharacter(__int64 *a1, unsigned int a2, int a3, int *a4, int *a5, int a6, _DWORD *a7)
{
  int v8; // r3
  int v9; // r10
  int v10; // r0
  int v11; // r7
  int v12; // r4
  int v13; // r5
  int v14; // r2
  BOOL v15; // r3
  int *v16; // r6
  BOOL v17; // r8
  void **v18; // r7
  int v19; // r3
  int v20; // r10
  __int64 v21; // r2
  _DWORD *v23; // r0
  int v24; // r0
  int v25; // r4 OVERLAPPED
  int v26; // r3
  int v27; // r0
  int v28; // [sp+18h] [bp-60h]
  int v29; // [sp+1Ch] [bp-5Ch]
  int v30; // [sp+20h] [bp-58h]
  int v32; // [sp+28h] [bp-50h] BYREF
  int v33; // [sp+2Ch] [bp-4Ch] BYREF
  int v34; // [sp+30h] [bp-48h] BYREF
  int v35[2]; // [sp+38h] [bp-40h] BYREF
  int v36; // [sp+40h] [bp-38h]
  int v37; // [sp+44h] [bp-34h]
  int v38; // [sp+48h] [bp-30h]
  int *v39; // [sp+4Ch] [bp-2Ch]
  int v40; // [sp+50h] [bp-28h] BYREF
  int v41; // [sp+54h] [bp-24h]

  v38 = a3;
  v39 = a4;
  v40 = 0;
  v41 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35[0] = 0;
  v8 = *((_DWORD *)a1 + 11);
  v9 = *((_DWORD *)a1 + 5);
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = (v8 & 1) != 0;
  v16 = (int *)*((_DWORD *)a1 + 6);
  v17 = v15;
  v30 = 0;
  v28 = 0;
  v29 = 0;
  v32 = 0;
  v33 = 0;
  if ( a2 < 0x20 )
    goto LABEL_19;
  v18 = (void **)a6;
  if ( v15 )
  {
    if ( a6 && *(_BYTE *)(a6 + 48) && (v19 = TxtpGetCacheEntry(a6), (v28 = v19) != 0)
      || (v19 = TxtpGetCacheEntry(&TxtpTextCache), (v28 = v19) != 0) )
    {
      v12 = *(_DWORD *)(v19 + 32);
      v17 = 0;
LABEL_8:
      v20 = 0;
      goto LABEL_9;
    }
  }
  v23 = BgpGxFillRectangle(v16, *((_DWORD *)a1 + 7));
  v37 = v16[1];
  v36 = *v16;
  v24 = BgpRasPrintGlyph(v23, (_DWORD *)a1 + 7, a2, v40, v41, 1, &v32, a6, a7);
  v13 = v24;
  if ( v24 < 0 )
  {
    DbgPrintEx(101, 0, (int)"BGFX internal font error %x char %x!\n", v24);
    v14 = v32;
    v11 = 0;
    goto LABEL_18;
  }
  v25 = v32;
  v29 = v32;
  if ( !v17 )
  {
    v13 = BgpFoGetTextMetrics((int)a1 + 28, (int)v35);
    if ( v13 < 0 )
      return v13;
    v26 = v35[1];
    *(_QWORD *)v16 = *(_QWORD *)(&v25 - 1);
    v30 = v26;
    v35[0] = 1;
  }
  if ( v9 )
  {
    TxtpJustifyRectangle(a1, a1 + 1, &v40);
    v13 = BgpGxBlendRectangle(v9, v16, &v40, &v33);
    v12 = v33;
    if ( v13 < 0 )
      goto LABEL_17;
  }
  else
  {
    v12 = (int)v16;
  }
  if ( !v17 )
    goto LABEL_8;
  v27 = BgpGetBitsPerPixel();
  if ( (int *)v12 != v16 && v27 == *(_DWORD *)(v12 + 8) )
  {
    v20 = v12;
LABEL_9:
    v21 = *a1;
    v41 = *((_DWORD *)a1 + 1);
    v40 += v21;
    if ( (v38 & 1) != 0
      || (dword_619018 & 0x1000000) != 0
      || (v13 = BgpGxDrawRectangle((char *)v12, (int)&v40), v13 >= 0) )
    {
      if ( v17 )
      {
        if ( !a6 || !*(_BYTE *)(a6 + 48) )
          v18 = &TxtpTextCache;
        v13 = TxtpAddCacheEntry(v18, a2, (char *)a1 + 28, v20);
      }
    }
    goto LABEL_17;
  }
  v13 = BgpGxConvertRectangle((_DWORD *)v12, v27, (int)&v34, 0);
  if ( v13 >= 0 )
  {
    if ( (int *)v12 != v16 )
      BgpGxRectangleDestroy(v12);
    v20 = v34;
    v12 = v34;
    goto LABEL_9;
  }
LABEL_17:
  v14 = v29;
  v11 = v30;
LABEL_18:
  v10 = v28;
LABEL_19:
  if ( v39 )
    *v39 = v14;
  if ( a5 )
    *a5 = v11;
  if ( (int *)v12 != v16 && !v10 && (!v17 || v13 < 0) && v12 )
    BgpGxRectangleDestroy(v12);
  if ( v35[0] )
  {
    *v16 = v36;
    v16[1] = v37;
  }
  return v13;
}
