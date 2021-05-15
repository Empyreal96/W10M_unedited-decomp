// WmipOpenBlock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall WmipOpenBlock(int a1, char a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r10
  int v7; // r4
  _DWORD *v8; // r6
  int *v9; // r7
  int **v11; // r0
  int *v12; // r2
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int *v17; // r2 OVERLAPPED
  int v18; // r1 OVERLAPPED
  int **v19; // r0
  int *v20; // r2
  int v21[8]; // [sp+8h] [bp-20h] BYREF

  v6 = a2;
  v21[0] = 0;
  if ( a1 == 2244928 || a1 == 2244924 )
  {
    v7 = WmipOpenGuidObject(a3, a2, a4, v21);
    if ( v7 < 0 )
      return v7;
    v8 = (_DWORD *)v21[0];
    *(_DWORD *)(v21[0] + 44) = a1;
    if ( a1 == 2244872 )
    {
      v8[26] |= 1u;
    }
    else
    {
      v9 = WmipFindGEByGuid((unsigned int)(v8 + 4), 0);
      KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
      if ( v9 )
      {
        v11 = (int **)v9[7];
        v12 = v8 + 8;
        v8[8] = v9 + 6;
        v8[9] = v11;
        if ( *v11 != v9 + 6 )
          __fastfail(3u);
        *v11 = v12;
        v9[7] = (int)v12;
      }
      v8[10] = v9;
      KeReleaseMutex((int)&WmipSMMutex);
      if ( a1 == 2244924 )
      {
        if ( !v9 || !v9[5] || !WmipIsQuerySetGuid(v9) )
        {
          v7 = -1073741163;
          goto LABEL_12;
        }
LABEL_7:
        if ( !v6 )
          v8[26] |= 2u;
        if ( v9 )
        {
LABEL_10:
          v7 = WmipEnableCollectOrEvent(v9, a1, v8 + 25);
          if ( v7 < 0 )
            goto LABEL_12;
          goto LABEL_11;
        }
        KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
        v13 = WmipAllocGuidEntry();
        v9 = (int *)v13;
        if ( v13 )
        {
          v14 = v8[5];
          v15 = v8[6];
          v16 = v8[7];
          *(_DWORD *)(v13 + 40) = v8[4];
          *(_DWORD *)(v13 + 44) = v14;
          *(_DWORD *)(v13 + 48) = v15;
          *(_DWORD *)(v13 + 52) = v16;
          v17 = (int *)WmipGEHeadPtr;
          v18 = *(_DWORD *)WmipGEHeadPtr;
          *(_QWORD *)v13 = *(_QWORD *)&v18;
          if ( *(int **)(v18 + 4) != v17 )
            __fastfail(3u);
          *(_DWORD *)(v18 + 4) = v13;
          *v17 = v13;
          v19 = *(int ***)(v13 + 28);
          v20 = v8 + 8;
          v8[8] = v9 + 6;
          v8[9] = v19;
          if ( *v19 != v9 + 6 )
            __fastfail(3u);
          *v19 = v20;
          v9[7] = (int)v20;
          v8[10] = v9;
          KeReleaseMutex((int)&WmipSMMutex);
          goto LABEL_10;
        }
        KeReleaseMutex((int)&WmipSMMutex);
        v7 = -1073741670;
LABEL_12:
        if ( v8 )
          ObfDereferenceObject((int)v8);
        return v7;
      }
      if ( a1 == 2244928 )
        goto LABEL_7;
    }
LABEL_11:
    *a5 = v8;
    v8 = 0;
    v7 = 0;
    goto LABEL_12;
  }
  return sub_815964();
}
