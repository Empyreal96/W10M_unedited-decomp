// sub_96A7B8 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_96A7B8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  unsigned int *v12; // r5
  int v13; // r7
  int v14; // r8
  int v15; // r9
  unsigned int v16; // r4
  __int64 v17; // r2
  _DWORD *v18; // r6
  unsigned int v19; // r1
  int v20; // r2
  int v21; // [sp-80h] [bp-80h] BYREF
  int v22; // [sp-7Ch] [bp-7Ch] BYREF
  int v23; // [sp-78h] [bp-78h] BYREF
  _DWORD v24[10]; // [sp-58h] [bp-58h] BYREF
  _DWORD v25[12]; // [sp-30h] [bp-30h] BYREF

  while ( 1 )
  {
    v16 = *v12;
    if ( (unsigned int *)*v12 == v12 )
      break;
    v17 = *(_QWORD *)v16;
    if ( *(unsigned int **)(v16 + 4) != v12 || *(_DWORD *)(v17 + 4) != v16 )
      __fastfail(3u);
    *v12 = v17;
    *(_DWORD *)(v17 + 4) = v12;
    v18 = *(_DWORD **)(v14 + 8736);
    if ( *v18 > 5u )
    {
      if ( TlgKeywordOn(*(_DWORD *)(v14 + 8736), 0x400000000000i64) )
      {
        v19 = *(_DWORD *)(v16 + 8);
        v22 = *(_DWORD *)(v16 + 20);
        v21 = *(_DWORD *)(v16 + 24);
        TlgCreateSz((int)v24, v19);
        v24[4] = v25;
        v24[5] = 0;
        v24[6] = 2;
        v24[7] = 0;
        v24[8] = *(_DWORD *)(v16 + 16);
        v24[9] = 0;
        v25[0] = *(unsigned __int16 *)(v16 + 12);
        v25[1] = 0;
        v25[2] = &v22;
        v25[3] = 0;
        v25[4] = 4;
        v25[5] = 0;
        v25[6] = &v21;
        v25[7] = 0;
        v25[8] = 4;
        v25[9] = 0;
        MmTlgWrite(v18, (unsigned __int8 *)(v15 + 1), v20, 7, 7, &v23);
      }
    }
    ExFreePoolWithTag(v16);
  }
  MmReleaseLoadLock(v13);
  __asm { POP.W           {R4-R9,R11,PC} }
}
