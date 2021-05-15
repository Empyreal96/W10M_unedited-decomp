// qsort 
 
void __fastcall qsort(unsigned int a1, unsigned int a2, unsigned int a3, int (__fastcall *a4)(unsigned int, _BYTE *))
{
  unsigned int v6; // r10
  _BYTE *v7; // r8
  char *v8; // r5
  unsigned int v9; // r3
  _BYTE *v10; // r5
  unsigned int i; // r4
  unsigned int v12; // r4
  _BYTE *v13; // r1
  int v14; // r0
  char v15; // r2
  char *v16; // r3
  _BYTE *v17; // r5
  unsigned int v18; // r4
  _BYTE *v19; // r1
  unsigned int v20; // r0
  char v21; // r2
  unsigned int v22; // r4
  _BYTE *v23; // r1
  unsigned int v24; // r0
  char v25; // r2
  unsigned int v26; // r4
  _BYTE *v27; // r1
  int v28; // r0
  char v29; // r2
  unsigned int v30; // r4
  _BYTE *v31; // r6
  unsigned int v32; // lr
  _BYTE *v33; // r1
  unsigned int v34; // r0
  char v35; // r2
  _BYTE *v36; // r6
  char *v37; // [sp+8h] [bp-120h]
  char *v38; // [sp+Ch] [bp-11Ch]
  int v39; // [sp+10h] [bp-118h]
  char v40[120]; // [sp+18h] [bp-110h] BYREF
  char v41; // [sp+90h] [bp-98h] BYREF

  v6 = a1;
  if ( (a1 || !a2) && a3 && a4 )
  {
    if ( a2 >= 2 )
    {
      v39 = 0;
      v7 = (_BYTE *)(a1 + (a2 - 1) * a3);
      v8 = v40;
      v37 = v40;
      v38 = &v41;
      while ( 1 )
      {
        while ( 1 )
        {
          if ( !a3 )
            __brkdiv0();
          v9 = (unsigned int)&v7[-v6] / a3 + 1;
          if ( v9 <= 8 )
          {
            if ( (unsigned int)v7 > v6 )
            {
              do
              {
                v10 = (_BYTE *)v6;
                for ( i = a3 + v6; i <= (unsigned int)v7; i += a3 )
                {
                  if ( a4(i, v10) > 0 )
                    v10 = (_BYTE *)i;
                }
                v12 = a3;
                v13 = v7;
                if ( v10 != v7 )
                {
                  v14 = v10 - v7;
                  do
                  {
                    v15 = v13[v14];
                    --v12;
                    v13[v14] = *v13;
                    *v13++ = v15;
                  }
                  while ( v12 );
                }
                v7 -= a3;
              }
              while ( (unsigned int)v7 > v6 );
              v8 = v37;
            }
            goto LABEL_22;
          }
          v17 = (_BYTE *)(v6 + (v9 >> 1) * a3);
          if ( a4(v6, v17) > 0 )
          {
            v18 = a3;
            v19 = v17;
            if ( (_BYTE *)v6 != v17 )
            {
              v20 = v6 - (_DWORD)v17;
              do
              {
                v21 = v19[v20];
                --v18;
                v19[v20] = *v19;
                *v19++ = v21;
              }
              while ( v18 );
            }
          }
          if ( a4(v6, v7) > 0 )
          {
            v22 = a3;
            v23 = v7;
            if ( (_BYTE *)v6 != v7 )
            {
              v24 = v6 - (_DWORD)v7;
              do
              {
                v25 = v23[v24];
                --v22;
                v23[v24] = *v23;
                *v23++ = v25;
              }
              while ( v22 );
            }
          }
          if ( a4((unsigned int)v17, v7) > 0 )
          {
            v26 = a3;
            v27 = v7;
            if ( v17 != v7 )
            {
              v28 = v17 - v7;
              do
              {
                v29 = v27[v28];
                --v26;
                v27[v28] = *v27;
                *v27++ = v29;
              }
              while ( v26 );
            }
          }
          v30 = v6;
          v31 = v7;
          while ( 1 )
          {
            if ( (unsigned int)v17 > v30 )
            {
              while ( 1 )
              {
                v30 += a3;
                if ( v30 >= (unsigned int)v17 )
                  break;
                if ( a4(v30, v17) > 0 )
                {
                  if ( (unsigned int)v17 > v30 )
                    goto LABEL_43;
                  goto LABEL_41;
                }
              }
            }
            do
LABEL_41:
              v30 += a3;
            while ( v30 <= (unsigned int)v7 && a4(v30, v17) <= 0 );
            do
LABEL_43:
              v31 -= a3;
            while ( v31 > v17 && a4((unsigned int)v31, v17) > 0 );
            if ( v30 > (unsigned int)v31 )
              break;
            v32 = a3;
            v33 = v31;
            if ( (_BYTE *)v30 != v31 )
            {
              v34 = v30 - (_DWORD)v31;
              do
              {
                v35 = v33[v34];
                --v32;
                v33[v34] = *v33;
                *v33++ = v35;
              }
              while ( v32 );
            }
            if ( v17 == v31 )
              v17 = (_BYTE *)v30;
          }
          v36 = &v31[a3];
          if ( v17 < v36 )
          {
            while ( 1 )
            {
              v36 -= a3;
              if ( v36 <= v17 )
                break;
              if ( a4((unsigned int)v36, v17) )
              {
                if ( v17 < v36 )
                  goto LABEL_57;
                goto LABEL_55;
              }
            }
          }
          do
LABEL_55:
            v36 -= a3;
          while ( (unsigned int)v36 > v6 && !a4((unsigned int)v36, v17) );
LABEL_57:
          v8 = v37;
          if ( (int)&v36[-v6] >= (int)&v7[-v30] )
            break;
          if ( v30 < (unsigned int)v7 )
          {
            *(_DWORD *)v37 = v7;
            v8 = v37 + 4;
            *(_DWORD *)v38 = v30;
            v37 += 4;
            v38 += 4;
            ++v39;
          }
          if ( v6 >= (unsigned int)v36 )
          {
LABEL_22:
            v8 -= 4;
            v37 = v8;
            v16 = v38 - 4;
            v38 -= 4;
            if ( --v39 < 0 )
              return;
            v6 = *(_DWORD *)v16;
            v7 = *(_BYTE **)v8;
          }
          else
          {
            v7 = v36;
          }
        }
        if ( v6 < (unsigned int)v36 )
        {
          *(_DWORD *)v37 = v36;
          v8 = v37 + 4;
          *(_DWORD *)v38 = v6;
          v37 += 4;
          v38 += 4;
          ++v39;
        }
        if ( v30 >= (unsigned int)v7 )
          goto LABEL_22;
        v6 = v30;
      }
    }
  }
  else
  {
    PopPoCoalescinCallback();
  }
}
