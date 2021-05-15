// MiPageNotZero 
 
_DWORD *__fastcall MiPageNotZero(_DWORD *a1, unsigned int a2)
{
  _DWORD *v3; // r6
  unsigned int v4; // r4
  int *v5; // r5
  unsigned int v6; // r0
  int v7; // r2
  int v8; // r8
  int v9; // r4
  int v10; // t1
  int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r1
  int v15; // [sp+8h] [bp-20h]

  v3 = a1;
  do
    v4 = __ldrex((unsigned int *)&dword_63441C);
  while ( __strex(v4 + 1, (unsigned int *)&dword_63441C) );
  v5 = a1;
  v6 = (unsigned int)(a1 + 1024);
  v7 = 0;
  v8 = 0;
  v15 = 0;
  if ( (unsigned int)v3 >= v6 )
    goto LABEL_14;
  while ( 1 )
  {
    v10 = *v5++;
    v9 = v10;
    if ( v10 )
    {
      if ( ++v7 != 1 )
        goto LABEL_14;
      v8 = ((_WORD)v5 - 4) & 0xFFF;
      v15 = v9;
      if ( ((v9 - 1) & v9) != 0 )
        break;
    }
    if ( (unsigned int)v5 >= v6 )
      goto LABEL_10;
  }
  v7 = 2;
LABEL_10:
  if ( v7 == 1 )
  {
    v11 = 299;
    do
      v12 = __ldrex((unsigned int *)&dword_634418);
    while ( __strex(v12 + 1, (unsigned int *)&dword_634418) );
  }
  else
  {
LABEL_14:
    v11 = 295;
  }
  if ( (MmPageValidationAction & 1) != 0 )
    KeBugCheckEx(v11, (int)v3, a2, 0, 0);
  KeSetEvent(dword_63F7E0, 0, 0);
  if ( (MiFlags & 0x30) == 32 )
  {
    do
      v13 = __ldrex((unsigned int *)algn_63439C);
    while ( !v13 && __strex(1u, (unsigned int *)algn_63439C) );
    if ( !v13 )
    {
      dword_6343A8 = v8 + (a2 << 12);
      *(_DWORD *)algn_6343AC = (a2 >> 20) + __CFADD__(v8, a2 << 12);
      dword_6343A0 = v15;
      dword_634398 = v11;
      dword_6343B8 = (int)MiBadMemoryLogger;
      dword_6343BC = (int)&dword_634398;
      dword_6343B0 = 0;
      ExQueueWorkItem(&dword_6343B0, 1);
    }
  }
  return KeZeroPages(v3, 0x1000u);
}
