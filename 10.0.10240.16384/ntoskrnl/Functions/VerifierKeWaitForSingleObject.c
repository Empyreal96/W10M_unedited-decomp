// VerifierKeWaitForSingleObject 
 
int __fastcall VerifierKeWaitForSingleObject(unsigned int a1, int a2, __int64 a3, __int64 *a4)
{
  int v4; // r9
  int v5; // r10
  unsigned int v7; // r5
  unsigned int v8; // r0
  int v9; // r4
  int v10; // r1
  int v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r6
  int v14; // r7
  int v15; // r4
  unsigned int v17; // [sp+8h] [bp-28h] BYREF
  unsigned int v18; // [sp+Ch] [bp-24h] BYREF
  int v19; // [sp+10h] [bp-20h]
  int vars4; // [sp+34h] [bp+4h]
  int varg_r0[2]; // [sp+38h] [bp+8h] BYREF
  __int64 varg_r2; // [sp+40h] [bp+10h]

  varg_r0[1] = a2;
  varg_r2 = a3;
  LODWORD(a3) = (char)a3;
  v4 = (char)a3;
  v5 = HIDWORD(a3);
  v19 = a2;
  varg_r0[0] = a1;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v7 + 0x4C) & 4) != 0 )
    v8 = *(unsigned __int8 *)(v7 + 134);
  else
    v8 = KeGetCurrentIrql(a1);
  v9 = (*(_DWORD *)(v7 + 80) >> 5) & 1;
  if ( v8 <= 2 )
  {
    if ( v8 != 2 )
      goto LABEL_12;
    if ( a4 )
    {
      a3 = *a4;
      if ( !*a4 )
        goto LABEL_12;
      v10 = 290;
    }
    else
    {
      v10 = 289;
    }
  }
  else
  {
    v10 = 288;
  }
  VerifierBugCheckIfAppropriate(196, v10, v8, a1, (int)a4);
LABEL_12:
  HIDWORD(a3) = MmVerifierData;
  if ( (MmVerifierData & 0x800) != 0 && v4 == 1 && (!a4 || (a3 = *a4, (HIDWORD(a3) |= a3) != 0)) && v9 )
  {
    v11 = RtlpGetStackLimits((int)&v18, (int)&v17, a3, SHIDWORD(a3));
    v12 = v17;
    v13 = v18;
    v14 = v11;
  }
  else
  {
    v14 = 0;
    v13 = 0;
    v12 = 0;
  }
  VfUtilSynchronizationObjectSanityChecks(a1, 1);
  if ( v14 && a1 >= v13 && a1 < v12 )
    VerifierBugCheckIfAppropriate(196, 291, a1, 0, 0);
  if ( ViKeInjectStatusAlerted(v5) )
    v15 = 257;
  else
    v15 = pXdvKeWaitForSingleObject(a1, v19, v4, v5, a4);
  if ( (v15 & 0xFFFFFF7F) == 0 )
    ViKeObjectAcquired(1, varg_r0, a4, vars4);
  return v15;
}
