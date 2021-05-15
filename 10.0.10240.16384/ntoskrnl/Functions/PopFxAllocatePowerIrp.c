// PopFxAllocatePowerIrp 
 
int __fastcall PopFxAllocatePowerIrp(int a1, int a2, int a3, int a4, int a5, char a6, _DWORD *a7, _DWORD *a8)
{
  unsigned int *v10; // r6
  int v11; // r7
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r5
  unsigned int *v17; // r1
  unsigned int v18; // r2
  int v19; // r4
  unsigned int *v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r1
  unsigned int v23; // r1
  unsigned int v24; // r1
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r2
  unsigned int v28; // r1
  unsigned int v29; // r1
  BOOL v30; // r4
  unsigned int v31; // r1
  unsigned int v32; // r1
  BOOL v33; // r4
  unsigned int v34; // r1
  unsigned int v35; // r1
  _DWORD *v36; // r2
  unsigned int v37; // r1
  unsigned int v38; // r1
  unsigned int v39; // r1
  BOOL v40; // r4
  unsigned int v41; // r1
  unsigned int v42; // r1
  unsigned int v43; // r1
  unsigned int *v44; // r2
  unsigned int v45; // r1
  unsigned int v46; // r1
  int varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v10 = (unsigned int *)(a1 + 44);
  *a7 = 0;
  *a8 = 0;
  v11 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52A380();
  v13 = (unsigned __int8 *)v10 + 3;
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 | 0x80, v13) );
  __dmb(0xBu);
  if ( v14 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v10);
  while ( 1 )
  {
    v15 = *v10;
    if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v15 & 0x40000000) == 0 )
    {
      do
        v25 = __ldrex(v10);
      while ( v25 == v15 && __strex(v15 | 0x40000000, v10) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v16 = *(_DWORD *)(a1 + 40);
  if ( v16 )
  {
    if ( a6 )
      goto LABEL_13;
    __dmb(0xBu);
    v17 = (unsigned int *)(v16 + 112);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 + 1, v17) );
    __dmb(0xBu);
    if ( *(_BYTE *)(v16 + 108) )
    {
      __dmb(0xBu);
      do
      {
        v26 = __ldrex(v17);
        v27 = v26 - 1;
      }
      while ( __strex(v27, v17) );
      __dmb(0xBu);
      if ( !v27 )
        KeSetEvent(v16 + 116, 0, 0);
      v19 = -1073741738;
    }
    else
    {
LABEL_13:
      v19 = 0;
      __dmb(0xBu);
      v20 = (unsigned int *)(v16 + 16);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21, v20) );
      __dmb(0xBu);
      __dmb(0xBu);
      if ( (v21 & 0x10) != 0 )
      {
        do
          v28 = __ldrex(v20);
        while ( __strex(v28, v20) );
        __dmb(0xBu);
        if ( (v28 & 0x20) == 0 )
          goto LABEL_46;
        __dmb(0xBu);
        do
          v29 = __ldrex(v20);
        while ( __strex(v29, v20) );
        __dmb(0xBu);
        v30 = (v29 & 0x100) != 0;
        __dmb(0xBu);
        do
          v31 = __ldrex(v20);
        while ( __strex(v31, v20) );
        __dmb(0xBu);
        if ( v30 == ((v31 & 0x200) != 0) )
        {
          v19 = -1073741670;
        }
        else
        {
LABEL_46:
          __dmb(0xBu);
          do
            v32 = __ldrex(v20);
          while ( __strex(v32, v20) );
          __dmb(0xBu);
          v33 = (v32 & 0x200) != 0;
          __dmb(0xBu);
          do
            v34 = __ldrex(v20);
          while ( __strex(v34 | 0x20, v20) );
          __dmb(0xBu);
          do
            v35 = __ldrex(v20);
          while ( __strex(v35 ^ 0x200, v20) );
          __dmb(0xBu);
          v36 = (_DWORD *)(v16 + 4 * v33);
          v19 = 259;
          v36[72] = a2;
          v36[76] = a4;
          v36[74] = a3;
          v36[78] = a5;
        }
      }
      else
      {
        do
          v22 = __ldrex(v20);
        while ( __strex(v22, v20) );
        __dmb(0xBu);
        if ( (v22 & 0x10) == 0 )
        {
          __dmb(0xBu);
          do
            v23 = __ldrex(v20);
          while ( __strex(v23, v20) );
          __dmb(0xBu);
          if ( (v23 & 0x20) != 0 )
          {
            if ( a6 )
            {
              __dmb(0xBu);
              do
                v37 = __ldrex(v20);
              while ( __strex(v37, v20) );
              __dmb(0xBu);
              do
                v38 = __ldrex(v20);
              while ( __strex(v38 ^ 0x100, v20) );
              __dmb(0xBu);
              do
                v39 = __ldrex(v20);
              while ( __strex(v39, v20) );
              __dmb(0xBu);
              v40 = (v39 & 0x100) != 0;
              __dmb(0xBu);
              do
                v41 = __ldrex(v20);
              while ( __strex(v41, v20) );
              __dmb(0xBu);
              if ( v40 == ((v41 & 0x200) != 0) )
              {
                __dmb(0xBu);
                do
                  v42 = __ldrex(v20);
                while ( __strex(v42 & 0xFFFFFFDF, v20) );
                __dmb(0xBu);
              }
              __dmb(0xBu);
              do
                v43 = __ldrex(v20);
              while ( __strex(v43 | 0x10, v20) );
              __dmb(0xBu);
              v19 = 0;
              *a7 = *(_DWORD *)(v16 + 8);
              *a8 = *(_DWORD *)(v16 + 12);
            }
            else
            {
              v19 = -1073741670;
            }
            __dmb(0xBu);
            v44 = (unsigned int *)(v16 + 112);
            do
            {
              v45 = __ldrex(v44);
              v46 = v45 - 1;
            }
            while ( __strex(v46, v44) );
            __dmb(0xBu);
            if ( !v46 )
              KeSetEvent(v16 + 116, 0, 0);
          }
          else
          {
            __dmb(0xBu);
            do
              v24 = __ldrex(v20);
            while ( __strex(v24 | 0x10, v20) );
            __dmb(0xBu);
            KeResetEvent(v16 + 320);
            *a7 = *(_DWORD *)(v16 + 8);
            *a8 = *(_DWORD *)(v16 + 12);
          }
        }
      }
    }
  }
  else
  {
    v19 = -1073741130;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10);
  }
  else
  {
    __dmb(0xBu);
    *v10 = 0;
  }
  KfLowerIrql(v11);
  return v19;
}
