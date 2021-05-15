// PopHiberChecksumHiberFileData 
 
char *__fastcall PopHiberChecksumHiberFileData(int a1, int a2, unsigned int a3, unsigned int a4, int a5, unsigned int a6)
{
  int v6; // r5
  char *result; // r0
  int v11; // r1
  unsigned int v12; // r5
  unsigned int v13; // r7
  unsigned int v14; // r4
  unsigned int v15; // r9
  unsigned __int64 v16; // r0
  unsigned int v17; // r8
  unsigned int v18; // r10
  unsigned __int64 v19; // kr08_8
  int v20; // r7
  int v21; // r3
  int v22; // r5
  unsigned int v23; // r2
  int v24; // r0
  __int16 v25; // r3
  unsigned int v26; // kr10_4
  unsigned int v27; // r0
  bool v28; // cf
  unsigned int v29; // r2
  int v30; // r1
  unsigned int v31; // r0
  unsigned int v32; // r2
  int v33; // r1
  char *v35; // [sp+Ch] [bp-24h]
  int v36; // [sp+10h] [bp-20h]

  v6 = a2;
  result = (char *)ReadTimeStampCounter();
  v35 = result;
  v36 = v11;
  if ( *(_DWORD *)(a1 + 296) )
  {
    if ( v6 )
    {
      v12 = *(_DWORD *)(a1 + 300) >> 1;
      v13 = 0;
    }
    else
    {
      v13 = *(_DWORD *)(a1 + 284);
      v12 = *(_DWORD *)(a1 + 280);
    }
    v14 = (a4 << 23) | (a3 >> 9);
    v15 = a4 >> 9;
    if ( a4 >> 9 <= v13 && (a4 >> 9 < v13 || v14 < v12) )
    {
      v16 = a6;
      if ( (a6 & 0x1FF) != 0 )
        v16 = a6 - (unsigned __int64)(a6 & 0x1FF) + 512;
      v19 = (v16 >> 9) + __PAIR64__(v15, v14);
      v18 = HIDWORD(v19);
      v17 = v19;
      if ( v19 >= __PAIR64__(v13, v12) )
      {
        v17 = v12;
        v18 = v13;
      }
      v20 = 0;
      if ( v15 <= v18 && (v15 < v18 || v14 < v17) )
      {
        v21 = a5;
        while ( 1 )
        {
          v22 = *(_DWORD *)(a1 + 296);
          v23 = a6 - v20;
          if ( a6 - v20 > 0x200 )
            v23 = 512;
          v24 = tcpxsum(0, (uint32x4_t *)(v20 + v21), v23);
          if ( a2 )
          {
            *(_WORD *)(v22 + 2 * v14) = v24;
          }
          else if ( *(unsigned __int16 *)(v22 + 2 * v14) != v24 )
          {
            KeBugCheckEx(160, 270, 10, *(unsigned __int16 *)(v22 + 2 * v14), *(unsigned __int16 *)(a1 + 288));
          }
          v25 = *(_WORD *)(v22 + 2 * v14);
          v26 = v14 + 1;
          v15 = (__PAIR64__(v15, v14++) + 1) >> 32;
          *(_WORD *)(a1 + 288) = v25;
          v21 = a5;
          v20 += 512;
          if ( v15 >= v18 )
          {
            if ( v15 > v18 )
              break;
            v21 = a5;
            if ( v26 >= v17 )
              break;
          }
        }
      }
      if ( a2 )
      {
        *(_DWORD *)(a1 + 280) = v14;
        *(_DWORD *)(a1 + 284) = v15;
        v27 = ReadTimeStampCounter();
        v28 = v27 >= (unsigned int)v35;
        v29 = v27 - (_DWORD)v35;
        result = &PopSleepStats;
        qword_61EFD0 += __PAIR64__(v30 - (v36 + (unsigned int)!v28), v29);
      }
      else
      {
        v31 = ReadTimeStampCounter();
        v28 = v31 >= (unsigned int)v35;
        v32 = v31 - (_DWORD)v35;
        result = &PopSleepStats;
        qword_61F0F8 += __PAIR64__(v33 - (v36 + (unsigned int)!v28), v32);
      }
    }
  }
  return result;
}
