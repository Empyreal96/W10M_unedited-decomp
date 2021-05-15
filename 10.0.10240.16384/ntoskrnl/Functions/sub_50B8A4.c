// sub_50B8A4 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_50B8A4(int a1, int a2, int a3, unsigned int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  unsigned int *v13; // r4
  unsigned int v14; // r3
  unsigned int v15; // r2
  int v16; // r4
  int v17; // r8
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r1
  int v23; // lr
  int v24; // r0
  unsigned int *v25; // r2
  unsigned int v26; // r1
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int *v29; // r3
  unsigned int v30; // r5
  __int16 v31; // r6
  unsigned int v32; // r7
  int v33; // [sp-1Ch] [bp-1Ch]
  int v34; // [sp-18h] [bp-18h]
  unsigned __int8 v35; // [sp-18h] [bp-18h]
  unsigned __int8 v36; // [sp-17h] [bp-17h]
  unsigned __int8 v37; // [sp-16h] [bp-16h]
  unsigned __int8 v38; // [sp-15h] [bp-15h]
  int v39; // [sp-14h] [bp-14h]
  int v40; // [sp-10h] [bp-10h]
  _BYTE v41[12]; // [sp-Ch] [bp-Ch] BYREF

  if ( (dword_682604 & 0x41) != 0 )
    EtwTracePool(3616, v31, v30, a4, v32);
  if ( (v31 & 0x20) != 0 )
  {
    v16 = ExpSessionPoolTrackTable;
    v22 = ExpSessionPoolTrackTableMask;
    v29 = &ExpSessionPoolTrackTableSize;
  }
  else
  {
    v16 = ExPoolTagTables[*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)];
    v22 = PoolTrackTableMask;
    v29 = &PoolTrackTableSize;
  }
  v24 = *v29;
  v39 = v22;
  v40 = *v29;
  v33 = v16;
  v17 = v22 & ((40543 * (v38 ^ (4 * (v37 ^ (4 * (v36 ^ (4 * v35))))))) >> 2);
  v23 = v17;
  v34 = v17;
  while ( 1 )
  {
    while ( 1 )
    {
      v13 = (unsigned int *)(v16 + 28 * v17);
      if ( *v13 == v30 )
      {
        if ( (v31 & 1) != 0 )
        {
          v25 = v13 + 4;
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 + 1, v25) );
          v27 = v13 + 6;
          do
            v28 = __ldrex(v27);
          while ( __strex(v28 + v32, v27) );
        }
        else
        {
          v18 = v13 + 1;
          do
            v19 = __ldrex(v18);
          while ( __strex(v19 + 1, v18) );
          v20 = v13 + 3;
          do
            v21 = __ldrex(v20);
          while ( __strex(v21 + v32, v20) );
        }
LABEL_20:
        __asm { POP.W           {R4-R11,PC} }
      }
      if ( !*v13 )
        break;
LABEL_13:
      v17 = (v17 + 1) & v22;
      v16 = v33;
      if ( v17 == v23 )
      {
        ExpInsertPoolTrackerExpansion(v30, v32, v31);
        goto LABEL_20;
      }
    }
    if ( (v31 & 0x20) == 0 && (v14 = *(_DWORD *)(PoolTrackTable + 28 * v17)) != 0 )
    {
      *v13 = v14;
      v16 = v33;
    }
    else
    {
      if ( v17 == v24 - 1 )
        goto LABEL_13;
      if ( (v31 & 0x20) != 0 )
      {
        do
          v15 = __ldrex(v13);
        while ( !v15 && __strex(v30, v13) );
        v16 = v33;
      }
      else
      {
        KeAcquireInStackQueuedSpinLock((unsigned int *)&ExpTaggedPoolLock, (unsigned int)v41);
        if ( !*(_DWORD *)(PoolTrackTable + 28 * v17) )
        {
          *(_DWORD *)(PoolTrackTable + 28 * v17) = v30;
          *v13 = v30;
        }
        KeReleaseInStackQueuedSpinLock((int)v41);
        v23 = v34;
        v22 = v39;
        v24 = v40;
        v16 = v33;
      }
    }
  }
}
