// PspChangeProcessExecutionState 
 
int __fastcall PspChangeProcessExecutionState(int a1)
{
  unsigned int *v2; // lr
  unsigned int v3; // r1
  int result; // r0
  int v5; // r10
  int v6; // r8
  int v7; // r7
  unsigned int v8; // r6
  unsigned int v9; // r4
  int v10; // r5
  int v11; // r3
  unsigned int *v12; // lr
  unsigned int v13; // r1
  int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r2
  int v24; // r3
  int v25; // [sp+0h] [bp-58h]
  int v26; // [sp+4h] [bp-54h]
  char v27[24]; // [sp+8h] [bp-50h] BYREF
  char v28[56]; // [sp+20h] [bp-38h] BYREF

  v2 = (unsigned int *)(a1 + 188);
  v3 = *(_DWORD *)(a1 + 188);
  result = 0;
  v25 = 0;
  v5 = 0;
  __dmb(0xBu);
  v6 = 0;
  if ( (v3 & 0x40000000) == 0 )
  {
    v7 = (v3 >> 28) & 3;
    v8 = (v3 >> 22) & 3;
    if ( v7 != v8 )
    {
      __dmb(0xBu);
      do
        v9 = __ldrex(v2);
      while ( v9 == v3 && __strex(v3 | 0x40000000, v2) );
      __dmb(0xBu);
      if ( v9 == v3 )
      {
LABEL_8:
        v10 = 0;
        if ( !v5 )
        {
          KiStackAttachProcess(a1, 0, (int)v28);
          v18 = MmGetSessionIdEx(a1);
          if ( v18 != -1 )
          {
            v22 = MmGetSessionById(v18, v19, v20, v21);
            v6 = v22;
            if ( v22 )
            {
              if ( MmAttachSession(v22, (int)v27, v23, v24) < 0 )
              {
                ObfDereferenceObject(v6);
                v6 = 0;
              }
            }
          }
          v5 = 1;
        }
        if ( (((unsigned __int8)v8 ^ (unsigned __int8)v7) & 2) != 0 )
        {
          if ( (v7 & 2) != 0 )
            v10 = 1;
          else
            MmInSwapWorkingSet(a1);
        }
        if ( (((unsigned __int8)v8 ^ (unsigned __int8)v7) & 1) != 0 )
        {
          if ( (v7 & 1) != 0 )
            PsFreezeProcess(a1, 1);
          else
            PsThawProcess(a1, 1);
        }
        v11 = v7;
        v26 = v7;
        v8 = v7;
        if ( v10 )
        {
          v17 = MmOutSwapWorkingSet(a1, PspOutSwapSharedPages != 0);
          if ( v17 < 0 )
          {
            if ( v17 == -1073741671 )
              v25 = -1073741671;
            v8 = v7 & 0xFFFFFFFD;
          }
          v11 = v7;
        }
        v12 = (unsigned int *)(a1 + 188);
        v13 = *(_DWORD *)(a1 + 188);
        __dmb(0xBu);
        while ( 1 )
        {
          v7 = (v13 >> 28) & 3;
          if ( v7 != v11 && v7 != v8 )
            goto LABEL_8;
          __dmb(0xBu);
          v14 = v13 & 0x8F3FFFFF;
          v15 = v13 & 0x8F3FFFFF | ((v8 | (v8 << 6)) << 22);
          do
          {
            v16 = __ldrex(v12);
            if ( v16 != v13 )
              break;
            v14 = __strex(v15, v12);
          }
          while ( v14 );
          __dmb(0xBu);
          if ( v16 == v13 )
            break;
          v11 = v26;
          v13 = v16;
        }
        if ( v6 )
        {
          MmDetachSession(v6, (int)v27, v15, v14);
          ObfDereferenceObject(v6);
        }
        KiUnstackDetachProcess((unsigned int)v28, 0);
        result = v25;
      }
      else
      {
        result = sub_7C1AE4();
      }
    }
  }
  return result;
}
