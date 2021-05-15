// PpmUpdateIdleVeto 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PpmUpdateIdleVeto(int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v6; // r1
  BOOL v7; // r7
  _DWORD *v8; // r0
  _DWORD *v9; // r4
  int v10; // r3
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  unsigned int v13; // r2
  unsigned int *v14; // r2
  unsigned int *v15; // r4
  unsigned int **v16; // r0
  unsigned int v17; // r3
  unsigned int **v18; // r2
  unsigned int v19; // r2

  if ( !a2 )
    return -1073741811;
  v6 = a3[4];
  v7 = v6 != 0;
  if ( !a1 )
  {
    v8 = (_DWORD *)a3[1];
    v9 = a3 + 1;
    while ( v8 != v9 )
    {
      if ( v8[2] == a2 )
      {
        v10 = v8[3] - 1;
        v8[3] = v10;
        if ( !v10 )
        {
          *(_QWORD *)&v11 = *(_QWORD *)v8;
          if ( *(_DWORD **)(*v8 + 4) != v8 || (_DWORD *)*v12 != v8 )
            __fastfail(3u);
          *v12 = v11;
          *(_DWORD *)(v11 + 4) = v12;
          if ( v7 )
          {
            *v8 = 0;
            v8[1] = 0;
          }
          else
          {
            ExFreePoolWithTag(v8);
          }
          if ( (_DWORD *)*v9 == v9 )
          {
            __dmb(0xBu);
            do
              v13 = __ldrex(a3);
            while ( __strex(0, a3) );
            goto LABEL_36;
          }
        }
        return 0;
      }
      v8 = (_DWORD *)*v8;
    }
    return -1073741811;
  }
  v14 = (unsigned int *)a3[1];
  v15 = a3 + 1;
  while ( v14 != v15 )
  {
    if ( v14[2] == a2 )
    {
      v17 = v14[3];
      if ( v17 == -1 )
        return -1073741675;
      v14[3] = v17 + 1;
      return 0;
    }
    v14 = (unsigned int *)*v14;
  }
  if ( v6 )
  {
    if ( a2 > a3[3] )
      return -1073741811;
    v16 = (unsigned int **)(v6 + 16 * a2 - 16);
  }
  else
  {
    v16 = (unsigned int **)ExAllocatePoolWithTag(512, 16);
    if ( !v16 )
      return -1073741670;
  }
  *v16 = 0;
  v16[1] = 0;
  v16[2] = 0;
  v16[3] = 0;
  v16[2] = (unsigned int *)a2;
  v16[3] = (unsigned int *)1;
  v18 = (unsigned int **)a3[2];
  *v16 = v15;
  v16[1] = (unsigned int *)v18;
  if ( *v18 != v15 )
    __fastfail(3u);
  *v18 = (unsigned int *)v16;
  a3[2] = (unsigned int)v16;
  __dmb(0xBu);
  do
    v19 = __ldrex(a3);
  while ( __strex(1u, a3) );
LABEL_36:
  __dmb(0xBu);
  return 0;
}
