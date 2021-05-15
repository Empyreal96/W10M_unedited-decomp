// IoBuildPoDeviceNotifyList 
 
int __fastcall IoBuildPoDeviceNotifyList(int a1, int a2)
{
  _DWORD *v3; // r2
  int v4; // r1
  _DWORD *v5; // r3
  int v6; // r3
  int v7; // r4
  int *v8; // r5
  int v9; // r0
  int v10; // r2
  int **v11; // r1
  int v12; // r3
  int *v13; // r1
  __int64 v14; // kr00_8
  int *v15; // r1
  int v16; // r3
  int *v17; // r2
  int v18; // r3
  int v19; // r2
  int v20; // r3
  int v21; // r5
  int v22; // r1
  int v23; // r3
  int v24; // r0
  int v25; // r3
  int v26; // r3
  int v27; // r3
  int v28; // r1
  _DWORD *v29; // r0
  int v30; // r2
  int v31; // r3
  int v32; // r3
  int v33; // r4
  int v34; // r2
  int v35; // r3
  int v36; // r3
  int v37; // r7
  int v38; // r1
  int v39; // r0
  unsigned int v40; // r4
  int v41; // r3
  int v42; // r3
  int v43; // r1
  _DWORD *v44; // r0
  int v45; // r2
  unsigned int v46; // r5
  int v47; // r3
  int v48; // r3
  int result; // r0
  int *v50; // r1
  int v51; // r2
  _DWORD *i; // r2
  _DWORD *j; // r2
  int v54; // r2
  int **v55; // r4
  int v56; // r3
  int *v57; // [sp+0h] [bp-20h] BYREF
  int **v58; // [sp+4h] [bp-1Ch]

  v58 = &v57;
  v57 = (int *)&v57;
  PnpLockDeviceActionQueue(a1, a2);
  memset((_BYTE *)a1, 0, 208);
  v3 = (_DWORD *)(a1 + 16);
  v4 = 5;
  do
  {
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3 + 2;
    v3[3] = v3 + 2;
    v3[4] = v3 + 4;
    v3[5] = v3 + 4;
    v5 = v3 + 6;
    v3 += 10;
    *v5 = v5;
    v5[1] = v5;
    --v4;
  }
  while ( v4 );
  v6 = *(_DWORD *)(IopRootDeviceNode + 4);
  v7 = IopRootDeviceNode;
  while ( v6 )
  {
    v7 = v6;
    v6 = *(_DWORD *)(v6 + 4);
  }
  if ( v7 != IopRootDeviceNode )
  {
    do
    {
      v8 = (int *)(v7 + 84);
      *(_BYTE *)(v7 + 112) = 0;
      *(_DWORD *)(v7 + 128) = 0;
      *(_DWORD *)(v7 + 132) = 0;
      *(_DWORD *)(v7 + 136) = 0;
      *(_DWORD *)(v7 + 140) = 0;
      *(_DWORD *)(v7 + 116) = *(_DWORD *)(v7 + 16);
      v9 = IoGetAttachedDeviceReference(*(_DWORD *)(v7 + 16));
      *(_DWORD *)(v7 + 108) = v9;
      *(_DWORD *)(v7 + 124) = IopCaptureObjectName(*(_DWORD *)(v9 + 8));
      *(_DWORD *)(v7 + 120) = IopCaptureObjectName(*(_DWORD *)(v7 + 108));
      ObfReferenceObject(*(_DWORD *)(v7 + 116));
      *(_BYTE *)(v7 + 112) = 0;
      if ( IopCheckDeviceFlags(v7 + 84, 0x2000) )
        *(_BYTE *)(v7 + 112) = 2;
      v10 = IopRootDeviceNode;
      if ( *(_DWORD *)(v7 + 8) == IopRootDeviceNode && *(_DWORD *)(v7 + 300) && (*(_DWORD *)(v7 + 268) & 4) == 0 )
      {
        v11 = v58;
        *v8 = (int)&v57;
        *(_DWORD *)(v7 + 88) = v11;
        if ( *v11 != (int *)&v57 )
          __fastfail(3u);
        *v11 = v8;
        v10 = IopRootDeviceNode;
        v58 = (int **)(v7 + 84);
      }
      v12 = *(_DWORD *)v7;
      if ( *(_DWORD *)v7 )
      {
        do
        {
          v7 = v12;
          v12 = *(_DWORD *)(v12 + 4);
        }
        while ( v12 );
      }
      else
      {
        v7 = *(_DWORD *)(v7 + 8);
      }
    }
    while ( v7 != v10 );
  }
  while ( 1 )
  {
    v13 = v57;
    if ( v57 == (int *)&v57 )
      break;
    v14 = *(_QWORD *)v57;
    if ( (int **)v57[1] != &v57 || *(int **)(v14 + 4) != v57 )
      __fastfail(3u);
    v57 = (int *)*v57;
    *(_DWORD *)(v14 + 4) = &v57;
    *((_BYTE *)v13 + 28) |= 1u;
    v15 = v13 - 21;
    v16 = v15[1];
    v17 = v15;
    while ( v16 )
    {
      v17 = (int *)v16;
      v16 = *(_DWORD *)(v16 + 4);
    }
    while ( v17 != v15 )
    {
      *((_BYTE *)v17 + 112) |= 1u;
      v18 = *v17;
      if ( *v17 )
      {
        do
        {
          v17 = (int *)v18;
          v18 = *(_DWORD *)(v18 + 4);
        }
        while ( v18 );
      }
      else
      {
        v17 = (int *)v17[2];
      }
    }
  }
  v19 = IopRootDeviceNode;
  do
  {
    v20 = *(_DWORD *)(v19 + 4);
    v21 = 0;
    v22 = v19;
    while ( v20 )
    {
      v22 = v20;
      v20 = *(_DWORD *)(v20 + 4);
    }
    while ( v22 != v19 )
    {
      if ( (*(_BYTE *)(v22 + 112) & 2) != 0 )
      {
        v23 = *(_DWORD *)(v22 + 4);
        v24 = v22;
        while ( v23 )
        {
          v24 = v23;
          v23 = *(_DWORD *)(v23 + 4);
        }
        if ( v24 != v22 )
        {
          do
          {
            *(_BYTE *)(v24 + 112) |= 2u;
            v25 = *(_DWORD *)v24;
            if ( *(_DWORD *)v24 )
            {
              do
              {
                v24 = v25;
                v25 = *(_DWORD *)(v25 + 4);
              }
              while ( v25 );
            }
            else
            {
              v24 = *(_DWORD *)(v24 + 8);
            }
          }
          while ( v24 != v22 );
          v19 = IopRootDeviceNode;
        }
      }
      v26 = *(_DWORD *)v22;
      if ( *(_DWORD *)v22 )
      {
        do
        {
          v22 = v26;
          v26 = *(_DWORD *)(v26 + 4);
        }
        while ( v26 );
      }
      else
      {
        v22 = *(_DWORD *)(v22 + 8);
      }
    }
    v27 = *(_DWORD *)(v19 + 4);
    v28 = v19;
    while ( v27 )
    {
      v28 = v27;
      v27 = *(_DWORD *)(v27 + 4);
    }
    if ( v28 == v19 )
      break;
    do
    {
      if ( (*(_BYTE *)(v28 + 112) & 2) != 0 )
      {
        v29 = *(_DWORD **)(v28 + 92);
        if ( v29 != (_DWORD *)(v28 + 92) )
        {
          do
          {
            v30 = *(v29 - 1);
            if ( (*(_BYTE *)(v30 + 28) & 2) == 0 )
            {
              v21 = 1;
              *(_BYTE *)(v30 + 28) |= 2u;
            }
            v29 = (_DWORD *)*v29;
          }
          while ( v29 != (_DWORD *)(v28 + 92) );
          v19 = IopRootDeviceNode;
        }
      }
      v31 = *(_DWORD *)v28;
      if ( *(_DWORD *)v28 )
      {
        do
        {
          v28 = v31;
          v31 = *(_DWORD *)(v31 + 4);
        }
        while ( v31 );
      }
      else
      {
        v28 = *(_DWORD *)(v28 + 8);
      }
    }
    while ( v28 != v19 );
  }
  while ( v21 );
  v32 = *(_DWORD *)(v19 + 4);
  v33 = v19;
  while ( v32 )
  {
    v33 = v32;
    v32 = *(_DWORD *)(v32 + 4);
  }
  while ( v33 != v19 )
  {
    if ( (*(_BYTE *)(v33 + 112) & 2) != 0 )
    {
      v34 = *(_DWORD *)(v33 + 108);
      ++*(_BYTE *)(v33 + 112);
      while ( v34 )
      {
        if ( *(_DWORD *)(v34 + 44) == 7 )
        {
          if ( IopCheckDeviceFlags(v33 + 84, 256) )
            *(_BYTE *)(v33 + 112) = 2;
          break;
        }
        v34 = *(_DWORD *)(*(_DWORD *)(v34 + 176) + 24);
      }
      v19 = IopRootDeviceNode;
    }
    v35 = *(_DWORD *)v33;
    if ( *(_DWORD *)v33 )
    {
      do
      {
        v33 = v35;
        v35 = *(_DWORD *)(v35 + 4);
      }
      while ( v35 );
    }
    else
    {
      v33 = *(_DWORD *)(v33 + 8);
    }
  }
  do
  {
    v36 = *(_DWORD *)(v19 + 4);
    v37 = 0;
    v38 = v19;
    while ( v36 )
    {
      v38 = v36;
      v36 = *(_DWORD *)(v36 + 4);
    }
    while ( v38 != v19 )
    {
      v39 = *(_DWORD *)(v38 + 8);
      if ( v39 != v19 )
      {
        v40 = *(unsigned __int8 *)(v38 + 112);
        if ( *(unsigned __int8 *)(v39 + 112) > v40 )
        {
          *(_BYTE *)(v39 + 112) = v40;
          v19 = IopRootDeviceNode;
        }
      }
      v41 = *(_DWORD *)v38;
      if ( *(_DWORD *)v38 )
      {
        do
        {
          v38 = v41;
          v41 = *(_DWORD *)(v41 + 4);
        }
        while ( v41 );
      }
      else
      {
        v38 = *(_DWORD *)(v38 + 8);
      }
    }
    v42 = *(_DWORD *)(v19 + 4);
    v43 = v19;
    while ( v42 )
    {
      v43 = v42;
      v42 = *(_DWORD *)(v42 + 4);
    }
    if ( v43 == v19 )
      break;
    do
    {
      v44 = *(_DWORD **)(v43 + 100);
      if ( v44 != (_DWORD *)(v43 + 100) )
      {
        do
        {
          v45 = v44[5];
          v46 = *(unsigned __int8 *)(v43 + 112);
          if ( *(unsigned __int8 *)(v45 + 28) > v46 )
          {
            v37 = 1;
            *(_BYTE *)(v45 + 28) = v46;
          }
          v44 = (_DWORD *)*v44;
        }
        while ( v44 != (_DWORD *)(v43 + 100) );
        v19 = IopRootDeviceNode;
      }
      v47 = *(_DWORD *)v43;
      if ( *(_DWORD *)v43 )
      {
        do
        {
          v43 = v47;
          v47 = *(_DWORD *)(v47 + 4);
        }
        while ( v47 );
      }
      else
      {
        v43 = *(_DWORD *)(v43 + 8);
      }
    }
    while ( v43 != v19 );
  }
  while ( v37 );
  v48 = *(_DWORD *)(v19 + 4);
  result = v19;
  while ( v48 )
  {
    result = v48;
    v48 = *(_DWORD *)(v48 + 4);
  }
  if ( result != v19 )
  {
    do
    {
      v50 = (int *)(result + 84);
      v51 = a1 + 40 * *(unsigned __int8 *)(result + 112);
      ++*(_DWORD *)(v51 + 8);
      if ( *(_DWORD *)(result + 8) != IopRootDeviceNode )
      {
        ++*(_DWORD *)(result + 136);
        ++*(_DWORD *)(*(_DWORD *)(result + 8) + 128);
      }
      for ( i = *(_DWORD **)(result + 100); i != (_DWORD *)(result + 100); i = (_DWORD *)*i )
        ++*(_DWORD *)(result + 136);
      for ( j = *(_DWORD **)(result + 92); j != (_DWORD *)(result + 92); j = (_DWORD *)*j )
        ++*(_DWORD *)(result + 128);
      v54 = a1 + 40 * *(unsigned __int8 *)(result + 112) + 16;
      v55 = *(int ***)(a1 + 40 * *(unsigned __int8 *)(result + 112) + 20);
      *v50 = v54;
      *(_DWORD *)(result + 88) = v55;
      if ( *v55 != (int *)v54 )
        __fastfail(3u);
      *v55 = v50;
      *(_DWORD *)(v54 + 4) = v50;
      v56 = *(_DWORD *)result;
      if ( *(_DWORD *)result )
      {
        do
        {
          result = v56;
          v56 = *(_DWORD *)(v56 + 4);
        }
        while ( v56 );
      }
      else
      {
        result = *(_DWORD *)(result + 8);
      }
    }
    while ( result != IopRootDeviceNode );
  }
  *(_BYTE *)a1 = 1;
  *(_DWORD *)(a1 + 4) = &IopWarmEjectPdo;
  return result;
}
