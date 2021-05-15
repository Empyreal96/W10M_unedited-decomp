// VerifierKeWaitForMultipleObjects 
 
int __fastcall VerifierKeWaitForMultipleObjects(int a1, int a2, __int64 a3, char a4, unsigned __int8 a5, _QWORD *a6, int a7)
{
  int *v7; // r6
  unsigned int v9; // r5
  unsigned int v10; // r0
  unsigned int v11; // r3
  _QWORD *v12; // r5
  int v13; // r4
  int v14; // r1
  int v15; // r8
  int v16; // r0
  unsigned int v17; // r9
  unsigned int v18; // r10
  unsigned int *v19; // r5
  int v20; // r6
  unsigned int v21; // r4
  unsigned int v22; // t1
  int v23; // r4
  signed int v24; // r2
  int *v25; // r1
  int v26; // r0
  int v28; // [sp+10h] [bp-38h]
  unsigned int v29; // [sp+14h] [bp-34h] BYREF
  unsigned int v30; // [sp+18h] [bp-30h] BYREF
  int *v31; // [sp+1Ch] [bp-2Ch]
  int v32; // [sp+20h] [bp-28h]
  int v33; // [sp+24h] [bp-24h]
  int vars4; // [sp+4Ch] [bp+4h]

  v7 = (int *)a2;
  v31 = (int *)a2;
  v32 = HIDWORD(a3);
  v33 = a3;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v9 + 0x4C) & 4) != 0 )
    v10 = *(unsigned __int8 *)(v9 + 134);
  else
    v10 = KeGetCurrentIrql(a1);
  v11 = *(_DWORD *)(v9 + 80);
  v12 = a6;
  v13 = (v11 >> 5) & 1;
  if ( v10 <= 2 )
  {
    if ( v10 != 2 )
      goto LABEL_12;
    if ( a6 )
    {
      a3 = *a6;
      if ( !*a6 )
        goto LABEL_12;
      v14 = 290;
    }
    else
    {
      v14 = 289;
    }
  }
  else
  {
    v14 = 288;
  }
  VerifierBugCheckIfAppropriate(196, v14, v10, *v7, (int)a6);
LABEL_12:
  v15 = a4;
  HIDWORD(a3) = MmVerifierData;
  if ( (MmVerifierData & 0x800) != 0 && a4 == 1 && (!a6 || (a3 = *a6, (HIDWORD(a3) |= a3) != 0)) && v13 )
  {
    v16 = RtlpGetStackLimits((int)&v30, (int)&v29, a3, SHIDWORD(a3));
    v17 = v29;
    v18 = v30;
    v28 = v16;
  }
  else
  {
    v28 = 0;
    v18 = 0;
    v17 = 0;
  }
  if ( a1 )
  {
    v19 = (unsigned int *)v7;
    v20 = a1;
    do
    {
      v22 = *v19++;
      v21 = v22;
      VfUtilSynchronizationObjectSanityChecks(v22, 1);
      if ( v28 && v21 >= v18 && v21 < v17 )
        VerifierBugCheckIfAppropriate(196, 291, v21, 0, 0);
      --v20;
    }
    while ( v20 );
    v12 = a6;
    v15 = a4;
    v7 = v31;
  }
  if ( ViKeInjectStatusAlerted(a5) )
    v23 = 257;
  else
    v23 = pXdvKeWaitForMultipleObjects(a1, v7, v33, v32, v15, a5, v12, a7);
  v24 = v23 & 0xFFFFFF7F;
  if ( v15 )
  {
    if ( v23 >= 0 && v24 < a1 )
    {
      v25 = &v7[v24];
      v26 = 1;
      goto LABEL_36;
    }
  }
  else if ( !v24 )
  {
    v25 = v7;
    v26 = a1;
LABEL_36:
    ViKeObjectAcquired(v26, v25, v12, vars4);
    return v23;
  }
  return v23;
}
