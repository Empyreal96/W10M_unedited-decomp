// IoSteerInterrupt 
 
int __fastcall IoSteerInterrupt(_DWORD *a1, int a2)
{
  int v2; // r5
  int v5; // r0
  int v6; // r0
  int v7; // r1
  int v8; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r0
  int v13; // r2
  int v14; // r1
  int v16; // r0
  int v17; // r2
  int v18; // r2
  int v19; // r3
  int v20; // r5
  int v21; // r0
  int v22; // r2
  int v23; // r3
  int v24; // r3
  int v25; // r2
  int v26; // r1
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r3
  int v31; // r3
  int v32; // r2
  int v33; // r1
  int v34; // r2

  v2 = -1073741823;
  v5 = KeGetCurrentIrql(a1);
  if ( v5 )
  {
    v6 = KeGetCurrentIrql(v5);
    KeBugCheckEx(289, 1, v6, 0, 0);
  }
  if ( !a1 || !a2 )
    __fastfail(5u);
  if ( !*a1 )
  {
    v7 = *(_DWORD *)a2;
    if ( *(int *)a2 < 2 && (v7 != 1 || *(_DWORD *)(a2 + 8)) )
    {
      v8 = a1[2];
      if ( v8 )
      {
        v9 = *(_DWORD *)(*(_DWORD *)(v8 + 176) + 20);
        if ( v9 && (*(_DWORD *)(v9 + 268) & 0x20000) == 0 )
        {
          v10 = a1[1];
          if ( v10 != 1 )
          {
            if ( v10 == 2 )
            {
              v11 = *(_DWORD *)(a1[3] + 184) + 88;
              goto LABEL_21;
            }
            if ( v10 == 3 )
            {
              v11 = *(_DWORD *)(a1[3] + 20);
              goto LABEL_21;
            }
            if ( v10 != 4 )
              return -1073741637;
          }
          v11 = a1[3];
LABEL_21:
          v12 = *(_DWORD *)(v11 + 228);
          if ( *(_DWORD *)(v12 + 44) != *(_DWORD *)(v11 + 44) )
            __fastfail(5u);
          if ( v7 == 1 )
          {
            v13 = *(_DWORD *)(a2 + 8);
            v14 = *(unsigned __int16 *)(a2 + 4);
          }
          else
          {
            if ( v7 )
              return v2;
            v13 = 0;
            v14 = 0;
          }
          return KeIntSteerAssignCpuSet(v12, v14, v13);
        }
        IoAddTriageDumpDataBlock(v8, *(unsigned __int16 *)(v8 + 2));
        v16 = *(_DWORD *)(a1[2] + 8);
        if ( v16 )
        {
          IoAddTriageDumpDataBlock(v16, *(__int16 *)(v16 + 2));
          v17 = *(_DWORD *)(a1[2] + 8);
          if ( *(_WORD *)(v17 + 28) )
          {
            IoAddTriageDumpDataBlock(v17 + 28, 2);
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(a1[2] + 8) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(a1[2] + 8) + 28));
          }
        }
        v18 = a1[2];
        if ( v18 )
          v19 = *(_DWORD *)(*(_DWORD *)(v18 + 176) + 20);
        else
          v19 = 0;
        if ( v19 )
        {
          if ( v18 )
            v20 = *(_DWORD *)(*(_DWORD *)(v18 + 176) + 20);
          else
            v20 = 0;
          if ( v18 )
            v21 = *(_DWORD *)(*(_DWORD *)(v18 + 176) + 20);
          else
            v21 = 0;
          IoAddTriageDumpDataBlock(v21, 460);
          if ( *(_WORD *)(v20 + 20) )
          {
            IoAddTriageDumpDataBlock(v20 + 20, 2);
            IoAddTriageDumpDataBlock(*(_DWORD *)(v20 + 24), *(unsigned __int16 *)(v20 + 20));
          }
          v22 = a1[2];
          if ( v22 )
            v23 = *(_DWORD *)(*(_DWORD *)(v22 + 176) + 20);
          else
            v23 = 0;
          if ( *(_WORD *)(v23 + 28) )
          {
            if ( v22 )
              v24 = *(_DWORD *)(*(_DWORD *)(v22 + 176) + 20);
            else
              v24 = 0;
            IoAddTriageDumpDataBlock(v24 + 28, 2);
            v25 = a1[2];
            if ( v25 )
              v26 = *(_DWORD *)(*(_DWORD *)(v25 + 176) + 20);
            else
              v26 = 0;
            if ( v25 )
              v27 = *(_DWORD *)(*(_DWORD *)(v25 + 176) + 20);
            else
              v27 = 0;
            IoAddTriageDumpDataBlock(*(_DWORD *)(v27 + 32), *(unsigned __int16 *)(v26 + 28));
          }
          v28 = a1[2];
          if ( v28 )
            v29 = *(_DWORD *)(*(_DWORD *)(v28 + 176) + 20);
          else
            v29 = 0;
          if ( *(_DWORD *)(v29 + 8) )
          {
            v30 = v28 ? *(_DWORD *)(*(_DWORD *)(v28 + 176) + 20) : 0;
            if ( *(_WORD *)(*(_DWORD *)(v30 + 8) + 28) )
            {
              if ( v28 )
                v31 = *(_DWORD *)(*(_DWORD *)(v28 + 176) + 20);
              else
                v31 = 0;
              IoAddTriageDumpDataBlock(*(_DWORD *)(v31 + 8) + 28, 2);
              v32 = a1[2];
              if ( v32 )
                v33 = *(_DWORD *)(*(_DWORD *)(v32 + 176) + 20);
              else
                v33 = 0;
              if ( v32 )
                v34 = *(_DWORD *)(*(_DWORD *)(v32 + 176) + 20);
              else
                v34 = 0;
              IoAddTriageDumpDataBlock(
                *(_DWORD *)(*(_DWORD *)(v34 + 8) + 32),
                *(unsigned __int16 *)(*(_DWORD *)(v33 + 8) + 28));
            }
          }
        }
      }
      KeBugCheckEx(202, 2, a1[2], 0, 0);
    }
  }
  return -1073741811;
}
