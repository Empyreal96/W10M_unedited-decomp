// VerifierKeWaitForMultipleObjectsNoReboot 
 
int __fastcall VerifierKeWaitForMultipleObjectsNoReboot(int a1, int *a2, __int64 a3, char a4, unsigned __int8 a5, __int64 *a6, int a7)
{
  int *v7; // r6
  int v8; // r10
  unsigned int v9; // r5
  unsigned int v10; // r0
  int v11; // r5
  int v12; // r1
  int v13; // r6
  int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r8
  int v17; // r9
  int v18; // r6
  unsigned int *v19; // r10
  unsigned int v20; // r5
  unsigned int v21; // t1
  int result; // r0
  int v23; // [sp+10h] [bp-38h]
  unsigned int v25; // [sp+18h] [bp-30h] BYREF
  unsigned int v26; // [sp+1Ch] [bp-2Ch] BYREF
  int v27; // [sp+20h] [bp-28h]
  int v28; // [sp+24h] [bp-24h]

  v7 = a2;
  v23 = a1;
  v27 = HIDWORD(a3);
  v28 = a3;
  v8 = a1;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v9 + 0x4C) & 4) != 0 )
    v10 = *(unsigned __int8 *)(v9 + 134);
  else
    v10 = KeGetCurrentIrql(a1);
  v11 = (*(_DWORD *)(v9 + 80) >> 5) & 1;
  if ( v10 <= 2 )
  {
    if ( v10 != 2 )
      goto LABEL_12;
    if ( a6 )
    {
      a3 = *a6;
      if ( !*a6 )
        goto LABEL_12;
      v12 = 290;
    }
    else
    {
      v12 = 289;
    }
  }
  else
  {
    v12 = 288;
  }
  VerifierBugCheckIfAppropriate(196, v12, v10, *v7, (int)a6);
LABEL_12:
  v13 = a4;
  HIDWORD(a3) = MmVerifierData;
  if ( (MmVerifierData & 0x800) != 0 && a4 == 1 && (!a6 || (a3 = *a6, (HIDWORD(a3) |= a3) != 0)) && v11 )
  {
    v14 = RtlpGetStackLimits((int)&v26, (int)&v25, a3, SHIDWORD(a3));
    v15 = v25;
    v16 = v26;
    v17 = v14;
  }
  else
  {
    v17 = 0;
    v16 = 0;
    v15 = 0;
  }
  if ( v8 )
  {
    v18 = v23;
    v19 = (unsigned int *)a2;
    do
    {
      v21 = *v19++;
      v20 = v21;
      VfUtilSynchronizationObjectSanityChecks(v21, 1);
      if ( v17 && v20 >= v16 && v20 < v15 )
        VerifierBugCheckIfAppropriate(196, 291, v20, 0, 0);
      --v18;
    }
    while ( v18 );
    v13 = a4;
    v8 = v23;
  }
  if ( ViKeInjectStatusAlerted(a5) )
    result = 257;
  else
    result = pXdvKeWaitForMultipleObjects(v8, a2, v28, v27, v13, a5, a6, a7);
  return result;
}
