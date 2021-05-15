// AnFwpFadeAnimationTimer 
 
int __fastcall AnFwpFadeAnimationTimer(unsigned int a1)
{
  __int64 v1; // r2
  _DWORD *v2; // r9
  _DWORD *v3; // r5
  _DWORD *v4; // r10
  __int64 v5; // kr00_8
  unsigned int v6; // r6
  int v7; // r7
  _BYTE *v8; // r2
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r3
  int v12; // r4
  _BYTE *v13; // r2
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r3
  int v17; // r9
  int v18; // r5
  _BYTE *v19; // r2
  unsigned int v20; // r1
  int v21; // r0
  unsigned int v22; // r3
  unsigned __int8 *v23; // r2
  unsigned int v24; // r0
  int v25; // r4
  unsigned __int8 *v26; // r1
  unsigned int v27; // r3
  unsigned int v28; // r3
  unsigned int v29; // r3
  unsigned __int8 *v30; // r2
  unsigned int v31; // r0
  int v32; // r5
  unsigned __int8 *v33; // r1
  unsigned int v34; // r3
  unsigned int v35; // r3
  unsigned int v36; // r3
  unsigned __int8 *v37; // r2
  unsigned int v38; // r0
  int v39; // lr
  unsigned __int8 *v40; // r1
  unsigned int v41; // r3
  unsigned int v42; // r3
  unsigned int v43; // r3
  char v44; // r10
  __int64 v45; // r2
  int v47; // [sp+0h] [bp-50h]
  int v48; // [sp+4h] [bp-4Ch]
  int v49; // [sp+Ch] [bp-44h]
  int v50; // [sp+10h] [bp-40h]
  __int64 v51; // [sp+18h] [bp-38h] BYREF
  int v52[2]; // [sp+20h] [bp-30h] BYREF
  char v53; // [sp+28h] [bp-28h] BYREF

  BgpFwAcquireLock(a1);
  if ( byte_653568 )
  {
    LogFwStat(&v51, 1, 6i64);
    LogFwStat(&v51, 1, 4i64);
    LODWORD(v1) = dword_618084;
    v2 = off_618094;
    v52[0] = dword_618088;
    v3 = off_6180B8;
    v4 = off_6180DC;
    v52[1] = dword_61808C;
    HIDWORD(v1) = (unsigned __int8)byte_618090;
    v5 = v1;
    LODWORD(v51) = (unsigned __int8)byte_618091;
    v47 = (unsigned __int8)byte_618092;
    v49 = dword_6180B4;
    v48 = dword_6180BC;
    v50 = dword_6180E0;
    if ( dword_61901C == dword_618084 )
      __brkdiv0();
    v6 = 10 * (dword_618080 - dword_618080 / (unsigned int)(dword_61901C - dword_618084));
    if ( BgpGetBitsPerPixel() == 24 )
    {
      v7 = 0;
      if ( !v47 )
      {
        v8 = (_BYTE *)v3[5];
        v9 = 0;
        if ( v3[3] )
        {
          v10 = *(_DWORD *)(v48 + 20) - (_DWORD)v8;
          do
          {
            if ( *v8 )
            {
              v11 = ((unsigned __int8)*v8 * v6) >> 10;
              v8[v10] = v11;
              if ( v11 )
                ++v7;
            }
            ++v9;
            ++v8;
          }
          while ( v9 < v3[3] );
        }
      }
      v12 = 0;
      if ( !HIDWORD(v5) )
      {
        v13 = (_BYTE *)v2[5];
        v14 = 0;
        if ( v2[3] )
        {
          v15 = *(_DWORD *)(v49 + 20) - (_DWORD)v13;
          do
          {
            if ( *v13 )
            {
              v16 = ((unsigned __int8)*v13 * v6) >> 10;
              v13[v15] = v16;
              if ( v16 )
                ++v12;
            }
            ++v14;
            ++v13;
          }
          while ( v14 < v2[3] );
        }
      }
      v17 = v51;
      v18 = 0;
      if ( !(_DWORD)v51 )
      {
        v19 = (_BYTE *)v4[5];
        v20 = 0;
        if ( v4[3] )
        {
          v21 = *(_DWORD *)(v50 + 20) - (_DWORD)v19;
          do
          {
            if ( *v19 )
            {
              v22 = ((unsigned __int8)*v19 * v6) >> 10;
              v19[v21] = v22;
              if ( v22 )
                ++v18;
            }
            ++v20;
            ++v19;
          }
          while ( v20 < v4[3] );
        }
      }
    }
    else
    {
      v7 = 0;
      if ( !v47 )
      {
        v23 = (unsigned __int8 *)v3[5];
        v24 = 0;
        if ( v3[3] )
        {
          v25 = *(_DWORD *)(v48 + 20) - (_DWORD)v23;
          do
          {
            if ( *(_DWORD *)v23 )
            {
              v26 = &v23[v25];
              v27 = (*v23 * v6) >> 10;
              v23[v25] = v27;
              if ( v27 )
                ++v7;
              v28 = (v23[1] * v6) >> 10;
              v26[1] = v28;
              if ( v28 )
                ++v7;
              v29 = (v23[2] * v6) >> 10;
              v26[2] = v29;
              if ( v29 )
                ++v7;
            }
            v24 += 4;
            v23 += 4;
          }
          while ( v24 < v3[3] );
        }
      }
      v12 = 0;
      if ( !HIDWORD(v5) )
      {
        v30 = (unsigned __int8 *)v2[5];
        v31 = 0;
        if ( v2[3] )
        {
          v32 = *(_DWORD *)(v49 + 20) - (_DWORD)v30;
          do
          {
            if ( *(_DWORD *)v30 )
            {
              v33 = &v30[v32];
              v34 = (*v30 * v6) >> 10;
              v30[v32] = v34;
              if ( v34 )
                ++v12;
              v35 = (v30[1] * v6) >> 10;
              v33[1] = v35;
              if ( v35 )
                ++v12;
              v36 = (v30[2] * v6) >> 10;
              v33[2] = v36;
              if ( v36 )
                ++v12;
            }
            v31 += 4;
            v30 += 4;
          }
          while ( v31 < v2[3] );
        }
      }
      v17 = v51;
      v18 = 0;
      if ( !(_DWORD)v51 )
      {
        v37 = (unsigned __int8 *)v4[5];
        v38 = 0;
        if ( v4[3] )
        {
          v39 = *(_DWORD *)(v50 + 20) - (_DWORD)v37;
          do
          {
            if ( *(_DWORD *)v37 )
            {
              v40 = &v37[v39];
              v41 = (*v37 * v6) >> 10;
              v37[v39] = v41;
              if ( v41 )
                ++v18;
              v42 = (v37[1] * v6) >> 10;
              v40[1] = v42;
              if ( v42 )
                ++v18;
              v43 = (v37[2] * v6) >> 10;
              v40[2] = v43;
              if ( v43 )
                ++v18;
            }
            v38 += 4;
            v37 += 4;
          }
          while ( v38 < v4[3] );
        }
      }
    }
    LogFwStat(&v51, 0, 4i64);
    LogFwStat(&v51, 1, 3i64);
    if ( !v47 )
    {
      BgpGxDrawRectangle((char *)v48, (int)v52);
      if ( !v7 )
        LOBYTE(v47) = 1;
    }
    v44 = BYTE4(v5);
    if ( !HIDWORD(v5) )
    {
      if ( !(_DWORD)v5 && !v12 || (BgpGxDrawRectangle((char *)v49, (int)&dword_618098), !v12) )
        v44 = 1;
    }
    if ( !v17 )
    {
      if ( (_DWORD)v5 || v12 )
        BgpGxDrawRectangle((char *)v50, (int)&dword_6180C0);
      if ( !v18 )
        LOBYTE(v17) = 1;
    }
    LogFwStat(&v51, 0, 3i64);
    HIDWORD(v45) = &v53;
    LODWORD(v45) = 6;
    LogFwStat(&v51, 0, v45);
    if ( v7 || v18 || v12 )
    {
      dword_618080 = v6 / 0xA;
      dword_618084 = v5 + 1;
      byte_618090 = v44;
      byte_618091 = v17;
      byte_618092 = v47;
    }
    else
    {
      byte_653568 = 0;
      KeCancelTimer((int)&unk_653408);
      KeSetEvent((int)&unk_649DC8, 0, 0);
    }
  }
  return BgpFwReleaseLock();
}
