// KiInterruptDispatchCommon 
 
int __fastcall KiInterruptDispatchCommon(int a1, int a2, int a3, char *a4, _DWORD *a5)
{
  int v8; // r10
  int v9; // r7
  unsigned int *v10; // r9
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r5
  __int64 v15; // r0
  int v16; // r2
  bool v17; // zf
  int v18; // r4
  unsigned int v19; // r10
  int v20; // r7
  int v21; // r0
  unsigned int v22; // r2
  int v23; // r8
  int v24; // r1
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r3
  int v29; // r7
  int v30; // r0
  char **v31; // r1
  int v32; // r2
  int v33; // r4
  int v34; // r0
  char **v35; // r1
  int v36; // r2
  int v37; // [sp+0h] [bp-70h] BYREF
  int v38; // [sp+4h] [bp-6Ch]
  int v39; // [sp+8h] [bp-68h]
  int v40; // [sp+Ch] [bp-64h]
  unsigned int v41; // [sp+10h] [bp-60h]
  int v42; // [sp+14h] [bp-5Ch]
  int v43; // [sp+18h] [bp-58h]
  int v44; // [sp+1Ch] [bp-54h]
  _DWORD *v45; // [sp+20h] [bp-50h]
  int v46; // [sp+24h] [bp-4Ch]
  int v47; // [sp+28h] [bp-48h] BYREF
  __int16 v48; // [sp+2Ch] [bp-44h]
  __int16 v49; // [sp+2Eh] [bp-42h]
  int v50; // [sp+30h] [bp-40h]
  int v51; // [sp+34h] [bp-3Ch]
  char v52; // [sp+38h] [bp-38h] BYREF
  _DWORD var30[13]; // [sp+40h] [bp-30h] BYREF

  v45 = a5;
  v39 = a1;
  v40 = 0;
  v51 = a2;
  v8 = a1;
  v9 = 0;
  var30[0] = 0;
  var30[1] = 0;
  var30[2] = 0;
  v42 = 0;
  v43 = 0;
  v41 = KeGetCurrentIrql(a1);
  if ( !a4 )
    a4 = &v52;
  *(_DWORD *)a4 = a4;
  *((_DWORD *)a4 + 1) = a4;
  if ( v8 )
  {
    v10 = (unsigned int *)(KiGlobalSecondaryIDT + 28 * (a2 - 4096));
    v38 = KfRaiseIrql(12);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_553A78();
    do
      v12 = __ldrex(v10);
    while ( __strex(1u, v10) );
    __dmb(0xBu);
    if ( v12 )
      KxWaitForSpinLockAndAcquire(v10);
    v13 = KiGetInterruptObjectFromSecondaryVector(a2);
  }
  else
  {
    v10 = 0;
    KeGetCurrentProcessorNumberEx((int)&v37);
    v49 = 0;
    v50 = 0;
    v48 = v37;
    v47 = 1 << SBYTE2(v37);
    KeSetSystemGroupAffinityThread((int)&v47, var30);
    v38 = KfRaiseIrql(15);
    v13 = KiGetInterruptObjectFromVector(a2);
  }
  v14 = v13;
  if ( v13 )
  {
    v15 = KiUpdateInterruptObjectActiveCount(v13, 1, 0x10000);
    v17 = (a3 & HIDWORD(v15)) == 0;
    v18 = v15;
    if ( !v17 )
    {
      while ( *(_BYTE *)(v18 + 49) )
      {
        v28 = *(_DWORD *)(v18 + 4);
        if ( !v28 )
          goto LABEL_59;
        v18 = v28 - 4;
        if ( v28 - 4 == v14 )
        {
          if ( !*(_BYTE *)(v28 + 45) )
            break;
LABEL_59:
          v18 = 0;
          break;
        }
      }
    }
    if ( v18 )
    {
      v16 = 0;
      v19 = 0;
      v44 = *(_DWORD *)(v14 + 64);
      v37 = 0;
      while ( v41 <= 2 || *(_BYTE *)(v18 + 49) )
      {
        if ( (*(_DWORD *)(v18 + 60) & HIDWORD(v15)) != 0 )
        {
          v23 = *(_DWORD *)(v18 + 4) - 4;
        }
        else
        {
          ++v19;
          KiUpdateInterruptObjectActiveCount(v18, 1, v16);
          if ( v39 )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(v10);
            }
            else
            {
              __dmb(0xBu);
              *v10 = 0;
            }
          }
          v20 = v38;
          KfLowerIrql(v38);
          v21 = KiInvokeInterruptServiceRoutine(v18, v20, v51);
          v40 = 2;
          v9 = v21;
          v46 = v21;
          if ( v39 )
          {
            v38 = KfRaiseIrql(12);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(v10);
            }
            else
            {
              do
                v22 = __ldrex(v10);
              while ( __strex(1u, v10) );
              __dmb(0xBu);
              if ( v22 )
                KxWaitForSpinLockAndAcquire(v10);
            }
          }
          else
          {
            v38 = KfRaiseIrql(15);
          }
          v23 = *(_DWORD *)(v18 + 4) - 4;
          KiUpdateInterruptObjectActiveCount(v18, 0, v22);
          if ( (*(_DWORD *)(v18 + 60) & 2) != 0 && !*(_WORD *)(v18 + 58) )
          {
            v29 = *(_DWORD *)(v18 + 88);
            if ( v39 )
              v30 = KiDisconnectSecondaryInterruptInternal(v18);
            else
              v30 = KiDisconnectInterruptInternal(v18, *(_DWORD *)(v29 + 4));
            *(_DWORD *)(v29 + 8) = v30;
            v31 = (char **)*((_DWORD *)a4 + 1);
            v32 = v18 + 4;
            *(_DWORD *)(v18 + 4) = a4;
            *(_DWORD *)(v18 + 8) = v31;
            if ( *v31 != a4 )
              __fastfail(3u);
            v9 = v46;
            *v31 = (char *)v32;
            *((_DWORD *)a4 + 1) = v32;
          }
          v16 = v37;
          HIDWORD(v15) = 1;
        }
        if ( v44 )
        {
          if ( v9 )
          {
            v16 = 1;
            v37 = 1;
          }
          if ( v23 == v14 )
          {
            if ( v19 <= 1 || !v16 )
            {
              v9 = 1;
              goto LABEL_31;
            }
            v16 = 0;
            v37 = 0;
            v19 = 0;
            v9 = 0;
          }
        }
        else if ( v9 || v23 == v14 )
        {
          goto LABEL_31;
        }
        v18 = v23;
      }
      v43 = 1;
      if ( v40 != 2 )
        v40 = 1;
      v42 = *(_DWORD *)(v18 + 44);
