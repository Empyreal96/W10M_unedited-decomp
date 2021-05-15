// VerifierKeWaitForSingleObjectNoReboot 
 
int __fastcall VerifierKeWaitForSingleObjectNoReboot(unsigned int a1, int a2, __int64 a3, __int64 *a4)
{
  int v4; // r9
  int v5; // r10
  unsigned int v7; // r5
  unsigned int v8; // r0
  int v9; // r5
  int v10; // r1
  int v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r6
  int v14; // r7
  int result; // r0
  unsigned int v16; // [sp+8h] [bp-28h] BYREF
  unsigned int v17; // [sp+Ch] [bp-24h] BYREF
  int v18; // [sp+10h] [bp-20h]

  LODWORD(a3) = (char)a3;
  v4 = (char)a3;
  v5 = HIDWORD(a3);
  v18 = a2;
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
    v11 = RtlpGetStackLimits((int)&v17, (int)&v16, a3, SHIDWORD(a3));
    v12 = v16;
    v13 = v17;
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
    result = 257;
  else
    result = pXdvKeWaitForSingleObject(a1, v18, v4, v5, a4);
  return result;
}
