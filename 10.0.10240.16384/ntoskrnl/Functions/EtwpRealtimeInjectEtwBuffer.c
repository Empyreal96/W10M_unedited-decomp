// EtwpRealtimeInjectEtwBuffer 
 
int __fastcall EtwpRealtimeInjectEtwBuffer(_DWORD *a1, int a2, int a3)
{
  int v4; // r6
  unsigned int v6; // r1
  int v7; // r5
  _DWORD *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r2
  unsigned int *v13; // lr
  _DWORD *v14; // r4
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r1
  _DWORD *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  int v25[2]; // [sp+4h] [bp-44h] BYREF
  unsigned int v26; // [sp+Ch] [bp-3Ch]
  int v27; // [sp+10h] [bp-38h]
  _BYTE v28[48]; // [sp+18h] [bp-30h] BYREF

  v4 = a2;
  v25[1] = a3;
  if ( *(_WORD *)(a3 + 54) == 6 )
  {
    v6 = *(_DWORD *)(a2 + 44) + 1;
    *(_DWORD *)(v4 + 44) = v6;
    if ( (a1[3] & 0x10000000) != 0 || v6 > 2 )
      return 0;
  }
  else
  {
    *(_DWORD *)(a2 + 44) = 0;
  }
  v8 = (_DWORD *)(*(_DWORD *)(v4 + 12) + 172);
  __pld(v8);
  v9 = *v8 & 0xFFFFFFFE;
  do
    v10 = __ldrex(v8);
  while ( v10 == v9 && __strex(v9 + 2, v8) );
  __dmb(0xBu);
  if ( v10 != v9 && !ExfAcquireRundownProtection(v8) )
    return -1073741558;
  v11 = KiStackAttachProcess(*(_DWORD *)(v4 + 12), 0, (int)v28);
  v12 = a1[42];
  __dmb(0xBu);
  **(_DWORD **)(v4 + 76) = v12;
  **(_DWORD **)(v4 + 80) = a1[47];
  if ( **(_DWORD **)(v4 + 32) < (unsigned int)(2 * a1[41]) )
  {
    v7 = EtwpFindUserBufferSpace(v11, v4, *(_DWORD *)(a3 + 48), v25, a2);
    if ( v7 >= 0 )
    {
      v26 = 0;
      memmove(v25[0], a3, *(_DWORD *)(a3 + 48));
      v13 = (unsigned int *)(v25[0] + 32);
      v14 = *(_DWORD **)(v4 + 36);
      __pld(v14);
      v15 = *v14;
      do
      {
        *v13 = v15;
        v16 = v15;
        __dmb(0xBu);
        do
          v17 = __ldrex(v14);
        while ( v17 == v15 && __strex((unsigned int)v13, v14) );
        v15 = v17;
      }
      while ( v17 != v16 );
      v26 = v17;
      __dmb(0xBu);
      v18 = *(unsigned int **)(v4 + 32);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 + 1, v18) );
      __dmb(0xBu);
      if ( !v15 )
        KeSetEvent(*(_DWORD *)(v4 + 28), 0, 0);
    }
  }
  else
  {
    v7 = -1073741764;
    v27 = -1073741764;
  }
  KiUnstackDetachProcess((unsigned int)v28, 0);
  v20 = (_DWORD *)(*(_DWORD *)(v4 + 12) + 172);
  __pld(v20);
  v21 = *v20 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v22 = __ldrex(v20);
  while ( v22 == v21 && __strex(v21 - 2, v20) );
  if ( v22 != v21 )
    ExfReleaseRundownProtection((unsigned __int8 *)v20);
  return v7;
}
