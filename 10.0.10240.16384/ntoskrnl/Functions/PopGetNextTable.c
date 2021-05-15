// PopGetNextTable 
 
unsigned int __fastcall PopGetNextTable(int a1, _DWORD *a2, int a3, unsigned int a4, char a5, unsigned int a6)
{
  int v6; // r8
  int v7; // lr
  unsigned int v8; // r7
  unsigned int *v10; // r9
  unsigned int v11; // r5
  unsigned int v12; // r2
  _DWORD *v13; // r10
  _DWORD *v14; // r2
  int v15; // r1
  int v16; // r0
  int v17; // r5
  unsigned int v18; // r4
  unsigned int v19; // r3
  int v20; // r3
  int *v21; // r10
  int v22; // r5
  int v23; // r4
  unsigned int v24; // r0
  unsigned int v25; // r2
  int *v26; // r3
  __int64 v27; // r0
  int *v29; // [sp+0h] [bp-40h]
  int v30; // [sp+4h] [bp-3Ch]
  char v32; // [sp+Ch] [bp-34h]
  unsigned int v33; // [sp+10h] [bp-30h] BYREF
  _BYTE *v34; // [sp+14h] [bp-2Ch]
  __int64 v35[5]; // [sp+18h] [bp-28h] BYREF

  v6 = a4;
  v33 = a4;
  v34 = a2;
  v29 = (int *)(a4 + 28);
  v7 = 0;
  v8 = 0;
  v30 = 0;
  v32 = 0;
  *a2 = 0;
  if ( !a5 )
    v32 = 1;
  v10 = (unsigned int *)(a1 + 8);
  do
    v11 = __ldrex(v10);
  while ( !v11 && __strex(1u, v10) );
  __dmb(0xBu);
  if ( v11 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v10 );
      do
        v12 = __ldrex(v10);
      while ( !v12 && __strex(1u, v10) );
      __dmb(0xBu);
    }
    while ( v12 );
  }
  v13 = (_DWORD *)(a1 + 40);
  if ( *(_DWORD *)(a1 + 68) != a1 + 40 && *(_DWORD *)(a1 + 176) )
  {
    do
    {
      v14 = *(_DWORD **)(a1 + 68);
      if ( v14 == v13 )
        break;
      v15 = *(_DWORD *)(a1 + 72);
      v16 = v14[5];
      v17 = v14[3] + v15;
      v18 = v14[4] - v17;
      v19 = *(_DWORD *)(a1 + 176) - v8;
      if ( v18 <= v19 )
      {
        *(_DWORD *)(a1 + 68) = *v14;
        *(_DWORD *)(a1 + 72) = 0;
      }
      else
      {
        v18 = *(_DWORD *)(a1 + 176) - v8;
        *(_DWORD *)(a1 + 72) = v19 + v15;
      }
      *(_DWORD *)(a3 + 4 * v7) = 0;
      *(_DWORD *)(a3 + 4 * v7) = (v18 - 1) & 0xF ^ (16 * v17);
      v20 = v7 + 1;
      v7 = (unsigned __int16)(v7 + 1);
      v30 = v7;
      if ( v18 )
      {
        v21 = v29;
        v22 = v16 + (v15 << 12);
        v8 += v18;
        do
        {
          MmGetPhysicalAddress((int)v35, v22, (int)v14, v20);
          v14 = (_DWORD *)v35[0];
          --v18;
          v22 += 4096;
          v20 = v35[0] >> 12;
          *v21++ = v20;
        }
        while ( v18 );
        v29 = v21;
        v13 = (_DWORD *)(a1 + 40);
      }
    }
    while ( v8 < *(_DWORD *)(a1 + 176) );
    v6 = v33;
    v10 = (unsigned int *)(a1 + 8);
  }
  v23 = v30;
  if ( v8 < *(_DWORD *)(a1 + 176) )
  {
    while ( 1 )
    {
      v24 = RtlFindNextForwardRunClearCapped(
              *(unsigned int **)(a1 + 64),
              *(_DWORD *)(a1 + 72),
              *(_DWORD *)(a1 + 176) - v8,
              &v33);
      if ( !v24 )
        break;
      v25 = v33;
      v8 += v24;
      *(_DWORD *)(a1 + 72) = v33 + v24;
      *(_DWORD *)(a3 + 4 * v23) = 0;
      *(_DWORD *)(a3 + 4 * v23) = ((_BYTE)v24 - 1) & 0xF ^ (16 * v25);
      v23 = (unsigned __int16)(v23 + 1);
      v26 = v29;
      do
      {
        *v26++ = v25++;
        --v24;
      }
      while ( v24 );
      v29 = v26;
      if ( v8 >= *(_DWORD *)(a1 + 176) )
        goto LABEL_30;
    }
    *(_DWORD *)(a1 + 72) = **(_DWORD **)(a1 + 64);
  }
LABEL_30:
  __dmb(0xBu);
  LODWORD(v27) = 0;
  *v10 = 0;
  if ( v8 )
  {
    HIDWORD(v27) = v8 << 12;
    *v34 = v23;
    *(_DWORD *)v6 = 0;
    *(_WORD *)(v6 + 6) = 0;
    *(_QWORD *)(v6 + 16) = v27;
    *(_DWORD *)(v6 + 24) = 0;
    *(_WORD *)(v6 + 4) = 4 * ((((v8 << 12) + 4095) >> 12) + 7);
    MmMapMemoryDumpMdlEx(a6, v8 << 12, v6, v32);
    *(_WORD *)(v6 + 6) |= 1u;
  }
  return v8;
}
