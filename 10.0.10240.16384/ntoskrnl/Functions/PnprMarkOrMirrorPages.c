// PnprMarkOrMirrorPages 
 
int __fastcall PnprMarkOrMirrorPages(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  int v3; // r4
  unsigned int v4; // r1
  int *v5; // r8
  unsigned int v6; // r9
  int v7; // r2
  __int64 v8; // kr00_8
  unsigned int v9; // r7
  unsigned int v10; // r6
  int v11; // r0
  int v12; // r3
  int v13; // r3
  unsigned int v15; // [sp+8h] [bp-30h]
  char var28[44]; // [sp+10h] [bp-28h] BYREF
  __int64 varg_r0; // [sp+40h] [bp+8h]
  __int64 varg_r2; // [sp+48h] [bp+10h]

  varg_r2 = a2;
  varg_r0 = a1;
  v3 = PnprContext;
  v4 = a1 >> 12;
  v5 = *(int **)(PnprContext + 112);
  v6 = (a2 >> 12) + v4 - 1;
  v15 = v4;
  if ( v5 != (int *)(PnprContext + 112) )
  {
    v7 = a3;
    do
    {
      v8 = *((_QWORD *)v5 + 1);
      v9 = HIDWORD(v8) + v8 - 1;
      if ( v6 < (unsigned int)v8 )
        break;
      v10 = v4;
      if ( v4 <= (unsigned int)v8 )
        v10 = v5[2];
      if ( v6 < v9 )
        v9 = v6;
      if ( v10 <= v9 )
      {
        if ( v7 )
        {
          v11 = (*(int (__fastcall **)(_DWORD, _DWORD, unsigned int, _DWORD, unsigned int, _DWORD))(v3 + 580))(
                  *(_DWORD *)(v3 + 552),
                  *(_DWORD *)(v3 + 580),
                  v10 << 12,
                  0,
                  (v9 - v10 + 1) << 12,
                  0);
          v3 = PnprContext;
          if ( v11 < 0 )
          {
            v12 = *(_DWORD *)(PnprContext + 608);
            if ( !v12 )
              v12 = 3415;
            *(_DWORD *)(PnprContext + 608) = v12;
            v13 = *(_DWORD *)(v3 + 612);
            if ( !v13 )
              v13 = 8;
            *(_DWORD *)(v3 + 612) = v13;
          }
        }
        else
        {
          KeAcquireInStackQueuedSpinLock((unsigned int *)(v3 + 120), (unsigned int)var28);
          RtlClearBits((_BYTE *)v5 + 16, v10 - v8, v9 - v10 + 1);
          KeReleaseInStackQueuedSpinLock((int)var28);
          v3 = PnprContext;
        }
        v4 = v15;
        v7 = a3;
      }
      v5 = (int *)*v5;
    }
    while ( v5 != (int *)(v3 + 112) );
  }
  return 0;
}
