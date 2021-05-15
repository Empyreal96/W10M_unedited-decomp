// EtwpEnableTrace 
 
int __fastcall EtwpEnableTrace(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5, char a6, int a7, int a8, int a9, int a10, int a11, _WORD *a12, int *a13)
{
  int v13; // r7
  int v14; // r6
  unsigned int v17; // r4
  _WORD *v18; // r2
  int result; // r0
  unsigned int v20; // r2
  int *v21; // r1
  int v22; // r3
  int v23; // t1
  _BYTE *v24; // r0
  unsigned int v25; // r5
  __int64 v26; // r3
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r4
  unsigned int v31; // r3
  int v32; // r1
  int v33; // r2
  int v34; // r3
  int v35; // r8
  unsigned int v36; // r6
  int v37; // r10
  unsigned int i; // r4
  unsigned __int16 *v39; // r0
  int v40; // r3
  __int64 v41; // r1
  int v42; // r3
  unsigned int v43; // r4
  int v44; // r6
  int v45; // r3
  int v46; // r3
  __int64 v47; // r1
  int v48; // r3
  _DWORD *varg_r0; // [sp+28h] [bp+8h]
  _DWORD *varg_r1; // [sp+2Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v13 = 120;
  v14 = 0;
  if ( a12 )
  {
    v17 = 0;
    v18 = a12;
    while ( !*v18 )
    {
      ++v17;
      v18 += 4;
      if ( v17 >= 3 )
        goto LABEL_6;
    }
    result = sub_8110EC();
  }
  else
  {
LABEL_6:
    if ( a13 )
    {
      v20 = 0;
      v21 = a13;
      do
      {
        v23 = *v21++;
        v22 = v23;
        if ( v23 )
        {
          v31 = *(unsigned __int16 *)(v22 + 2);
          if ( v31 )
          {
            if ( v31 > 0x40 )
              JUMPOUT(0x811104);
            ++v14;
            v13 += 2 * (v31 + 2);
          }
        }
        ++v20;
      }
      while ( v20 < 2 );
    }
    v24 = (_BYTE *)ExAllocatePoolWithTag(1, v13 + 16 * v14, 1953985605);
    v25 = (unsigned int)v24;
    if ( v24 )
    {
      memset(v24, 0, v13 + 16 * v14);
      LODWORD(v26) = 3;
      HIDWORD(v26) = v13 + 16 * v14;
      *(_QWORD *)v25 = v26;
      if ( a2 )
      {
        v32 = a2[1];
        v33 = a2[2];
        v34 = a2[3];
        *(_DWORD *)(v25 + 56) = *a2;
        *(_DWORD *)(v25 + 60) = v32;
        *(_DWORD *)(v25 + 64) = v33;
        *(_DWORD *)(v25 + 68) = v34;
      }
      v27 = a1[1];
      v28 = a1[2];
      v29 = a1[3];
      *(_DWORD *)(v25 + 40) = *a1;
      *(_DWORD *)(v25 + 44) = v27;
      *(_DWORD *)(v25 + 48) = v28;
      *(_DWORD *)(v25 + 52) = v29;
      *(_DWORD *)(v25 + 116) = v14;
      *(_DWORD *)(v25 + 72) = a5;
      *(_BYTE *)(v25 + 76) = a6;
      *(_DWORD *)(v25 + 96) = a9;
      *(_DWORD *)(v25 + 100) = a10;
      *(_DWORD *)(v25 + 88) = a7;
      *(_DWORD *)(v25 + 92) = a8;
      *(_WORD *)(v25 + 78) = a3;
      *(_DWORD *)(v25 + 80) = a11;
      if ( v14 )
      {
        v35 = v25 + 120 + 16 * v14;
        v36 = v25 + 120;
        v37 = 0;
        for ( i = 0; i < 3; ++i )
        {
          v39 = &a12[4 * i];
          if ( *v39 && *((_DWORD *)v39 + 1) )
          {
            if ( i )
            {
              if ( i == 1 )
                v40 = -2147483632;
              else
                v40 = -2147483616;
            }
            else
            {
              v40 = -2147483640;
            }
            *(_DWORD *)(v36 + 12) = v40;
            HIDWORD(v41) = *v39 + 2;
            LODWORD(v41) = (int)(v35 - v25) >> 31;
            *(_QWORD *)(v36 + 4) = v41;
            *(_DWORD *)v36 = v35 - v25;
            memmove(v35, *((_DWORD *)v39 + 1), HIDWORD(v41));
            v42 = *(_DWORD *)(v36 + 8);
            ++v37;
            v36 += 16;
            v35 += v42;
          }
        }
        v43 = 0;
        v44 = v25 + 120 + 16 * v37;
        do
        {
          v45 = a13[v43];
          if ( v45 && *(_WORD *)(v45 + 2) )
          {
            if ( v43 )
              v46 = -2147479552;
            else
              v46 = -2147483136;
            *(_DWORD *)(v44 + 12) = v46;
            HIDWORD(v47) = 2 * (*(unsigned __int16 *)(a13[v43] + 2) + 2);
            LODWORD(v47) = (int)(v35 - v25) >> 31;
            *(_QWORD *)(v44 + 4) = v47;
            *(_DWORD *)v44 = v35 - v25;
            memmove(v35, a13[v43], HIDWORD(v47));
            v48 = *(_DWORD *)(v44 + 8);
            v44 += 16;
            v35 += v48;
          }
          ++v43;
        }
        while ( v43 < 2 );
      }
      v30 = EtwpEnableGuid(v25, 0);
      ExFreePoolWithTag(v25);
    }
    else
    {
      v30 = -1073741801;
    }
    result = v30;
  }
  return result;
}
