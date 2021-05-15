// NtWaitForDebugEvent 
 
int __fastcall NtWaitForDebugEvent(int a1, _DWORD *a2, int a3, int a4)
{
  _BYTE *v4; // r6
  int *v5; // r5
  int v7; // r10
  int v8; // r4
  unsigned int v9; // r9
  int v10; // r4
  int v11; // r1
  int v12; // r0
  unsigned int v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r3
  _DWORD *v16; // r4
  int v17; // r0
  int v18; // r6
  _DWORD *v19; // r1
  unsigned int v20; // r1
  int v21; // r8
  int v22; // r5
  unsigned int v24; // [sp+Ch] [bp-C4h] BYREF
  int v25; // [sp+10h] [bp-C0h]
  int v26; // [sp+14h] [bp-BCh]
  __int64 v27; // [sp+18h] [bp-B8h] BYREF
  unsigned int v28; // [sp+20h] [bp-B0h] BYREF
  unsigned int v29; // [sp+24h] [bp-ACh]
  _DWORD *v30; // [sp+28h] [bp-A8h]
  int v31; // [sp+2Ch] [bp-A4h]
  __int64 *v32; // [sp+34h] [bp-9Ch]
  unsigned int v33; // [sp+38h] [bp-98h]
  _BYTE *v34; // [sp+3Ch] [bp-94h]
  int v35; // [sp+40h] [bp-90h]
  __int64 v36; // [sp+48h] [bp-88h] BYREF
  int v37; // [sp+50h] [bp-80h] BYREF
  _BYTE v38[92]; // [sp+54h] [bp-7Ch] BYREF
  int varg_r0; // [sp+D8h] [bp+8h]
  _DWORD *varg_r1; // [sp+DCh] [bp+Ch]
  int varg_r2; // [sp+E0h] [bp+10h]
  int varg_r3; // [sp+E4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (_BYTE *)a4;
  v34 = (_BYTE *)a4;
  v5 = (int *)a3;
  v30 = a2;
  LOBYTE(varg_r1) = (_BYTE)a2;
  v25 = a1;
  v32 = (__int64 *)a3;
  v24 = a4;
  v27 = 0i64;
  v28 = 0;
  v29 = 0;
  v37 = 0;
  memset(v38, 0, sizeof(v38));
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v5 )
  {
    v27 = *(_QWORD *)v5;
    v5 = (int *)&v27;
    v32 = &v27;
    KeQuerySystemTime(&v28);
  }
  if ( v7 )
  {
    if ( (unsigned int)v4 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *v4 = *v4;
    v4[95] = v4[95];
  }
  v8 = ObReferenceObjectByHandle(a1, 1, DbgkDebugObjectType, v7, (int)&v24, 0);
  if ( v8 >= 0 )
  {
    v31 = 0;
    v25 = 0;
    v9 = v24;
    v8 = KeWaitForSingleObject(v24, 0, v7, v30, v5);
    if ( v8 >= 0 )
    {
      v24 = v29;
      v33 = v28;
      do
      {
        if ( v8 == 258 || v8 == 257 || v8 == 192 )
          break;
        v26 = 0;
        v28 = 0;
        v10 = KeAbPreAcquire(v9 + 16, 0, 0);
        v11 = KfRaiseIrql(1);
        v35 = v11;
        v12 = v9 + 16;
        do
          v13 = __ldrex((unsigned __int8 *)v12);
        while ( __strex(v13 & 0xFE, (unsigned __int8 *)v12) );
        __dmb(0xBu);
        if ( (v13 & 1) == 0 )
        {
          ExpAcquireFastMutexContended(v12, v10);
          v12 = v9 + 16;
          v11 = v35;
        }
        if ( v10 )
          *(_BYTE *)(v10 + 14) |= 1u;
        *(_DWORD *)(v12 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v12 + 28) = v11;
        if ( (*(_DWORD *)(v9 + 56) & 1) != 0 )
        {
          v8 = -1073740972;
        }
        else
        {
          v14 = *(_DWORD **)(v9 + 48);
          v15 = (_DWORD *)(v9 + 48);
          if ( v14 == (_DWORD *)(v9 + 48) )
          {
            v16 = (_DWORD *)v28;
          }
          else
          {
            do
            {
              v16 = v14;
              v17 = v14[11];
              if ( (v17 & 5) == 0 )
              {
                v18 = 1;
                v26 = 1;
                v19 = *(_DWORD **)(v9 + 48);
                if ( v19 != v14 )
                {
                  while ( v14[6] != v19[6] )
                  {
                    v19 = (_DWORD *)*v19;
                    if ( v19 == v14 )
                      goto LABEL_27;
                  }
                  v14[11] = v17 | 4;
                  v14[12] = 0;
                  v18 = 0;
                  v26 = 0;
LABEL_27:
                  v15 = (_DWORD *)(v9 + 48);
                }
                if ( v18 )
                  break;
              }
              v14 = (_DWORD *)*v14;
            }
            while ( v14 != v15 );
            v4 = v34;
          }
          if ( v26 )
          {
            v31 = v16[8];
            v25 = v16[9];
            ObfReferenceObjectWithTag(v25);
            ObfReferenceObjectWithTag(v31);
            DbgkpConvertKernelToUserStateChange(&v37, v16);
            v16[11] |= 1u;
          }
          else
          {
            KeResetEvent(v9);
          }
          v8 = 0;
          v12 = v9 + 16;
        }
        *(_DWORD *)(v12 + 4) = 0;
        v28 = *(_DWORD *)(v12 + 28);
        __dmb(0xBu);
        do
          v20 = __ldrex((unsigned int *)v12);
        while ( !v20 && __strex(1u, (unsigned int *)v12) );
        if ( v20 )
          ExpReleaseFastMutexContended((unsigned int *)v12, v20);
        KfLowerIrql((unsigned __int8)v28);
        KeAbPostRelease(v9 + 16);
        if ( v8 < 0 )
          break;
        if ( v26 )
        {
          v21 = v25;
          v22 = v31;
          DbgkpOpenHandles(&v37, v31, v25);
          ObfDereferenceObjectWithTag(v21);
          ObfDereferenceObjectWithTag(v22);
          break;
        }
        if ( v27 < 0 )
        {
          KeQuerySystemTime(&v36);
          v27 += v36 - __PAIR64__(v24, v33);
          v24 = HIDWORD(v36);
          v33 = v36;
          if ( v27 >= 0 )
          {
            v8 = 258;
            break;
          }
        }
        v8 = KeWaitForSingleObject(v9, 0, v7, v30, v5);
      }
      while ( v8 >= 0 );
    }
    ObfDereferenceObject(v9);
    memmove((int)v4, (int)&v37, 0x60u);
  }
  return v8;
}
