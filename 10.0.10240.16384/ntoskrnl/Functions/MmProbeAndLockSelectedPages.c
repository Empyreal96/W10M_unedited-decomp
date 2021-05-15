// MmProbeAndLockSelectedPages 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall MmProbeAndLockSelectedPages(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r1
  int v14; // r0
  int v15; // r7
  int v16; // r3
  char v17; // r2
  int v18; // r8
  unsigned int v19; // r5
  unsigned int *v21; // r9
  int v22; // r5
  unsigned int *v23; // r6
  _DWORD *v24; // r1
  unsigned int v25; // t1
  _DWORD *v26; // r1
  int v27; // [sp-C0Eh] [bp-1044h]
  _DWORD v28[4]; // [sp-C06h] [bp-103Ch] BYREF
  _DWORD *v29; // [sp-BF6h] [bp-102Ch]
  int v30; // [sp-BD2h] [bp-1008h]
  _QWORD v31[376]; // [sp-BC6h] [bp-FFCh] BYREF

  _chkstk();
  v15 = v14;
  v27 = v16;
  v18 = v17;
  v19 = ((*(_DWORD *)(v14 + 20) & 0xFFF) != 0) + (*(_DWORD *)(v14 + 20) >> 12);
  if ( v19 <= 0x200 )
  {
    v21 = (unsigned int *)&v31[v19];
    memmove((int)v31, v13, 8 * v19);
    do
    {
      v22 = ((int (__fastcall *)(_DWORD *, int, _DWORD, int, int, int, int))MiProbeAndLockPrepare)(
              v28,
              v15,
              v31[0],
              1,
              v18,
              v27,
              1);
      if ( v22 < 0 )
        break;
      v23 = (unsigned int *)v31;
      if ( v31 < (_QWORD *)v21 )
      {
        v24 = v29;
        while ( 1 )
        {
          v25 = *v23;
          v23 += 2;
          v28[0] = v25;
          v28[1] = v25 + 1;
          *v24 = -1;
          if ( v25 >= MmUserProbeAddress )
          {
            if ( v18 )
              break;
          }
          v22 = ((int (__fastcall *)(_DWORD *))MiProbeLeafFrame)(v28);
          if ( v22 >= 0 )
          {
            v22 = ((int (__fastcall *)(_DWORD *))MiProbeLockFrame)(v28);
            if ( v22 >= 0 )
            {
              v26 = v29;
              *v29 = v30;
              v24 = v26 + 1;
              v29 = v24;
              if ( v23 < v21 )
                continue;
            }
          }
          goto LABEL_11;
        }
        v22 = -1073741819;
        ++dword_6343C0;
      }
LABEL_11:
      v22 = ((int (__fastcall *)(_DWORD *, int, int))MiProbeAndLockComplete)(v28, v22, 7);
    }
    while ( v22 == -1073741267 );
    if ( v22 >= 0 )
      __asm { POP.W           {R4-R11,PC} }
    RtlRaiseStatus(v22);
  }
  return sub_51ADBC();
}
