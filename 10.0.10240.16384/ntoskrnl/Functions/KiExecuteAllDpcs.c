// KiExecuteAllDpcs 
 
int __fastcall KiExecuteAllDpcs(__int64 a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r4
  int v5; // r7
  _DWORD *v7; // r10
  int v8; // r9
  __int16 *v9; // r4
  int v10; // r3
  unsigned __int16 *v11; // r5
  unsigned int *v12; // lr
  unsigned int v13; // r2
  unsigned int v14; // r1
  int *v15; // r2
  int v16; // r3
  int v17; // r0
  int v18; // r3
  _QWORD *v19; // lr
  int v20; // r4
  unsigned int v21; // r1
  unsigned int i; // r2
  unsigned int v23; // r2
  int (*v24)(void); // r3
  int v25; // r0
  int v26; // r1
  int *v27; // r3
  int v28; // r5
  _DWORD *v29; // r8
  int v30; // r5
  __int64 v31; // r0
  __int64 v32; // r0
  int v33; // r5
  int v34; // r8
  unsigned int v35; // r4
  int v36; // r1
  int v38; // [sp+Ch] [bp-BCh] BYREF
  int *v39; // [sp+10h] [bp-B8h]
  __int16 *v40; // [sp+14h] [bp-B4h]
  unsigned int v41; // [sp+18h] [bp-B0h]
  int v42; // [sp+1Ch] [bp-ACh]
  int v43; // [sp+20h] [bp-A8h]
  _DWORD *v44; // [sp+24h] [bp-A4h]
  int v45; // [sp+28h] [bp-A0h]
  __int16 v46; // [sp+30h] [bp-98h] BYREF
  int v47; // [sp+34h] [bp-94h]
  int v48; // [sp+38h] [bp-90h]
  int v49; // [sp+3Ch] [bp-8Ch]
  int v50; // [sp+40h] [bp-88h]
  unsigned __int16 *v51; // [sp+44h] [bp-84h]
  int v52; // [sp+48h] [bp-80h]
  int v53; // [sp+4Ch] [bp-7Ch]
  int v54; // [sp+50h] [bp-78h]
  int v55[2]; // [sp+58h] [bp-70h] BYREF
  _DWORD v56[2]; // [sp+60h] [bp-68h] BYREF
  int v57[8]; // [sp+68h] [bp-60h] BYREF
  int var40[17]; // [sp+88h] [bp-40h] BYREF

  v3 = a1 + 24 * (a3 + 70);
  v4 = *(_DWORD *)(v3 + 12);
  v5 = a1;
  v7 = (_DWORD *)a2;
  v44 = (_DWORD *)a2;
  v8 = HIDWORD(a1);
  v42 = HIDWORD(a1);
  v45 = a1;
  v43 = v3;
  if ( !v4 )
    return a1;
  LODWORD(a1) = dword_682604;
  if ( (dword_682604 & 0x80) != 0 )
  {
    if ( a3 )
    {
      LODWORD(a1) = sub_52F0D8();
      return a1;
    }
    v46 = 3908;
    v47 = 4196866;
    v9 = &v46;
  }
  else
  {
    v9 = 0;
  }
  v10 = *(_DWORD *)(v5 + 3276);
  v40 = v9;
  v52 = v10;
  v11 = (unsigned __int16 *)(v5 + 2 * (a3 + 878));
  v51 = v11;
  while ( 1 )
  {
    v12 = (unsigned int *)(v3 + 8);
    if ( (a1 & 0x210000) != 0 )
    {
      LODWORD(a1) = KiAcquireSpinLockInstrumented(v3 + 8);
      goto LABEL_51;
    }
    do
      v13 = __ldrex(v12);
    while ( __strex(1u, v12) );
    __dmb(0xBu);
    if ( v13 )
    {
      LODWORD(a1) = KxWaitForSpinLockAndAcquire(v3 + 8);
LABEL_51:
      v12 = (unsigned int *)(v3 + 8);
    }
    if ( *(int *)(v3 + 12) <= 1 )
    {
      __dmb(0xBu);
      do
        v14 = __ldrex(v11);
      while ( __strex(v14 & 0xFFED, v11) );
      __dmb(0xBu);
      if ( !*(_DWORD *)(v3 + 12) )
        break;
    }
    v15 = *(int **)v3;
    v16 = **(_DWORD **)v3;
    *(_DWORD *)v3 = v16;
    if ( !v16 )
      *(_DWORD *)(v3 + 4) = v3;
    v17 = (int)(v15 - 1);
    v38 = v15[2];
    v39 = v15 - 1;
    v18 = v15[3];
    v19 = (_QWORD *)v15[6];
    v15[6] = 0;
    v50 = v18;
    v48 = v15[4];
    v49 = v15[5];
    --*(_DWORD *)(v3 + 12);
    *(_DWORD *)(v3 + 20) = v15 - 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v3 + 8);
      v17 = (int)v39;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v3 + 8) = 0;
    }
    __enable_irq();
    if ( (dword_682604 & 0x40000) != 0 )
    {
      v55[0] = v38;
      v55[1] = -927066983 * (__ROR4__(bswap32(KiWaitAlways ^ v17) ^ v38, KiWaitNever) ^ KiWaitNever);
      v57[0] = (int)v55;
      v57[1] = 0;
      v57[2] = 8;
      v57[3] = 0;
      EtwTraceKernelEvent(v57, 1, 537133056, 3941, 4196866);
      v17 = (int)v39;
    }
    if ( v9 )
    {
      v20 = 0;
      v21 = EtwpActiveSystemLoggers;
      for ( i = __clz(__rbit(EtwpActiveSystemLoggers)); 1 != (unsigned __int8)(i >> 5); i = __clz(__rbit(v21)) )
      {
        v21 &= v21 - 1;
        if ( &EtwpGroupMasks[8 * i] && (EtwpGroupMasks[8 * i + 1] & 0x80) != 0 )
          v20 |= 1 << EtwpSystemLogger[2 * i + 1];
      }
      v23 = 0;
      v41 = 0;
      do
      {
        if ( ((1 << v23) & v20) != 0 )
        {
          v24 = (int (*)(void))*(&EtwpSystemTimeStamp + v23);
          if ( (char *)v24 == (char *)EtwpGetPerfCounter )
          {
            KeQueryPerformanceCounter(v56, 0);
            v25 = v56[0];
            v26 = v56[1];
          }
          else
          {
            v25 = v24();
          }
          v23 = v41;
          v27 = &v57[2 * v41 + 4];
          *v27 = v25;
          v27[1] = v26;
        }
        else
        {
          v57[2 * v23 + 4] = 0;
          v57[2 * v23 + 5] = 0;
        }
        v41 = ++v23;
      }
      while ( v23 < 2 );
      v8 = v42;
      v3 = v43;
      v7 = v44;
      v5 = v45;
      v17 = (int)v39;
    }
    v28 = (*v7)++ & 0xF;
    v29 = &v7[3 * v28];
    v29[4] = v38;
    v29[5] = KeTickCount;
    v30 = *(_DWORD *)(v8 + 308);
    *(_DWORD *)(v5 + 2332) = 0;
    *(_DWORD *)(v5 + 3276) = v19;
    v54 = v30;
    if ( v19 != (_QWORD *)1 )
    {
      LODWORD(v31) = ReadTimeStampCounter();
      v19[4] = v31;
      v17 = (int)v39;
    }
    LODWORD(a1) = ((int (__fastcall *)(int, int, int, int))v38)(v17, v50, v48, v49);
    if ( v19 != (_QWORD *)1 )
    {
      LODWORD(v32) = ReadTimeStampCounter();
      a1 = v32 + v19[3] - v19[4];
      v30 = v54;
      ++v19[5];
      v19[3] = a1;
    }
    v29[6] = KeTickCount;
    if ( v30 != *(_DWORD *)(v8 + 308) )
      KeBugCheck2(199, 4, v38, v30, *(_DWORD *)(v8 + 308), 0);
    v9 = v40;
    if ( v40 )
    {
      var40[4] = (int)&v38;
      var40[5] = 0;
      var40[6] = 4;
      var40[7] = 0;
      v33 = *((_DWORD *)v40 + 1);
      v34 = (unsigned __int16)*v40;
      v35 = EtwpActiveSystemLoggers;
      LODWORD(a1) = __clz(__rbit(EtwpActiveSystemLoggers));
      v53 = a1;
      if ( 1 != (unsigned __int8)((unsigned int)a1 >> 5) )
      {
        do
        {
          v35 &= v35 - 1;
          if ( &EtwpGroupMasks[8 * (_DWORD)a1] && (EtwpGroupMasks[8 * (_DWORD)a1 + 1] & 0x80) != 0 )
          {
            var40[0] = (int)&v57[2 * (unsigned __int16)EtwpSystemLogger[2 * (_DWORD)a1 + 1] + 4];
            var40[1] = 0;
            var40[3] = 0;
            v36 = (unsigned __int16)EtwpSystemLogger[2 * (_DWORD)a1];
            var40[2] = 8;
            EtwpLogKernelEvent(var40, v36, 2, v34, v33);
          }
          LODWORD(a1) = __clz(__rbit(v35));
          v53 = a1;
        }
        while ( 1 != (unsigned __int8)((unsigned int)a1 >> 5) );
        v8 = v42;
        v3 = v43;
        v7 = v44;
        v5 = v45;
      }
      v9 = v40;
    }
    __disable_irq();
    if ( !*(_DWORD *)(v3 + 12) )
      goto LABEL_47;
    v11 = v51;
    LODWORD(a1) = dword_682604;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    LODWORD(a1) = KiReleaseSpinLockInstrumented(v12);
  }
  else
  {
    __dmb(0xBu);
    *v12 = 0;
  }
LABEL_47:
  *(_DWORD *)(v5 + 3276) = v52;
  return a1;
}
