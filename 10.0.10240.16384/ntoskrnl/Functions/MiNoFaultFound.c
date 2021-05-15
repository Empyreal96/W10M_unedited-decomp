// MiNoFaultFound 
 
int __fastcall MiNoFaultFound(int a1, unsigned int *a2, int a3, int a4, int a5)
{
  unsigned int v6; // r5
  unsigned int v10; // r4
  unsigned int v11; // r1
  int v12; // r7
  int v13; // r0
  unsigned int *varg_r1; // [sp+24h] [bp+Ch]
  int varg_r2; // [sp+28h] [bp+10h]
  int varg_r3; // [sp+2Ch] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = *a2;
  if ( (a1 & 1) == 0 || (v6 & 0x200) == 0 )
    return sub_514508();
  v10 = v6 & 0xFFFFFDFF | 0x10;
  if ( a5 )
  {
    __dmb(0xBu);
    do
      v11 = __ldrex(a2);
    while ( v11 == a5 && __strex(v10, a2) );
    __dmb(0xBu);
    if ( v11 != a5 )
      return 0;
  }
  else if ( (unsigned int)(a2 + 0x10000000) > 0x3FFFFF )
  {
    *a2 = v10;
  }
  else
  {
    v12 = 0;
    __dmb(0xBu);
    *a2 = v10;
    if ( (v6 & 2) == 0 && (((unsigned __int8)v6 | 0x10) & 2) != 0 )
      v12 = 1;
    if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
    {
      v13 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v13, v13 + 4 * ((unsigned __int16)a2 & 0xFFF), v6 & 0xFFFFFDFF | 0x10);
    }
    if ( v12 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( (MiFlags & 0x300) == 0 )
    KeFlushSingleTb(a3, a4);
  return 1;
}
