// MiWritePageFileHash 
 
int *__fastcall MiWritePageFileHash(int a1, int a2, _DWORD *a3, int a4, unsigned int a5)
{
  int v6; // r2
  int v7; // r6
  int *result; // r0
  int v9; // r4
  unsigned int i; // r7
  int v11; // r1
  int v12; // r0
  unsigned int v13; // r2
  _DWORD *v14; // r2
  int *v15; // r1
  _DWORD *v16; // r0
  int v17; // t1
  char v20[16]; // [sp+Ch] [bp-70h] BYREF
  _DWORD v21[24]; // [sp+1Ch] [bp-60h] BYREF

  v6 = a1;
  v7 = 0;
  if ( !a2 )
  {
    v9 = 0;
LABEL_6:
    for ( i = 0; ; ++i )
    {
      result = &MmPfnDatabase;
      if ( i >= a5 )
        break;
      v21[v7] = 0;
      if ( a3 )
      {
        if ( *a3 != dword_6348F4 )
        {
          v11 = 1;
          v12 = MmPfnDatabase + 24 * *a3;
          v13 = (*(_DWORD *)(v12 + 8) >> 5) & 0x1F;
          if ( (dword_681260 & 1) != 0 || v13 == 31 )
            goto LABEL_15;
          if ( v13 >> 3 == 3 && ((*(_DWORD *)(v12 + 8) >> 5) & 7) != 0 )
            v11 = 0;
          if ( v11 == 1 && v13 >> 3 != 1 )
LABEL_15:
            v21[v7] = MiComputePageHash(v12, v9, v13);
          else
            v21[v7] = 2;
        }
        v6 = a1;
      }
      if ( ++v7 == 16 )
        goto LABEL_23;
LABEL_18:
      if ( v9 )
        v9 += 4096;
      if ( a3 )
        ++a3;
      v6 = a1;
    }
    if ( !v7 )
      return result;
LABEL_23:
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v6 + 116), (unsigned int)v20);
    v14 = (_DWORD *)(*(_DWORD *)(a1 + 108) + 4 * a4);
    v15 = v21;
    v16 = &v14[v7];
    do
    {
      v17 = *v15++;
      *v14++ = v17;
    }
    while ( v14 != v16 );
    KeReleaseInStackQueuedSpinLock((int)v20);
    a4 += v7;
    v7 = 0;
    goto LABEL_18;
  }
  if ( (*(_WORD *)(a2 + 6) & 5) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 12);
    if ( v9 )
      v9 += ((int)a3 - a2 - 28) >> 2 << 12;
    goto LABEL_6;
  }
  return (int *)sub_54934C();
}
