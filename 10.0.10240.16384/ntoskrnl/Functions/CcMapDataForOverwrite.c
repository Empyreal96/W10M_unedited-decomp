// CcMapDataForOverwrite 
 
unsigned int __fastcall CcMapDataForOverwrite(int a1, _DWORD *a2, int a3, _DWORD *a4, int *a5)
{
  unsigned int v8; // r4
  unsigned int v9; // r6
  int v10; // r5
  int v11; // r0
  int v12; // r5
  unsigned int *v13; // r1
  int v14; // r2
  unsigned int v15; // r0
  unsigned int result; // r0
  unsigned int v17; // [sp+8h] [bp-30h]
  int v18; // [sp+10h] [bp-28h] BYREF
  int v19; // [sp+14h] [bp-24h]
  unsigned int v20; // [sp+18h] [bp-20h]
  int varg_r0; // [sp+40h] [bp+8h]
  _DWORD *varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]
  _DWORD *varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v8 = ((*a2 & 0xFFFu) + a3 + 4095) >> 12;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  if ( (*(_DWORD *)(v10 + 96) & 0x20000) == 0 )
  {
    v11 = KeAcquireQueuedSpinLock(5);
    *(_DWORD *)(v10 + 96) |= 0x20000u;
    KeReleaseQueuedSpinLock(5, v11);
  }
  v17 = *(unsigned __int8 *)(v9 + 972) + 4 * *(_DWORD *)(v9 + 948);
  CcMapDataCommon(a1, a2, a3, 1, &v18, a5);
  v12 = *a5;
  v19 = *a5;
  while ( v8 )
  {
    *(_BYTE *)(v9 + 972) = 1;
    if ( --v8 > *(_DWORD *)(v9 + 948) )
    {
      if ( v8 <= 0xF )
        *(_DWORD *)(v9 + 948) = v8;
      else
        *(_DWORD *)(v9 + 948) = 15;
    }
    if ( !MmCheckCachedPageStates(v12, 1, 5, 0) )
      MmCheckCachedPageStates(v12, 1, 4, 0);
    v12 += 4096;
    v19 = v12;
    v20 = v8;
  }
  *(_BYTE *)(v9 + 972) = v17 & 3;
  *(_DWORD *)(v9 + 948) = v17 >> 2;
  v13 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4304);
  v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3E4);
  do
  {
    v15 = __ldrex(v13);
    result = v15 + v14;
  }
  while ( __strex(result, v13) );
  *varg_r3 = v18;
  return result;
}
