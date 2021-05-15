// RtlQueryAtomInAtomTable 
 
int __fastcall RtlQueryAtomInAtomTable(_DWORD *a1, unsigned int a2, _DWORD *a3, _DWORD *a4, int a5, unsigned int *a6)
{
  int v9; // r8
  int v10; // r4
  unsigned int v11; // r5
  unsigned int v12; // r3
  int v13; // r0
  int v14; // r6
  unsigned int v15; // r5
  unsigned int v16; // r3
  unsigned int *v17; // r5
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  _BYTE v24[64]; // [sp+20h] [bp-40h] BYREF

  v9 = (int)a1;
  if ( !RtlpLockAtomTable(a1) )
    return -1073741811;
  if ( a2 >= 0xC000 )
  {
    v10 = -1073741816;
    v13 = RtlpAtomMapAtomToHandleEntry(v9, a2 & 0x3FFF);
    v14 = v13;
    if ( !v13 || *(unsigned __int16 *)(v13 + 6) != a2 || !RtlpLookupLowBox(v9, v13) )
      goto LABEL_33;
    v10 = 0;
    if ( a3 )
      *a3 = *(unsigned __int16 *)(v14 + 20);
    if ( a4 )
      *a4 = *(unsigned __int16 *)(v14 + 22);
    if ( !a5 )
      goto LABEL_32;
    v15 = 2 * *(unsigned __int8 *)(v14 + 24);
    v16 = *a6;
    if ( v15 >= *a6 )
    {
      if ( v16 < 2 )
      {
        *a6 = v15;
        v15 = 0;
      }
      else
      {
        v15 = v16 - 2;
      }
    }
    if ( v15 )
    {
      memmove(a5, v14 + 26, v15);
      *(_WORD *)(a5 + 2 * (v15 >> 1)) = 0;
      *a6 = v15;
      goto LABEL_32;
    }
    goto LABEL_31;
  }
  if ( !a2 )
  {
    v10 = -1073741811;
    goto LABEL_33;
  }
  v10 = 0;
  if ( a3 )
    *a3 = 1;
  if ( a4 )
    *a4 = 1;
  if ( a5 )
  {
    v11 = 2 * snwprintf_s((int)v24, 16, -1, (int)L"#%u");
    v12 = *a6;
    if ( v11 >= *a6 )
    {
      if ( v12 < 2 )
        v11 = 0;
      else
        v11 = v12 - 2;
    }
    if ( v11 )
    {
      memmove(a5, (int)v24, v11);
      *(_WORD *)(a5 + 2 * (v11 >> 1)) = 0;
      *a6 = v11;
      goto LABEL_32;
    }
LABEL_31:
    v10 = -1073741789;
  }
LABEL_32:
  v9 = (int)a1;
LABEL_33:
  v17 = (unsigned int *)(v9 + 8);
  __dmb(0xBu);
  do
    v18 = __ldrex(v17);
  while ( __strex(v18 - 1, v17) );
  if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v9 + 8));
  v19 = KeAbPostRelease(v9 + 8);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v10;
}
