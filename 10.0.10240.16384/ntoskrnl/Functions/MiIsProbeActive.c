// MiIsProbeActive 
 
int __fastcall MiIsProbeActive(unsigned int *a1, int a2, char a3)
{
  int v3; // r8
  int v6; // r5
  _DWORD *v7; // r4
  int v8; // r0
  unsigned int v9; // r0
  unsigned int v10; // r7
  unsigned int v11; // r1
  int v12; // lr
  unsigned int v13; // r3
  __int16 *v14; // r6
  unsigned int v15; // r2
  __int16 v16; // t1
  _DWORD *v17; // r3
  _DWORD *v18; // r2
  _DWORD *v19; // r10
  unsigned int *v20; // r3
  unsigned int v21; // r9
  unsigned int v22; // t1
  unsigned int v23; // r8
  _DWORD *v25; // r6
  int v26; // r0
  __int16 v27; // r3
  unsigned int *i; // [sp+8h] [bp-38h]
  unsigned int *v30; // [sp+10h] [bp-30h] BYREF
  unsigned int v31; // [sp+14h] [bp-2Ch]
  char v32[40]; // [sp+18h] [bp-28h] BYREF

  v3 = a3 & 1;
  if ( (a3 & 1) == 0 || (a3 & 2) != 0 || dword_634884[0] )
  {
    v6 = 0;
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634880, (unsigned int)v32);
    v7 = (_DWORD *)dword_634884[0];
    if ( !dword_634884[0] )
    {
LABEL_42:
      KeReleaseInStackQueuedSpinLock((int)v32);
      return v6;
    }
    if ( !v3 )
    {
      v30 = a1;
      v31 = (unsigned int)a1 + a2 - 1;
      if ( dword_634884[0] )
      {
        do
        {
          v8 = MiIoPfnRangeCompare(&v30, (int)v7);
          if ( v8 >= 0 )
          {
            if ( v8 <= 0 )
              break;
            v7 = (_DWORD *)v7[1];
          }
          else
          {
            v7 = (_DWORD *)*v7;
          }
        }
        while ( v7 );
        v10 = (unsigned int)v30;
        v9 = v31;
        while ( v7 )
        {
          v11 = v7[5];
          if ( v9 < v11 )
            break;
          v12 = v7[6];
          if ( v10 < v11 )
            v13 = 0;
          else
            v13 = v10 - v11;
          v14 = (__int16 *)(v12 + 2 * v13);
          if ( v9 + 1 > v11 + 512 )
            v15 = v12 + 1024;
          else
            v15 = v12 + 2 * (v9 - v11 + 1);
          if ( (unsigned int)v14 < v15 )
          {
            while ( 1 )
            {
              v16 = *v14++;
              __dmb(0xBu);
              if ( (v16 & 0x3FFF) != 0 )
                break;
              if ( (unsigned int)v14 >= v15 )
                goto LABEL_26;
            }
            v6 = 1;
LABEL_26:
            v10 = (unsigned int)v30;
            v9 = v31;
          }
          if ( v6 == 1 )
            break;
          v17 = (_DWORD *)v7[1];
          v18 = v7;
          if ( v17 )
          {
            do
            {
              v7 = v17;
              v17 = (_DWORD *)*v17;
            }
            while ( v17 );
          }
          else
          {
            while ( 1 )
            {
              v7 = (_DWORD *)(v7[2] & 0xFFFFFFFC);
              if ( !v7 || (_DWORD *)*v7 == v18 )
                break;
              v18 = v7;
            }
          }
        }
      }
      goto LABEL_42;
    }
    v19 = 0;
    v20 = &a1[a2];
    v21 = -1;
    for ( i = v20; ; v20 = i )
    {
      if ( a1 >= v20 )
        goto LABEL_42;
      v22 = *a1++;
      v23 = v22 >> 12;
      if ( MI_IS_PFN(v22 >> 12) )
      {
        if ( (a3 & 2) != 0 && *(unsigned __int16 *)(MmPfnDatabase + 24 * v23 + 16) > 2u )
        {
LABEL_41:
          v6 = 1;
          goto LABEL_42;
        }
      }
      else if ( v21 == -1 || v21 != (v23 & 0xFFFFFE00) )
      {
        if ( !v19 || v19[5] != (v23 & 0xFFFFFE00) )
        {
          v25 = v7;
          if ( !v7 )
            goto LABEL_58;
          do
          {
            v26 = MiIoPfnCompare(v23, (int)v25);
            if ( v26 >= 0 )
            {
              if ( v26 <= 0 )
                break;
              v25 = (_DWORD *)v25[1];
            }
            else
            {
              v25 = (_DWORD *)*v25;
            }
          }
          while ( v25 );
          if ( !v25 )
          {
LABEL_58:
            v21 = v23 & 0xFFFFFE00;
            continue;
          }
          v19 = v25;
        }
        v27 = *(_WORD *)(v19[6] + 2 * (v23 - v19[5]));
        __dmb(0xBu);
        if ( (v27 & 0x3FFF) != 0 )
          goto LABEL_41;
        v7 = (_DWORD *)dword_634884[0];
      }
    }
  }
  return 0;
}
