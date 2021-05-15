// PopGetWakeSource 
 
int __fastcall PopGetWakeSource(int a1, unsigned int *a2)
{
  unsigned int v2; // r4
  int *v3; // r6
  unsigned int *v4; // r9
  int v5; // r4
  int v6; // r1
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r0
  int v10; // r2
  int v11; // r5
  int v12; // r3
  int *v13; // r10
  unsigned int v14; // r8
  unsigned int v15; // r7
  int v16; // t1
  __int64 v17; // r0
  _DWORD *v18; // r9
  int v19; // r9
  int v20; // r1
  int v21; // r7
  int v22; // r2
  char *v23; // r10
  int v24; // r3
  _DWORD *v25; // r5
  _DWORD *v26; // t1
  int *v27; // r9
  _DWORD *v28; // r6
  int v29; // r4
  int *v31; // [sp+8h] [bp-40h] BYREF
  unsigned int *v32; // [sp+Ch] [bp-3Ch]
  int *v33; // [sp+10h] [bp-38h]
  int v34; // [sp+14h] [bp-34h]
  int *v35; // [sp+18h] [bp-30h]
  int v36; // [sp+1Ch] [bp-2Ch]
  int v37; // [sp+20h] [bp-28h]
  int v38; // [sp+24h] [bp-24h]

  v2 = *a2;
  v3 = (int *)a1;
  v4 = a2;
  v31 = 0;
  v32 = a2;
  v35 = (int *)a1;
  if ( v2 && !a1 )
    return -1073741811;
  KeWaitForSingleObject((unsigned int)&PopWakeSourceAvailable, 0, 0, 0, 0);
  v9 = PopGetCurrentWakeInfos((int *)&v31, v6, v7, v8);
  v11 = v9;
  v12 = 4 * v9;
  v13 = v31;
  v14 = 4 * v9 + 4;
  v38 = v9;
  if ( v9 )
  {
    v33 = v31;
    v15 = v9;
    do
    {
      v16 = *v13++;
      HIDWORD(v17) = v16 + 12;
      v18 = *(_DWORD **)(v16 + 12);
      v10 = *(_DWORD *)(v16 + 20) + 1;
      v14 = ((v14 + 7) & 0xFFFFFFF8) + 4 * v10;
      while ( v18 != (_DWORD *)HIDWORD(v17) )
      {
        v17 = PopWakeSourceSize(v18, HIDWORD(v17));
        v18 = (_DWORD *)*v18;
        v14 = v17 + ((v14 + 7) & 0xFFFFFFF8);
      }
      --v15;
    }
    while ( v15 );
    v13 = v31;
    v4 = v32;
    v12 = 4 * v11;
  }
  if ( v14 <= v2 )
  {
    v12 += (int)(v3 + 1);
    *v3 = v11;
    if ( v11 )
    {
      v19 = (char *)v13 - (char *)v3;
      v37 = (char *)v13 - (char *)v3;
      v20 = (int)v3;
      v21 = v11;
      do
      {
        v22 = *(_DWORD *)(v19 + v20);
        v23 = (char *)((v12 + 7) & 0xFFFFFFF8);
        *(_DWORD *)v23 = *(_DWORD *)(v22 + 20);
        *(_DWORD *)(v20 + 4) = v23 - (char *)v3;
        v20 += 4;
        v33 = (int *)(v23 + 4);
        v24 = *(_DWORD *)(v22 + 20);
        v26 = *(_DWORD **)(v22 + 12);
        v10 = v22 + 12;
        v25 = v26;
        v36 = v20;
        v12 = (int)&v23[4 * v24 + 4];
        v34 = v10;
        if ( v26 != (_DWORD *)v10 )
        {
          v27 = v33;
          v28 = (_DWORD *)v10;
          do
          {
            v29 = (v12 + 7) & 0xFFFFFFF8;
            *v27++ = v29 - (_DWORD)v23;
            PopCopyWakeSource(v29, v20, (int)v25);
            v25 = (_DWORD *)*v25;
            v12 = *(_DWORD *)(v29 + 4) + v29;
          }
          while ( v25 != v28 );
          v3 = v35;
          v20 = v36;
          v19 = v37;
        }
        --v21;
      }
      while ( v21 );
      v11 = v38;
      v13 = v31;
      v4 = v32;
    }
    v5 = 0;
  }
  else
  {
    v5 = -1073741789;
  }
  if ( v11 )
    PopDereferenceWakeInfos(v11, v13, v10, v12);
  *v4 = v14;
  return v5;
}
