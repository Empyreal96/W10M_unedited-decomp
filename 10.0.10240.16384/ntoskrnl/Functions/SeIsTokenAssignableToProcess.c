// SeIsTokenAssignableToProcess 
 
int __fastcall SeIsTokenAssignableToProcess(int a1, bool *a2)
{
  int v2; // r4
  int v3; // r5
  int v6; // r0
  unsigned int v7; // r6
  int result; // r0
  unsigned int v9; // r2
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned int v13; // r2
  __int64 v14; // kr00_8
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  bool v18; // r3
  char v19; // [sp+0h] [bp-30h] BYREF
  unsigned __int8 v20; // [sp+1h] [bp-2Fh] BYREF
  char v21[6]; // [sp+2h] [bp-2Eh] BYREF
  unsigned __int16 *v22; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 *v23; // [sp+10h] [bp-20h] BYREF

  v2 = 0;
  v3 = 0;
  v20 = 0;
  v21[0] = 0;
  v19 = 0;
  *a2 = 0;
  v6 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v7 = v6;
  if ( !v6 )
    return sub_7E8C34();
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(v6 + 48), 1);
  SepCopyTokenIntegrity(v7, &v23);
  v10 = ExReleaseResourceLite(*(_DWORD *)(v7 + 48));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  ObFastDereferenceObject((_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244), v7);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 48), 1);
  SepCopyTokenIntegrity(a1, &v22);
  v14 = *(_QWORD *)(a1 + 168);
  v15 = ExReleaseResourceLite(*(_DWORD *)(a1 + 48));
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  if ( (_DWORD)v14 == 2 && SHIDWORD(v14) < 2 )
    return -1073741659;
  result = RtlSidDominates(v23, v22, &v19);
  if ( result >= 0 )
  {
    if ( v19 )
    {
      result = SepIsChildTokenByPointer(a1, &v20);
      v2 = v20;
      if ( !v20 )
      {
        if ( result < 0 )
          return result;
        result = SepIsSiblingTokenByPointer(a1, v21);
        v3 = (unsigned __int8)v21[0];
      }
    }
    if ( result >= 0 )
    {
      v18 = v3 || v2;
      *a2 = v18;
    }
  }
  return result;
}
