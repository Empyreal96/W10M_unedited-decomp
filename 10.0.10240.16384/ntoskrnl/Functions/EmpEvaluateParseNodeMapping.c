// EmpEvaluateParseNodeMapping 
 
int __fastcall EmpEvaluateParseNodeMapping(int a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6, int a7, unsigned int a8, _DWORD *a9, unsigned int a10, _DWORD *a11, unsigned int a12, _DWORD *a13, unsigned int a14)
{
  int v15; // r5
  _DWORD *v17; // r1
  _DWORD *v18; // r2
  unsigned int v19; // r1
  unsigned int *v20; // r0
  unsigned int v21; // r3
  unsigned int v22; // t1
  _DWORD *v23; // r2
  unsigned int v24; // r1
  unsigned int *v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // t1
  unsigned int v29; // r4
  unsigned int v30; // r3

  v15 = 0;
  if ( a1 && a2 == a10 + a12 + a14 )
  {
    v17 = a9;
    if ( a9 && (v29 = 0, a10) )
    {
      while ( 1 )
      {
        v30 = *(_DWORD *)((char *)v17 + a1 - (_DWORD)a9);
        if ( v30 >= a4 )
          break;
        ++v29;
        *v17++ = *(_DWORD *)(a3 + 4 * v30);
        if ( v29 >= a10 )
          goto LABEL_4;
      }
    }
    else
    {
LABEL_4:
      v18 = a11;
      if ( a11 && (v19 = 0, a12) )
      {
        v20 = (unsigned int *)(a1 + 4 * a10);
        while ( 1 )
        {
          v22 = *v20++;
          v21 = v22;
          if ( v22 >= a6 )
            break;
          ++v19;
          *v18++ = *(_DWORD *)(a5 + 4 * v21);
          if ( v19 >= a12 )
            goto LABEL_9;
        }
      }
      else
      {
LABEL_9:
        v23 = a13;
        if ( a13 && (v24 = 0, a14) )
        {
          v25 = (unsigned int *)(a1 + 4 * (a10 + a12));
          while ( 1 )
          {
            v27 = *v25++;
            v26 = v27;
            if ( v27 >= a8 )
              break;
            ++v24;
            *v23++ = *(_DWORD *)(a7 + 4 * v26);
            if ( v24 >= a14 )
              goto LABEL_14;
          }
        }
        else
        {
LABEL_14:
          v15 = 1;
        }
      }
    }
  }
  return v15;
}
