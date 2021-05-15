// CmpReportNotifyHelper 
 
int __fastcall CmpReportNotifyHelper(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int (__fastcall *v7)(int, int, int *); // r4
  int v8; // r5
  int result; // r0
  unsigned int v11; // r7
  unsigned int v12; // r8
  int v13; // r0
  int v14; // r6
  unsigned int v15; // r5
  int v16; // r0
  int v17; // r5
  _DWORD *v18; // r4
  int v19; // r6
  unsigned int *v20; // r4
  unsigned int v21; // r1
  int v22; // r0
  int v23; // r5
  int v24; // r6
  int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r3
  unsigned int v28; // r3
  int i; // r2
  int v30; // r1
  int v31; // r1
  int v32; // r2
  int v34; // [sp+14h] [bp-3Ch] BYREF
  int v35; // [sp+18h] [bp-38h]
  int v36; // [sp+1Ch] [bp-34h]
  int v37; // [sp+20h] [bp-30h]
  _DWORD v38[10]; // [sp+28h] [bp-28h] BYREF

  v7 = *(int (__fastcall **)(int, int, int *))(a3 + 4);
  v34 = -1;
  v8 = a2;
  v36 = a4;
  result = v7(a3, a4, &v34);
  v35 = result;
  if ( result )
  {
    v11 = *(_DWORD *)(v8 + 1864);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = KeAbPreAcquire(v11, 0, 0);
    v14 = v13;
    do
      v15 = __ldrex((unsigned __int8 *)v11);
    while ( __strex(v15 & 0xFE, (unsigned __int8 *)v11) );
    __dmb(0xBu);
    if ( (v15 & 1) == 0 )
      ExpAcquireFastMutexContended(v11, v13);
    if ( v14 )
      *(_BYTE *)(v14 + 14) |= 1u;
    *(_DWORD *)(v11 + 4) = v12;
    v16 = KfRaiseIrql(1);
    v17 = a2;
    v38[0] = v38;
    v38[1] = v38;
    v18 = *(_DWORD **)(a2 + 1800);
    v19 = v16;
    v37 = v16;
    if ( v18 )
    {
      v22 = a6;
      v23 = v35;
      v24 = v36;
      while ( 1 )
      {
        v25 = v18[4];
        v26 = (*(_DWORD *)(v25 + 4) >> 21) & 0x3FF;
        v27 = (*(_DWORD *)(a1 + 4) >> 21) & 0x3FF;
        if ( v26 > v27 )
        {
LABEL_22:
          v17 = a2;
          v19 = v37;
          break;
        }
        v28 = v27 - v26;
        for ( i = a1; v28; --v28 )
          i = *(_DWORD *)(i + 40);
        if ( i == v25 )
        {
          v30 = v18[6];
          if ( (v30 & v22 & 0x3FFFFFFF) != 0 && ((v30 & 0x40000000) != 0 || v24 == *(_DWORD *)(i + 24)) )
          {
            if ( *(_DWORD *)(v18[5] + 28) )
              return sub_804CD8();
            if ( (!a5
               || *(_DWORD *)(v18[5] + 28)
               && TmIsTransactionActive()
               && *(_DWORD *)(a5 + 24) == *(_DWORD *)(v18[5] + 28))
              && CmpNotifyTriggerCheck((int)v18, a3, v23) )
            {
              CmpPostNotify(v18, v31, v32);
            }
            v22 = a6;
          }
        }
        v18 = (_DWORD *)*v18;
        if ( !v18 )
          goto LABEL_22;
      }
    }
    KfLowerIrql(v19);
    v20 = *(unsigned int **)(v17 + 1864);
    v20[1] = 0;
    __dmb(0xBu);
    do
      v21 = __ldrex(v20);
    while ( !v21 && __strex(1u, v20) );
    if ( v21 )
      ExpReleaseFastMutexContended(v20, v21);
    KeAbPostRelease((unsigned int)v20);
    CmpDelayedDerefKeys(v38);
    result = (*(int (__fastcall **)(int, int *))(a3 + 8))(a3, &v34);
  }
  return result;
}
