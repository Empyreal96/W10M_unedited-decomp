// MmSetPfnListPriorities 
 
int __fastcall MmSetPfnListPriorities(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  unsigned int v3; // r8
  int v4; // r7
  unsigned int v5; // r6
  int v6; // r4
  int v7; // r9
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned __int8 *v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r6
  unsigned int v14; // r2
  char v15; // r3
  int v16; // r1
  int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r1
  int v23; // r2
  int v25; // [sp+0h] [bp-30h] BYREF
  int v26; // [sp+4h] [bp-2Ch]
  int v27; // [sp+8h] [bp-28h]
  int v28; // [sp+Ch] [bp-24h]

  v2 = a2;
  v3 = (unsigned int)&a2[4 * a1];
  v4 = 0;
  if ( (unsigned int)a2 < v3 )
  {
    do
    {
      v5 = v2[2];
      if ( MI_IS_PFN(v5) )
      {
        v27 = v5;
        v6 = MmPfnDatabase + 24 * v5;
        v25 = 0;
        v26 = 0;
        v28 = 0;
        v7 = KfRaiseIrql(2);
        v8 = (unsigned __int8 *)(v6 + 15);
        do
          v9 = __ldrex(v8);
        while ( __strex(v9 | 0x80, v8) );
        __dmb(0xBu);
        if ( v9 >> 7 )
        {
          v10 = (unsigned __int8 *)(v6 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v11 = *(_DWORD *)(v6 + 12);
              __dmb(0xBu);
            }
            while ( v11 < 0 );
            do
              v12 = __ldrex(v10);
            while ( __strex(v12 | 0x80, v10) );
            __dmb(0xBu);
          }
          while ( v12 >> 7 );
        }
        MiIdentifyPfn((int *)v6, &v25);
        v13 = v28;
        if ( v28 == v2[3]
          && !((v26 ^ v2[1]) & 0x1FFFFFF | (*v2 ^ v25) & 0xFFFFFE00)
          && ((v14 = *(_BYTE *)(v6 + 18) & 7, v14 == 6) || v14 >= 2 && v14 <= 4) )
        {
          v15 = *(_BYTE *)(v6 + 19);
          v16 = (v2[1] >> 25) & 7;
          if ( (v15 & 8) != 0 )
            v17 = 5;
          else
            v17 = v15 & 7;
          if ( v16 != v17 )
          {
            if ( v14 == 2 )
              MiRelinkStandbyPage(v6, v16, 1022);
            else
              *(_BYTE *)(v6 + 19) = v15 & 0xF8 | (v2[1] >> 25) & 7;
          }
          __dmb(0xBu);
          v18 = (unsigned int *)(v6 + 12);
          do
            v19 = __ldrex(v18);
          while ( __strex(v19 & 0x7FFFFFFF, v18) );
          KfLowerIrql(v7);
        }
        else
        {
          __dmb(0xBu);
          v20 = (unsigned int *)(v6 + 12);
          do
            v21 = __ldrex(v20);
          while ( __strex(v21 & 0x7FFFFFFF, v20) );
          KfLowerIrql(v7);
          v28 = v13 | 2;
          v22 = v26;
          v23 = v27;
          v4 = -1073741788;
          *v2 = v25;
          v2[1] = v22;
          v2[2] = v23;
          v2[3] = v13 | 2;
        }
      }
      else
      {
        v4 = -1073741584;
      }
      v2 += 4;
    }
    while ( (unsigned int)v2 < v3 );
  }
  return v4;
}
