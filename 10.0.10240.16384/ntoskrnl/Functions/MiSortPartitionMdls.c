// MiSortPartitionMdls 
 
int __fastcall MiSortPartitionMdls(int result)
{
  _DWORD *v1; // r2
  __int64 v2; // r4
  _DWORD *v3; // r8
  unsigned int v4; // r3
  unsigned int v5; // r9
  _DWORD *v6; // r6
  int v7; // r7
  int v8; // r4
  int v9; // r2
  unsigned int v10; // r1
  int v11; // t1
  _DWORD *v12; // r10
  unsigned int v13; // r6
  unsigned int v14; // r8
  int v15; // r0
  _DWORD *v16; // r7
  unsigned int v17; // r1
  _DWORD *v18; // r6
  int v19; // r7
  _QWORD *v20; // r0
  _QWORD *v21; // r6
  _QWORD *v22; // r1
  _DWORD *v23; // r0
  unsigned int *v24; // r4
  _DWORD *v25; // r5
  int v26; // r6
  int v27; // r7
  _DWORD *v28; // r4
  unsigned __int8 *v29; // r3
  unsigned int v30; // r1
  unsigned int v31; // r0
  unsigned int v32; // r1
  _DWORD *v33; // r4
  _DWORD *v34; // [sp+8h] [bp-30h]
  int v35; // [sp+Ch] [bp-2Ch]
  int v36; // [sp+Ch] [bp-2Ch]
  _DWORD *v37; // [sp+10h] [bp-28h]
  int v38; // [sp+14h] [bp-24h]
  int v39; // [sp+14h] [bp-24h]
  int vars4; // [sp+3Ch] [bp+4h]

  v1 = *(_DWORD **)(result + 28);
  HIDWORD(v2) = 0;
  v3 = (_DWORD *)result;
  v37 = (_DWORD *)result;
  if ( v1 )
  {
    do
    {
      v4 = v1[5];
      v1 = (_DWORD *)*v1;
      HIDWORD(v2) += v4 >> 12;
    }
    while ( v1 );
    if ( HIDWORD(v2) )
    {
      result = ExAllocatePoolWithTag(512, 4 * HIDWORD(v2));
      v5 = result;
      v38 = result;
      if ( result )
      {
        v6 = (_DWORD *)v3[7];
        v7 = 0;
        while ( v6 )
        {
          v8 = v6[5] >> 12;
          memmove(v5 + 4 * v7, (int)(v6 + 7), 4 * v8);
          v6 = (_DWORD *)*v6;
          v7 += v8;
        }
        qsort(v5, HIDWORD(v2), 4u, (int (__fastcall *)(unsigned int, _BYTE *))MiPartitionMdlPageSort);
        v9 = HIDWORD(v2);
        v10 = v5 + 4 * HIDWORD(v2);
        do
        {
          v11 = *(_DWORD *)(v10 - 4);
          v10 -= 4;
          --v9;
          if ( (v11 & 0x80000000) == 0 )
            break;
          --HIDWORD(v2);
        }
        while ( v9 );
        v34 = 0;
        v35 = 0;
        v12 = 0;
        v13 = HIDWORD(v2) << 12;
        if ( HIDWORD(v2) << 12 )
        {
          while ( 1 )
          {
            v14 = v13 <= 0xFFFFF000 ? v13 : -4096;
            v15 = IoAllocateMdl(0, v14, 0, 0, 0);
            v16 = (_DWORD *)v15;
            if ( !v15 )
              break;
            memmove(v15 + 28, v5 + 4 * v35, 4 * (v14 >> 12));
            v35 += v14 >> 12;
            if ( v12 )
            {
              *v12 = v16;
            }
            else
            {
              v12 = v16;
              v34 = v16;
            }
            v13 -= v14;
            if ( !v13 )
            {
              v3 = v37;
              goto LABEL_21;
            }
          }
          v28 = v34;
          if ( v34 )
          {
            do
            {
              v28 = (_DWORD *)*v28;
              ExFreePoolWithTag(v34);
              v34 = v28;
            }
            while ( v28 );
            v5 = v38;
          }
        }
        else
        {
LABEL_21:
          LODWORD(v2) = 1;
          v17 = 0;
          if ( HIDWORD(v2) )
          {
            v18 = (_DWORD *)v5;
            do
            {
              if ( v17 )
              {
                if ( *v18 != *(v18 - 1) + 1 )
                {
                  LODWORD(v2) = v2 + 1;
                  if ( !(_DWORD)v2 )
                    break;
                }
              }
              ++v17;
              ++v18;
            }
            while ( v17 < HIDWORD(v2) );
          }
          v19 = 0;
          v36 = 0;
          if ( (_DWORD)v2 )
          {
            v20 = (_QWORD *)ExAllocatePoolWithTag(512, 8 * (v2 + 1));
            v21 = v20;
            if ( v20 )
            {
              *v20 = v2;
              LODWORD(v2) = 0;
              if ( HIDWORD(v2) )
              {
                v22 = v20 - 1;
                v23 = (_DWORD *)v5;
                do
                {
                  if ( !(_DWORD)v2 || *v23 != *(v23 - 1) + 1 )
                  {
                    *((_DWORD *)++v22 + 2) = *v23;
                    *((_DWORD *)v22 + 3) = 0;
                  }
                  LODWORD(v2) = v2 + 1;
                  ++v23;
                  ++*((_DWORD *)v22 + 3);
                }
                while ( (unsigned int)v2 < HIDWORD(v2) );
              }
              v19 = MiConvertInitialMemoryBlock(v3, v21);
              if ( v19 )
                v36 = MiCreateNodeLists();
              ExFreePoolWithTag(v21);
            }
          }
          v24 = v3 + 42;
          v39 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3 + 42);
          }
          else
          {
            v29 = (unsigned __int8 *)v3 + 171;
            do
              v30 = __ldrex(v29);
            while ( __strex(v30 | 0x80, v29) );
            __dmb(0xBu);
            if ( v30 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v3 + 42);
            while ( 1 )
            {
              v31 = *v24;
              if ( (*v24 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v31 & 0x40000000) == 0 )
              {
                do
                  v32 = __ldrex(v24);
                while ( v32 == v31 && __strex(v31 | 0x40000000, v24) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
          v25 = (_DWORD *)v3[7];
          v26 = v3[29];
          v3[7] = v34;
          v3[29] = v19;
          v27 = v3[8];
          v3[8] = v36;
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3 + 42, vars4);
          }
          else
          {
            __dmb(0xBu);
            *v24 = 0;
          }
          KfLowerIrql(v39);
          if ( v25 )
          {
            do
            {
              v33 = (_DWORD *)*v25;
              ExFreePoolWithTag(v25);
              v25 = v33;
            }
            while ( v33 );
          }
          if ( v27 )
            MiDereferencePageRuns(v27);
          if ( v26 )
            MiDereferencePageRuns(v26);
        }
        result = ExFreePoolWithTag(v5);
      }
    }
  }
  return result;
}
