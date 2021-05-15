// PiQueryPowerRelations 
 
int __fastcall PiQueryPowerRelations(int *a1, int a2)
{
  int v2; // r5
  int v4; // r0
  int v5; // r1
  unsigned int v6; // r0
  int v7; // r2
  int *v9; // r8
  unsigned int *v10; // r2
  unsigned int v11; // r4
  unsigned int v12; // r3
  _DWORD *v13; // r7
  int v14; // r0
  unsigned int i; // r4
  int *v16; // r2
  _DWORD *v17; // r2
  _DWORD *v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r1
  int v22; // r3
  unsigned int v23; // r1
  int v24; // r3
  int v25; // r5
  int v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r3
  int v30; // r2
  int v31; // r1
  int v32; // r3
  unsigned int v33; // r1
  int v34; // r3
  int v35; // r3
  int v36; // r3
  int v37; // r2
  int v38; // r1
  int v39; // r2
  int v40[8]; // [sp+8h] [bp-20h] BYREF

  v2 = 0;
  v40[0] = 0;
  if ( !a2 )
  {
    v2 = PnpQueryDeviceRelations(a1[4], 2, 0, v40);
    if ( v2 < 0 )
    {
      v40[0] = 0;
      goto LABEL_2;
    }
    v9 = a1 + 25;
    if ( (int *)a1[25] != a1 + 25 )
      return sub_811558();
    v10 = (unsigned int *)v40[0];
    if ( !v40[0] || !*(_DWORD *)v40[0] )
    {
      v2 = 0;
      goto LABEL_2;
    }
    v11 = 0;
    if ( *(_DWORD *)v40[0] )
    {
      do
      {
        v12 = v10[v11 + 1];
        if ( !v12 || (v13 = *(_DWORD **)(*(_DWORD *)(v12 + 176) + 20)) == 0 || (v13[67] & 0x20000) != 0 )
        {
          v19 = v10[v11 + 1];
          if ( v19 )
          {
            IoAddTriageDumpDataBlock(v19, *(unsigned __int16 *)(v19 + 2));
            v10 = (unsigned int *)v40[0];
            v20 = *(_DWORD *)(*(_DWORD *)(v40[0] + 4 * v11 + 4) + 8);
            if ( v20 )
            {
              IoAddTriageDumpDataBlock(v20, *(__int16 *)(v20 + 2));
              v10 = (unsigned int *)v40[0];
              v21 = *(_DWORD *)(*(_DWORD *)(v40[0] + 4 * v11 + 4) + 8);
              if ( *(_WORD *)(v21 + 28) )
              {
                IoAddTriageDumpDataBlock(v21 + 28, 2);
                v22 = *(_DWORD *)(*(_DWORD *)(v40[0] + 4 * v11 + 4) + 8);
                IoAddTriageDumpDataBlock(*(_DWORD *)(v22 + 32), *(unsigned __int16 *)(v22 + 28));
                v10 = (unsigned int *)v40[0];
              }
            }
            v23 = v10[v11 + 1];
            if ( v23 )
              v24 = *(_DWORD *)(*(_DWORD *)(v23 + 176) + 20);
            else
              v24 = 0;
            if ( v24 )
            {
              if ( v23 )
                v25 = *(_DWORD *)(*(_DWORD *)(v23 + 176) + 20);
              else
                v25 = 0;
              if ( v23 )
                v26 = *(_DWORD *)(*(_DWORD *)(v23 + 176) + 20);
              else
                v26 = 0;
              IoAddTriageDumpDataBlock(v26, 460);
              if ( *(_WORD *)(v25 + 20) )
              {
                IoAddTriageDumpDataBlock(v25 + 20, 2);
                IoAddTriageDumpDataBlock(*(_DWORD *)(v25 + 24), *(unsigned __int16 *)(v25 + 20));
              }
              v10 = (unsigned int *)v40[0];
              v27 = *(_DWORD *)(v40[0] + 4 * v11 + 4);
              if ( v27 )
                v28 = *(_DWORD *)(*(_DWORD *)(v27 + 176) + 20);
              else
                v28 = 0;
              if ( *(_WORD *)(v28 + 28) )
              {
                if ( v27 )
                  v29 = *(_DWORD *)(*(_DWORD *)(v27 + 176) + 20);
                else
                  v29 = 0;
                IoAddTriageDumpDataBlock(v29 + 28, 2);
                v30 = *(_DWORD *)(v40[0] + 4 * v11 + 4);
                if ( v30 )
                  v31 = *(_DWORD *)(*(_DWORD *)(v30 + 176) + 20);
                else
                  v31 = 0;
                if ( v30 )
                  v32 = *(_DWORD *)(*(_DWORD *)(v30 + 176) + 20);
                else
                  v32 = 0;
                IoAddTriageDumpDataBlock(*(_DWORD *)(v32 + 32), *(unsigned __int16 *)(v31 + 28));
                v10 = (unsigned int *)v40[0];
              }
              v33 = v10[v11 + 1];
              if ( v33 )
                v34 = *(_DWORD *)(*(_DWORD *)(v33 + 176) + 20);
              else
                v34 = 0;
              if ( *(_DWORD *)(v34 + 8) )
              {
                v35 = v33 ? *(_DWORD *)(*(_DWORD *)(v33 + 176) + 20) : 0;
                if ( *(_WORD *)(*(_DWORD *)(v35 + 8) + 28) )
                {
                  if ( v33 )
                    v36 = *(_DWORD *)(*(_DWORD *)(v33 + 176) + 20);
                  else
                    v36 = 0;
                  IoAddTriageDumpDataBlock(*(_DWORD *)(v36 + 8) + 28, 2);
                  v37 = *(_DWORD *)(v40[0] + 4 * v11 + 4);
                  if ( v37 )
                    v38 = *(_DWORD *)(*(_DWORD *)(v37 + 176) + 20);
                  else
                    v38 = 0;
                  if ( v37 )
                    v39 = *(_DWORD *)(*(_DWORD *)(v37 + 176) + 20);
                  else
                    v39 = 0;
                  IoAddTriageDumpDataBlock(
                    *(_DWORD *)(*(_DWORD *)(v39 + 8) + 32),
                    *(unsigned __int16 *)(*(_DWORD *)(v38 + 8) + 28));
                  v10 = (unsigned int *)v40[0];
                }
              }
            }
          }
          KeBugCheckEx(202, 2, v10[v11 + 1], 0, 0);
        }
        if ( v13[2] )
        {
          v14 = ExAllocatePoolWithTag(512, 28, 1920421956);
          if ( !v14 )
          {
            v2 = -1073741670;
            break;
          }
          *(_DWORD *)(v14 + 20) = v13 + 21;
          *(_BYTE *)(v14 + 24) = 0;
          *(_DWORD *)(v14 + 8) = a1 + 21;
          v16 = (int *)a1[26];
          *(_DWORD *)v14 = v9;
          *(_DWORD *)(v14 + 4) = v16;
          if ( (int *)*v16 != v9 )
            __fastfail(3u);
          *v16 = v14;
          a1[26] = v14;
          v17 = (_DWORD *)(v14 + 12);
          v18 = (_DWORD *)v13[24];
          *v17 = v13 + 23;
          v17[1] = v18;
          if ( (_DWORD *)*v18 != v13 + 23 )
            __fastfail(3u);
          *v18 = v17;
          v13[24] = v17;
          v10 = (unsigned int *)v40[0];
        }
        ++v11;
      }
      while ( v11 < *v10 );
    }
  }
LABEL_2:
  v4 = PiQueryPowerDependencyRelations(a1);
  if ( v4 < 0 && v2 >= 0 )
    v2 = v4;
  PiValidatePowerRelations(a1);
  v6 = v40[0];
  if ( v40[0] )
  {
    for ( i = 0; i < *(_DWORD *)v40[0]; ++i )
    {
      ObfDereferenceObject(*(_DWORD *)(v6 + 4 * i + 4));
      v6 = v40[0];
    }
    ExFreePoolWithTag(v6);
  }
  PpDevNodeLockTree(0, v5);
  v7 = a1[43];
  if ( v7 != 768 && v7 != 769 && v7 != 787 && v7 != 788 )
    PiPnpRtlPdoRaiseNtPlugPlayPropertyChangeEvent(a1[4], 19);
  PpDevNodeUnlockTree(0);
  return v2;
}
