// IopLiveDumpAllocAndInitResources 
 
int __fastcall IopLiveDumpAllocAndInitResources(int a1)
{
  unsigned int v2; // r6
  int v3; // r0
  __int64 v4; // kr00_8
  unsigned int v5; // r1
  unsigned int v6; // r8
  int v7; // r9
  int v8; // r5
  _DWORD *v9; // r0
  int v10; // r1
  int v11; // r2
  unsigned int v12; // r3
  _DWORD *v13; // r0
  int v14; // r3
  int v15; // r5
  int v16; // r0
  __int64 v17; // kr08_8
  int v18; // r7
  _BYTE *v19; // r0
  __int64 v20; // kr10_8
  _DWORD *v21; // r2
  int v22; // r3
  int v23; // r0
  __int64 v24; // kr18_8
  int v25; // r0
  __int64 v26; // kr20_8
  _DWORD *i; // r5
  __int64 v28; // kr28_8
  __int64 v29; // r0
  int v30; // r1
  _DWORD v32[2]; // [sp+8h] [bp-58h] BYREF
  _DWORD v33[20]; // [sp+10h] [bp-50h] BYREF

  v2 = 0;
  v3 = KeQueryInterruptTime();
  v4 = *(_QWORD *)(a1 + 324);
  v6 = v5;
  v7 = v3;
  if ( (_DWORD)v4 && *(_DWORD *)(v4 + 4) || HIDWORD(v4) && *(_DWORD *)(HIDWORD(v4) + 4) )
    goto LABEL_5;
  *(_DWORD *)(a1 + 140) = a1;
  v9 = IopLiveDumpResetCorralContext((_DWORD *)(a1 + 140));
  v13 = (_DWORD *)IopGetPhysicalMemoryBlock((int)v9, v10, v11, v12);
  v2 = (unsigned int)v13;
  if ( !v13 )
    goto LABEL_7;
  if ( !*v13 )
  {
    v8 = -1073741595;
    goto LABEL_41;
  }
  v14 = v13[2 * *v13] + v13[2 * *v13 + 1];
  *(_DWORD *)(a1 + 52) = v14;
  v15 = (((unsigned int)(v14 + 7) >> 3) + 4095) & 0xFFFFF000;
  v16 = ExAllocatePoolWithTag(512, v15, 1886217292);
  *(_DWORD *)(a1 + 244) = v16;
  if ( !v16 )
    goto LABEL_7;
  v17 = *(_QWORD *)(a1 + 324);
  if ( (_DWORD)v17 && *(_DWORD *)(v17 + 4) || HIDWORD(v17) && *(_DWORD *)(HIDWORD(v17) + 4) )
    goto LABEL_5;
  *(_DWORD *)(a1 + 236) = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(a1 + 240) = v16;
  RtlSetAllBits((_DWORD *)(a1 + 236));
  IopLiveDumpDiscardVirtualAddressRange(a1, *(_DWORD *)(a1 + 244), v15);
  v18 = (v15 + 8295) & 0xFFFFF000;
  v19 = (_BYTE *)ExAllocatePoolWithTag(512, v18, 1886217292);
  *(_DWORD *)(a1 + 228) = v19;
  if ( !v19 )
    goto LABEL_7;
  v20 = *(_QWORD *)(a1 + 324);
  if ( (_DWORD)v20 && *(_DWORD *)(v20 + 4) || HIDWORD(v20) && *(_DWORD *)(HIDWORD(v20) + 4) )
    goto LABEL_5;
  *(_DWORD *)(a1 + 232) = v18;
  memset(v19, 0, (v15 + 8295) & 0xFFFFF000);
  v21 = (_DWORD *)(*(_DWORD *)(a1 + 228) + 4096);
  v21[8] = v18;
  v21[9] = 0;
  v22 = *(_DWORD *)(a1 + 52);
  v21[12] = v22;
  v21[13] = 0;
  *(_DWORD *)(a1 + 220) = v22;
  *(_DWORD *)(a1 + 224) = v21 + 14;
  RtlClearAllBits(a1 + 220);
  IopLiveDumpDiscardVirtualAddressRange(a1, *(_DWORD *)(a1 + 228), *(_DWORD *)(a1 + 232));
  v23 = ExAllocatePoolWithTag(512, v15, 1886217292);
  *(_DWORD *)(a1 + 256) = v23;
  if ( !v23 )
    goto LABEL_7;
  v24 = *(_QWORD *)(a1 + 324);
  if ( (_DWORD)v24 && *(_DWORD *)(v24 + 4) || HIDWORD(v24) && *(_DWORD *)(HIDWORD(v24) + 4) )
    goto LABEL_5;
  *(_DWORD *)(a1 + 248) = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(a1 + 252) = v23;
  RtlClearAllBits(a1 + 248);
  IopLiveDumpDiscardVirtualAddressRange(a1, *(_DWORD *)(a1 + 256), v15);
  v25 = ExAllocatePoolWithTag(512, v15, 1886217292);
  *(_DWORD *)(a1 + 268) = v25;
  if ( !v25 )
  {
LABEL_7:
    v8 = -1073741670;
    goto LABEL_41;
  }
  v26 = *(_QWORD *)(a1 + 324);
  if ( (_DWORD)v26 && *(_DWORD *)(v26 + 4) || HIDWORD(v26) && *(_DWORD *)(HIDWORD(v26) + 4) )
    goto LABEL_5;
  *(_DWORD *)(a1 + 260) = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(a1 + 264) = v25;
  RtlClearAllBits(a1 + 260);
  IopLiveDumpDiscardVirtualAddressRange(a1, *(_DWORD *)(a1 + 268), v15);
  for ( i = *(_DWORD **)(a1 + 36); i; i = (_DWORD *)i[7] )
    IopLiveDumpDiscardVirtualAddressRange(a1, i[4], i[5]);
  v8 = IopLiveDumpAllocateMappingResources(a1);
  if ( v8 < 0 )
    goto LABEL_41;
  if ( (v28 = *(_QWORD *)(a1 + 324), (_DWORD)v28) && *(_DWORD *)(v28 + 4)
    || HIDWORD(v28) && *(_DWORD *)(HIDWORD(v28) + 4) )
  {
LABEL_5:
    v8 = -1073741248;
    goto LABEL_41;
  }
  v8 = IopLiveDumpEstimateMemoryPages((_DWORD *)a1);
  if ( v8 >= 0 )
  {
    v8 = IopLiveDumpAllocateDumpBuffers(a1);
    if ( v8 >= 0 )
      IopLiveDumpTraceBufferAllocation();
  }
LABEL_41:
  if ( (unsigned int)dword_617540 > 5 && TlgKeywordOn((int)&dword_617540, 0x400000000000i64) )
  {
    LODWORD(v29) = KeQueryInterruptTime();
    v32[0] = _rt_udiv64(10000i64, v29 - __PAIR64__(v6, v7));
    v32[1] = v30;
    v33[8] = v32;
    v33[9] = 0;
    v33[10] = 8;
    v33[11] = 0;
    TlgWrite(&dword_617540, (unsigned __int8 *)&word_4138FE + 1, a1 + 348, a1 + 332, 3, v33);
  }
  if ( v2 )
    ExFreePoolWithTag(v2);
  if ( v8 < 0 )
    IopLiveDumpReleaseResources(a1);
  return v8;
}
