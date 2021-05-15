// sub_8125D8 
 
void __fastcall sub_8125D8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
  int v15; // r4
  int *v16; // r5
  int v17; // r6
  _DWORD *v19; // r0
  int *v20; // r9
  unsigned int v21; // r6
  unsigned int v22; // r5
  int *v23; // r1
  unsigned int v24; // r2
  int v25; // t1
  unsigned int v26; // r3
  int v27; // r7
  int v28; // r0
  unsigned int v29; // r5
  int *v30; // r8
  unsigned int v31; // r10
  int v32; // r0
  _DWORD *v33; // r1
  int *v34; // lr
  _DWORD *v35; // r2
  int v36; // r2
  int v37; // r3
  int v38; // t1
  int v39; // r0
  int v40; // [sp+10h] [bp+10h]

  v19 = *(_DWORD **)(v15 + 32);
  a13 = 0;
  a14 = 0;
  a15 = 0;
  PopPepGetDeviceVetoMasks(v19, &a13);
  PopDiagTraceFxDeviceRegistration(
    v17,
    *(_DWORD *)(v15 + 28),
    *(_DWORD *)(v15 + 36),
    *(_DWORD *)(*(_DWORD *)(v15 + 28) + 80));
  if ( a11 )
    v20 = POP_ETW_EVENT_COMPONENT_REGISTRATION_RUNDOWN;
  else
    v20 = POP_ETW_EVENT_COMPONENT_REGISTRATION;
  if ( EtwEventEnabled(*v16, v16[1], (int)v20) )
  {
    v21 = *(_DWORD *)(v15 + 388);
    if ( v21 )
    {
      v22 = *(_DWORD *)(**(_DWORD **)(v15 + 392) + 108);
      if ( v21 > 1 )
      {
        v23 = (int *)(*(_DWORD *)(v15 + 392) + 4);
        v24 = v21 - 1;
        do
        {
          v25 = *v23++;
          v26 = *(_DWORD *)(v25 + 108);
          if ( v26 > v22 )
            v22 = v26;
          --v24;
        }
        while ( v24 );
      }
      v27 = ExAllocatePoolWithTag(1, 28 * v22, 1297630800);
      if ( v27 )
      {
        v28 = 3 * v22;
        v29 = 0;
        v40 = v28;
        do
        {
          v30 = *(int **)(*(_DWORD *)(v15 + 392) + 4 * v29);
          memset((_BYTE *)(v27 + 8 * v28), 0, 4 * v30[27]);
          PopPepGetComponentVetoMasks(*(_DWORD *)(v15 + 32), v29, (_DWORD *)(v27 + 8 * v40));
          if ( v30[27] )
          {
            v31 = 0;
            v32 = 0;
            v33 = (_DWORD *)v27;
            v34 = (int *)(v27 + 8 * v40);
            do
            {
              ++v31;
              v35 = (_DWORD *)(v32 + v30[28]);
              *v33 = *v35;
              v33[1] = v35[1];
              v36 = v32 + v30[28];
              v33[2] = *(_DWORD *)(v36 + 8);
              v33[3] = *(_DWORD *)(v36 + 12);
              v37 = *(_DWORD *)(v30[28] + v32 + 16);
              v32 += 24;
              v33[4] = v37;
              v38 = *v34++;
              v33[5] = v38;
              v33 += 6;
            }
            while ( v31 < v30[27] );
          }
          PopDiagTraceFxComponentRegistration(v20, *(_DWORD *)(v15 + 28), v29, v30[13] < 0);
          v39 = v30[46];
          if ( v39 )
            PopFxTracePerfRegistration(v39, a11);
          ++v29;
          v28 = v40;
        }
        while ( v29 < v21 );
        ExFreePoolWithTag(v27);
      }
    }
  }
  JUMPOUT(0x7A3284);
}
