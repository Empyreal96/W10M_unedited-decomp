// MiRemoveSpecialPoolRange 
 
__int16 *__fastcall MiRemoveSpecialPoolRange(unsigned int *a1, char a2, int *a3)
{
  unsigned int v5; // r7
  int v6; // r8
  int v7; // r4
  int v8; // r3
  __int16 *result; // r0
  unsigned int v10; // r4
  unsigned int v11; // r10
  int *v12; // r5
  unsigned int v13; // r1
  int v14; // r3
  _BYTE v15[16]; // [sp-4h] [bp-C8h] BYREF
  int v16; // [sp+Ch] [bp-B8h] BYREF
  char v17; // [sp+10h] [bp-B4h]
  char v18; // [sp+11h] [bp-B3h]
  int v19; // [sp+14h] [bp-B0h]
  int v20; // [sp+18h] [bp-ACh]
  int v21; // [sp+1Ch] [bp-A8h]
  int v22; // [sp+20h] [bp-A4h]

  if ( (a2 & 1) != 0 )
  {
    v5 = (unsigned int)(a1 + 1);
    v6 = 7;
  }
  else
  {
    v5 = (unsigned int)(a1 + 4);
    v6 = 13;
  }
  v7 = MmPfnDatabase + 24 * (*(_DWORD *)((((unsigned int)a3 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  KeAcquireInStackQueuedSpinLock(a1, (unsigned int)v15);
  v8 = *(_DWORD *)(v7 + 8) & 0x1FFF | (((*(_DWORD *)(v7 + 8) >> 13) - 1) << 13);
  *(_DWORD *)(v7 + 8) = v8;
  if ( (v8 & 0xFFFFE000) != 0 )
  {
    InsertTailListPte(v5, a3);
    result = (__int16 *)KeReleaseInStackQueuedSpinLock((int)v15);
  }
  else
  {
    v10 = (unsigned int)a3 & 0xFFFFF000;
    v11 = ((unsigned int)a3 & 0xFFFFF000) + 4096;
    v12 = (int *)((unsigned int)a3 & 0xFFFFF000);
    if ( ((unsigned int)a3 & 0xFFFFF000) < v11 )
    {
      do
      {
        if ( v12 != a3 )
          RemoveListEntryPte(v5, v12);
        v12 += 2;
      }
      while ( (unsigned int)v12 < v11 );
    }
    if ( a1 != (unsigned int *)&unk_634D00 )
      MiVaRegionSessionSpecialPool(v10 << 10, 0);
    KeReleaseInStackQueuedSpinLock((int)v15);
    do
      v13 = __ldrex((unsigned int *)&dword_632D50);
    while ( __strex(v13 - 1, (unsigned int *)&dword_632D50) );
    if ( a1 == (unsigned int *)&unk_634D00 )
      v14 = 0;
    else
      v14 = 2;
    v16 = v14;
    v17 = 0;
    v18 = 0;
    v21 = 0;
    v19 = 33;
    v22 = 0;
    v20 = 0;
    if ( a1 != (unsigned int *)&unk_634D00 )
      v6 = 1;
    result = MiReturnSystemVa(v10 << 10, (v10 << 10) + 0x400000, v6, (unsigned int)&v16);
  }
  return result;
}
