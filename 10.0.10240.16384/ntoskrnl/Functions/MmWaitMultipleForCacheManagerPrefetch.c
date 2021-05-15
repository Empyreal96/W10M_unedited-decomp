// MmWaitMultipleForCacheManagerPrefetch 
 
int __fastcall MmWaitMultipleForCacheManagerPrefetch(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // r3
  unsigned int v5; // r6
  unsigned int v6; // r7
  unsigned int *v7; // r4
  int *v8; // r9
  int v10; // r3
  unsigned int v11; // r5
  unsigned int *v12; // lr
  _DWORD *v13; // r1
  _DWORD *v14; // r0
  _DWORD *v15; // r2
  _DWORD *v16; // r0
  __int64 *v17; // r9
  __int64 v18; // kr00_8
  _DWORD *v19; // r9
  int v20; // r2
  int v21; // r0
  int v22; // r0
  int v23; // [sp+10h] [bp-A0h]
  char *v24; // [sp+14h] [bp-9Ch]
  _DWORD *v26; // [sp+1Ch] [bp-94h]
  char v27[16]; // [sp+20h] [bp-90h] BYREF
  char v28[128]; // [sp+30h] [bp-80h] BYREF

  v3 = a1;
  v5 = a2;
  v6 = a2;
  if ( a3 )
    v6 = a2 + 1;
  if ( a2 > 3 )
  {
    v21 = ExAllocatePoolWithTag(512, 28 * v6, 1633118541);
    v3 = a1;
    v7 = (unsigned int *)v21;
  }
  else
  {
    v7 = 0;
  }
  if ( v7 )
  {
    v8 = (int *)&v7[v6];
    v24 = (char *)v8;
  }
  else
  {
    v8 = (int *)v28;
    v7 = (unsigned int *)v27;
    v24 = v28;
    if ( v5 > 3 )
      return sub_54ACD8();
  }
  v10 = v3 - (_DWORD)v7;
  v23 = v10;
  while ( 1 )
  {
    v11 = 0;
    if ( v5 )
      break;
LABEL_28:
    if ( a3 )
      v7[v11++] = a3;
    v22 = KeWaitForMultipleObjects(v11, v7, 1, 18, 0, 0, 0, v8);
    v10 = v23;
    if ( v22 == v11 - 1 )
    {
      if ( a3 )
      {
        if ( v7 != (unsigned int *)v27 )
          ExFreePoolWithTag(v7, 0);
        return v6 - 1;
      }
      v10 = v23;
    }
  }
  v12 = v7;
LABEL_11:
  v13 = *(_DWORD **)((char *)v12 + v10);
  do
  {
    v14 = (_DWORD *)*v13;
    v26 = (_DWORD *)*v13;
    if ( v13[13] != v13[12] )
    {
      while ( 1 )
      {
        v15 = (_DWORD *)v13[14];
        if ( !v15[5] )
          break;
        v16 = v13 + 14;
        v17 = (__int64 *)v13[14];
        v18 = *v17;
        if ( *((_DWORD **)v17 + 1) != v13 + 14 || *(__int64 **)(v18 + 4) != v17 )
          __fastfail(3u);
        *v16 = v18;
        *(_DWORD *)(v18 + 4) = v16;
        v19 = (_DWORD *)v13[15];
        *v15 = v16;
        v15[1] = v19;
        if ( (_DWORD *)*v19 != v16 )
          __fastfail(3u);
        *v19 = v15;
        v13[15] = v15;
        v20 = v13[13] + 1;
        v13[13] = v20;
        if ( v20 == v13[12] )
          goto LABEL_18;
      }
      if ( v15 == (_DWORD *)-16 )
      {
LABEL_18:
        v14 = v26;
        goto LABEL_19;
      }
      ++v11;
      *v12++ = (unsigned int)(v15 + 4);
      v10 = v23;
      if ( v11 >= v5 )
      {
        v8 = (int *)v24;
        goto LABEL_28;
      }
      goto LABEL_11;
    }
LABEL_19:
    v13 = v14;
  }
  while ( v14 );
  MmWaitForCacheManagerPrefetch(*(_DWORD **)(a1 + 4 * v11));
  if ( v7 != (unsigned int *)v27 )
    ExFreePoolWithTag(v7, 0);
  return v11;
}