LABEL_31:
      v8 = v39;
    }
    KiUpdateInterruptObjectActiveCount(v14, 0, v16);
    if ( (*(_DWORD *)(v14 + 60) & 2) != 0 && !*(_WORD *)(v14 + 58) )
    {
      v33 = *(_DWORD *)(v14 + 88);
      if ( v8 )
        v34 = KiDisconnectSecondaryInterruptInternal(v14);
      else
        v34 = KiDisconnectInterruptInternal(v14, *(_DWORD *)(v33 + 4));
      *(_DWORD *)(v33 + 8) = v34;
      v35 = (char **)*((_DWORD *)a4 + 1);
      v36 = v14 + 4;
      *(_DWORD *)(v14 + 4) = a4;
      *(_DWORD *)(v14 + 8) = v35;
      if ( *v35 != a4 )
        __fastfail(3u);
      *v35 = (char *)v36;
      *((_DWORD *)a4 + 1) = v36;
    }
  }
  if ( v8 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v10);
    }
    else
    {
      __dmb(0xBu);
      *v10 = 0;
    }
    KfLowerIrql(v38);
  }
  else
  {
    KfLowerIrql(v38);
    KeRevertToUserGroupAffinityThread((int)var30, v25, v26, v27);
  }
  if ( v43 )
    IoProcessPassiveInterrupts(v42, v24);
  if ( v41 < 2 )
    KiProcessDisconnectList(a4);
  if ( v45 )
    *v45 = v40;
  return v9;
}
