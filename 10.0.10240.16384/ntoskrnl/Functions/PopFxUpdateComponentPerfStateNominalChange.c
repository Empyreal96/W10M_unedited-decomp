// PopFxUpdateComponentPerfStateNominalChange 
 
int __fastcall PopFxUpdateComponentPerfStateNominalChange(int result, int a2, int a3, int a4)
{
  int v4; // r6
  unsigned int v5; // r5
  int v6; // r9
  int v8; // r7
  int v9; // r8
  unsigned int *v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r3
  __int64 v13; // r0
  int v14; // r2
  char v15[4]; // [sp+8h] [bp-30h] BYREF
  int v16; // [sp+Ch] [bp-2Ch]
  _DWORD v17[10]; // [sp+10h] [bp-28h] BYREF

  v4 = 0;
  v5 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)(result + 392) + 4 * a2);
  v16 = a3;
  v8 = *(_DWORD *)(v6 + 184);
  v9 = result;
  v10 = *(unsigned int **)(v8 + 28);
  if ( *(_DWORD *)(v8 + 84) )
  {
    do
    {
      result = PopFxQueryCurrentComponentPerfState(v9, v6, v5, 1, v17, v15);
      if ( v15[0] )
      {
        v12 = v17[0];
        v11 = v17[1];
        *v10 = v5;
        ++v4;
        v10[2] = v12;
        v10[3] = v11;
        v10 += 4;
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)(v8 + 84) );
    if ( v4 )
    {
      *(_DWORD *)(v8 + 32) = v4;
      LODWORD(v13) = KeQueryInterruptTime();
      v14 = *(_DWORD *)(v8 + 28);
      *(_QWORD *)(v8 + 40) = v13;
      HIDWORD(v13) = v16;
      *(_BYTE *)(v8 + 48) = 1;
      result = PopDiagTraceFxPerfNominalChange(v8, HIDWORD(v13), a4, v4, v14);
    }
  }
  return result;
}
