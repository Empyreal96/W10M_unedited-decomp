// KeProfileInterruptWithSource 
 
int __fastcall KeProfileInterruptWithSource(int result, int a2)
{
  int v3; // r7
  int **v4; // r5
  int *v5; // r4
  unsigned int v6; // r6
  unsigned int v7; // r2
  unsigned int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r6
  int i; // r4
  unsigned int v13; // r2
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r1

  v3 = result;
  v4 = (int **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 16);
  v5 = *v4;
  v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  while ( v5 != (int *)v4 )
  {
    if ( *((__int16 *)v5 + 22) == a2 )
    {
      if ( *((_WORD *)v5 - 2) == 17 )
      {
        result = ((int (__fastcall *)(int, int))v5[3])(v3, v5[4]);
      }
      else if ( (((unsigned int)v5[10] >> *(_DWORD *)(v6 + 1428)) & 1) != 0 )
      {
        v7 = *(_DWORD *)(v3 + 128);
        v8 = v5[3];
        if ( v7 >= v8 && v7 <= v5[4] )
        {
          v9 = (unsigned int *)((((v7 - v8) >> v5[5]) & 0xFFFFFFFC) + v5[6]);
          __dmb(0xBu);
          do
            v10 = __ldrex(v9);
          while ( __strex(v10 + 1, v9) );
          __dmb(0xBu);
        }
      }
    }
    v5 = (int *)*v5;
  }
  v11 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  for ( i = KiProfileListHead; (int *)i != &KiProfileListHead; i = *(_DWORD *)i )
  {
    if ( *(__int16 *)(i + 44) == a2 )
    {
      if ( *(_WORD *)(i - 4) == 17 )
      {
        result = (*(int (__fastcall **)(int, _DWORD))(i + 12))(v3, *(_DWORD *)(i + 16));
      }
      else if ( ((*(_DWORD *)(i + 40) >> *(_DWORD *)(v11 + 1428)) & 1) != 0 )
      {
        v13 = *(_DWORD *)(v3 + 128);
        v14 = *(_DWORD *)(i + 12);
        if ( v13 >= v14 && v13 <= *(_DWORD *)(i + 16) )
        {
          v15 = (unsigned int *)((((v13 - v14) >> *(_DWORD *)(i + 20)) & 0xFFFFFFFC) + *(_DWORD *)(i + 24));
          __dmb(0xBu);
          do
            v16 = __ldrex(v15);
          while ( __strex(v16 + 1, v15) );
          __dmb(0xBu);
        }
      }
    }
  }
  return result;
}
