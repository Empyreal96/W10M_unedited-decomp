// FsRtlAllocateExtraCreateParameterFromLookasideList 
 
int __fastcall FsRtlAllocateExtraCreateParameterFromLookasideList(_DWORD *a1, int a2, char a3, int a4, int a5, _DWORD *a6)
{
  int v6; // r8
  unsigned int v9; // r7
  _DWORD *v10; // r6
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int result; // r0
  int v15; // r0
  __int64 v16; // kr08_8
  int v17; // r0

  v6 = 2;
  v9 = a2 + 52;
  if ( (a3 & 2) != 0 )
    v6 = 66;
  if ( v9 > *(_DWORD *)(a5 + 36) )
    return FsRtlAllocateExtraCreateParameter(a1);
  if ( (a3 & 2) != 0 )
  {
    v15 = ExAllocateFromNPagedLookasideList(a5);
  }
  else
  {
    ++*(_DWORD *)(a5 + 12);
    v10 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)a5);
    if ( v10 )
    {
LABEL_6:
      *v10 = 1215324997;
      v10[1] = 0;
      v10[2] = 0;
      v10[3] = 0;
      v11 = a1[1];
      v12 = a1[2];
      v13 = a1[3];
      v10[4] = *a1;
      v10[5] = v11;
      v10[6] = v12;
      v10[7] = v13;
      v10[8] = a4;
      v10[9] = v6;
      v10[10] = v9;
      v10[11] = a5;
      v10[12] = 0;
      result = 0;
      *a6 = v10 + 13;
      return result;
    }
    v16 = *(_QWORD *)(a5 + 32);
    v17 = *(_DWORD *)(a5 + 28);
    ++*(_DWORD *)(a5 + 16);
    v15 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(a5 + 40))(v17, HIDWORD(v16), v16);
  }
  v10 = (_DWORD *)v15;
  if ( v15 )
    goto LABEL_6;
  return sub_7F45B8();
}
