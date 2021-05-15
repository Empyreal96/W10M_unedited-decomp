// sub_7CD094 
 
void __fastcall sub_7CD094(int a1, int a2, int a3, int a4, int a5, int *a6, unsigned int a7, int a8, unsigned int *a9)
{
  int v9; // r4
  unsigned int *v10; // r8
  int v11; // r10
  int v12; // r4
  int v13; // r9
  unsigned int v14; // r5
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r7
  int v18; // r8
  int v19; // r4
  unsigned int v20; // r1
  unsigned int v21; // r1
  _WORD *v22; // r3
  int *v23; // r3
  _DWORD *v24; // r7

  v11 = KsepPoolAllocatePaged(2048);
  if ( v11 )
  {
    v12 = KsepRegistryQueryDriverShims(*(_DWORD *)(v9 + 4), v11);
    if ( v12 >= 0 )
    {
      v12 = KsepStringSplitMultiString(v11, a8, &a5, &a7);
      v13 = a5;
      v14 = a7;
      if ( v12 >= 0 )
      {
        v15 = KsepPoolAllocatePaged(52 * a7);
        v16 = v15;
        if ( v15 )
        {
          v17 = 0;
          if ( v14 )
          {
            v18 = v13;
            v19 = v15;
            do
            {
              if ( KsepStringDuplicate(v19 + 16, *(unsigned __int16 **)(v18 + 4)) < 0 )
                break;
              *(_DWORD *)(v19 + 44) = 0;
              ++v17;
              v19 += 52;
              v18 += 8;
            }
            while ( v17 < v14 );
            v13 = a5;
            v10 = a9;
          }
          v12 = KsepDbGetShimInfo(v16, v14);
          if ( v12 >= 0 )
          {
            v23 = a6;
            *v10 = v14;
            v12 = 0;
            *v23 = v16;
          }
          else
          {
            __dmb(0xBu);
            do
            {
              v20 = __ldrex(&KsepHistoryErrorsIndex);
              v21 = v20 + 1;
            }
            while ( __strex(v21, &KsepHistoryErrorsIndex) );
            __dmb(0xBu);
            v22 = &KsepHistoryErrors[4 * (v21 & 0x3F)];
            *((_DWORD *)v22 + 1) = v12;
            v22[1] = 2;
            *v22 = 1040;
            if ( (KsepDebugFlag & 2) != 0 )
              KsepDebugPrint(0, (int)"KSE: Cannot resolve registry shims to Sdb: 0x%x\n");
            KsepLogError(0, (int)"KSE: Cannot resolve registry shims to Sdb: 0x%x\n", v12);
          }
        }
        else
        {
          v12 = -1073741801;
        }
      }
      if ( v13 )
      {
        if ( v14 )
        {
          v24 = (_DWORD *)v13;
          do
          {
            KsepStringFree(v24);
            v24 += 2;
            --v14;
          }
          while ( v14 );
        }
        KsepPoolFreePaged(v13);
      }
    }
    KsepPoolFreePaged(v11);
    if ( v12 >= 0 )
      JUMPOUT(0x770F1C);
  }
  JUMPOUT(0x770F0E);
}
