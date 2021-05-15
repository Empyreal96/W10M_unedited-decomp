// MiScanNonPagedPoolVa 
 
int __fastcall MiScanNonPagedPoolVa(int a1, int a2, int a3, int a4)
{
  int v7; // r0
  int v8; // r4
  int v9; // lr
  unsigned int v10; // r6
  unsigned int v12; // r7
  int v13; // r4
  int v14; // r5
  unsigned int v15; // r10
  unsigned int v16; // r0
  unsigned int v17; // r9
  unsigned int v18; // r5
  int v19; // r0
  int v20; // r2
  unsigned int v21; // [sp+10h] [bp-48h]
  int v22; // [sp+14h] [bp-44h]
  int v23; // [sp+18h] [bp-40h]
  int v24; // [sp+1Ch] [bp-3Ch]
  unsigned int v25; // [sp+20h] [bp-38h] BYREF
  unsigned int v26; // [sp+24h] [bp-34h]
  int v27; // [sp+28h] [bp-30h]
  int v28; // [sp+2Ch] [bp-2Ch]
  char v29[40]; // [sp+30h] [bp-28h] BYREF

  v7 = dword_6337E8 + 176 * a2;
  v8 = *(unsigned __int8 *)(a4 + 24);
  v24 = a3;
  v9 = a3 + 18;
  v10 = *(_DWORD *)(v7 + 4 * a3 + 168);
  v27 = a2;
  v28 = a1;
  v22 = v7;
  v23 = a3 + 18;
  if ( v8 == 1 )
    return sub_548BA4();
  v12 = v10 >> 10;
  v13 = -1;
  v14 = -1;
  v21 = -1;
  v26 = (unsigned int)(a1 + 1023) >> 10;
  v15 = v10 >> 10;
  while ( 1 )
  {
    v16 = RtlFindNextForwardRunClearCapped(v7 + 8 * v9, v12, -1, &v25);
    v17 = v16;
    if ( v16 )
      break;
    if ( v14 != -1 || !v15 || *(_BYTE *)(a4 + 24) )
      return v13;
    v14 = v15;
    v12 = 0;
    v21 = v15;
    v15 = 0;
LABEL_9:
    v7 = v22;
    v9 = v23;
  }
  v18 = v25;
  if ( v25 >= v21 )
    return v13;
  if ( v16 < v26 )
    goto LABEL_20;
  if ( v25 == v12 || v12 != v15 || v26 != 1 || *(_DWORD *)a4 )
  {
    if ( (v10 >> 10 >= v12 || v10 >> 10 < v25) && (!*(_DWORD *)a4 || *(_DWORD *)a4 == 1) )
      v10 = v25 << 10;
  }
  else
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)(v22 + 128), (unsigned int)v29);
    v20 = v22 + 4 * v24;
    if ( v10 == *(_DWORD *)(v20 + 168) )
    {
      v10 = v18 << 10;
      *(_DWORD *)(v20 + 168) = v18 << 10;
    }
    else
    {
      v10 = v18 << 10;
    }
    KeReleaseInStackQueuedSpinLock((int)v29);
  }
  if ( *(_BYTE *)(a4 + 24) == 1 && v10 < v18 << 10 )
    v10 = v18 << 10;
  v19 = MiScanLeafNonPagedPool(v28, v27, v24, a4, v18 << 10, v17 << 10, v10);
  if ( v19 == -1 )
  {
LABEL_20:
    v12 = v18 + v17;
    v14 = v21;
    goto LABEL_9;
  }
  return v19;
}
