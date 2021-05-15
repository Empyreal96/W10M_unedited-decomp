// MiDeleteValidSystemPte 
 
int __fastcall MiDeleteValidSystemPte(_DWORD *a1, int a2, int a3, int a4, int *a5)
{
  int v8; // r4
  int result; // r0
  BOOL v10; // r5
  unsigned __int8 *v11; // r1
  unsigned int v12; // r2
  unsigned int *v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r0
  int v21; // r3
  unsigned int v22; // r2
  _DWORD v24[4]; // [sp+10h] [bp-40h] BYREF
  int v25[12]; // [sp+20h] [bp-30h] BYREF

  v8 = MmPfnDatabase + 24 * (*a1 >> 12);
  if ( *(_DWORD *)v8 )
    return sub_53D360();
  if ( (_DWORD *)(*(_DWORD *)(v8 + 4) | 0x80000000) != a1 )
    KeBugCheckEx(26, 1025, a1);
  if ( (*(_BYTE *)(a3 + 112) & 7) != 0 && (*(_BYTE *)(a3 + 112) & 7) == 1 )
  {
    if ( (unsigned int)a1 + 1070596095 <= 0xFFD )
    {
      v15 = *(_DWORD *)(a3 + 4944) + 4 * ((unsigned int)(((_DWORD)a1 << 20) - dword_63389C) >> 22);
      if ( v15 < 0xC0000000 || v15 > 0xC03FFFFF )
      {
        *(_DWORD *)v15 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v15 = 0;
        if ( v15 + 1070596096 <= 0xFFF )
        {
          v20 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v20, (_DWORD *)(v20 + 4 * (v15 & 0xFFF)), 0);
        }
      }
    }
    v16 = (unsigned int *)(a3 - 3220);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 - 1, v16) );
    v18 = (unsigned int *)(a3 - 3216);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 - 1, v18) );
  }
  MiInsertTbFlushEntry(a4, a2 & 0xFFFFF000, 1);
  if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
  {
    *a1 = 0;
  }
  else
  {
    __dmb(0xBu);
    *a1 = 0;
    if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
    {
      v14 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v14, (_DWORD *)(v14 + 4 * ((unsigned __int16)a1 & 0xFFF)), 0);
    }
  }
  v10 = (dword_682604 & 1) != 0 && (unsigned int)(a2 + 0x40000000) <= 0x3FFFFF;
  v11 = (unsigned __int8 *)(v8 + 15);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  __dmb(0xBu);
  if ( v12 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v21 = *(_DWORD *)(v8 + 12);
        __dmb(0xBu);
      }
      while ( (v21 & 0x80000000) != 0 );
      do
        v22 = __ldrex(v11);
      while ( __strex(v22 | 0x80, v11) );
      __dmb(0xBu);
    }
    while ( v22 >> 7 );
  }
  *(_DWORD *)(v8 + 12) |= 0x40000000u;
  if ( v10 )
  {
    v24[0] = 0;
    v24[1] = 0;
    v24[2] = 0;
    v24[3] = 0;
    MiIdentifyPfn(v8, v24);
  }
  *(_DWORD *)v8 = *a5;
  *a5 = v8;
  *(_BYTE *)(v8 + 18) = *(_BYTE *)(v8 + 18) & 0xF8 | 5;
  __dmb(0xBu);
  v13 = (unsigned int *)(v8 + 12);
  do
    result = __ldrex(v13);
  while ( __strex(result & 0x7FFFFFFF, v13) );
  if ( v10 )
  {
    v25[0] = (int)v24;
    v25[1] = 0;
    v25[2] = 16;
    v25[3] = 0;
    result = EtwTraceKernelEvent(v25, 1, 536870913, 631, 289413890);
  }
  return result;
}
