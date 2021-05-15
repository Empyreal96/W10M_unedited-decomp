// IoRetrievePriorityInfo 
 
int __fastcall IoRetrievePriorityInfo(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r3
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r2
  int v11; // r4
  unsigned int v12; // r0
  int v13; // r2
  unsigned int v14; // r3
  int v15; // r3
  int v16; // r3

  a4[3] = 2;
  if ( a1 && (*(_DWORD *)(a1 + 8) & 0xE0000) != 0 )
  {
    a4[3] = IoGetIoPriorityHint(a1);
  }
  else
  {
    if ( !a2 )
    {
      if ( !a3 )
        goto LABEL_32;
      v7 = (*(_DWORD *)(a3 + 960) >> 9) & 7;
      if ( (*(_DWORD *)(*(_DWORD *)(a3 + 336) + 192) & 0x100000) != 0 )
        v7 = 0;
      if ( v7 >= 2 || a3 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !*(_DWORD *)(a3 + 1000) )
        goto LABEL_9;
      goto LABEL_39;
    }
    v6 = *(_DWORD *)(a2 + 124);
    if ( !v6 )
    {
      if ( !a3 )
      {
LABEL_32:
        a4[1] = -1;
        a4[2] = -1;
        return 0;
      }
      v7 = (*(_DWORD *)(a3 + 960) >> 9) & 7;
      if ( (*(_DWORD *)(*(_DWORD *)(a3 + 336) + 192) & 0x100000) != 0 )
        v7 = 0;
      if ( v7 >= 2 || a3 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !*(_DWORD *)(a3 + 1000) )
        goto LABEL_9;
LABEL_39:
      v7 = 2;
LABEL_9:
      a4[3] = v7;
      goto LABEL_10;
    }
    v16 = *(_DWORD *)(v6 + 32);
    if ( !v16 )
    {
      if ( !a3 )
        goto LABEL_32;
      v7 = (*(_DWORD *)(a3 + 960) >> 9) & 7;
      if ( (*(_DWORD *)(*(_DWORD *)(a3 + 336) + 192) & 0x100000) != 0 )
        v7 = 0;
      if ( v7 >= 2 || a3 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) || !*(_DWORD *)(a3 + 1000) )
        goto LABEL_9;
      goto LABEL_39;
    }
    a4[3] = v16 - 1;
  }
LABEL_10:
  if ( !a3 )
    goto LABEL_32;
  if ( *(char *)(a3 + 123) >= 16 || !*(_DWORD *)(a3 + 68) )
    goto LABEL_13;
  v11 = 0;
  v12 = KfRaiseIrql(2);
  v13 = *(_DWORD *)(a3 + 68);
  v14 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( v13 )
  {
    v15 = *(_DWORD *)(v14 + 3760) + v13;
    if ( v15 )
      v11 = (*(unsigned __int8 *)(v15 + 92) >> 3) & 1;
  }
  if ( v12 < 2 )
    KfLowerIrql(v12);
  if ( v11 )
    v8 = 1;
  else
LABEL_13:
    v8 = *(char *)(a3 + 347);
  a4[1] = v8;
  v9 = (*(_DWORD *)(a3 + 960) >> 12) & 7;
  if ( (*(_DWORD *)(*(_DWORD *)(a3 + 336) + 192) & 0x100000) != 0 && v9 >= 2 )
    v9 = 2;
  a4[2] = v9;
  return 0;
}
