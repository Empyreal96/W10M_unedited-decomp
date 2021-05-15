// WmipCopyFromEventQueues 
 
int __fastcall WmipCopyFromEventQueues(_DWORD *a1, unsigned int a2, int a3, int a4, _DWORD *a5, int *a6, unsigned __int8 a7)
{
  unsigned int v7; // r6
  int result; // r0
  _DWORD *v10; // r4
  unsigned int v11; // r7
  _DWORD *v12; // r5
  int v13; // r2
  int v14; // r9
  int v15; // r10
  unsigned int v16; // r1
  int v17; // r7
  int v18; // lr
  int v19; // r4
  int v20; // r2
  _DWORD *v21; // r7
  unsigned int *v22; // r5
  unsigned int v23; // r4
  unsigned int v24; // r3
  char *v25; // r3
  int v26; // r5
  int v27; // t1
  unsigned int *v28; // r4

  v7 = a2;
  result = a7;
  if ( a2 )
  {
    v10 = a1;
    v11 = a2;
    while ( 1 )
    {
      v12 = (_DWORD *)*v10;
      if ( a7 )
        break;
      v13 = v12[20];
      if ( v13 && v12[23] )
      {
        v10[1] = v13;
        *(_WORD *)(v13 + 10) = 0;
        *(_DWORD *)(v10[1] + 8) |= v12[24] << 16;
        v12[24] = 0;
      }
      else
      {
        v10[1] = 0;
      }
      v10 += 2;
      if ( !--v11 )
        goto LABEL_8;
    }
    result = sub_7EF9FC();
  }
  else
  {
LABEL_8:
    v14 = 0;
    v15 = 0;
    while ( 1 )
    {
      v16 = 0;
      v17 = -1;
      v18 = 0x7FFFFFFF;
      v19 = -1;
      if ( !v7 )
        break;
      result = (int)a1;
      do
      {
        v20 = *(_DWORD *)(result + 4);
        if ( v20 && *(_QWORD *)(v20 + 16) < __SPAIR64__(v18, v17) )
        {
          v18 = *(_DWORD *)(v20 + 20);
          v17 = *(_DWORD *)(v20 + 16);
          v19 = v16;
        }
        ++v16;
        result += 8;
      }
      while ( v16 < v7 );
      if ( v19 == -1 )
        break;
      v21 = &a1[2 * v19];
      v22 = (unsigned int *)v21[1];
      v23 = (*v22 + 7) & 0xFFFFFFF8;
      v15 = a3;
      result = memmove(a3, (int)v22, *v22);
      *(_DWORD *)(a3 + 12) = v23;
      v24 = v22[3];
      a3 += v23;
      v14 += v23;
      if ( v24 )
        v25 = (char *)v22 + v24;
      else
        v25 = 0;
      v21[1] = v25;
    }
    *a6 = v15;
    for ( *a5 = v14; v7; --v7 )
    {
      v27 = *a1;
      a1 += 2;
      v26 = v27;
      if ( a7 )
        v28 = (unsigned int *)(v26 + 60);
      else
        v28 = (unsigned int *)(v26 + 80);
      if ( *v28 )
      {
        ExFreePoolWithTag(*v28);
        *v28 = 0;
        v28[1] = 0;
        v28[3] = 0;
      }
      result = KeResetEvent(v26);
    }
  }
  return result;
}
