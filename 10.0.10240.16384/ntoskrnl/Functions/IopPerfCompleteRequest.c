// IopPerfCompleteRequest 
 
int *__fastcall IopPerfCompleteRequest(int a1, unsigned __int8 a2)
{
  int v4; // r2
  int v5; // r0
  unsigned __int8 *v6; // r5
  unsigned int v7; // r8
  int v8; // r2
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r4
  unsigned int v16; // r4
  int v17; // r3
  unsigned __int8 v18; // r2
  bool v19; // zf
  unsigned __int64 v21; // [sp+8h] [bp-58h] BYREF
  unsigned int v22; // [sp+10h] [bp-50h]
  unsigned __int8 *v23; // [sp+18h] [bp-48h] BYREF
  int v24; // [sp+1Ch] [bp-44h]
  int v25; // [sp+20h] [bp-40h]
  unsigned int v26; // [sp+24h] [bp-3Ch]
  unsigned __int8 v27; // [sp+28h] [bp-38h]
  unsigned __int64 *v28; // [sp+30h] [bp-30h] BYREF
  int v29; // [sp+34h] [bp-2Ch]
  int v30; // [sp+38h] [bp-28h]
  int v31; // [sp+3Ch] [bp-24h]

  if ( *(_WORD *)a1 != 6 )
    return (int *)IopfCompleteRequest(a1, a2);
  v4 = *(char *)(a1 + 34);
  v5 = *(char *)(a1 + 35);
  if ( v5 > (char)(v4 + 1) )
    return (int *)IopfCompleteRequest(a1, a2);
  v6 = 0;
  v7 = 0;
  if ( v5 <= v4 )
  {
    v6 = *(unsigned __int8 **)(a1 + 96);
    if ( *((_DWORD *)v6 + 6) )
    {
      if ( (IopPerfStatus & 2) != 0 )
      {
        v8 = *(_DWORD *)(a1 + 104);
        if ( (*(_BYTE *)(a1 + 39) & 0x80) == 0 && v8 && (*(_WORD *)(v8 + 2) & 2) != 0 )
        {
          v10 = *(_DWORD *)(a1 + 104);
          if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0
            || (!v10 || (*(_WORD *)(v10 + 2) & 0x10) == 0 ? (v11 = 0) : (v11 = 1), !v11) )
          {
            v12 = *(_DWORD *)(a1 + 104);
            KeQuerySystemTime(&v21);
            IopProcessIoTracking(
              v21 - *(_DWORD *)(v12 + 28),
              (v21 - *(_QWORD *)(v12 + 28)) >> 32,
              *(_DWORD *)(*((_DWORD *)v6 + 6) + 44));
            IopFreeIrpExtension(a1, 1, 1);
          }
        }
      }
      v13 = *(_DWORD *)(*((_DWORD *)v6 + 6) + 8);
      if ( v13 )
      {
        v14 = *v6;
        if ( v14 <= 0x1B )
          v7 = *(_DWORD *)(v13 + 4 * v14 + 56);
      }
    }
    else
    {
      v7 = *((_DWORD *)v6 + 8);
    }
  }
  if ( (IopPerfStatus & 1) == 0 )
    return (int *)IopfCompleteRequest(a1, a2);
  __dmb(0xBu);
  do
  {
    v15 = __ldrex(&IopPerfDriverUniqueMatchId);
    v16 = v15 + 1;
  }
  while ( __strex(v16, &IopPerfDriverUniqueMatchId) );
  __dmb(0xBu);
  v28 = &v21;
  v21 = __PAIR64__(a1, v7);
  v22 = v16;
  v29 = 0;
  v30 = 12;
  v31 = 0;
  EtwTraceKernelEvent((int *)&v28, 1, 0x20000010u, 308, 4200450);
  if ( v6 )
  {
    v25 = 0;
    v17 = *((_DWORD *)v6 + 9);
    v23 = v6;
    v24 = v17;
    v26 = v16;
    v27 = v6[3];
    v18 = v6[3];
    if ( *(int *)(a1 + 24) < 0 )
      v19 = (v18 & 0x80) == 0;
    else
      v19 = (v18 & 0x40) == 0;
    if ( !v19 || *(_BYTE *)(a1 + 36) && (v6[3] & 0x20) != 0 )
    {
      v25 = *((_DWORD *)v6 + 8);
      v24 = *((_DWORD *)v6 + 9);
    }
    else
    {
      v6[3] = v18 | 0xC0;
    }
    *((_DWORD *)v6 + 8) = IopPerfCompletionRoutine;
    *((_DWORD *)v6 + 9) = &v23;
  }
  IopfCompleteRequest(a1, a2);
  v28 = &v21;
  v29 = 0;
  v30 = 8;
  v31 = 0;
  v21 = __PAIR64__(v16, a1);
  return EtwTraceKernelEvent((int *)&v28, 1, 0x20000010u, 309, 4200450);
}
